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

@class TDListItem;
@class TDListItemQueue;
@protocol TDListViewDataSource;
@protocol TDListViewDelegate;

typedef enum {
    TDListViewOrientationPortrait = 0,
    TDListViewOrientationLandscape
} TDListViewOrientation;

typedef enum {
    TDListViewDropOn = 0,
    TDListViewDropBefore
} TDListViewDropOperation;

extern NSString *const TDListItemPboardType;

@interface TDListView : NSView {
    NSScrollView *scrollView;
    id <TDListViewDataSource>dataSource;
    id <TDListViewDelegate>delegate;
    NSColor *backgroundColor;
    CGFloat itemExtent;
    CGFloat itemMargin;
    NSIndexSet *selectionIndexes;
    NSUInteger anchorIndex;
    TDListViewOrientation orientation;
    BOOL displaysClippedItems;
    BOOL allowsMultipleSelection;
    
    //BOOL needsReload;
    
    NSMutableArray *items;
    NSMutableArray *unusedItems;
    TDListItemQueue *queue;
    
    // drag and drop
    NSEvent *lastMouseDownEvent;
    NSIndexSet *draggingIndexes;
    NSIndexSet *draggingVisibleIndexes;
    NSPoint dragOffset;
    NSDragOperation localDragOperationMask;
    NSDragOperation nonLocalDragOperationMask;
    NSUInteger dropIndex;
    NSUInteger dropVisibleIndex;
    TDListViewDropOperation dropOp;
    NSMutableArray *itemFrames;
    BOOL suppressLayout;
    BOOL delegateRespondsToValidateDrop;
    BOOL isDragSource;
}

- (void)reloadData;
- (TDListItem *)dequeueReusableItemWithIdentifier:(NSString *)s;
- (NSUInteger)indexForItemAtPoint:(NSPoint)p;
- (TDListItem *)itemAtIndex:(NSUInteger)i;
- (NSRect)frameForItemAtIndex:(NSUInteger)index;

/* Drag and drop support */

/* Configures the value returned from -draggingSourceOperationMaskForLocal:. 
    An isLocal value of YES indicates that 'dragOperationMask' applies when the destination object is in the same application. 
 By default, NSDragOperationEvery will be returned. An isLocal value of NO indicates that 'dragOperationMask' applies when the destination object 
 is in an application outside the receiver's application. By default, NSDragOperationNone is returned. 
 NSCollectionView will save the values you set for each isLocal setting. You typically will invoke this method, and not override it.
 */
- (void)setDraggingSourceOperationMask:(NSDragOperation)mask forLocal:(BOOL)localDestination;

/* This method computes and returns an image to use for dragging. You can override this to return a custom drag image, 
 or call it from the delegate method to get the default drag image. 'index' contains the index of the item being dragged. 
 'event' is a reference to the mouse down event that began the drag. 'dragImageOffset' is an in/out parameter. 
 This method will be called with dragImageOffset set to NSZeroPoint, but it can be modified to re-position the returned image. 
 A dragImageOffset of NSZeroPoint will cause the image to be centered under the mouse. 
 By default, an image will be created that contains a rendering of the visible portions of the views for each item. 
 If the delegate implements the equivalent delegate method, it will be preferred over this method.
 */
- (NSImage *)draggingImageForItemsAtIndexes:(NSIndexSet *)set withEvent:(NSEvent *)evt offset:(NSPointPointer)dragImageOffset;

- (BOOL)ignoreModifierKeysWhileDragging;

@property (nonatomic, assign) IBOutlet NSScrollView *scrollView;
@property (nonatomic, assign) IBOutlet id <TDListViewDataSource>dataSource;
@property (nonatomic, assign) IBOutlet id <TDListViewDelegate>delegate;
@property (nonatomic, retain) NSColor *backgroundColor;
@property (nonatomic, assign) CGFloat itemExtent; // height if isPortrait. width if isLandscape
@property (nonatomic, assign) CGFloat itemMargin; // height if isPortrait. width if isLandscape
@property (nonatomic, copy) NSIndexSet *selectionIndexes;
@property (nonatomic, assign) NSUInteger anchorIndex;
@property (nonatomic, assign) TDListViewOrientation orientation;
@property (nonatomic, assign) BOOL displaysClippedItems; // default=YES
@property (nonatomic, assign) BOOL allowsMultipleSelection; // default=NO

// convenience
@property (nonatomic, readonly, getter=isPortrait) BOOL portrait;
@property (nonatomic, readonly, getter=isLandscape) BOOL landscape;
@end

@protocol TDListViewDataSource <NSObject>
@required
- (NSUInteger)numberOfItemsInListView:(TDListView *)lv;
- (TDListItem *)listView:(TDListView *)lv itemAtIndex:(NSUInteger)i;
@end

