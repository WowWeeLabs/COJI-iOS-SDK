//
//  CojiCommandValues.h
//  BluetoothRobotControlLibrary
//
//  Created by David Chan on 3/4/17.
//  Copyright (c) 2017 WowWee Group Limited. All rights reserved.
//

@import Foundation;


FOUNDATION_EXPORT NSString *const COJI_BLUETOOTH_CUSTOM_DATA_IDENTIFIER;

typedef enum : uint8_t {
    kCojiAnimationIndex_Character_001,
    kCojiAnimationIndex_Character_002,
    kCojiAnimationIndex_Character_003,
    kCojiAnimationIndex_Character_004,
    kCojiAnimationIndex_Character_005,
    kCojiAnimationIndex_Character_006,
    kCojiAnimationIndex_Character_007,
    kCojiAnimationIndex_Character_008,
    kCojiAnimationIndex_Character_009,
    kCojiAnimationIndex_Character_010,
    kCojiAnimationIndex_Character_011,
    kCojiAnimationIndex_Character_012,
    kCojiAnimationIndex_Character_013,
    kCojiAnimationIndex_Character_014,
    kCojiAnimationIndex_Character_015,
    kCojiAnimationIndex_Character_016,
    kCojiAnimationIndex_Character_017,
    kCojiAnimationIndex_Character_018,
    kCojiAnimationIndex_Character_019,
    kCojiAnimationIndex_Character_020,
    kCojiAnimationIndex_Character_021,
    kCojiAnimationIndex_Character_022,
    kCojiAnimationIndex_Character_023,
    kCojiAnimationIndex_Character_024,
    kCojiAnimationIndex_Character_025,
    kCojiAnimationIndex_Character_026,
    kCojiAnimationIndex_Character_027,
    kCojiAnimationIndex_Character_028,
    kCojiAnimationIndex_Character_029,
    kCojiAnimationIndex_Character_030,
    
    kCojiAnimationIndex_Default_001,
    kCojiAnimationIndex_Default_002,
    kCojiAnimationIndex_Default_003,
    kCojiAnimationIndex_Default_004,
    kCojiAnimationIndex_Default_005,
    kCojiAnimationIndex_Default_007,
    kCojiAnimationIndex_Default_008,
    kCojiAnimationIndex_Default_010,
    kCojiAnimationIndex_Default_011,
    kCojiAnimationIndex_Default_012,
    kCojiAnimationIndex_Default_013,
    kCojiAnimationIndex_Default_014,
    kCojiAnimationIndex_Default_015,
    kCojiAnimationIndex_Default_016,
    kCojiAnimationIndex_Default_017,
    kCojiAnimationIndex_Default_018,
    kCojiAnimationIndex_Default_019,
    kCojiAnimationIndex_Default_020,
    kCojiAnimationIndex_Default_021,
    kCojiAnimationIndex_Default_022,
    kCojiAnimationIndex_Default_023,
    kCojiAnimationIndex_Default_024,
    kCojiAnimationIndex_Default_025,
    kCojiAnimationIndex_Default_026,
    kCojiAnimationIndex_Default_027,
    kCojiAnimationIndex_Default_028,
    kCojiAnimationIndex_Default_029,
    kCojiAnimationIndex_Default_030,
    
    kCojiAnimationIndex_Emoji_001,
    kCojiAnimationIndex_Emoji_002,
    kCojiAnimationIndex_Emoji_003,
    kCojiAnimationIndex_Emoji_004,
    kCojiAnimationIndex_Emoji_005,
    kCojiAnimationIndex_Emoji_006,
    kCojiAnimationIndex_Emoji_007,
    kCojiAnimationIndex_Emoji_008,
    kCojiAnimationIndex_Emoji_009,
    kCojiAnimationIndex_Emoji_010,
    kCojiAnimationIndex_Emoji_011,
    kCojiAnimationIndex_Emoji_012,
    kCojiAnimationIndex_Emoji_013,
    kCojiAnimationIndex_Emoji_014,
    kCojiAnimationIndex_Emoji_015,
    kCojiAnimationIndex_Emoji_016,
    kCojiAnimationIndex_Emoji_017,
    kCojiAnimationIndex_Emoji_018,
    kCojiAnimationIndex_Emoji_019,
    kCojiAnimationIndex_Emoji_020,
    kCojiAnimationIndex_Emoji_021,
    kCojiAnimationIndex_Emoji_022,
    kCojiAnimationIndex_Emoji_023,
    kCojiAnimationIndex_Emoji_024,
    kCojiAnimationIndex_Emoji_025,
    kCojiAnimationIndex_Emoji_026,
    kCojiAnimationIndex_Emoji_027,
    kCojiAnimationIndex_Emoji_028,
    kCojiAnimationIndex_Emoji_029,
    kCojiAnimationIndex_Emoji_030,
    
    kCojiAnimationIndex_Reward_001,
    kCojiAnimationIndex_Reward_002,
    kCojiAnimationIndex_Reward_003,
    kCojiAnimationIndex_Reward_004,
    kCojiAnimationIndex_Reward_005,
    kCojiAnimationIndex_Reward_006,
    kCojiAnimationIndex_Reward_007,
    kCojiAnimationIndex_Reward_008,
    kCojiAnimationIndex_Reward_009,
    kCojiAnimationIndex_Reward_010,
    kCojiAnimationIndex_Reward_011,
    kCojiAnimationIndex_Reward_012,
    kCojiAnimationIndex_Reward_013,
    kCojiAnimationIndex_Reward_014,
    kCojiAnimationIndex_Reward_015,
    kCojiAnimationIndex_Reward_016,
    kCojiAnimationIndex_Reward_017,
    kCojiAnimationIndex_Reward_018,
    kCojiAnimationIndex_Reward_019,
    kCojiAnimationIndex_Reward_020,
    kCojiAnimationIndex_Reward_021,
    kCojiAnimationIndex_Reward_022,
    kCojiAnimationIndex_Reward_023,
    kCojiAnimationIndex_Reward_024,
    kCojiAnimationIndex_Reward_025,
    kCojiAnimationIndex_Reward_026,
    kCojiAnimationIndex_Reward_027,
    kCojiAnimationIndex_Reward_028,
    kCojiAnimationIndex_Reward_029,
    kCojiAnimationIndex_Reward_030,
    kCojiAnimationIndex_Reward_031,
    kCojiAnimationIndex_Reward_032,
    kCojiAnimationIndex_Reward_033,
    kCojiAnimationIndex_Reward_034,
    
    kCojiAnimationIndex_Tool_001,
    kCojiAnimationIndex_Tool_002,
    kCojiAnimationIndex_Tool_003,
    kCojiAnimationIndex_Tool_004,
    kCojiAnimationIndex_Tool_005,
    kCojiAnimationIndex_Tool_006,
    kCojiAnimationIndex_Tool_007,
    kCojiAnimationIndex_Tool_008,
    kCojiAnimationIndex_Tool_009,
    kCojiAnimationIndex_Tool_010,
    kCojiAnimationIndex_Tool_011,
    kCojiAnimationIndex_Tool_012,
    kCojiAnimationIndex_Tool_013,
    kCojiAnimationIndex_Tool_014,
    kCojiAnimationIndex_Tool_015,
    kCojiAnimationIndex_Tool_016,
    kCojiAnimationIndex_Tool_017,
    kCojiAnimationIndex_Tool_018,
    kCojiAnimationIndex_Tool_019,
    kCojiAnimationIndex_Tool_020,
    
    kCojiAnimationIndex_Vehicle_001,
    kCojiAnimationIndex_Vehicle_002,
    kCojiAnimationIndex_Vehicle_003,
    kCojiAnimationIndex_Vehicle_004,
    kCojiAnimationIndex_Vehicle_005,
    kCojiAnimationIndex_Vehicle_006,
    kCojiAnimationIndex_Vehicle_007,
    kCojiAnimationIndex_Vehicle_008,
    kCojiAnimationIndex_Vehicle_009,
    kCojiAnimationIndex_Vehicle_010,
    kCojiAnimationIndex_Vehicle_011,
    kCojiAnimationIndex_Vehicle_012,
    kCojiAnimationIndex_Vehicle_013,
    kCojiAnimationIndex_Vehicle_014,
    kCojiAnimationIndex_Vehicle_015,
    kCojiAnimationIndex_Vehicle_016,
    kCojiAnimationIndex_Vehicle_017,
    kCojiAnimationIndex_Vehicle_018,
    kCojiAnimationIndex_Vehicle_019,
    kCojiAnimationIndex_Vehicle_020,
    
} kCojiAnimationIndex;

