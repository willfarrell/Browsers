//
//  TDTabsViewController.h
//  TDAppKit
//
//  Created by Todd Ditchendorf on 11/10/10.
//  Copyright 2010 Todd Ditchendorf. All rights reserved.
//

#import <TDAppKit/TDViewController.h>
#import <TDAppKit/TDListView.h>

@class TDTabModel;
@class TDTabsListViewController;
@class TDTabListItemStyle;

@protocol TDTabsListViewControllerDelegate <NSObject>
- (NSUInteger)numberOfTabsInTabsViewController:(TDTabsListViewController *)tvc;
- (TDTabModel *)tabsViewController:(TDTabsListViewController *)tvc tabModelAtIndex:(NSUInteger)i;

- (NSMenu *)tabsViewController:(TDTabsListViewController *)tvc contextMenuForTabModelAtIndex:(NSUInteger)i;
- (void)tabsViewController:(TDTabsListViewController *)tvc didSelectTabModelAtIndex:(NSUInteger)i;
- (void)tabsViewController:(TDTabsListViewController *)tvc didCloseTabModelAtIndex:(NSUInteger)i;
- (void)tabsViewControllerWantsNewTab:(TDTabsListViewController *)tvc;
@end

@interface TDTabsListViewController : TDViewController <TDListViewDataSource, TDListViewDelegate, NSTextFieldDelegate> {
    id <TDTabsListViewControllerDelegate> delegate;
    NSScrollView *scrollView;
    TDListView *listView;
    BOOL allowsTabTitleEditing;
    TDTabListItemStyle *listItemStyle;
    NSUInteger editingIndex;
    TDTabModel *draggingTabModel;
}

- (IBAction)closeTabButtonClick:(id)sender;

+ (void)registerStyleClass:(Class)cls forName:(NSString *)name;
- (void)useStyleNamed:(NSString *)styleName;

- (void)updateAllTabModels;
- (void)updateAllTabModelsFromIndex:(NSUInteger)startIndex;
- (void)updateSelectedTabModel;

@property (nonatomic, assign) id <TDTabsListViewControllerDelegate> delegate; // weak ref
@property (nonatomic, retain) IBOutlet NSScrollView *scrollView;
@property (nonatomic, retain) IBOutlet TDListView *listView;
@property (nonatomic, assign) BOOL allowsTabTitleEditing;
@property (nonatomic, retain) TDTabListItemStyle *listItemStyle;
@end
