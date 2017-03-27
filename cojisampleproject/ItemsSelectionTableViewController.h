//
//  ItemsSelectionTableViewController.h
//  EmojiBot
//
//  Created by David Chan on 22/9/15.
//  Copyright © 2015 Hexed Bits. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol ItemsSelectionTableViewCallback <NSObject>

- (void)didSelectRow:(int)selection Mode:(int)_mode;

@end

enum ItemsSelectionTableViewControllerMode {
    ItemsSelectionTableViewControllerMode_LED,
    ItemsSelectionTableViewControllerMode_Remote,
    ItemsSelectionTableViewControllerMode_ModuleSetting,
    ItemsSelectionTableViewControllerMode_FileSelection,
    ItemsSelectionTableViewControllerMode_AnimationSelection,
    ItemsSelectionTableViewControllerMode_ImageSelection,
    ItemsSelectionTableViewControllerMode_SoundSelection,
    ItemsSelectionTableViewControllerMode_ImageTemplateSelection,
};

@interface ItemsSelectionTableViewController : UITableViewController {
    
}

@property (nonatomic, readwrite) NSArray *arrItems;
@property (assign, readwrite) int mode;
@property (nonatomic, readwrite) id<ItemsSelectionTableViewCallback> delegate;

@end
