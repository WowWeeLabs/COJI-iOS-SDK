//
//  ConnectionViewController.h
//  cojisampleproject
//
//  Created by David Chan on 17/3/2017.
//  Copyright © 2017 wowwee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <WowweeCojiSDK/WowweeCojiSDK.h>
#import "LoadingView.h"

@interface ConnectionViewController : UIViewController <CBCentralManagerDelegate, CojiDelegate> {
    NSMutableArray      *peripheralList;
    BOOL                isConnected;
    LoadingView         *viewLoading;
}

#pragma mark - IBAction
- (IBAction)refreshAction:(id)sender;

#pragma mark - Public Methods
- (void)cleanRobots;
- (void)prepareCBCentralManager;
- (void)startScanning;
- (void)stopScanning;
- (void)changePage;

@property (strong, nonatomic) CBCentralManager              *cm;
@property (atomic, readwrite) IBOutlet UITableView          *tableView;

@end

