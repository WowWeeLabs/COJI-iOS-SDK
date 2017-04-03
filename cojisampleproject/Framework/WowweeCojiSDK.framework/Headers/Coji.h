//
//  Coji.h
//  BluetoothRobotControlLibrary
//
//  Created by David Chan on 3/4/17.
//  Copyright (c) 2017 WowWee Group Limited. All rights reserved.
// 

@import UIKit;
@import Foundation;
@import CoreBluetooth;

#import "BluetoothRobot.h"
#import "CojiCommandValues.h"
#import "CojiConstants.h"

@protocol CojiDelegate;

FOUNDATION_EXPORT NSString *const COJI_CONNECTED_NOTIFICATION_NAME;
FOUNDATION_EXPORT NSString *const COJI_DISCONNECTED_NOTIFICATION_NAME;

typedef NS_ENUM(NSInteger, CojiLogLevel) {
    CojiLogLevelDebug,
    CojiLogLevelErrors,
    CojiLogLevelNone
};

@interface Coji : BluetoothRobot {
    
}

/** Event manager handles handling basic events which do not require app interaction **/
@property (nonatomic, readonly) NSString *firmwareString;
@property (nonatomic, assign) CojiLogLevel logLevel;

/** Delegate for receiving callbacks */
@property (nonatomic, weak) id<CojiDelegate> delegate;
@property (nonatomic, readwrite) NSMutableArray* animationListenerList;

#pragma mark - Drive Methods
- (void)driveForwardWithSpeed:(float)speed Time:(float)sec;
- (void)driveBackwardWithSpeed:(float)speed Time:(float)sec;
- (void)turnLeftWithSpeed:(float)speed Time:(float)sec;
- (void)turnRightWithSpeed:(float)speed Time:(float)sec;

#pragma mark - Module Setting Methods
- (void)setDisplayName:(NSString*)displayName;
- (void)getFirmwareVersion;
- (void)getLEDBackLight;
- (void)enableLEDBackLight:(BOOL)isEnabled;
- (void)requestBatteryLevel;
- (void)requestVolumeLevel;
- (void)setVolumeLevel:(float)level;
- (void)reboot;

#pragma mark - Interaction Methods
- (void)playAnimationWithAnimationIndex:(uint8_t)animationIndex EnableSound:(BOOL)isEnableSound;
- (void)showImageWithImageIndex:(int)imgIndex TemplateID:(kCojiImage_AnimationTemplate)templateID;
- (void)playSoundWithSoundIndex:(uint8_t)soundIndex;
- (void)stopCommandWithType:(kCojiStopType)type;
- (void)requestChestRGBLED;
- (void)setChestRGBLEDWithRed:(BOOL)isRedEnabled Green:(BOOL)isGreenEnabled Blue:(BOOL)isBlueEnabled;
- (void)checkConnectionStatus;

@end

#pragma mark - Delegate Callbacks
@protocol CojiDelegate <NSObject>
@optional
/** Connection Methods **/
- (void)cojiDeviceReady:(Coji *)robot;
- (void)cojiDeviceDisconnected:(Coji *)robot error:(NSError *)error;
- (void)cojiDeviceFailedToConnect:(Coji *)robot error:(NSError *)error;
- (void)cojiDeviceReconnecting:(Coji *)robot;
- (void)cojiDeviceWentToSleep:(Coji *)robot;
- (void)cojiDeviceWokeUp:(Coji *)robot;
- (void)coji:(Coji *)robot didReceiveBatteryLevel:(float)level;
- (void)coji:(Coji *)robot didReceivePWMSetting:(float)status;
- (void)coji:(Coji *)robot didReceiveIdleTime:(int)time;
- (void)coji:(Coji *)robot didReceiveIdleAnimationSoundEnabled:(BOOL)isEnabled;
- (void)coji:(Coji *)robot didReceiveUserDataAddress:(int)address Data:(int)data;
- (void)coji:(Coji *)robot didReceiveVolume:(float)volume;
- (void)coji:(Coji *)robot didReceiveLEDBackLightEnabled:(BOOL)isEnabled;
- (void)coji:(Coji *)robot didReceivePWM:(int)pwm;
- (void)coji:(Coji *)robot didReceiveActivation:(int)activation;
- (void)coji:(Coji *)robot didReceiveAnimationStatus:(int)status AnimationID:(int)animationID;
- (void)coji:(Coji *)robot didReceiveChestLEDWithRed:(BOOL)isRed Green:(BOOL)isGreen Blue:(BOOL)isBlue;
- (void)coji:(Coji *)robot didReceiveLeftButton:(int)leftButtonStatus CenterButton:(int)centerButtonStatus RightButton:(int)rightButtonStatus;
- (void)coji:(Coji *)robot didReceiveTiltLeft:(int)tiltLeftStatus TiltRight:(int)tiltRightStatus TiltForward:(int)tiltForwardStatus TiltBackward:(int)tiltBackwardStatus LieDownForward:(int)lieDownForwardStatus LieDownBackward:(int)lieDownBackwardStatus Shake:(int)shakeStatus PickUp:(int)pickUpStatus;
- (void)coji:(Coji *)robot didReceiveSaveResourcesResponse:(int)status;
- (void)coji:(Coji *)robot didReceiveDeleteResourcesResponse:(int)status;
- (void)coji:(Coji *)robot didReceiveCreateDirectoryResponse:(int)status;
- (void)coji:(Coji *)robot didReceiveChangeDirectoryResponse:(int)status;
- (void)coji:(Coji *)robot didReceiveListResourcesResponse:(NSArray*)resourcesArray;
- (void)coji:(Coji *)robot didReceiveGetCurrectDirectoryResponse:(NSString*)pathString;
- (void)coji:(Coji *)robot didReceiveRenameFirmwareWithCorrectChecksum:(BOOL)isCorrectCheckSum :(int)errorCode;
- (void)coji:(Coji *)robot didReceiveResourceExist:(BOOL)isExist Size:(int)size;
- (void)coji:(Coji *)robot didReceiveFirmwareVersion:(NSString*)version;
- (void)coji:(Coji *)robot didReceiveSaveCommandsStatus:(BOOL)status;
- (void)coji:(Coji *)robot didReceiveConnectionStatus:(BOOL)status;
- (void)coji:(Coji *)robot didReceiveImageStatus:(int)status ImageID:(int)imageID;
- (void)coji:(Coji *)robot didReceiveSoundStatus:(int)status SoundID:(int)soundID;
@end
