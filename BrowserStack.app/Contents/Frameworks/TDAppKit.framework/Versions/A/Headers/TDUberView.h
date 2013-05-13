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

@class TDUberView;

@protocol TDUberViewDelegate <NSObject>
// TODO
@end

@interface TDUberView : NSView 
#if FU_BUILD_TARGET_SNOW_LEOPARD
<NSSplitViewDelegate>
#endif
{
    id <TDUberViewDelegate>delegate;
    
    NSString *autosaveName;
    
    NSSplitView *verticalSplitView;
    NSSplitView *horizontalSplitView;
    NSView *leftSuperview;
    NSView *rightSuperview;
    NSView *bottomSuperview;
    NSView *midSuperview;
    NSView *topSuperview;
    NSView *leftView;
    NSView *rightView;
    NSView *bottomView;
    NSView *midView;
    NSView *topView;
    BOOL leftViewOpen;
    BOOL rightViewOpen;
    BOOL topViewOpen;
    BOOL bottomViewOpen;
    
    NSString *currentLeftIdentifier;
    NSString *currentRightIdentifier;
    NSString *currentTopIdentifier;
    NSString *currentBottomIdentifier;

    NSTimer *timer;
    NSSplitViewDividerStyle splitViewDividerStyle;
    CGFloat preferredLeftSplitWidth;
    CGFloat preferredRightSplitWidth;
    CGFloat preferredTopSplitHeight;
    CGFloat preferredBottomSplitHeight;
    BOOL snapsToPreferredSplitWidths;
    CGFloat snapTolerance;

    CGFloat dragStartMidWidth;
    CGFloat dragStartRightRatio;
    CGFloat dragStartLeftRatio;
    CGFloat dragStartMidHeight;
    CGFloat dragStartTopRatio;
    CGFloat dragStartBottomRatio;
}

// designated initializer
- (id)initWithFrame:(NSRect)frame dividerStyle:(NSSplitViewDividerStyle)dividerStyle;

- (IBAction)resetToPreferredSplitPositions:(id)sender;

- (IBAction)toggleLeftView:(id)sender;
- (IBAction)openLeftView:(id)sender;
- (IBAction)closeLeftView:(id)sender;

- (IBAction)toggleRightView:(id)sender;
- (IBAction)openRightView:(id)sender;
- (IBAction)closeRightView:(id)sender;

- (IBAction)toggleTopView:(id)sender;
- (IBAction)openTopView:(id)sender;
- (IBAction)closeTopView:(id)sender;

- (IBAction)toggleBottomView:(id)sender;
- (IBAction)openBottomView:(id)sender;
- (IBAction)closeBottomView:(id)sender;

- (void)reflectStoredOpenStates;

@property (nonatomic, assign) id <TDUberViewDelegate>delegate; // weak ref

@property (nonatomic, copy) NSString *autosaveName;

@property (nonatomic, retain) NSView *leftView;
@property (nonatomic, retain) NSView *rightView;
@property (nonatomic, retain) NSView *topView;
@property (nonatomic, retain) NSView *midView;
@property (nonatomic, retain) NSView *bottomView;

@property (nonatomic, retain) NSSplitView *verticalSplitView; // this one has split divider lines running north sout
@property (nonatomic, retain) NSSplitView *horizontalSplitView; // this one has split divider lines running east west

@property (nonatomic) NSSplitViewDividerStyle splitViewDividerStyle;
@property (nonatomic) CGFloat preferredLeftSplitWidth;
@property (nonatomic) CGFloat preferredRightSplitWidth;
@property (nonatomic) CGFloat preferredTopSplitHeight;
@property (nonatomic) CGFloat preferredBottomSplitHeight;
@property (nonatomic) BOOL snapsToPreferredSplitWidths;
@property (nonatomic) CGFloat snapTolerance;

@property (nonatomic, readonly, getter=isLeftViewOpen) BOOL leftViewOpen;
@property (nonatomic, readonly, getter=isRightViewOpen) BOOL rightViewOpen;
@property (nonatomic, readonly, getter=isTopViewOpen) BOOL topViewOpen;
@property (nonatomic, readonly, getter=isBottomViewOpen) BOOL bottomViewOpen;
@end
