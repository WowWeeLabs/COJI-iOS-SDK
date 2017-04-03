//
//  CojiSDKConfig.h
//  BluetoothRobotControlLibrary
//
//  Created by David Chan on 3/4/17.
//  Copyright (c) 2017 WowWee Group Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

// These can be overridden by defining them before importing the SDK

typedef enum {
    MRFCojiScanOptionMask_ShowAllDevices       = 0,
    MRFCojiScanOptionMask_FilterByProductId    = 1 << 0,
    MRFCojiScanOptionMask_FilterByServices     = 1 << 1,
    MRFCojiScanOptionMask_FilterByDeviceName   = 1 << 2,
} CojiFinderScanOptions;

#ifndef COJI_SCAN_OPTIONS
#define COJI_SCAN_OPTIONS MRFCojiScanOptionMask_ShowAllDevices | MRFCojiScanOptionMask_FilterByProductId
#endif

@interface CojiSDKConfig : NSObject
@end