typedef enum : uint8_t {
    kCojiSoundIndex_NA_Sfx_Pop,
    kCojiSoundIndex_A_Sfx_Pop,
    kCojiSoundIndex_A_Sfx_Receive,
    kCojiSoundIndex_Emoji_Intro_Music,
    kCojiSoundIndex_Girl_Dance,
    kCojiSoundIndex_Volcano_Explode,
    kCojiSoundIndex_Lightbulb_ding,
    kCojiSoundIndex_Alien,
    kCojiSoundIndex_Attention,
    kCojiSoundIndex_Baby_Suck,
    kCojiSoundIndex_Bark,
    kCojiSoundIndex_BdayMusic_1,
    kCojiSoundIndex_Big_Pop,
    kCojiSoundIndex_Bomb,
    kCojiSoundIndex_Booo,
    kCojiSoundIndex_Bounce,
    kCojiSoundIndex_CarouselMusic,
    kCojiSoundIndex_Cartoon_Drip,
    kCojiSoundIndex_Cartoon_Drip_1,
    kCojiSoundIndex_Cha_ching,
    kCojiSoundIndex_Clang,
    kCojiSoundIndex_Click,
    kCojiSoundIndex_Coaster_Screams,
    kCojiSoundIndex_Coji_Annoyed,
    kCojiSoundIndex_Coji_Coji_1,
    kCojiSoundIndex_Coji_Coji_2,
    kCojiSoundIndex_Coji_Coji_3,
    kCojiSoundIndex_Coji_Crying,
    kkCojiSoundIndex_Coji_Hike,
    kCojiSoundIndex_Coji_Huh_,
    kCojiSoundIndex_Coji_Hungry_1,
    kCojiSoundIndex_Coji_Loop_1,
    kCojiSoundIndex_Coji_Macro,
    kCojiSoundIndex_Coji_Munch,
    kCojiSoundIndex_Coji_Ouch,
    kCojiSoundIndex_Coji_Sequence_1,
    kCojiSoundIndex_Coji_Serious,
    kCojiSoundIndex_Coji_Shy,
    kCojiSoundIndex_Coji_Sings,
    kCojiSoundIndex_Coji_Smirks,
    kCojiSoundIndex_Coji_Smooch,
    kCojiSoundIndex_Coji_Surprised_1,
    kCojiSoundIndex_Coji_Yum,
    kCojiSoundIndex_CoolMusic,
    kCojiSoundIndex_Crank,
    kCojiSoundIndex_Detective,
    kCojiSoundIndex_Devil_Sneers,
    kCojiSoundIndex_Dragon,
    kCojiSoundIndex_Dragon_Roar,
    kCojiSoundIndex_ElectricZap,
    kCojiSoundIndex_Fire,
    kCojiSoundIndex_Flap_Wings,
    kCojiSoundIndex_Flush,
    kCojiSoundIndex_Foghorn,
    kCojiSoundIndex_Generic_Car_Motor,
    kCojiSoundIndex_Glug,
    kCojiSoundIndex_GuitarRiff,
    kCojiSoundIndex_HammerKnock,
    kCojiSoundIndex_Hockey,
    kCojiSoundIndex_Jet_Flying,
    kCojiSoundIndex_Lightning,
    kCojiSoundIndex_LowBattery,
    kCojiSoundIndex_Meow,
    kCojiSoundIndex_Motor_Rev,
    kCojiSoundIndex_Octopus,
    kCojiSoundIndex_Panting,
    kCojiSoundIndex_PartyHorn,
    kCojiSoundIndex_Propeller_Spins,
    kCojiSoundIndex_Pump,
    kCojiSoundIndex_Rain,
    kCojiSoundIndex_Rattle,
    kCojiSoundIndex_Reel,
    kCojiSoundIndex_RegalTune,
    kCojiSoundIndex_Ring,
    kCojiSoundIndex_Roar,
    kCojiSoundIndex_Rooster_Crows,
    kCojiSoundIndex_Sax,
    kCojiSoundIndex_SchoolBell,
    kCojiSoundIndex_Slip,
    kCojiSoundIndex_Slots,
    kCojiSoundIndex_Slurpy_Lick,
    kCojiSoundIndex_Sparkle,
    kCojiSoundIndex_Splat,
    kCojiSoundIndex_Swoosh,
    kCojiSoundIndex_TechoBeat,
    kCojiSoundIndex_Tick,
    kCojiSoundIndex_Train_Chug,
    kCojiSoundIndex_Triumphant,
    kCojiSoundIndex_Trumpet,
    kCojiSoundIndex_Tweet,
    kCojiSoundIndex_Unlock,
    kCojiSoundIndex_Whoa_2,
    kCojiSoundIndex_Wink,
    kCojiSoundIndex_Yawn,
    kCojiSoundIndex_Zip,
    kCojiSoundIndex_crack,
    kCojiSoundIndex_police_whistle,
    kCojiSoundIndex_Alien_Tune,
    kCojiSoundIndex_Angles_Sing,
    kCojiSoundIndex_Baby,
    kCojiSoundIndex_Backward_3,
    kCojiSoundIndex_Beep,
    kCojiSoundIndex_Blink,
    kCojiSoundIndex_Boing_1,
    kCojiSoundIndex_Bomb_NA,
    kCojiSoundIndex_Coji_Awe_Cute,
    kCojiSoundIndex_Coji_Burp,
    kCojiSoundIndex_Coji_Comic_Scream,
    kCojiSoundIndex_Coji_No_Like,
    kCojiSoundIndex_Coji_Sneeze,
    kCojiSoundIndex_Coji_Sniff_2Xs,
    kCojiSoundIndex_Coji_blahhh,
    kCojiSoundIndex_Dizzy,
    kCojiSoundIndex_Dog,
    kCojiSoundIndex_Excite,
    kCojiSoundIndex_Fireworks,
    kCojiSoundIndex_Fly_Buzz,
    kCojiSoundIndex_Frog,
    kCojiSoundIndex_Giggle,
    kCojiSoundIndex_Grumpy_3,
    kCojiSoundIndex_Head_Button_3,
    kCojiSoundIndex_Humph,
    kCojiSoundIndex_Laugh_3,
    kCojiSoundIndex_Meow_NA,
    kCojiSoundIndex_Meow_Scratch,
    kCojiSoundIndex_Monkey_Sounds,
    kCojiSoundIndex_Munch,
    kCojiSoundIndex_Music_Note,
    kCojiSoundIndex_Oink_Snort,
    kCojiSoundIndex_Pleading,
    kCojiSoundIndex_Plop,
    kCojiSoundIndex_Power_Boat,
    kCojiSoundIndex_Power_up,
    kCojiSoundIndex_Rocket_Blast_Off,
    kCojiSoundIndex_Scratch,
    kCojiSoundIndex_Side_Button_2,
    kCojiSoundIndex_Siren,
    kCojiSoundIndex_Slime,
    kCojiSoundIndex_Snore,
    kCojiSoundIndex_Snore_3,
    kCojiSoundIndex_Sparkle_NA,
    kCojiSoundIndex_Spin_3,
    kCojiSoundIndex_Splash,
    kCojiSoundIndex_Spray,
    kCojiSoundIndex_Tiptoe,
    kCojiSoundIndex_Turn,
    kCojiSoundIndex_Waiting_Whistle_2,
    kCojiSoundIndex_Wave,
    kCojiSoundIndex_Wee_3,
    kCojiSoundIndex_Whoa_3,
    kCojiSoundIndex_Wind_Gust,
    kCojiSoundIndex_Woohoo,
    kCojiSoundIndex_WowWee,
    kCojiSoundIndex_Yippe,
    kCojiSoundIndex_forward_3,
} kCojiSoundIndex;

