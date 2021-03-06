WowWee COJI iOS SDK
================================

![](Images/COJI.png)

The free COJI iOS SDK lets you control your [WowWee COJI (http://wowwee.com/coji/) on devices running iOS 9.0 and above and Xcode 8. To use this SDK you will also need a physical COJI robot.

For information on WowWee products visit: <http://www.wowwee.com>

Table of Contents
---------------------------------------

- [Quick Installation](#quick-installation)
- [Using the SDK](#using-the-sdk)
	- [Scan and Connect COJI](#scan-and-connect-coji)
	- [Control COJI](#control-coji)
- [Notes about the SDK](#notes-about-the-sdk)
- [License](#license)
- [Contributing](#contributing)
- [Credits](#credits)
- [Projects using this SDK](#projects-using-this-sdk)

Quick Installation
---------------------------------

1. Clone the repository

		git clone https://github.com/WowWeeLabs/COJI-iOS-SDK.git

2. In XCode, create a new project. The simplest application is a Single-View application.

3. Open the project navigator in Xcode and drag the **WowWeeCOJISDK.framework** file from the Mac OS Finder to the Frameworks directory for your project in XCode.

![](Images/Project-Navigator-Example.png)

4. Confirm that the framework is added to your project by going into _Project Settings_ (first item in the project navigator), then click the first target (e.g. _cojisampleproject_), then _Build Phases_. If there is not a _"Copy Files"_ phase., click the top left + to add one. Set the destination to _"Frameworks"_ and add the framework file under the _"Name"_ section.

![](Images/Copy-Framework-Example.png)

Also make that the framework is present under the _"Link Binary With Libraries"_ section.
	
![](Images/Link-Frameworks-Example.png)

5. In the DeviceHub.h file, add the following line at the top of the file:

		#import <WowWeeCOJISDK/WowWeeCOJISDK.h>
	
Alternatively you can add this line into your Project-Prefix.pch (e.g. _COJI-Prefix.pch_) file so that you don't need to import in each class your planning to use the SDK in.
	
6. Check that the project compiles successfully after completing the above steps by pressing ⌘+b in Xcode to build the project. The project should build successfully.
			
7. You should be now ready to go! Plug in an iOS device then compile and run the project using ⌘+r . When you turn on a COJI you should see some debug messages in the logs.


Using the SDK
---------------------------------

7. Choose the classes you want to handle the delegate callbacks from a COJI Robot, these classes will receive callbacks for when events happen (such as finding a new robot, robot connected, robot falls over etc) in this case we will simply choose our DeviceHub class.

		Scan
			- (void)startScaning{
				[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onCojiFinderNotification:) name:CojiFinderNotificationID object:nil];
				[[COJIRobotFinderSDK sharedInstance] scanForRobots];
			}


			-(void)stopScaning{
				[[CojiRobotFinderSDK sharedInstance] stopScanForRobots];
				[[NSNotificationCenter defaultCenter] removeObserver:self name: CojiFinderNotificationID object:nil];
			}

		Connect directly when found available device via -(void)cojiFoundNotification:(NSNotification *)note
			- (void)onCojiFinderNotification: (NSNotification *)notification {
    				NSDictionary *info = notification.userInfo;
				    if(info){
				        NSNumber *code = [info objectForKey: @"code"];
				        //id data = [info objectForKey: @"data"];
				        if (code.intValue == CojiFinderNote_CojiFound){
						[peripheralList removeAllObjects];
            
				        NSMutableArray* arr = [[CojiFinder sharedInstance] robotsFound];
				        for (int i=0; i<[arr count]; i++) {
				                BluetoothRobot *robot = [arr objectAtIndex:i];
				                [peripheralList addObject:robot];
			                }
			                [self.tableView reloadData];
				    } else if (code.intValue == CojiFinderNote_CojiListCleared) {
				            [self.tableView reloadData];
				            [peripheralList removeAllObjects];
				    } else if (code.intValue == CojiFinderNote_BluetoothError) {
				            NSLog(@"Bluetooth error!");
				    } else if (code.intValue == CojiFinderNote_BluetoothIsOff) {
				            NSLog(@"Bluetooth is off!");
				    } else if (code.intValue == CojiFinderNote_BluetoothIsAvailable) {
					    NSLog(@“COJIFinderNote_BluetoothIsAvailable");
				    }
				}
			}

		Connect via devices array [[COJIRobotFinderSDK sharedInstance]devicesFound] 
			- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
			    Coji *robot = nil;
			    robot = [[[CojiFinder sharedInstance] robotsFound] objectAtIndex:indexPath.row];
			    robot.delegate = self;
			    [robot connect];
			    [viewLoading show];
			}
			
			
		Drive COJI
			[robot driveForwardWithSpeed:0.5f Time:0.16f];
                        [robot driveBackwardWithSpeed:0.5f Time:0.16f];
                        [robot turnLeftWithSpeed:1.0f Time:0.16f];
                        [robot turnRightWithSpeed:1.0f Time:0.16f];

		Play animation
			[robot playAnimationWithAnimationIndex:animationIndex EnableSound:YES]; // animationIndex = kCojiAnimationIndex_Character_001 - kCojiAnimationIndex_Vehicle_020 (Type: kCojiAnimationIndex)
		Stop animation
			[robot stopCommandWithType:kCojiStopTypeAnimation];
		Play sound
			[robot playSoundWithSoundIndex:soundIndex]; // soundIndex = kCojiSoundIndex_NA_Sfx_Pop - kCojiSoundIndex_forward_3 (Type: kCojiSoundIndex)
                Stop sound
			[robot stopCommandWithType:kCojiStopTypeSound];
		Show image
			[robot showImageWithImageIndex:imageIndex TemplateID:templateIndex]; // imageIndex = kCojiImageIndex_Character_1F408 - kCojiImageIndex_Vehicle_2708_B (Type: kCojiImageIndex) templateIndex = kCojiImage_AnimationTemplate_ScaleUp - kCojiImage_AnimationTemplate_None (Type: kCojiImage_AnimationTemplate)
                    
			    

Notes about the SDK
---------------------------------

### CocoaPods Compatible

For now we do not support CocoaPods. Pull requests are welcome.


### Apple Watch Support

At present we don't have an Apple Watch device to test with. When it becomes available we are open to adding support for WatchKit.

### Full Source Code

At this stage we do not plan on releasing our full library source code. 

### Are there any restrictions on releasing my own application?

The SDK is currently and will always be free for you to build and release your own applications. Your welcome to charge money or release free applications using our SDK without restrictions.

If you create a great application, all we ask is that you provide a link for people to purchase their own COJI so they can enjoy your product.

### OSX Support

Currently the SDK is not available for OSX however we will make this available if it's important to you. If that's the case please open up an issue in the bug tracker.
.
### Can I use your cool joystick class?

Yes we have provided the source code in our sample project, feel free to use this or make changes as you want. We would love pull requests.


License
---------------------------------
COJI iOS SDK is available under the Apache License, Version 2.0 license. See the [LICENSE.txt](https://raw.githubusercontent.com/WowWeeLabs/COJI-iOS-SDK/master/LICENSE.md) file for more info.

You are free to use our SDK in your own projects whether free or paid. There are no restrictions on releasing into the Apple App Store or Google Play.


Contributing
---------------------------------
We happily accept any pull requests and monitor issues on GitHub regularly. Please feel free to give us your suggestions or enhancements. Please note that due to resource constraints we most likely cannot add new features to the COJI robot himself, but we will certainly consider them for inclusion to future robots/versions.

Tell your friends, fork our project, buy our robot and share with us your own projects! These are the best kinds of positive feedback to us.

Credits
---------------------------------
* [YMSCoreBluetooth](https://github.com/kickingvegas/YmsCoreBluetooth.git) & [Our Fork](https://github.com/WowWeeLabs/YmsCoreBluetooth)
* [MSWeakTimer](https://github.com/mindsnacks/MSWeakTimer)
* [NSTimer-Blocks](https://github.com/jivadevoe/NSTimer-Blocks)
* [OWQueueStack](https://github.com/yangyubo/OWQueueStack)

Projects using this SDK
---------------------------------
* [WowWee COJI Official App](https://itunes.apple.com/hk/app/r.e.v.-robotic-enhanced-vehicles/id968261465?mt=8) - Official app developed by WowWee using this SDK.
* Send us a pull request to add your app here
