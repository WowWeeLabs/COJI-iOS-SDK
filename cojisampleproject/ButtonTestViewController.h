//
//  ButtonTestViewController.h
//  Sample Project
//
//  Created by David Chan on 3/4/17.
//  Copyright © 2017 WowWee Group Limited. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ItemsSelectionTableViewController.h"
#import <WowweeCojiSDK/WowweeCojiSDK.h>

@interface ButtonTestViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, CojiDelegate> {
    BOOL isPressedLeftBtn;
    BOOL isPressedCenterBtn;
    BOOL isPressedRightBtn;
    BOOL isTiltLeft;
    BOOL isTiltRight;
    BOOL isTiltForward;
    BOOL isTiltBackward;
    BOOL isLieForwardDown;
    BOOL isLieBackwardDown;
    BOOL isShake;
    BOOL isPickUp;
}

#pragma mark - Property
@property (readwrite, atomic) IBOutlet UITableView* menuTable;
@property (nonatomic, readwrite) NSArray *arrItems;

@end