typedef enum : int {
    kCojiImageIndex_Character_1F408,
    kCojiImageIndex_Character_1F408_B,
    kCojiImageIndex_Character_1F408_C,
    kCojiImageIndex_Character_1F408_D,
    kCojiImageIndex_Character_1F408_E,
    kCojiImageIndex_Character_1F408_F,
    kCojiImageIndex_Character_1F408_G,
    kCojiImageIndex_Character_1F418,
    kCojiImageIndex_Character_1F418_B,
    kCojiImageIndex_Character_1F418_C,
    kCojiImageIndex_Character_1F419,
    kCojiImageIndex_Character_1F419_B,
    kCojiImageIndex_Character_1F427,
    kCojiImageIndex_Character_1F427_B,
    kCojiImageIndex_Character_1F42D,
    kCojiImageIndex_Character_1F42D_B,
    kCojiImageIndex_Character_1F42D_C,
    kCojiImageIndex_Character_1F42D_D,
    kCojiImageIndex_Character_1F432,
    kCojiImageIndex_Character_1F432_B,
    kCojiImageIndex_Character_1F432_C,
    kCojiImageIndex_Character_1F432_D,
    kCojiImageIndex_Character_1F432_E,
    kCojiImageIndex_Character_1F432_F,
    kCojiImageIndex_Character_1F432_G,
    kCojiImageIndex_Character_1F433,
    kCojiImageIndex_Character_1F433_B,
    kCojiImageIndex_Character_1F433_C,
    kCojiImageIndex_Character_1F433_D,
    kCojiImageIndex_Character_1F433_E,
    kCojiImageIndex_Character_1F433_F,
    kCojiImageIndex_Character_1F433_G,
    kCojiImageIndex_Character_1F433_H,
    kCojiImageIndex_Character_1F435,
    kCojiImageIndex_Character_1F435_B,
    kCojiImageIndex_Character_1F435_C,
    kCojiImageIndex_Character_1F435_D,
    kCojiImageIndex_Character_1F436,
    kCojiImageIndex_Character_1F436_B,
    kCojiImageIndex_Character_1F436_C,
    kCojiImageIndex_Character_1F436_D,
    kCojiImageIndex_Character_1F437,
    kCojiImageIndex_Character_1F437_B,
    kCojiImageIndex_Character_1F437_C,
    kCojiImageIndex_Character_1F438,
    kCojiImageIndex_Character_1F438_B,
    kCojiImageIndex_Character_1F438_C,
    kCojiImageIndex_Character_1F438_D,
    kCojiImageIndex_Character_1F438_E,
    kCojiImageIndex_Character_1F438_F,
    kCojiImageIndex_Character_1F438_G,
    kCojiImageIndex_Character_1F438_H,
    kCojiImageIndex_Character_1F438_I,
    kCojiImageIndex_Character_1F438_J,
    kCojiImageIndex_Character_1F46e,
    kCojiImageIndex_Character_1F476,
    kCojiImageIndex_Character_1F476_B,
    kCojiImageIndex_Character_1F476_C,
    kCojiImageIndex_Character_1F476_D,
    kCojiImageIndex_Character_1F476_E,
    kCojiImageIndex_Character_1F476_F,
    kCojiImageIndex_Character_1F476_G,
    kCojiImageIndex_Character_1F476_H,
    kCojiImageIndex_Character_1F478,
    kCojiImageIndex_Character_1F478_B,
    kCojiImageIndex_Character_1F47b,
    kCojiImageIndex_Character_1F47b_B,
    kCojiImageIndex_Character_1F47d,
    kCojiImageIndex_Character_1F47d_B,
    kCojiImageIndex_Character_1F47d_C,
    kCojiImageIndex_Character_1F483,
    kCojiImageIndex_Character_1F483_B,
    kCojiImageIndex_Character_1F483_C,
    kCojiImageIndex_Character_1F483_D,
    kCojiImageIndex_Character_1F483_E,
    kCojiImageIndex_Character_1F483_F,
    kCojiImageIndex_Character_1F981,
    kCojiImageIndex_Character_1F981_B,
    kCojiImageIndex_Character_1F981_C,
    kCojiImageIndex_Character_1F981_D,
    kCojiImageIndex_Character_1F981_E,
    kCojiImageIndex_Character_1F984,
    kCojiImageIndex_Character_1F984_B,
    kCojiImageIndex_Character_1f40c,
    kCojiImageIndex_Character_1f411,
    kCojiImageIndex_Character_1f411_B,
    kCojiImageIndex_Character_1f413,
    kCojiImageIndex_Character_1f413_B,
    kCojiImageIndex_Character_1f413_C,
    kCojiImageIndex_Character_1f413_D,
    kCojiImageIndex_Character_1f426,
    kCojiImageIndex_Character_1f426_B,
    kCojiImageIndex_Character_1f429,
    kCojiImageIndex_Character_1f429_B,
    kCojiImageIndex_Character_1f42c,
    kCojiImageIndex_Character_1f42c_B,
    kCojiImageIndex_Character_1f42c_C,
    kCojiImageIndex_Character_1f42c_D,
    kCojiImageIndex_Character_1f42c_E,
    kCojiImageIndex_Character_1f42c_F,
    kCojiImageIndex_Character_1f42c_G,
    kCojiImageIndex_Character_1f47e,
    kCojiImageIndex_Character_1f47e_B,
    kCojiImageIndex_Character_1f575,
    kCojiImageIndex_Character_1f577,
    kCojiImageIndex_Character_1f577_B,
    kCojiImageIndex_Character_1f63b,
    kCojiImageIndex_Character_1f63b_B,
    kCojiImageIndex_Character_1f916,
    kCojiImageIndex_Character_1f916_B,
    kCojiImageIndex_Character_1f916_C,
    kCojiImageIndex_Character_1f916_D,
    kCojiImageIndex_Character_1f916_E,
    kCojiImageIndex_Character_Blank,
    kCojiImageIndex_Default_1F337,
    kCojiImageIndex_Default_1F337_D,
    kCojiImageIndex_Default_1F337_G,
    kCojiImageIndex_Default_1F337_H,
    kCojiImageIndex_Default_1F337_J,
    kCojiImageIndex_Default_1F337_K,
    kCojiImageIndex_Default_1F3B6,
    kCojiImageIndex_Default_1F3B6_B,
    kCojiImageIndex_Default_1F4a3,
    kCojiImageIndex_Default_1F4a3_B,
    kCojiImageIndex_Default_1F4a3_C,
    kCojiImageIndex_Default_1F4a3_D,
    kCojiImageIndex_Default_1F4a3_E,
    kCojiImageIndex_Default_1F4a3_F,
    kCojiImageIndex_Default_1F4a3_G,
    kCojiImageIndex_Default_1F4a3_H,
    kCojiImageIndex_Default_1F4a3_I,
    kCojiImageIndex_Default_1F4a3_J,
    kCojiImageIndex_Default_1F4a3_K,
    kCojiImageIndex_Default_1F4a9,
    kCojiImageIndex_Default_1F4a9_B,
    kCojiImageIndex_Default_1F4a9_C,
    kCojiImageIndex_Default_1F4a9_D,
    kCojiImageIndex_Default_1F4a9_E,
    kCojiImageIndex_Default_1F4a9_F,
    kCojiImageIndex_Default_1F4a9_G,
    kCojiImageIndex_Default_1F504_A,
    kCojiImageIndex_Default_1F504_B,
    kCojiImageIndex_Default_1F504_C,
    kCojiImageIndex_Default_1F504_D,
    kCojiImageIndex_Default_1F61A,
    kCojiImageIndex_Default_1F61A_B,
    kCojiImageIndex_Default_1F61A_C,
    kCojiImageIndex_Default_1F61A_DD,
    kCojiImageIndex_Default_1F61A_EE,
    kCojiImageIndex_Default_1F61A_F,
    kCojiImageIndex_Default_1F61A_G,
    kCojiImageIndex_Default_1F61A_H,
    kCojiImageIndex_Default_1F61A_I,
    kCojiImageIndex_Default_1F61A_J,
    kCojiImageIndex_Default_1f32e,
    kCojiImageIndex_Default_1f32e_B,
    kCojiImageIndex_Default_1f32e_C,
    kCojiImageIndex_Default_1f32e_D,
    kCojiImageIndex_Default_1f32e_E,
    kCojiImageIndex_Default_1f32e_F,
    kCojiImageIndex_Default_1f386,
    kCojiImageIndex_Default_1f386_B,
    kCojiImageIndex_Default_1f386_C,
    kCojiImageIndex_Default_1f386_D,
    kCojiImageIndex_Default_1f386_E,
    kCojiImageIndex_Default_1f386_F,
    kCojiImageIndex_Default_1f386_G,
    kCojiImageIndex_Default_1f386_H,
    kCojiImageIndex_Default_1f44c_1f3fd,
    kCojiImageIndex_Default_1f44c_1f3fd_B,
    kCojiImageIndex_Default_1f44d_1f3fd,
    kCojiImageIndex_Default_1f44d_1f3fd_B,
    kCojiImageIndex_Default_1f44e_1f3fd,
    kCojiImageIndex_Default_1f44e_1f3fd_B,
    kCojiImageIndex_Default_1f49c,
    kCojiImageIndex_Default_1f49c_A,
    kCojiImageIndex_Default_1f603,
    kCojiImageIndex_Default_1f603_B,
    kCojiImageIndex_Default_1f603_C,
    kCojiImageIndex_Default_1f607,
    kCojiImageIndex_Default_1f607_B,
    kCojiImageIndex_Default_1f607_C,
    kCojiImageIndex_Default_1f607_D,
    kCojiImageIndex_Default_1f607_E,
    kCojiImageIndex_Default_1f608,
    kCojiImageIndex_Default_1f608_B,
    kCojiImageIndex_Default_1f608_C,
    kCojiImageIndex_Default_1f608_D,
    kCojiImageIndex_Default_1f60a,
    kCojiImageIndex_Default_1f60a_B,
    kCojiImageIndex_Default_1f60f,
    kCojiImageIndex_Default_1f60f_B,
    kCojiImageIndex_Default_1f61b,
    kCojiImageIndex_Default_1f61b_B,
    kCojiImageIndex_Default_1f61b_C,
    kCojiImageIndex_Default_1f620,
    kCojiImageIndex_Default_1f620_B,
    kCojiImageIndex_Default_1f620_C,
    kCojiImageIndex_Default_1f622,
    kCojiImageIndex_Default_1f622_B,
    kCojiImageIndex_Default_1f622_C,
    kCojiImageIndex_Default_1f622_D,
    kCojiImageIndex_Default_1f622_E,
    kCojiImageIndex_Default_1f622_F,
    kCojiImageIndex_Default_1f622_G,
    kCojiImageIndex_Default_1f622_H,
    kCojiImageIndex_Default_1f622_I,
    kCojiImageIndex_Default_1f622_J,
    kCojiImageIndex_Default_1f622_K,
    kCojiImageIndex_Default_1f631,
    kCojiImageIndex_Default_1f631_B,
    kCojiImageIndex_Default_1f631_C,
    kCojiImageIndex_Default_1f631_D,
    kCojiImageIndex_Default_1f631_E,
    kCojiImageIndex_Default_1f631_F,
    kCojiImageIndex_Default_1f631_G,
    kCojiImageIndex_Default_1f631_H,
    kCojiImageIndex_Default_1f634,
    kCojiImageIndex_Default_1f634_B,
    kCojiImageIndex_Default_1f634_C,
    kCojiImageIndex_Default_1f634_D,
    kCojiImageIndex_Default_1f634_E,
    kCojiImageIndex_Default_1f634_F,
    kCojiImageIndex_Default_1f634_G,
    kCojiImageIndex_Default_1f634_H,
    kCojiImageIndex_Default_1f635,
    kCojiImageIndex_Default_1f635_B,
    kCojiImageIndex_Default_1f635_C,
    kCojiImageIndex_Default_1f635_D,
    kCojiImageIndex_Default_1f635_E,
    kCojiImageIndex_Default_1f635_F,
    kCojiImageIndex_Default_1f635_G,
    kCojiImageIndex_Default_1f635_H,
    kCojiImageIndex_Default_2196,
    kCojiImageIndex_Default_2196_B,
    kCojiImageIndex_Default_2196_C,
    kCojiImageIndex_Default_2196_D,
    kCojiImageIndex_Default_2196_E,
    kCojiImageIndex_Default_2197,
    kCojiImageIndex_Default_2197_B,
    kCojiImageIndex_Default_2197_C,
    kCojiImageIndex_Default_2197_D,
    kCojiImageIndex_Default_2197_E,
    kCojiImageIndex_Default_2934,
    kCojiImageIndex_Default_2934_B,
    kCojiImageIndex_Default_2934_C,
    kCojiImageIndex_Default_2934_D,
    kCojiImageIndex_Default_2934_E,
    kCojiImageIndex_Default_2935,
    kCojiImageIndex_Default_2935_B,
    kCojiImageIndex_Default_2935_C,
    kCojiImageIndex_Default_2935_D,
    kCojiImageIndex_Default_2935_E,
    kCojiImageIndex_Default_2B06,
    kCojiImageIndex_Default_2B06_B,
    kCojiImageIndex_Default_2B06_C,
    kCojiImageIndex_Default_2B06_D,
    kCojiImageIndex_Default_2B06_E,
    kCojiImageIndex_Default_2B07,
    kCojiImageIndex_Default_2B07_B,
    kCojiImageIndex_Default_2B07_C,
    kCojiImageIndex_Default_2B07_D,
    kCojiImageIndex_Default_2B07_E,
    kCojiImageIndex_Default_3030,
    kCojiImageIndex_Default_3030_B,
    kCojiImageIndex_Default_3030_C,
    kCojiImageIndex_Default_3030_D,
    kCojiImageIndex_Default_3030_E,
    kCojiImageIndex_Default_Blank_Gery,
    kCojiImageIndex_Eyes_Eyes_1,
    kCojiImageIndex_Eyes_Eyes_2,
    kCojiImageIndex_Eyes_Eyes_3,
    kCojiImageIndex_Eyes_Eyes_DownA,
    kCojiImageIndex_Eyes_Eyes_DownB,
    kCojiImageIndex_Eyes_Eyes_DownC,
    kCojiImageIndex_Eyes_Eyes_DownD,
    kCojiImageIndex_Eyes_Eyes_IpB,
    kCojiImageIndex_Eyes_Eyes_LeftA,
    kCojiImageIndex_Eyes_Eyes_LeftB,
    kCojiImageIndex_Eyes_Eyes_LeftC,
    kCojiImageIndex_Eyes_Eyes_PleadA,
    kCojiImageIndex_Eyes_Eyes_PleadB,
    kCojiImageIndex_Eyes_Eyes_PleadC,
    kCojiImageIndex_Eyes_Eyes_PleadD,
    kCojiImageIndex_Eyes_Eyes_PleadE,
    kCojiImageIndex_Eyes_Eyes_PleadF,
    kCojiImageIndex_Eyes_Eyes_PleadG,
    kCojiImageIndex_Eyes_Eyes_PleadH,
    kCojiImageIndex_Eyes_Eyes_PleadI,
    kCojiImageIndex_Eyes_Eyes_PleadJ,
    kCojiImageIndex_Eyes_Eyes_RightA,
    kCojiImageIndex_Eyes_Eyes_RightB,
    kCojiImageIndex_Eyes_Eyes_RightC,
    kCojiImageIndex_Eyes_Eyes_ShyA,
    kCojiImageIndex_Eyes_Eyes_ShyB,
    kCojiImageIndex_Eyes_Eyes_ShyC,
    kCojiImageIndex_Eyes_Eyes_ShyD,
    kCojiImageIndex_Eyes_Eyes_ShyE,
    kCojiImageIndex_Eyes_Eyes_ShyF,
    kCojiImageIndex_Eyes_Eyes_ShyG,
    kCojiImageIndex_Eyes_Eyes_ShyH,
    kCojiImageIndex_Eyes_Eyes_UpA,
    kCojiImageIndex_Eyes_Eyes_UpB,
    kCojiImageIndex_Eyes_Eyes_UpC,
    kCojiImageIndex_Eyes_Eyes_UpD,
    kCojiImageIndex_Eyes_Eyes_UpE,
    kCojiImageIndex_Eyes_Eyes_Wink,
    kCojiImageIndex_Eyes_Eyes_WinkB,
    kCojiImageIndex_Eyes_Eyes_angryA,
    kCojiImageIndex_Eyes_Eyes_angryB,
    kCojiImageIndex_Eyes_Eyes_boredA,
    kCojiImageIndex_Eyes_Eyes_boredB,
    kCojiImageIndex_Eyes_Eyes_boredC,
    kCojiImageIndex_Eyes_Eyes_boredD,
    kCojiImageIndex_Eyes_Eyes_boredE,
    kCojiImageIndex_Eyes_Eyes_boredF,
    kCojiImageIndex_Eyes_Eyes_cheekyA,
    kCojiImageIndex_Eyes_Eyes_cheekyB,
    kCojiImageIndex_Eyes_Eyes_cheekyC,
    kCojiImageIndex_Eyes_Eyes_confusedA,
    kCojiImageIndex_Eyes_Eyes_confusedB,
    kCojiImageIndex_Eyes_Eyes_confusedC,
    kCojiImageIndex_Eyes_Eyes_confusedD,
    kCojiImageIndex_Eyes_Eyes_confusedE,
    kCojiImageIndex_Eyes_Eyes_confusedF,
    kCojiImageIndex_Eyes_Eyes_dizzyA,
    kCojiImageIndex_Eyes_Eyes_dizzyB,
    kCojiImageIndex_Eyes_Eyes_dizzyC,
    kCojiImageIndex_Eyes_Eyes_dizzyD,
    kCojiImageIndex_Eyes_Eyes_dizzyE,
    kCojiImageIndex_Eyes_Eyes_dizzyF,
    kCojiImageIndex_Eyes_Eyes_dizzyG,
    kCojiImageIndex_Eyes_Eyes_dizzyH,
    kCojiImageIndex_Eyes_Eyes_dizzyI,
    kCojiImageIndex_Eyes_Eyes_exciteA,
    kCojiImageIndex_Eyes_Eyes_exciteB,
    kCojiImageIndex_Eyes_Eyes_exciteC,
    kCojiImageIndex_Eyes_Eyes_exciteD,
    kCojiImageIndex_Eyes_Eyes_grumpyA,
    kCojiImageIndex_Eyes_Eyes_grumpyB,
    kCojiImageIndex_Eyes_Eyes_sadA,
    kCojiImageIndex_Eyes_Eyes_sadB,
    kCojiImageIndex_Eyes_Eyes_sadC,
    kCojiImageIndex_Eyes_Eyes_sadcryA,
    kCojiImageIndex_Eyes_Eyes_sadcryB,
    kCojiImageIndex_Eyes_Eyes_sadcryC,
    kCojiImageIndex_Eyes_Eyes_sadcryD,
    kCojiImageIndex_Eyes_Eyes_sadcryE,
    kCojiImageIndex_Eyes_Eyes_sadcryF,
    kCojiImageIndex_Eyes_Eyes_sadcryG,
    kCojiImageIndex_Eyes_Eyes_sadcryH,
    kCojiImageIndex_Eyes_Eyes_sadcryI,
    kCojiImageIndex_Eyes_Eyes_sadcryJ,
    kCojiImageIndex_Eyes_Eyes_sadcryK,
    kCojiImageIndex_Eyes_Eyes_sadcryL,
    kCojiImageIndex_Eyes_Eyes_seriousA,
    kCojiImageIndex_Eyes_Eyes_seriousB,
    kCojiImageIndex_Eyes_Eyes_sleepA,
    kCojiImageIndex_Eyes_Eyes_sleepB,
    kCojiImageIndex_Eyes_Eyes_sleepC,
    kCojiImageIndex_Eyes_Eyes_surprisedA,
    kCojiImageIndex_Eyes_Eyes_surprisedB,
    kCojiImageIndex_Eyes_Eyes_tiredA,
    kCojiImageIndex_Eyes_Eyes_tiredB,
    kCojiImageIndex_Eyes_Eyes_tiredC,
    kCojiImageIndex_Eyes_Eyes_tiredD,
    kCojiImageIndex_Eyes_Eyes_tiredE,
    kCojiImageIndex_Reward_1f327,
    kCojiImageIndex_Reward_1f327_B,
    kCojiImageIndex_Reward_1f328,
    kCojiImageIndex_Reward_1f328_B,
    kCojiImageIndex_Reward_1f328_C,
    kCojiImageIndex_Reward_1f342,
    kCojiImageIndex_Reward_1f342_B,
    kCojiImageIndex_Reward_1f342_C,
    kCojiImageIndex_Reward_1f355,
    kCojiImageIndex_Reward_1f355_B,
    kCojiImageIndex_Reward_1f355_C,
    kCojiImageIndex_Reward_1f355_D,
    kCojiImageIndex_Reward_1f355_E,
    kCojiImageIndex_Reward_1f355_F,
    kCojiImageIndex_Reward_1f355_G,
    kCojiImageIndex_Reward_1f367,
    kCojiImageIndex_Reward_1f367_B,
    kCojiImageIndex_Reward_1f367_C,
    kCojiImageIndex_Reward_1f367_D,
    kCojiImageIndex_Reward_1f367_E,
    kCojiImageIndex_Reward_1f367_F,
    kCojiImageIndex_Reward_1f381,
    kCojiImageIndex_Reward_1f383,
    kCojiImageIndex_Reward_1f383_B,
    kCojiImageIndex_Reward_1f387_,
    kCojiImageIndex_Reward_1f387_B,
    kCojiImageIndex_Reward_1f387_C,
    kCojiImageIndex_Reward_1f387_D,
    kCojiImageIndex_Reward_1f387_E,
    kCojiImageIndex_Reward_1f387_F,
    kCojiImageIndex_Reward_1f387_G,
    kCojiImageIndex_Reward_1f3a0,
    kCojiImageIndex_Reward_1f3a7,
    kCojiImageIndex_Reward_1f3b0,
    kCojiImageIndex_Reward_1f3b0_B,
    kCojiImageIndex_Reward_1f3b0_C,
    kCojiImageIndex_Reward_1f3b0_D,
    kCojiImageIndex_Reward_1f3b0_E,
    kCojiImageIndex_Reward_1f3b0_F,
    kCojiImageIndex_Reward_1f3b0_G,
    kCojiImageIndex_Reward_1f3c2,
    kCojiImageIndex_Reward_1f3c2_B,
    kCojiImageIndex_Reward_1f3c2_C,
    kCojiImageIndex_Reward_1f3c2_D,
    kCojiImageIndex_Reward_1f3c2_E,
    kCojiImageIndex_Reward_1f3c2_F,
    kCojiImageIndex_Reward_1f3c4,
    kCojiImageIndex_Reward_1f3c4_B,
    kCojiImageIndex_Reward_1f3c5,
    kCojiImageIndex_Reward_1f3c6,
    kCojiImageIndex_Reward_1f3c6_B,
    kCojiImageIndex_Reward_1f3c8,
    kCojiImageIndex_Reward_1f3c8_B,
    kCojiImageIndex_Reward_1f3c8_C,
    kCojiImageIndex_Reward_1f3d2,
    kCojiImageIndex_Reward_1f3d2_B,
    kCojiImageIndex_Reward_1f3d2_C,
    kCojiImageIndex_Reward_1f3d2_D,
    kCojiImageIndex_Reward_1f3d2_E,
    kCojiImageIndex_Reward_1f3d2_F,
    kCojiImageIndex_Reward_1f3d2_G,
    kCojiImageIndex_Reward_1f3d5,
    kCojiImageIndex_Reward_1f3d6,
    kCojiImageIndex_Reward_1f3eb,
    kCojiImageIndex_Reward_1f3eb_B,
    kCojiImageIndex_Reward_1f3eb_C,
    kCojiImageIndex_Reward_1f3f0,
    kCojiImageIndex_Reward_1f3f0_B,
    kCojiImageIndex_Reward_1f407,
    kCojiImageIndex_Reward_1f407_B,
    kCojiImageIndex_Reward_1f407_C,
    kCojiImageIndex_Reward_1f41d,
    kCojiImageIndex_Reward_1f41d_B,
    kCojiImageIndex_Reward_1f423,
    kCojiImageIndex_Reward_1f423_B,
    kCojiImageIndex_Reward_1f423_C,
    kCojiImageIndex_Reward_1f423_D,
    kCojiImageIndex_Reward_1f423_E,
    kCojiImageIndex_Reward_1f441,
    kCojiImageIndex_Reward_1f441_B,
    kCojiImageIndex_Reward_1f441_C,
    kCojiImageIndex_Reward_1f441_D,
    kCojiImageIndex_Reward_1f451,
    kCojiImageIndex_Reward_1f496,
    kCojiImageIndex_Reward_1f496_B,
    kCojiImageIndex_Reward_1f4a5,
    kCojiImageIndex_Reward_1f4a5_B,
    kCojiImageIndex_Reward_1f4a5_C,
    kCojiImageIndex_Reward_1f4a5_D,
    kCojiImageIndex_Reward_1f4a5_E,
    kCojiImageIndex_Reward_1f4a5_F,
    kCojiImageIndex_Reward_1f4ab,
    kCojiImageIndex_Reward_1f4ab_B,
    kCojiImageIndex_Reward_1f4ab_C,
    kCojiImageIndex_Reward_1f4ab_D,
    kCojiImageIndex_Reward_1f4ab_E,
    kCojiImageIndex_Reward_1f4ab_F,
    kCojiImageIndex_Reward_1f4cc,
    kCojiImageIndex_Reward_1f60d,
    kCojiImageIndex_Reward_1f60d_B,
    kCojiImageIndex_Reward_1f68c,
    kCojiImageIndex_Reward_1f68d,
    kCojiImageIndex_Reward_1f910,
    kCojiImageIndex_Reward_1f910E,
    kCojiImageIndex_Reward_1f910_B,
    kCojiImageIndex_Reward_1f910_C,
    kCojiImageIndex_Reward_1f910_D,
    kCojiImageIndex_Reward_1f910_G,
    kCojiImageIndex_Reward_2603,
    kCojiImageIndex_Reward_2603_B,
    kCojiImageIndex_Reward_262e,
    kCojiImageIndex_Reward_26a1,
    kCojiImageIndex_Reward_26a1_B,
    kCojiImageIndex_Reward_26a1_C,
    kCojiImageIndex_Tool_1F354,
    kCojiImageIndex_Tool_1F354_B,
    kCojiImageIndex_Tool_1F354_C,
    kCojiImageIndex_Tool_1F354_D,
    kCojiImageIndex_Tool_1F354_E,
    kCojiImageIndex_Tool_1F354_F,
    kCojiImageIndex_Tool_1F354_G,
    kCojiImageIndex_Tool_1F354_H,
    kCojiImageIndex_Tool_1F354_I,
    kCojiImageIndex_Tool_1F354_J,
    kCojiImageIndex_Tool_1F354_K,
    kCojiImageIndex_Tool_1F4a1,
    kCojiImageIndex_Tool_1F4a1_B,
    kCojiImageIndex_Tool_1F4a1_C,
    kCojiImageIndex_Tool_1F4a1_D,
    kCojiImageIndex_Tool_1F4a1_E,
    kCojiImageIndex_Tool_1F4a1_F,
    kCojiImageIndex_Tool_1f308,
    kCojiImageIndex_Tool_1f308_B,
    kCojiImageIndex_Tool_1f308_C,
    kCojiImageIndex_Tool_1f308_D,
    kCojiImageIndex_Tool_1f308_E,
    kCojiImageIndex_Tool_1f308_G,
    kCojiImageIndex_Tool_1f308_H,
    kCojiImageIndex_Tool_1f30b,
    kCojiImageIndex_Tool_1f30b_B,
    kCojiImageIndex_Tool_1f30b_C,
    kCojiImageIndex_Tool_1f30b_D,
    kCojiImageIndex_Tool_1f30b_E,
    kCojiImageIndex_Tool_1f30b_F,
    kCojiImageIndex_Tool_1f30b_G,
    kCojiImageIndex_Tool_1f30b_H,
    kCojiImageIndex_Tool_1f32a,
    kCojiImageIndex_Tool_1f32a_B,
    kCojiImageIndex_Tool_1f32d,
    kCojiImageIndex_Tool_1f32d_B,
    kCojiImageIndex_Tool_1f32d_C,
    kCojiImageIndex_Tool_1f32d_D,
    kCojiImageIndex_Tool_1f32d_E,
    kCojiImageIndex_Tool_1f34c,
    kCojiImageIndex_Tool_1f34c_B,
    kCojiImageIndex_Tool_1f34c_C,
    kCojiImageIndex_Tool_1f34c_D,
    kCojiImageIndex_Tool_1f366,
    kCojiImageIndex_Tool_1f366_B,
    kCojiImageIndex_Tool_1f366_C,
    kCojiImageIndex_Tool_1f366_D,
    kCojiImageIndex_Tool_1f366_E,
    kCojiImageIndex_Tool_1f366_F,
    kCojiImageIndex_Tool_1f37c,
    kCojiImageIndex_Tool_1f37c_B,
    kCojiImageIndex_Tool_1f37c_C,
    kCojiImageIndex_Tool_1f37c_D,
    kCojiImageIndex_Tool_1f37c_E,
    kCojiImageIndex_Tool_1f37c_F,
    kCojiImageIndex_Tool_1f382,
    kCojiImageIndex_Tool_1f382_B,
    kCojiImageIndex_Tool_1f388,
    kCojiImageIndex_Tool_1f388_B,
    kCojiImageIndex_Tool_1f389,
    kCojiImageIndex_Tool_1f389_B,
    kCojiImageIndex_Tool_1f39f,
    kCojiImageIndex_Tool_1f39f_B,
    kCojiImageIndex_Tool_1f3a3,
    kCojiImageIndex_Tool_1f3a3_B,
    kCojiImageIndex_Tool_1f3a3_C,
    kCojiImageIndex_Tool_1f3a3_D,
    kCojiImageIndex_Tool_1f3a3_E,
    kCojiImageIndex_Tool_1f3a3_F,
    kCojiImageIndex_Tool_1f3a4,
    kCojiImageIndex_Tool_1f3a4_B,
    kCojiImageIndex_Tool_1f3b7,
    kCojiImageIndex_Tool_1f3b7_B,
    kCojiImageIndex_Tool_1f3b8,
    kCojiImageIndex_Tool_1f3b8_B,
    kCojiImageIndex_Tool_1f484,
    kCojiImageIndex_Tool_1f484_B,
    kCojiImageIndex_Tool_1f484_C,
    kCojiImageIndex_Tool_1f484_D,
    kCojiImageIndex_Tool_1f484_E,
    kCojiImageIndex_Tool_1f484_F,
    kCojiImageIndex_Tool_1f48b,
    kCojiImageIndex_Tool_1f48b_B,
    kCojiImageIndex_Tool_1f48c,
    kCojiImageIndex_Tool_1f511,
    kCojiImageIndex_Tool_1f511_B,
    kCojiImageIndex_Tool_1f511_C,
    kCojiImageIndex_Tool_1f511_D,
    kCojiImageIndex_Tool_1f525,
    kCojiImageIndex_Tool_1f525_B,
    kCojiImageIndex_Tool_1f526,
    kCojiImageIndex_Tool_1f526_B,
    kCojiImageIndex_Tool_1f526_C,
    kCojiImageIndex_Tool_1f526_D,
    kCojiImageIndex_Tool_1f527,
    kCojiImageIndex_Tool_1f527_B,
    kCojiImageIndex_Tool_1f528,
    kCojiImageIndex_Tool_1f528_B,
    kCojiImageIndex_Tool_1f52e,
    kCojiImageIndex_Tool_1f52e_B,
    kCojiImageIndex_Tool_1f576,
    kCojiImageIndex_Tool_1f576_B,
    kCojiImageIndex_Tool_1f576_C,
    kCojiImageIndex_Tool_1f6bd,
    kCojiImageIndex_Tool_1f9c0,
    kCojiImageIndex_Tool_23f0,
    kCojiImageIndex_Tool_23f0_B,
    kCojiImageIndex_Tool_23f0_C,
    kCojiImageIndex_Tool_23f0_D,
    kCojiImageIndex_Tool_23f0_E,
    kCojiImageIndex_Tool_23f0_F,
    kCojiImageIndex_Tool_23f0_G,
    kCojiImageIndex_Tool_23f0_H,
    kCojiImageIndex_Tool_23f0_I,
    kCojiImageIndex_Tool_2602,
    kCojiImageIndex_Tool_2602_B,
    kCojiImageIndex_Tool_2602_C,
    kCojiImageIndex_Tool_26bd,
    kCojiImageIndex_Tool_26bd_B,
    kCojiImageIndex_Vehicle_1F3cd,
    kCojiImageIndex_Vehicle_1F3cd_B,
    kCojiImageIndex_Vehicle_1F3cd_C,
    kCojiImageIndex_Vehicle_1F680,
    kCojiImageIndex_Vehicle_1F680_B,
    kCojiImageIndex_Vehicle_1F680_C,
    kCojiImageIndex_Vehicle_1F680_D,
    kCojiImageIndex_Vehicle_1F681,
    kCojiImageIndex_Vehicle_1F681_B,
    kCojiImageIndex_Vehicle_1F681_C,
    kCojiImageIndex_Vehicle_1F682,
    kCojiImageIndex_Vehicle_1F682_B,
    kCojiImageIndex_Vehicle_1F692_A,
    kCojiImageIndex_Vehicle_1F692_B,
    kCojiImageIndex_Vehicle_1F692_C,
    kCojiImageIndex_Vehicle_1F692_D,
    kCojiImageIndex_Vehicle_1F692_E,
    kCojiImageIndex_Vehicle_1F692_F,
    kCojiImageIndex_Vehicle_1F692_G,
    kCojiImageIndex_Vehicle_1F692_H,
    kCojiImageIndex_Vehicle_1F692_I,
    kCojiImageIndex_Vehicle_1F692_J,
    kCojiImageIndex_Vehicle_1F692_K,
    kCojiImageIndex_Vehicle_1F692_L,
    kCojiImageIndex_Vehicle_1F692_M,
    kCojiImageIndex_Vehicle_1F692_Njpg,
    kCojiImageIndex_Vehicle_1F692_O,
    kCojiImageIndex_Vehicle_1F693,
    kCojiImageIndex_Vehicle_1F693_B,
    kCojiImageIndex_Vehicle_1F6F3,
    kCojiImageIndex_Vehicle_1F6F3_B,
    kCojiImageIndex_Vehicle_1f3a2,
    kCojiImageIndex_Vehicle_1f3a2_B,
    kCojiImageIndex_Vehicle_1f3a2_C,
    kCojiImageIndex_Vehicle_1f3a2_D,
    kCojiImageIndex_Vehicle_1f3a2_E,
    kCojiImageIndex_Vehicle_1f3a2_F,
    kCojiImageIndex_Vehicle_1f3a2_G,
    kCojiImageIndex_Vehicle_1f3a2_H,
    kCojiImageIndex_Vehicle_1f3a2_I,
    kCojiImageIndex_Vehicle_1f3a2_J,
    kCojiImageIndex_Vehicle_1f3c1,
    kCojiImageIndex_Vehicle_1f3c1_B,
    kCojiImageIndex_Vehicle_1f3c1_C,
    kCojiImageIndex_Vehicle_1f3c3,
    kCojiImageIndex_Vehicle_1f3c3_B,
    kCojiImageIndex_Vehicle_1f3c3_C,
    kCojiImageIndex_Vehicle_1f3ce,
    kCojiImageIndex_Vehicle_1f3ce_B,
    kCojiImageIndex_Vehicle_1f3ce_C,
    kCojiImageIndex_Vehicle_1f3ce_D,
    kCojiImageIndex_Vehicle_1f3ce_E,
    kCojiImageIndex_Vehicle_1f3ce_F,
    kCojiImageIndex_Vehicle_1f3d7,
    kCojiImageIndex_Vehicle_1f3d7_B,
    kCojiImageIndex_Vehicle_1f3d7_C,
    kCojiImageIndex_Vehicle_1f3d7_D,
    kCojiImageIndex_Vehicle_1f3d7_E,
    kCojiImageIndex_Vehicle_1f3d7_F,
    kCojiImageIndex_Vehicle_1f4a6,
    kCojiImageIndex_Vehicle_1f4a6_B,
    kCojiImageIndex_Vehicle_1f4a8,
    kCojiImageIndex_Vehicle_1f4a8_B,
    kCojiImageIndex_Vehicle_1f691,
    kCojiImageIndex_Vehicle_1f691_B,
    kCojiImageIndex_Vehicle_1f6a6,
    kCojiImageIndex_Vehicle_1f6a6_B,
    kCojiImageIndex_Vehicle_1f6e5,
    kCojiImageIndex_Vehicle_1f6e5_B,
    kCojiImageIndex_Vehicle_1f6e5_C,
    kCojiImageIndex_Vehicle_1f6e5_D,
    kCojiImageIndex_Vehicle_2693,
    kCojiImageIndex_Vehicle_2693_B,
    kCojiImageIndex_Vehicle_2693_C,
    kCojiImageIndex_Vehicle_26fd,
    kCojiImageIndex_Vehicle_26fd_B,
    kCojiImageIndex_Vehicle_26fd_C,
    kCojiImageIndex_Vehicle_26fd_D,
    kCojiImageIndex_Vehicle_2708,
    kCojiImageIndex_Vehicle_2708_B,
} kCojiImageIndex;

