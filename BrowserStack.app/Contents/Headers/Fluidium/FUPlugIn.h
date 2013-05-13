//  Copyright 2009 Todd Ditchendorf
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#import <Cocoa/Cocoa.h>

@class FUWindowController;
@protocol FUPlugInAPI;

#define FU_EXTERN __attribute__((visibility("default"))) 
#pragma GCC visibility push(default)

// Notification names
extern NSString *const FUPlugInViewControllerWillAppearNotifcation;
extern NSString *const FUPlugInViewControllerDidAppearNotifcation;
extern NSString *const FUPlugInViewControllerWillDisappearNotifcation;
extern NSString *const FUPlugInViewControllerDidDisappearNotifcation;

// keys for the userInfo dictionary of Notifications sent with names from above
extern NSString *const FUPlugInViewPlacementMaskKey;    // NSInteger
extern NSString *const FUPlugInKey;                     // FUPlugIn *
extern NSString *const FUPlugInViewControllerKey;       // NSViewController
extern NSString *const FUPlugInViewControllerDrawerKey; // NSDrawer -- this is only sent for view controllers currently in a drawer position

@interface NSObject (FUPlugInNotifications)
- (void)plugInViewControllerWillAppear:(NSNotification *)n;
- (void)plugInViewControllerDidAppear:(NSNotification *)n;
- (void)plugInViewControllerWillDisappear:(NSNotification *)n;
- (void)plugInViewControllerDidDisappear:(NSNotification *)n;
@end

typedef enum {
    FUPlugInViewPlacementDrawer = 1 << 1,
    FUPlugInViewPlacementUtilityPanel = 1 << 2,
    FUPlugInViewPlacementFloatingUtilityPanel = 1 << 3,
    FUPlugInViewPlacementHUDPanel = 1 << 4,
    FUPlugInViewPlacementFloatingHUDPanel = 1 << 5,
    FUPlugInViewPlacementSplitViewBottom = 1 << 6,
    FUPlugInViewPlacementSplitViewLeft = 1 << 7,
    FUPlugInViewPlacementSplitViewRight = 1 << 8,
    FUPlugInViewPlacementSplitViewTop = 1 << 9,
} FUPlugInViewPlacement;

#define FUPlugInViewPlacementAny (FUPlugInViewPlacementDrawer|FUPlugInViewPlacementUtilityPanel|FUPlugInViewPlacementFloatingUtilityPanel|FUPlugInViewPlacementHUDPanel|FUPlugInViewPlacementFloatingHUDPanel|FUPlugInViewPlacementSplitViewLeft|FUPlugInViewPlacementSplitViewRight|FUPlugInViewPlacementSplitViewTop|FUPlugInViewPlacementSplitViewBottom)
#define FUPlugInViewPlacementSplitView (FUPlugInViewPlacementSplitViewLeft|FUPlugInViewPlacementSplitViewRight|FUPlugInViewPlacementSplitViewTop|FUPlugInViewPlacementSplitViewBottom)
#define FUPlugInViewPlacementPanel (FUPlugInViewPlacementUtilityPanel|FUPlugInViewPlacementFloatingUtilityPanel|FUPlugInViewPlacementHUDPanel|FUPlugInViewPlacementFloatingHUDPanel)

#define FUPlugInViewPlacementIsVerticalSplitView(mask)  (mask) == FUPlugInViewPlacementSplitViewLeft || (mask) == FUPlugInViewPlacementSplitViewRight
#define FUPlugInViewPlacementIsHorizontalSplitView(mask)  (mask) == FUPlugInViewPlacementSplitViewBottom || (mask) == FUPlugInViewPlacementSplitViewTop
#define FUPlugInViewPlacementIsSplitView(mask)  ((mask) == FUPlugInViewPlacementSplitViewBottom || (mask) == FUPlugInViewPlacementSplitViewLeft || (mask) == FUPlugInViewPlacementSplitViewRight || (mask) == FUPlugInViewPlacementSplitViewTop)
#define FUPlugInViewPlacementIsPanel(mask)  ((mask) == FUPlugInViewPlacementUtilityPanel || (mask) == FUPlugInViewPlacementFloatingUtilityPanel || (mask) == FUPlugInViewPlacementHUDPanel || (mask) == FUPlugInViewPlacementFloatingHUDPanel)
#define FUPlugInViewPlacementIsDrawer(mask)  ((mask) == FUPlugInViewPlacementDrawer)

