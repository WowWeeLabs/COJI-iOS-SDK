//
//  FactoryMenuViewController.m
//  Sample Project
//
//  Created by David Chan on 3/4/17.
//  Copyright © 2017 WowWee Group Limited. All rights reserved.
//

#import "SDKMenuViewController.h"
#import "ButtonTestViewController.h"

@implementation SDKMenuViewController

static SDKMenuViewController* _factoryMenuViewController = nil;
NSString * const kFirmwareFilename = @"Coji_FW_2016060702.bin";

#pragma mark - Override Methods
- (void)viewDidLoad {
    [super viewDidLoad];
    
    _factoryMenuViewController = self;
    
    [self.firmwareLabel setText:[NSString stringWithFormat:@"Version: %@", @""]];
    
    self.ledColorArr = [NSArray arrayWithObjects:@"Turn Off", @"White", @"Red", @"Green", @"Blue", @"Yellow", @"Magenta", @"Cyan", @"Request Current Color", nil];
    
    self.remoteArr = [NSArray arrayWithObjects:@"Drive Forward", @"Drive Backward", @"Turn Left", @"Turn Right", nil];
    
    self.settingArr = @[@"Detect Battery", @"Reboot", @"Get Volume", @"Set Volume", @"Get LCD Display Back Light", @"Set LCD Display Back Light"];
    
    self.interactionArr = @[@"Play Animation", @"Show Image", @"Play Sound"];
    
    self.animationPathArr = [NSMutableArray arrayWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"AnimationList.plist" ofType:nil]];
    
    self.soundPathArr = [NSMutableArray arrayWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"SoundList.plist" ofType:nil]];
    
    self.imagePathArr = [NSMutableArray arrayWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"ImageList.plist" ofType:nil]];
    
    self.imageTemplateArr = @[@"kCojiImage_AnimationTemplate_ScaleUp", @"kCojiImage_AnimationTemplate_ScaleDown", @"kCojiImage_AnimationTemplate_RightToLeft", @"kCojiImage_AnimationTemplate_LeftToRight", @"kCojiImage_AnimationTemplate_CenterToLeft", @"kCojiImage_AnimationTemplate_CenterToRight", @"kCojiImage_AnimationTemplate_DownToCenter", @"kCojiImage_AnimationTemplate_CenterToDown", @"kCojiImage_AnimationTemplate_UpToCenter", @"kCojiImage_AnimationTemplate_CenterToUp", @"kCojiImage_AnimationTemplate_None"];
    
    self.selectionMenuArr = @[@"Change LED color", @"Button and accelerometer Test", @"Drive COJI", @"Modules Setting Features", @"Playing Features"];
    
    if ([[CojiFinder sharedInstance] firstConnectedCoji] != nil) {
        Coji * robot = [[CojiFinder sharedInstance] firstConnectedCoji];
        [robot setDelegate:self];
        [robot getFirmwareVersion];
    }
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [self.menuTable reloadData];
    [self.navigationController setNavigationBarHidden:YES animated:animated];
    [self.navigationItem setHidesBackButton:YES animated:NO];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
}

