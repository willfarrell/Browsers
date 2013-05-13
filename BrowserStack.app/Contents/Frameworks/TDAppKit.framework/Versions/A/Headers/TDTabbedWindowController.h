//
//  TDTabbedWindowController.h
//  TDAppKit
//
//  Created by Todd Ditchendorf on 11/10/10.
//  Copyright 2010 Todd Ditchendorf. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class TDTabsListViewController;

@interface TDTabbedWindowController : NSWindowController {
    TDTabsListViewController *tabsListViewController;
    BOOL fullScreen; // Lion only
    BOOL fullScreenTransitioning; // Lion only
    NSPanel *confirmTabCloseSheet;
}

//- (IBAction)performClose:(id)sender; // maps to -closeTab:. must do this for framework calls
- (IBAction)runConfirmTabCloseSheet:(id)sender;
- (IBAction)orderOutConfirmTabCloseSheet:(id)sender;

- (BOOL)isFullScreen; // Lion only
- (BOOL)isFullScreenTransitioning; // Lion only

// make SL compiler happy
- (void)windowWillEnterFullScreen:(NSNotification *)n;
- (void)windowDidEnterFullScreen:(NSNotification *)n;
- (void)windowWillExitFullScreen:(NSNotification *)n;
- (void)windowDidExitFullScreen:(NSNotification *)n;

@property (nonatomic, retain) TDTabsListViewController *tabsListViewController;
@property (nonatomic, retain) IBOutlet NSPanel *confirmTabCloseSheet;
@end
