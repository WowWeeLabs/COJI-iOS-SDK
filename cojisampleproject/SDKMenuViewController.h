//
//  FactoryMenuViewController.h
//  Sample Project
//
//  Created by David Chan on 3/4/17.
//  Copyright © 2017 WowWee Group Limited. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WowweeCojiSDK/WowweeCojiSDK.h>
#import "ItemsSelectionTableViewController.h"
#import "LoadingView.h"

typedef enum _SDKTestMenuMode {
    SDKMenuMode_LED = 0,
    SDKMenuMode_Button = 1,
    SDKMenuMode_RemoteControl = 2,
    SDKMenuMode_SettingFeatures = 3,
    SDKMenuMode_InteractionFeatures = 4,
    SDKMenuMode_BatteryFeatures = 5,
}SDKMenuMode;

@interface SDKMenuViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, ItemsSelectionTableViewCallback, CojiDelegate> {
    int                     selectedImageIndex;
}

#pragma mark - Property
@property (readwrite, atomic) IBOutlet UITableView      *menuTable;
@property (readwrite, atomic) IBOutlet UILabel          *firmwareLabel;
@property (nonatomic, readwrite) NSArray                *ledColorArr;
@property (nonatomic, readwrite) NSArray                *remoteArr;
@property (nonatomic, readwrite) NSArray                *settingArr;
@property (nonatomic, readwrite) NSArray                *interactionArr;
@property (nonatomic, readwrite) NSArray                *animationPathArr;
@property (nonatomic, readwrite) NSArray                *imagePathArr;
@property (nonatomic, readwrite) NSArray                *soundPathArr;
@property (nonatomic, readwrite) NSArray                *imageTemplateArr;

@property (nonatomic, readwrite) NSArray                *selectionMenuArr;

@end