#pragma mark - ItemsSelectionTableViewCallback
- (void)didSelectRow:(int)selection Mode:(int)_mode {
    if ([[CojiFinder sharedInstance] firstConnectedCoji] != nil) {
        Coji * robot = [[[CojiFinder sharedInstance] robotsConnected] objectAtIndex:0];
        switch (_mode) {
            case ItemsSelectionTableViewControllerMode_LED:
                switch (selection) {
                    case 0:
                        [robot setChestRGBLEDWithRed:NO Green:NO Blue:NO];
                        break;
                    case 1:
                        [robot setChestRGBLEDWithRed:YES Green:YES Blue:YES];
                        break;
                    case 2:
                        [robot setChestRGBLEDWithRed:YES Green:NO Blue:NO];
                        break;
                    case 3:
                        [robot setChestRGBLEDWithRed:NO Green:YES Blue:NO];
                        break;
                    case 4:
                        [robot setChestRGBLEDWithRed:NO Green:NO Blue:YES];
                        break;
                    case 5:
                        [robot setChestRGBLEDWithRed:YES Green:YES Blue:NO];
                        break;
                    case 6:
                        [robot setChestRGBLEDWithRed:YES Green:NO Blue:YES];
                        break;
                    case 7:
                        [robot setChestRGBLEDWithRed:NO Green:YES Blue:YES];
                        break;
                    case 8:
                        [robot requestChestRGBLED];
                        break;
                    default:
                        break;
                }
                break;
            case ItemsSelectionTableViewControllerMode_Remote:
                switch (selection) {
                    case 0:
                        [robot driveForwardWithSpeed:0.5f Time:0.16f];
                        break;
                    case 1:
                        [robot driveBackwardWithSpeed:0.5f Time:0.16f];
                        break;
                    case 2:
                        [robot turnLeftWithSpeed:1.0f Time:0.16f];
                        break;
                    case 3:
                        [robot turnRightWithSpeed:1.0f Time:0.16f];
                        break;
                    default:
                        break;
                }
                break;
            case ItemsSelectionTableViewControllerMode_ModuleSetting:
                if (selection == 0) {
                    if ([[CojiFinder sharedInstance] firstConnectedCoji] != nil) {
                        Coji * robot = [[[CojiFinder sharedInstance] robotsConnected] objectAtIndex:0];
                        [robot setDelegate:self];
                        [robot requestBatteryLevel];
                    }
                }
                else if (selection == 1) {
                    if ([[CojiFinder sharedInstance] firstConnectedCoji] != nil) {
                        Coji * robot = [[[CojiFinder sharedInstance] robotsConnected] objectAtIndex:0];
                        [robot reboot];
                    }
                }
                else if (selection == 2) {
                    if ([[CojiFinder sharedInstance] firstConnectedCoji] != nil) {
                        Coji * robot = [[[CojiFinder sharedInstance] robotsConnected] objectAtIndex:0];
                        [robot setDelegate:self];
                        [robot requestVolumeLevel];
                    }
                }
                else if (selection == 3) {
                    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Set Volume" message:@"Please enter volume level" preferredStyle:UIAlertControllerStyleAlert];
                    
                    [alertController addTextFieldWithConfigurationHandler:^(UITextField *textField) {
                        textField.placeholder = @"Value (0.0f-1.0f)";
                    }];
                    
                    [alertController addAction:[UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction *action) {
                    }]];
                    [alertController addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
                        NSString *sizeString = ((UITextField *)[alertController.textFields objectAtIndex:0]).text;
                        if (![sizeString isEqualToString:@""]) {
                            if ([[CojiFinder sharedInstance] firstConnectedCoji] != nil) {
                                Coji * robot = [[[CojiFinder sharedInstance] robotsConnected] objectAtIndex:0];
                                [robot setDelegate:self];
                                [robot setVolumeLevel:[sizeString floatValue]];
                            }
                        }
                        
                    }]];
                    [self presentViewController:alertController animated:YES completion:nil];
                }
                else if (selection == 4) {
                    if ([[CojiFinder sharedInstance] firstConnectedCoji] != nil) {
                        Coji * robot = [[[CojiFinder sharedInstance] robotsConnected] objectAtIndex:0];
                        [robot setDelegate:self];
                        [robot getLEDBackLight];
                    }
                }
                else if (selection == 5) {
                    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Set LED Backlight" message:@"Please enter value" preferredStyle:UIAlertControllerStyleAlert];
                    
                    [alertController addTextFieldWithConfigurationHandler:^(UITextField *textField) {
                        textField.placeholder = @"Value (0-Disable, 1-Enable)";
                    }];
                    
                    [alertController addAction:[UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction *action) {
                    }]];
                    [alertController addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
                        NSString *sizeString = ((UITextField *)[alertController.textFields objectAtIndex:0]).text;
                        if (![sizeString isEqualToString:@""]) {
                            if ([[CojiFinder sharedInstance] firstConnectedCoji] != nil) {
                                Coji * robot = [[[CojiFinder sharedInstance] robotsConnected] objectAtIndex:0];
                                [robot setDelegate:self];
                                [robot enableLEDBackLight:[sizeString intValue]==1];
                            }
                        }
                        
                    }]];
                    [self presentViewController:alertController animated:YES completion:nil];
                }
                break;
            case ItemsSelectionTableViewControllerMode_InteractionSelection:
                if (selection == 0) {
                    UIStoryboard* sb = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
                    ItemsSelectionTableViewController* controller = [sb instantiateViewControllerWithIdentifier:@"ItemsSelectionTableViewController"];
                    controller.arrItems = self.animationPathArr;
                    controller.delegate = self;
                    controller.mode = ItemsSelectionTableViewControllerMode_AnimationSelection;
                    if ([[CojiFinder sharedInstance] firstConnectedCoji] != nil) {
                        Coji * robot = [[[CojiFinder sharedInstance] robotsConnected] objectAtIndex:0];
                        [robot setDelegate:self];
                    }
                    [self.navigationController pushViewController:controller animated:YES];
                    [self.navigationController setNavigationBarHidden:NO animated:NO];
                }
                else if (selection == 1) {
                    UIStoryboard* sb = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
                    ItemsSelectionTableViewController* controller = [sb instantiateViewControllerWithIdentifier:@"ItemsSelectionTableViewController"];
                    controller.arrItems = self.imagePathArr;
                    controller.delegate = self;
                    controller.mode = ItemsSelectionTableViewControllerMode_ImageSelection;
                    if ([[CojiFinder sharedInstance] firstConnectedCoji] != nil) {
                        Coji * robot = [[[CojiFinder sharedInstance] robotsConnected] objectAtIndex:0];
                        [robot setDelegate:self];
                    }
                    [self.navigationController pushViewController:controller animated:YES];
                    [self.navigationController setNavigationBarHidden:NO animated:NO];
                }
                else if (selection == 2) {
                    UIStoryboard* sb = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
                    ItemsSelectionTableViewController* controller = [sb instantiateViewControllerWithIdentifier:@"ItemsSelectionTableViewController"];
                    controller.arrItems = self.soundPathArr;
                    controller.delegate = self;
                    controller.mode = ItemsSelectionTableViewControllerMode_SoundSelection;
                    if ([[CojiFinder sharedInstance] firstConnectedCoji] != nil) {
                        Coji * robot = [[[CojiFinder sharedInstance] robotsConnected] objectAtIndex:0];
                        [robot setDelegate:self];
                    }
                    [self.navigationController pushViewController:controller animated:YES];
                    [self.navigationController setNavigationBarHidden:NO animated:NO];
                }
                break;
            case ItemsSelectionTableViewControllerMode_AnimationSelection:
                if (selection == 0)
                    [robot stopCommandWithType:kCojiStopTypeAnimation];
                else
                    [robot playAnimationWithAnimationIndex:selection-1 EnableSound:YES];
                break;
            case ItemsSelectionTableViewControllerMode_ImageSelection: {
                    selectedImageIndex = selection;
                    UIStoryboard* sb = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
                    ItemsSelectionTableViewController* controller = [sb instantiateViewControllerWithIdentifier:@"ItemsSelectionTableViewController"];
                    controller.arrItems = self.imageTemplateArr;
                    controller.delegate = self;
                    controller.mode = ItemsSelectionTableViewControllerMode_ImageTemplateSelection;
                    if ([[CojiFinder sharedInstance] firstConnectedCoji] != nil) {
                        Coji * robot = [[[CojiFinder sharedInstance] robotsConnected] objectAtIndex:0];
                        [robot setDelegate:self];
                    }
                    [self.navigationController pushViewController:controller animated:YES];
                    [self.navigationController setNavigationBarHidden:NO animated:NO];
                }
                break;
            case ItemsSelectionTableViewControllerMode_SoundSelection:
                if (selection == 0)
                    [robot stopCommandWithType:kCojiStopTypeSound];
                else
                    [robot playSoundWithSoundIndex:selection-1];
                break;
            case ItemsSelectionTableViewControllerMode_ImageTemplateSelection:
                [robot showImageWithImageIndex:selectedImageIndex TemplateID:selection];
                break;
        }
    }
}

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.selectionMenuArr count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSString* identifierString = @"TableViewCellIdentifier";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifierString];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifierString];
    }
    
    [cell.textLabel setText:[self.selectionMenuArr objectAtIndex:indexPath.row]];
    return cell;
}