@protocol TDListViewDelegate <NSObject>
@optional
- (CGFloat)listView:(TDListView *)lv extentForItemAtIndex:(NSUInteger)i; // should return height if isPortrait. shoud return width if isLandscape
- (void)listView:(TDListView *)lv willDisplayItem:(TDListItem *)item atIndex:(NSUInteger)i;
- (NSIndexSet *)listView:(TDListView *)lv willSelectItemsAtIndexes:(NSIndexSet *)set;
- (void)listView:(TDListView *)lv didSelectItemsAtIndexes:(NSIndexSet *)set;
- (void)listView:(TDListView *)lv itemWasDoubleClickedAtIndex:(NSUInteger)i;
- (void)listView:(TDListView *)lv itemWasMiddleClickedAtIndex:(NSUInteger)i;
- (void)listViewEmptyAreaWasDoubleClicked:(TDListView *)lv;
- (void)listViewEmptyAreaWasClicked:(TDListView *)lv;
- (BOOL)listViewWantsSelectionOnRightClick:(TDListView *)lv;
- (NSMenu *)listView:(TDListView *)lv contextMenuForItemsAtIndexes:(NSIndexSet *)set;
/* Drag and drop support */

/* The return value indicates whether the list view can attempt to initiate a drag for the given event and items. 
 If the delegate does not implement this method, the list view will act as if it returned YES.
 */
- (BOOL)listView:(TDListView *)lv canDragItemsAtIndexes:(NSIndexSet *)set withEvent:(NSEvent *)evt slideBack:(BOOL *)slideBack;

/*
 This method is called after it has been determined that a drag should begin, but before the drag has been started. 
 To refuse the drag, return NO. To start the drag, declare the pasteboard types that you support with -[NSPasteboard declareTypes:owner:], 
 place your data for the items at the given indexes on the pasteboard, and return YES from the method. 
 The drag image and other drag related information will be set up and provided by the view once this call returns YES. 
 You need to implement this method for your list view to be a drag source.
 */
- (BOOL)listView:(TDListView *)lv writeItemsAtIndexes:(NSIndexSet *)set toPasteboard:(NSPasteboard *)pboard;

/* The delegate can support file promise drags by adding NSFilesPromisePboardType to the pasteboard in -collectionView:writeItemsAtIndexes:toPasteboard:. 
 NSCollectionView implements -namesOfPromisedFilesDroppedAtDestination: to return the results of this delegate method. 
 This method should return an array of filenames (not full paths) for the created files. The URL represents the drop location. 
 For more information on file promise dragging, see documentation for the NSDraggingSource protocol and -namesOfPromisedFilesDroppedAtDestination:. 
 You do not need to implement this method for your list view to be a drag source.
 */
- (NSArray *)listView:(TDListView *)lv namesOfPromisedFilesDroppedAtDestination:(NSURL *)dropURL forDraggedItemAtIndexes:(NSIndexSet *)set;

/* Allows the delegate to construct a custom dragging image for the items being dragged. 'indexes' contains the indexes of the items being dragged. 
 'event' is a reference to the  mouse down event that began the drag. 'dragImageOffset' is an in/out parameter. 
 This method will be called with dragImageOffset set to NSZeroPoint, but it can be modified to re-position the returned image. 
 A dragImageOffset of NSZeroPoint will cause the image to be centered under the mouse. You can safely call -[NSCollectionView draggingImageForItemsAtIndexes:withEvent:offset:] from within this method. 
 You do not need to implement this method for your list view to be a drag source.
 */
- (NSImage *)listView:(TDListView *)lv draggingImageForItemsAtIndexes:(NSIndexSet *)set withEvent:(NSEvent *)evt offset:(NSPointPointer)dragImageOffset;

/* This method is used by the list view to determine a valid drop target. Based on the mouse position, the list view will suggest a proposed index and drop operation. 
 These values are in/out parameters and can be changed by the delegate to retarget the drop operation. 
 The list view will propose NSCollectionViewDropOn when the dragging location is closer to the middle of the item than either of its edges. 
 Otherwise, it will propose NSCollectionViewDropBefore. You may override this default behavior by changing proposedDropOperation or proposedDropIndex. 
 This method must return a value that indicates which dragging operation the data source will perform. It must return something other than NSDragOperationNone to accept the drop.
 
 Note: to receive drag messages, you must first send -registerForDraggedTypes: to the list view with the drag types you want to support (typically this is done in -awakeFromNib). 
 You must implement this method for your list view to be a drag destination.
 */
- (NSDragOperation)listView:(TDListView *)lv validateDrop:(id <NSDraggingInfo>)draggingInfo proposedIndex:(NSUInteger *)proposedDropIndex dropOperation:(TDListViewDropOperation *)proposedDropOperation;

/* This method is called when the mouse is released over a list view that previously decided to allow a drop via the above validateDrop method. 
 At this time, the delegate should incorporate the data from the dragging pasteboard and update the list view's contents. 
 You must implement this method for your list view to be a drag destination.
 */
- (BOOL)listView:(TDListView *)lv acceptDrop:(id <NSDraggingInfo>)draggingInfo index:(NSUInteger)index dropOperation:(TDListViewDropOperation)dropOperation;

- (BOOL)listView:(TDListView *)lv shouldRunPoofAt:(NSPoint)endPointInScreen forRemovedItemsAtIndexes:(NSIndexSet *)set;

@end