typedef enum : uint8_t {
    kCojiAnimationStatusStarted = 0x00,
    kCojiAnimationStatusFinished = 0x01,
    kCojiAnimationStatusFailed = 0x02,
    kCojiAnimationStatusNewFailed = 0x03,
} kCojiAnimationStatus;

typedef enum : uint8_t {
    kCojiSoundStatusStarted = 0x00,
    kCojiSoundStatusFinished = 0x01,
    kCojiSoundStatusFailed = 0x02,
    kCojiSoundStatusNewFailed = 0x03,
} kCojiSoundStatus;

typedef enum : uint8_t {
    kCojiIdleAnimationSoundStatusOn = 0x00,
    kCojiIdleAnimationSoundStatusOff = 0x01,
    
} kCojiIdleAnimationSoundStatus;

typedef enum : uint8_t {
    kCojiButtonPressedStatusOn = 0x01,
    kCojiButtonPressedStatusOff = 0x00,
    
} kCojiButtonPressedStatus;

typedef enum : uint8_t {
    kCojiStopTypeAnimation = 0x01,
    kCojiStopTypeSound = 0x02,
    kCojiStopTypeFileTransfer = 0x03,
    
} kCojiStopType;

typedef enum : uint8_t {
    kCojiImage_AnimationTemplate_ScaleUp = 0x00,
    kCojiImage_AnimationTemplate_ScaleDown = 0x01,
    kCojiImage_AnimationTemplate_RightToLeft = 0x02,
    kCojiImage_AnimationTemplate_LeftToRight = 0x03,
    kCojiImage_AnimationTemplate_CenterToLeft = 0x04,
    kCojiImage_AnimationTemplate_CenterToRight = 0x05,
    kCojiImage_AnimationTemplate_DownToCenter = 0x06,
    kCojiImage_AnimationTemplate_CenterToDown = 0x07,
    kCojiImage_AnimationTemplate_UpToCenter = 0x08,
    kCojiImage_AnimationTemplate_CenterToUp = 0x09,
    kCojiImage_AnimationTemplate_None = 0x0A,
} kCojiImage_AnimationTemplate;

@interface CojiCommandValues : NSObject

@end

