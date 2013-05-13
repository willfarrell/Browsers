//
//  TDTabbedDocumentController.h
//  TDAppKit
//
//  Created by Todd Ditchendorf on 11/10/10.
//  Copyright 2010 Todd Ditchendorf. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface TDTabbedDocumentController : NSDocumentController {
    BOOL fullScreen;
}

- (Class)representedObjectClass;
- (id)newRepresentedObject;

- (IBAction)toggleFullScreen:(id)sender;
- (IBAction)newTab:(id)sender;

- (id)frontDocument;

- (BOOL)isFullScreen;
- (NSDictionary *)fullScreenOptions;
- (void)willEnterFullScreenMode;
- (void)didEnterFullScreenMode;
- (void)willExitFullScreenMode;
- (void)didExitFullScreenMode;
@end
