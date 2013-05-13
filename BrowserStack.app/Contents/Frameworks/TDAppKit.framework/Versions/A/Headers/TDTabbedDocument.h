//
//  TDTabbedDocument.h
//  TDAppKit
//
//  Created by Todd Ditchendorf on 11/10/10.
//  Copyright 2010 Todd Ditchendorf. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <TDAppKit/TDTabsListViewController.h>

@class TDTabModel;
@class TDTabViewController;

@interface TDTabbedDocument : NSDocument  <TDTabsListViewControllerDelegate> {
    NSString *identifier;
    NSMutableArray *models;
    TDTabModel *selectedTabModel;
    NSUInteger selectedTabIndex;
    BOOL userMustConfirmTabClose;
	
	BOOL hasSetUpTabsList;
    NSData *printInfoData;
    BOOL reverting;
}

//- (IBAction)performClose:(id)sender;
- (IBAction)closeTab:(id)sender;
//- (IBAction)closeWindow:(id)sender;

- (IBAction)newTab:(id)sender;
- (IBAction)newBackgroundTab:(id)sender;
- (IBAction)selectPreviousTab:(id)sender;
- (IBAction)selectNextTab:(id)sender;

- (IBAction)takeTabIndexToCloseFrom:(id)sender;
- (IBAction)takeTabIndexToMoveToNewWindowFrom:(id)sender;

- (void)addTabModelAtIndex:(NSUInteger)i;
- (void)addTabModel:(TDTabModel *)tm;
- (void)addTabModel:(TDTabModel *)tm atIndex:(NSUInteger)i;
- (void)removeTabModelAtIndex:(NSUInteger)i;
- (void)removeTabModel:(TDTabModel *)tm;

- (TDTabModel *)tabModelAtIndex:(NSUInteger)i;
- (NSUInteger)indexOfTabModel:(TDTabModel *)tm;
- (NSUInteger)indexOfTabModelWithRepresentedObject:(id)obj;

// subclass
- (void)didAddTabModelAtIndex:(NSUInteger)i;
- (void)willRemoveTabModelAtIndex:(NSUInteger)i;
- (void)selectedTabIndexWillChange;
- (void)selectedTabIndexDidChange;

- (NSString *)localizedDisplayNameForTab;
- (NSString *)localizedDisplayNameForTabPlural;

- (TDTabViewController *)newTabViewController;
- (NSMenu *)contextMenuForTabModelAtIndex:(NSUInteger)i;

@property (nonatomic, copy, readonly) NSArray *tabModels;
@property (nonatomic, assign) NSUInteger selectedTabIndex;
@property (nonatomic, retain, readonly) TDTabModel *selectedTabModel;
@property (nonatomic, retain, readonly) TDTabViewController *selectedTabViewController;
@property (nonatomic, assign) BOOL userMustConfirmTabClose;
@property (nonatomic, retain) NSData *printInfoData;
@end