#pragma mark - UITableViewDelegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == SDKMenuMode_LED) {
        UIStoryboard* sb = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
        ItemsSelectionTableViewController* controller = [sb instantiateViewControllerWithIdentifier:@"ItemsSelectionTableViewController"];
        controller.arrItems = self.ledColorArr;
        controller.delegate = self;
        controller.mode = ItemsSelectionTableViewControllerMode_LED;
        [self.navigationController pushViewController:controller animated:YES];
        [self.navigationController setNavigationBarHidden:NO animated:NO];
    }
    else if (indexPath.row == SDKMenuMode_Button) {
        UIStoryboard* sb = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
        ButtonTestViewController* controller = [sb instantiateViewControllerWithIdentifier:@"ButtonTestViewController"];
        [self.navigationController pushViewController:controller animated:YES];
        [self.navigationController setNavigationBarHidden:NO animated:NO];
    }
    else if (indexPath.row == SDKMenuMode_RemoteControl) {
        UIStoryboard* sb = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
        ItemsSelectionTableViewController* controller = [sb instantiateViewControllerWithIdentifier:@"ItemsSelectionTableViewController"];
        controller.arrItems = self.remoteArr;
        controller.delegate = self;
        controller.mode = ItemsSelectionTableViewControllerMode_Remote;
        [self.navigationController pushViewController:controller animated:YES];
        [self.navigationController setNavigationBarHidden:NO animated:NO];
    }
    else if (indexPath.row == SDKMenuMode_SettingFeatures) {
        UIStoryboard* sb = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
        ItemsSelectionTableViewController* controller = [sb instantiateViewControllerWithIdentifier:@"ItemsSelectionTableViewController"];
        controller.arrItems = self.settingArr;
        controller.delegate = self;
        controller.mode = ItemsSelectionTableViewControllerMode_ModuleSetting;
        [self.navigationController pushViewController:controller animated:YES];
        [self.navigationController setNavigationBarHidden:NO animated:NO];
    }
    else if (indexPath.row == SDKMenuMode_InteractionFeatures) {
        UIStoryboard* sb = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
        ItemsSelectionTableViewController* controller = [sb instantiateViewControllerWithIdentifier:@"ItemsSelectionTableViewController"];
        controller.arrItems = self.interactionArr;
        controller.delegate = self;
        controller.mode = ItemsSelectionTableViewControllerMode_InteractionSelection;
        [self.navigationController pushViewController:controller animated:YES];
        [self.navigationController setNavigationBarHidden:NO animated:NO];
    }
}


