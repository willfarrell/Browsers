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
#import <WebKit/WebKit.h>
#import "FUJavaScriptBridge.h"

#ifdef FAKE
@class AutoTyper;
#endif

@class FUWindowController;
@class FUWebView;
@class WebInspector;

@interface FUTabController : NSObject <DOMEventListener, FUJavaScriptBridgeDelegate> {
    FUWindowController *windowController;
    NSView *view;
    FUWebView *webView;
    NSMutableArray *currentFrameDocuments;
    FUJavaScriptBridge *javaScriptBridge;
    NSString *URLString;
    NSString *initialURLString;
    NSString *title;
    NSImage *favicon;
    NSString *statusText;
    
    NSString *promptResultText;
    NSView *promptView;
    NSTextView *promptTextView;
    
    WebInspector *inspector;

    BOOL lastLoadFailed;
    BOOL touched;
    
    BOOL isProcessing; // the 'is' is necessary here to match PSMTabBarControl
    BOOL canReload;
    BOOL didReceiveTitle;
    BOOL subresourceFailed;
    
    NSScriptCommand *suspendedCommand;
    BOOL submittingFromScript;
    
    NSMutableArray *javaScriptAlertQueue;
    NSAlert *currentJavaScriptAlert;
    
#ifdef FAKE
    AutoTyper *autoTyper;
    NSString *fileChooserPath;
#endif
}

- (id)initWithWindowController:(FUWindowController *)wc;

- (IBAction)webGoBack:(id)sender;
- (IBAction)webGoForward:(id)sender;
- (IBAction)webReload:(id)sender;
- (IBAction)webStopLoading:(id)sender;
- (IBAction)webGoHome:(id)sender;

// context menu actions
- (IBAction)openLinkInNewTabFromMenu:(id)sender;
- (IBAction)openLinkInNewWindowFromMenu:(id)sender;
- (IBAction)openFrameInNewWindowFromMenu:(id)sender;
- (IBAction)openImageInNewWindowFromMenu:(id)sender;
- (IBAction)searchWebFromMenu:(id)sender;
- (IBAction)downloadLinkAsFromMenu:(id)sender;

- (IBAction)showWebInspector:(id)sender;
- (IBAction)showErrorConsole:(id)sender;

- (IBAction)zoomIn:(id)sender;
- (IBAction)zoomOut:(id)sender;
- (IBAction)actualSize:(id)sender;

- (BOOL)canZoomIn;
- (BOOL)canZoomOut;
- (BOOL)canActualSize;

- (CGFloat)estimatedProgress;
- (NSString *)mainFrameDocumentSource;

- (void)loadURL:(NSString *)s;

- (void)prepareForClose;

@property (nonatomic, assign, readonly) FUWindowController *windowController; // weak ref
@property (nonatomic, retain) NSView *view;
@property (nonatomic, retain) FUWebView *webView;
@property (nonatomic, retain) NSMutableArray *currentFrameDocuments;
@property (nonatomic, retain) FUJavaScriptBridge *javaScriptBridge;
@property (nonatomic, copy) NSString *URLString;
@property (nonatomic, copy) NSString *initialURLString;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, retain) NSImage *favicon;
@property (nonatomic, copy) NSString *statusText;
@property (nonatomic, copy) NSString *promptResultText;
@property (nonatomic, retain) IBOutlet NSView *promptView;
@property (nonatomic, retain) IBOutlet NSTextView *promptTextView;
@property (nonatomic, retain) WebInspector *inspector;
@property (nonatomic) BOOL lastLoadFailed;

@property (nonatomic) BOOL isProcessing;
@property (nonatomic) BOOL canReload;
@property (nonatomic) BOOL subresourceFailed;

@property (nonatomic, retain) NSAlert *currentJavaScriptAlert;
@property (nonatomic, retain) NSMutableArray *javaScriptAlertQueue;
#ifdef FAKE
@property (nonatomic, retain) AutoTyper *autoTyper;
@property (nonatomic, copy) NSString *fileChooserPath;
#endif    
@end
