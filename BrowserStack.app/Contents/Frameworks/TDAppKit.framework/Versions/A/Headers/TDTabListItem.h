//
//  TDTabListItem.h
//  TDAppKit
//
//  Created by Todd Ditchendorf on 11/10/10.
//  Copyright 2010 Todd Ditchendorf. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <TDAppKit/TDListItem.h>

@class TDTabModel;
@class TDTabsListViewController;
@class TDTabListItemStyle;

@interface TDTabListItem : TDListItem {
    TDTabModel *tabModel;
    NSButton *closeButton;
    NSProgressIndicator *progressIndicator;
    TDTabsListViewController *tabsListViewController;
    
    BOOL showsCloseButton;
    BOOL showsProgressIndicator;
    
    NSTimer *drawHiRezTimer;
    BOOL drawHiRez;
}

+ (NSString *)reuseIdentifier;

- (void)drawHiRezLater;

- (NSRect)borderRectForBounds:(NSRect)bounds;
- (NSRect)titleRectForBounds:(NSRect)bounds;
- (NSRect)closeButtonRectForBounds:(NSRect)bounds;
- (NSRect)progressIndicatorRectForBounds:(NSRect)bounds;
- (NSRect)thumbnailRectForBounds:(NSRect)bounds;

@property (nonatomic, retain) TDTabModel *tabModel;
@property (nonatomic, retain) NSButton *closeButton;
@property (nonatomic, retain) NSProgressIndicator *progressIndicator;
@property (nonatomic, assign) TDTabsListViewController *tabsListViewController; // weakref
@property (nonatomic, assign) BOOL showsCloseButton;
@property (nonatomic, assign) BOOL showsProgressIndicator;
@end