#pragma mark - CojiDelegate
- (void)coji:(Coji *)robot didReceiveAnimationStatus:(int)status AnimationID:(int)animationID {
    UIAlertController *alertController = nil;
    NSString* titleString = @"Animation Status";
    NSString* msgString = @"";
    if (status == 0)
        msgString = [NSString stringWithFormat:@"Animation Started: %d", animationID];
    else if (status == 1)
        msgString = [NSString stringWithFormat:@"Animation Finished: %d", animationID];
    else if (status == 2)
        msgString = [NSString stringWithFormat:@"Animation Stopped to play: %d", animationID];
    else if (status == 3)
        msgString = [NSString stringWithFormat:@"Animation Failed to play: %d", animationID];
    
    alertController = [UIAlertController alertControllerWithTitle:titleString message:msgString preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction* ok = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil];
    [alertController addAction:ok];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)coji:(Coji *)coji didReceiveImageStatus:(int)status ImageID:(int)imageID {
    UIAlertController *alertController = nil;
    NSString* titleString = @"Image Status";
    NSString* msgString = @"";
    if (status == 0)
        msgString = [NSString stringWithFormat:@"Image Started: %d", imageID];
    else if (status == 1)
        msgString = [NSString stringWithFormat:@"Image Finished: %d", imageID];
    else if (status == 2)
        msgString = [NSString stringWithFormat:@"Image Stopped to play: %d", imageID];
    else if (status == 3)
        msgString = [NSString stringWithFormat:@"Image Failed to play: %d", imageID];
    
    
    alertController = [UIAlertController alertControllerWithTitle:titleString message:msgString preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction* ok = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil];
    [alertController addAction:ok];
    
    if (![msgString isEqualToString:@""])
        [self presentViewController:alertController animated:YES completion:nil];
}

