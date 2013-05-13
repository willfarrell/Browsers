//
//  Adapted very slightly from BWTransparentScrollView.h
//  BWToolkit
//
//  Created by Brandon Walkin (www.brandonwalkin.com)
//  All code is provided under the New BSD license.
//

#import <Cocoa/Cocoa.h>
//#import "WebDynamicScrollBarsView.h"

//@class TDClipView;

//@interface TDScrollView : WebDynamicScrollBarsView {
@interface TDScrollView : NSScrollView {
    BOOL suppressScrolling;
//    TDClipView *contentView;
}

//@property (nonatomic, retain) TDClipView *contentView;
@property (assign) BOOL suppressScrolling;
@end
