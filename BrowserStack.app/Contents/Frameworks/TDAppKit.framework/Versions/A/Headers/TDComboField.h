//
//  TDComboField.h
//  TDAppKit
//
//  Created by Todd Ditchendorf on 4/9/10.
//  Copyright 2010 Todd Ditchendorf. All rights reserved.
//

#import <TDAppKit/TDBar.h>
#import <TDAppKit/TDListView.h>

@class TDComboField;
@class TDComboFieldTextView;

@protocol TDComboFieldDataSource <NSObject>
@required
- (NSUInteger)numberOfItemsInComboField:(TDComboField *)cf;
- (id)comboField:(TDComboField *)cf objectAtIndex:(NSUInteger)i;
@optional
- (NSUInteger)comboField:(TDComboField *)cf indexOfItemWithStringValue:(NSString *)string;
- (NSString *)comboField:(TDComboField *)cf completedString:(NSString *)uncompletedString;
@end

@protocol TDComboFieldDelegate <NSObject>
@required
- (BOOL)comboField:(TDComboField *)cf writeDataToPasteboard:(NSPasteboard *)pboard;
@optional
- (void)comboFieldWillDismissPopUp:(TDComboField *)cf;
- (void)comboFieldDidEscape:(TDComboField *)cf;
@end

@interface TDComboField : NSTextField <TDListViewDataSource, TDListViewDelegate> {
    id <TDComboFieldDataSource>dataSource;
    NSScrollView *scrollView;
    TDListView *listView;
    NSWindow *listWindow;
    TDComboFieldTextView *fieldEditor;
    NSMutableArray *buttons;
    BOOL shouldDrag;
    NSImage *progressImage;
    CGFloat progress;
}

- (void)escape:(id)sender;

- (BOOL)isListVisible;
- (void)showDefaultIcon;

- (NSUInteger)numberOfItems;
- (NSUInteger)indexOfSelectedItem;
- (void)deselectItemAtIndex:(NSUInteger)i;
- (void)reloadData;

- (NSRect)listWindowRectForBounds:(NSRect)bounds;
- (NSRect)scrollViewRectForBounds:(NSRect)bounds;
- (NSRect)listViewRectForBounds:(NSRect)bounds;

@property (nonatomic, assign) id <TDComboFieldDataSource>dataSource;
@property (nonatomic, retain) NSScrollView *scrollView;
@property (nonatomic, retain) TDListView *listView;
@property (nonatomic, retain) NSWindow *listWindow;
@property (nonatomic, retain) TDComboFieldTextView *fieldEditor;

// favicon image
@property (nonatomic, retain) NSImage *image;

// buttons
- (NSButton *)addButtonWithSize:(NSSize)size;
- (NSButton *)buttonWithTag:(int)tag;
- (void)removeButton:(NSButton *)b;
- (NSRect)buttonFrame;

@property (nonatomic, readonly, retain) NSArray *buttons;

// progress
@property (nonatomic) CGFloat progress;
@property (nonatomic, retain) NSImage *progressImage;
@end