- (void)coji:(Coji *)coji didReceiveSoundStatus:(int)status SoundID:(int)soundID {
    if (status == 0x55)
        return;
    UIAlertController *alertController = nil;
    NSString* titleString = @"Sound Status";
    NSString* msgString = @"";
    if (status == 0)
        msgString = [NSString stringWithFormat:@"Sound Started: %d", soundID];
    else if (status == 1)
        msgString = [NSString stringWithFormat:@"Sound Finished: %d", soundID];
    else if (status == 2)
        msgString = [NSString stringWithFormat:@"Sound Stopped to play: %d", soundID];
    else if (status == 3)
        msgString = [NSString stringWithFormat:@"Sound Failed to play: %d", soundID];
    
    alertController = [UIAlertController alertControllerWithTitle:titleString message:msgString preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction* ok = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil];
    [alertController addAction:ok];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)coji:(Coji *)robot didReceiveChestLEDWithRed:(BOOL)isRed Green:(BOOL)isGreen Blue:(BOOL)isBlue {
    UIAlertController *alertController = nil;
    NSString* titleString = @"LED Color";
    NSString* msgString = @"Message";
    if (isRed && isGreen && isBlue) {
        msgString = @"White";
    }
    else if (isRed && isGreen) {
        msgString = @"Yellow";
    }
    else if (isGreen && isBlue) {
        msgString = @"Cyan";
    }
    else if (isRed && isBlue) {
        msgString = @"Magenta";
    }
    else if (isRed) {
        msgString = @"Red";
    }
    else if (isGreen) {
        msgString = @"Green";
    }
    else if (isBlue) {
        msgString = @"Blue";
    }
    else {
        msgString = @"Disabled";
    }
    
    alertController = [UIAlertController alertControllerWithTitle:titleString message:msgString preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction* ok = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil];
    [alertController addAction:ok];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)coji:(Coji *)coji didReceiveLEDBackLightEnabled:(BOOL)isEnabled {
    UIAlertController *alertController = nil;
    NSString* titleString = @"LED Back Light";
    NSString* msgString = @"Message";
    if (isEnabled) {
        msgString = @"Enabled";
    }
    else {
        msgString = @"Disabled";
    }
    
    alertController = [UIAlertController alertControllerWithTitle:titleString message:msgString preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction* ok = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil];
    [alertController addAction:ok];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)cojiDeviceDisconnected:(Coji *)robot error:(NSError *)error {    
    UIAlertController *alertController = nil;
    NSString* titleString = @"File Upload";
    NSString* msgString = @"Message";
    msgString = @"Coji Disconnected. Please kill app and reconnect";
    
    alertController = [UIAlertController alertControllerWithTitle:titleString message:msgString preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction* ok = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil];
    [alertController addAction:ok];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)coji:(Coji *)coji didReceiveVolume:(float)v {
    UIAlertController *alertController = nil;
    NSString* titleString = @"Volume";
    NSString* msgString = [NSString stringWithFormat:@"Value: %f", v];
    
    alertController = [UIAlertController alertControllerWithTitle:titleString message:msgString preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction* ok = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil];
    [alertController addAction:ok];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)coji:(Coji *)robot didReceiveBatteryLevel:(float)level {
    UIAlertController *alertController = nil;
    NSString* titleString = @"Battery";
    NSString* msgString = [NSString stringWithFormat:@"Value: %f", level];
    
    alertController = [UIAlertController alertControllerWithTitle:titleString message:msgString preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction* ok = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil];
    [alertController addAction:ok];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)coji:(Coji *)robot didReceiveFirmwareVersion:(NSString*)version {
    NSString *str = [NSString stringWithFormat:@"%@", version];
    [self.firmwareLabel setText:[NSString stringWithFormat:@"Version: %@", str]];
}

@end
