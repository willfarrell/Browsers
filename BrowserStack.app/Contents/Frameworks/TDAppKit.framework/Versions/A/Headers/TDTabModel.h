//
//  TDTabModel.h
//  TDAppKit
//
//  Created by Todd Ditchendorf on 11/10/10.
//  Copyright 2010 Todd Ditchendorf. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class TDTabbedDocument;
@class TDTabViewController;

@interface TDTabModel : NSObject <NSCoding> {
    NSString *title;
    id representedObject;
    TDTabbedDocument *document;
    TDTabViewController *tabViewController;
    
    NSImage *image;
    NSImage *scaledImage;
    NSUInteger index;
    BOOL selected;
    BOOL busy;
    
    BOOL needsNewImage;
    
    NSUInteger changeCount;
}

- (BOOL)wantsNewImage;
- (void)setNeedsNewImage:(BOOL)yn;

- (void)updateChangeCount:(NSDocumentChangeType)changeType;
- (BOOL)isDocumentEdited;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, retain) id representedObject;
@property (nonatomic, assign) TDTabbedDocument *document; // weak ref
@property (nonatomic, retain) TDTabViewController *tabViewController;
@property (nonatomic, retain) NSImage *image;
@property (nonatomic, retain) NSImage *scaledImage;
@property (nonatomic, assign) NSUInteger index;
@property (nonatomic, assign, getter=isSelected) BOOL selected;
@property (nonatomic, assign, getter=isBusy) BOOL busy;
@property (nonatomic, assign) NSUInteger changeCount;
@end
