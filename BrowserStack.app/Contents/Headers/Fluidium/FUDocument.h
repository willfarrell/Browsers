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

@class FUWindowController;
@class FUWebPrintView;

@interface FUDocument : NSDocument {
    FUWindowController *windowController;
    FUWebPrintView *printView;
    NSData *printInfoData;
    BOOL first;
}

- (void)windowControllerDidShowVisiblePlugIns:(FUWindowController *)wc;

- (IBAction)printDocumentAsOnePage:(id)sender;
- (IBAction)captureScreenshot:(id)sender;

@property (nonatomic, retain) FUWindowController *windowController;
@property (nonatomic, retain) FUWebPrintView *printView;
@property (nonatomic, retain) NSData *printInfoData;
@property (nonatomic, getter=isFirst) BOOL first;
@end
