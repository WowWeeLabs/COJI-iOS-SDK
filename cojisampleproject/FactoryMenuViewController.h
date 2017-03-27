//
//  FactoryMenuViewController.h
//  EmojiBot
//
//  Created by David Chan on 24/3/16.
//  Copyright © 2016 Hexed Bits. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WowweeCojiSDK/WowweeCojiSDK.h>
#import "ItemsSelectionTableViewController.h"
#import "LoadingView.h"

typedef enum _FactoryTestMenuMode {
    FactoryTestMenuMode_LED = 0,
    FactoryTestMenuMode_Button = 1,
    FactoryTestMenuMode_RemoteControl = 2,
    FactoryTestMenuMode_ModuleSettingFeatures = 3,
    FactoryTestMenuMode_PlayingFeatures = 4,
    FactoryTestMenuMode_BatteryFeatures = 5,
}FactoryTestMenuMode;

@interface FactoryMenuViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, ItemsSelectionTableViewCallback, CojiDelegate> {
    LoadingView* loadingView;
    int stage;
    int selectedIndex;
    
    int selectedImageIndex;
}

#pragma mark - Property
@property (readwrite, atomic) IBOutlet UITableView      *menuTable;
@property (readwrite, atomic) IBOutlet UILabel          *labelFirmware;
@property (nonatomic, readwrite) NSArray                *arrLEDColor;
@property (nonatomic, readwrite) NSArray                *arrRemote;
@property (nonatomic, readwrite) NSArray                *arrModuleSetting;
@property (nonatomic, readwrite) NSArray                *arrAnimationPath;
@property (nonatomic, readwrite) NSArray                *arrImagePath;
@property (nonatomic, readwrite) NSArray                *arrSoundPath;
@property (nonatomic, readwrite) NSArray                *arrImageTemplate;

@property (nonatomic, readwrite) NSMutableArray         *selectionMenuArray;
@property (nonatomic, readwrite) NSMutableArray         *secondSelectionMenuArray;

@end
