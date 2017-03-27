//
//  ConnectionViewController.m
//  cojisampleproject
//
//  Created by David Chan on 17/3/2017.
//  Copyright © 2017 wowwee. All rights reserved.
//

#import "ConnectionViewController.h"
#import "FactoryMenuViewController.h"

@interface ConnectionViewController ()

@end

@implementation ConnectionViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    peripheralList = [NSMutableArray new];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onCojiFinderNotification:) name:CojiFinderNotificationID object:nil];
    [self prepareCBCentralManager];
    
    NSArray* nibViews = [[NSBundle mainBundle] loadNibNamed:@"LoadingView"
                                                      owner:self
                                                    options:nil];
    viewLoading = [nibViews objectAtIndex:0];
    [viewLoading setFrame:[self.view frame]];
    [self.view addSubview:viewLoading];
    [viewLoading hide];
    
    [self.navigationController setNavigationBarHidden:YES];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - IBAction
- (IBAction)refreshAction:(id)sender {
    [self.tableView reloadData];
    
    [self cleanRobots];
    
    [self startScanning];
}

#pragma mark - Public Methods
- (void)cleanRobots {
#if !defined(TARGET_IPHONE_SIMULATOR) || TARGET_IPHONE_SIMULATOR == 0
    [self stopScanning];
    [[CojiFinder sharedInstance] clearFoundRobotList];
    [peripheralList removeAllObjects];
#endif
}

- (void)prepareCBCentralManager {
    //#if !defined(TARGET_IPHONE_SIMULATOR) || TARGET_IPHONE_SIMULATOR == 0
    //#else
    self.cm = [[CBCentralManager alloc] initWithDelegate:self queue:nil];
    //#endif
}
- (void)startScanning {
    [[CojiFinder sharedInstance] scanForRobots];
    //    self.scanningLabel.hidden = NO;
}

- (void)stopScanning {
    [[CojiFinder sharedInstance] stopScanForRobots];
}

- (void)changePage {
    UIStoryboard* sb = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    FactoryMenuViewController *controller = [sb instantiateViewControllerWithIdentifier:@"FactoryMenuViewController"];
    [self.navigationController pushViewController:controller animated:YES];
}

#pragma mark - UITableView DataSource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [peripheralList count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString* strIdentifier = @"RobotConnectionTableViewCellIdentifier";
    UITableViewCell* cell = nil;
    cell = [tableView dequeueReusableCellWithIdentifier:strIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:strIdentifier];
    }
    if ([peripheralList count] > indexPath.row){
        BluetoothRobot *robot = [peripheralList objectAtIndex:indexPath.row];
        [cell.textLabel setText:robot.name];
    }
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    Coji *robot = nil;
    robot = [[[CojiFinder sharedInstance] robotsFound] objectAtIndex:indexPath.row];
    robot.delegate = self;
    [robot connect];
    [viewLoading show];
}

#pragma mark - CBCentralManagerDelegate
- (void) centralManagerDidUpdateState:(CBCentralManager *)central {
    NSLog(@"checking state");
    switch (central.state) {
        case CBCentralManagerStatePoweredOff:
            NSLog(@"CoreBluetooth BLE hardware is powered off");
            break;
        case CBCentralManagerStatePoweredOn:
            NSLog(@"CoreBluetooth BLE hardware is powered on and ready");
            [self startScanning];
            break;
        case CBCentralManagerStateResetting:
            NSLog(@"CoreBluetooth BLE hardware is resetting");
            break;
        case CBCentralManagerStateUnauthorized:
            NSLog(@"CoreBluetooth BLE state is unauthorized");
            break;
        case CBCentralManagerStateUnknown:
            NSLog(@"CoreBluetooth BLE state is unknown");
            break;
        case CBCentralManagerStateUnsupported:
            NSLog(@"CoreBluetooth BLE hardware is unsupported on this platform");
            break;
        default:
            break;
    }
}

- (void) centralManager:(CBCentralManager *)central didDiscoverPeripheral:(CBPeripheral *)peripheral advertisementData:(NSDictionary *)advertisementData RSSI:(NSNumber *)RSSI {
    NSLog(@"Did discover peripheral %@", peripheral.name);
    
    [peripheralList addObject:peripheral];
}

- (void) centralManager:(CBCentralManager *)central didConnectPeripheral:(CBPeripheral *)peripheral
{
    NSLog(@"Did connect peripheral %@", peripheral.name);
}

- (void) centralManager:(CBCentralManager *)central didDisconnectPeripheral:(CBPeripheral *)peripheral error:(NSError *)error
{
    NSLog(@"Did disconnect peripheral %@", peripheral.name);
    
    //    if([self.navigationController.topViewController isKindOfClass:[RemoteViewController class]]) {
    //        [self.navigationController popViewControllerAnimated:YES];
    //    }
}

- (void)onCojiFinderNotification: (NSNotification *)notification {
    NSDictionary *info = notification.userInfo;
    if(info){
        NSNumber *code = [info objectForKey: @"code"];
        //id data = [info objectForKey: @"data"];
        if (code.intValue == CojiFinderNote_CojiFound){
            [peripheralList removeAllObjects];
            
            NSMutableArray* arr = [[CojiFinder sharedInstance] robotsFound];
            for (int i=0; i<[arr count]; i++) {
                BluetoothRobot *robot = [arr objectAtIndex:i];
                [peripheralList addObject:robot];
            }
            [self.tableView reloadData];
        } else if (code.intValue == CojiFinderNote_CojiListCleared) {
            [self.tableView reloadData];
            [peripheralList removeAllObjects];
        } else if (code.intValue == CojiFinderNote_BluetoothError) {
            NSLog(@"Bluetooth error!");
        } else if (code.intValue == CojiFinderNote_BluetoothIsOff) {
            NSLog(@"Bluetooth is off!");
        } else if (code.intValue == CojiFinderNote_BluetoothIsAvailable) {
            NSLog(@"RobosapienRobotFinderNote_BluetoothIsAvailable");
        }
    }
}

#pragma mark - CojiDelegate
- (void)cojiDeviceReady:(Coji *)robot {
    [viewLoading hide];
    [NSThread sleepForTimeInterval:2];
    robot.autoReconnect = YES;
    [self stopScanning];
    isConnected = NO;
    [self changePage];
}

- (void)cojiDeviceDisconnected:(Coji *)robot error:(NSError *)error {
    [robot disconnect];
}

- (void)cojiDeviceFailedToConnect:(Coji *)robot error:(NSError *)error {
    [viewLoading hide];
}

- (void)coji:(Coji *)robot didReceiveConnectionStatus:(BOOL)status {
    if (!isConnected) {
        [viewLoading hide];
        [NSThread detachNewThreadSelector:@selector(changePage) toTarget:self withObject:nil];
        isConnected = YES;
    }
}

@end