// note that your FUPlugIn subclass will be registered (by the Fluid SSB) for the four PlugInViewController notifications below
// your impl will also be registered (by the Fluid SSB) for all NSWindow Notifications on the window with which it is associated, if it responds to the appropriate callback selectors
// you can implement the NSWindowNotification callback methods if you like. they will be called if you do.
FU_EXTERN
@interface FUPlugIn : NSObject {
    NSArray *viewControllers;
    
    NSViewController *preferencesViewController;
    NSString *identifier;
    NSString *localizedTitle;
    NSString *localizedShortTitle;
    NSUInteger allowedViewPlacement;
    NSUInteger preferredViewPlacement;
    NSString *preferredMenuItemKeyEquivalent;
    NSUInteger preferredMenuItemKeyEquivalentModifierFlags;
    NSString *toolbarIconImageName;
    NSString *preferencesIconImageName;
    NSDictionary *defaultsDictionary;
    NSDictionary *aboutInfoDictionary;
    CGFloat preferredVerticalSplitPosition;
    CGFloat preferredHorizontalSplitPosition;
    NSInteger sortOrder;
    BOOL wantsToolbarButton;
    BOOL wantsMainMenuItem;
}

// the plugInController is this plugin's API back to the Fluid SSB application.
- (id)initWithPlugInAPI:(id <FUPlugInAPI>)api;

// Create a new NSViewController to display your plugin in a new window. Subsequent calls should always return a new object.
// The returned object should have a retain count of at least 1, and is 'owned' by the caller from a memory management perspective.
// Fluid will release it when its window is destroyed.
// This may be called multiple times - once for every window in which the user views your plugin.
- (NSViewController *)newPlugInViewController;

- (FUWindowController *)windowControllerForViewController:(NSViewController *)vc;

@property (nonatomic, readonly, retain) NSArray *viewControllers;

// return the single NSViewController which will control the 'Preferences' view that will appear in the Fluid Preferences window.
// only one should ever be created. you should probably create it lazily in your implementation of this method.
// returned object should be autoreleased.
@property (nonatomic, retain) NSViewController *preferencesViewController;

// unique reverse domain. e.g.: com.fluidapp.FoobarPlugIn
@property (nonatomic, copy) NSString *identifier;

// the display string title for this plugin. do not include 'Plug-in' in this string. Just the name of this plugin
// e.g.: 'Clipboard' rather than 'Clipboard Plug-in'.
@property (nonatomic, copy) NSString *localizedTitle;

// used in Preferences Window Icon grid
@property (nonatomic, copy) NSString *localizedShortTitle;

// an or'ed mask containing the UI placements allowed for this plugin
@property (nonatomic, assign) NSUInteger allowedViewPlacement;

// a single UI placement maks stating where this plugin should appear by default
@property (nonatomic, assign) NSUInteger preferredViewPlacement;

// a string that will be used as the 'keyboard shortcut' in the main menu item for this plugin
@property (nonatomic, copy) NSString *preferredMenuItemKeyEquivalent;

// an or'd mask of modifiers to be usind in the keyboard shortcut in the main menu item for this plugin
// e.g.: (NSControlKeyMask|NSAlternateKeyMask|NSCommandKeyMask)
@property (nonatomic, assign) NSUInteger preferredMenuItemKeyEquivalentModifierFlags;

// a string matching the filename of an image in this plugin bundle's Resources dir.
// this string should not include the file extension.
@property (nonatomic, copy) NSString *toolbarIconImageName;

// a string matching the filename of an image in this plugin bundle's Resources dir.
// this string should not include the file extension.
@property (nonatomic, copy) NSString *preferencesIconImageName;

// values in this dictionary will be added to NSUserDefaults for the currently running SSB.
// the keys in this dictionary should be carefully namespaced
@property (nonatomic, retain) NSDictionary *defaultsDictionary;

// a dictionary containing the standard keys and values provided as the 'options' arg to:
// -[NSApplication orderFrontStandardAboutPanelWithOptions:]. See Apple's documentation for that method.
@property (nonatomic, retain) NSDictionary *aboutInfoDictionary;

@property (nonatomic, assign) CGFloat preferredVerticalSplitPosition;

@property (nonatomic, assign) CGFloat preferredHorizontalSplitPosition;

@property (nonatomic, assign) NSInteger sortOrder;
@property (nonatomic, assign) BOOL wantsToolbarButton;
@property (nonatomic, assign) BOOL wantsMainMenuItem;
@end

#pragma GCC visibility pop
