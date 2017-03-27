/*
 * Copyright 2010-2014 WowWee Group Ltd, All Rights Reserved.
 *
 * Licensed under the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

@import CoreBluetooth;

#import "Coji.h"
#import "BluetoothRobotFinder.h"

FOUNDATION_EXPORT NSString *const CojiFinderNotificationID;
FOUNDATION_EXPORT bool const COJI_ROBOT_FINDER_DEBUG_MODE;

/**
 These are the values that can be sent from CojiFinder
 */
typedef enum : NSUInteger {
    CojiFinderNote_CojiFound = 1,
    CojiFinderNote_CojiListCleared,
    CojiFinderNote_BluetoothError,
    CojiFinderNote_BluetoothIsOff,
    CojiFinderNote_BluetoothIsAvailable,
} CojiFinderNote;

@interface CojiFinder : BluetoothRobotFinder <CBCentralManagerDelegate>

/**

 */
@property (nonatomic, strong, readonly) NSMutableArray *robotsFound;
@property (nonatomic, strong, readonly) NSMutableArray *robotsConnected;
@property (nonatomic, assign, readonly) CBCentralManagerState cbCentralManagerState;

// Log level
@property (nonatomic, assign) CojiLogLevel logLevel;

/**
 Starts the BLE scanning
 */
-(void)scanForRobots;

/**
 Starts the BLE scanning for a specified number of seconds. Normally you should use this method because endlessly scanning is very battery intensive.
 */
-(void)scanForRobotsForDuration:(NSUInteger)seconds;
-(void)stopScanForRobots;
-(void)clearFoundRobotList;

/**
 Quick access to first connected Coji in cojisConnected list
 @return cojisConnected[0] or nil if cojisConnected is empty
 */
-(Coji *)firstConnectedCoji;

@end
