//
//  CojiSDKConfig.h
//  WowWeeCojiSDK
//
//  Created by Forrest Chan on 17/11/14.
//  Copyright (c) 2014 WowWee Group Ltd. All rights reserved.
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
