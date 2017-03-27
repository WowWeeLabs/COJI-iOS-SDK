//
//  ButtonTestViewController.h
//  EmojiBot
//
//  Created by David Chan on 24/3/16.
//  Copyright © 2016 Hexed Bits. All rights reserved.
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
