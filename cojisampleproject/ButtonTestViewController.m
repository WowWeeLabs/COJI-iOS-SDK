//
//  ButtonTestViewController.m
//  EmojiBot
//
//  Created by David Chan on 24/3/16.
//  Copyright © 2016 Hexed Bits. All rights reserved.
//

#import "ButtonTestViewController.h"

@implementation ButtonTestViewController

#pragma mark - Override Methods
- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.arrItems = [NSArray arrayWithObjects:@"Button: Left", @"Button: Head", @"Button: Right", @"Acceleromter: Tilt Left", @"Acceleromter: Tilt Right", @"Acceleromter: Tilt Forward", @"Acceleromter: Tilt Backward", @"Acceleromter: Shake", @"Acceleromter: Pick Up", nil];
    
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [self.menuTable reloadData];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    Coji * robot = [[[CojiFinder sharedInstance] robotsConnected] objectAtIndex:0];
    robot.delegate = self;
}

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.arrItems count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSString* identifierString = @"TableViewCellIdentifier";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifierString];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifierString];
    }
    [cell.textLabel setText:[self.arrItems objectAtIndex:indexPath.row]];
    if (indexPath.row == 0) {
        if (isPressedLeftBtn)
            cell.accessoryType = UITableViewCellAccessoryCheckmark;
        else
            cell.accessoryType = UITableViewCellAccessoryNone;
    }
    else if (indexPath.row == 1) {
        if (isPressedCenterBtn)
            cell.accessoryType = UITableViewCellAccessoryCheckmark;
        else
            cell.accessoryType = UITableViewCellAccessoryNone;
    }
    else if (indexPath.row == 2) {
        if (isPressedRightBtn)
            cell.accessoryType = UITableViewCellAccessoryCheckmark;
        else
            cell.accessoryType = UITableViewCellAccessoryNone;
    }
    else if (indexPath.row == 3) {
        if (isTiltLeft)
            cell.accessoryType = UITableViewCellAccessoryCheckmark;
        else
            cell.accessoryType = UITableViewCellAccessoryNone;
    }
    else if (indexPath.row == 4) {
        if (isTiltRight)
            cell.accessoryType = UITableViewCellAccessoryCheckmark;
        else
            cell.accessoryType = UITableViewCellAccessoryNone;
    }
    else if (indexPath.row == 5) {
        if (isTiltForward)
            cell.accessoryType = UITableViewCellAccessoryCheckmark;
        else
            cell.accessoryType = UITableViewCellAccessoryNone;
    }
    else if (indexPath.row == 6) {
        if (isTiltBackward)
            cell.accessoryType = UITableViewCellAccessoryCheckmark;
        else
            cell.accessoryType = UITableViewCellAccessoryNone;
    }
    else if (indexPath.row == 7) {
        if (isShake)
            cell.accessoryType = UITableViewCellAccessoryCheckmark;
        else
            cell.accessoryType = UITableViewCellAccessoryNone;
    }
    else if (indexPath.row == 8) {
        if (isPickUp)
            cell.accessoryType = UITableViewCellAccessoryCheckmark;
        else
            cell.accessoryType = UITableViewCellAccessoryNone;
    }
    
    
    return cell;
}

- (void)close {
    if (isPickUp) {
        isPickUp = NO;
        [self.menuTable reloadData];
    }
    if (isShake) {
        isShake = NO;
        [self.menuTable reloadData];
    }
}

#pragma mark - CojiDelegate
- (void)coji:(Coji *)robot didReceiveLeftButton:(int)leftButtonStatus CenterButton:(int)centerButtonStatus RightButton:(int)rightButtonStatus {
    isPressedLeftBtn = (leftButtonStatus == kCojiButtonPressedStatusOn);
    isPressedCenterBtn = (centerButtonStatus == kCojiButtonPressedStatusOn);
    [self performSelector:@selector(close) withObject:nil afterDelay:1.0f];
    isPressedRightBtn = (rightButtonStatus == kCojiButtonPressedStatusOn);
    [self.menuTable reloadData];
}

- (void)coji:(Coji *)robot didReceiveTiltLeft:(int)tiltLeftStatus TiltRight:(int)tiltRightStatus TiltForward:(int)tiltForwardStatus TiltBackward:(int)tiltBackwardStatus LieDownForward:(int)lieDownForwardStatus LieDownBackward:(int)lieDownBackwardStatus Shake:(int)shakeStatus PickUp:(int)pickUpStatus {
    isTiltLeft = tiltLeftStatus == kCojiButtonPressedStatusOn;
    isTiltRight = tiltRightStatus == kCojiButtonPressedStatusOn;
    isTiltForward = tiltForwardStatus == kCojiButtonPressedStatusOn;
    isTiltBackward = tiltBackwardStatus == kCojiButtonPressedStatusOn;
    isLieForwardDown = lieDownForwardStatus == kCojiButtonPressedStatusOn;
    isLieBackwardDown = lieDownBackwardStatus == kCojiButtonPressedStatusOn;
    isShake = shakeStatus == kCojiButtonPressedStatusOn;
    isPickUp = pickUpStatus == kCojiButtonPressedStatusOn;
    if (isPickUp || isShake)
        [self performSelector:@selector(close) withObject:nil afterDelay:1.0f];
    [self.menuTable reloadData];
}

- (void)coji:(Coji *)robot didReceiveConnectionStatus:(BOOL)status {
    [robot isConnected];
}

@end
