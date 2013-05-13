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

#pragma GCC visibility push(default)

extern NSString *const kFUHTTPSchemePrefix;
extern NSString *const kFUHTTPSSchemePrefix;
extern NSString *const kFUFileSchemePrefix;
extern NSString *const kFUJavaScriptSchemePrefix;

extern NSString *const kFUAboutBlank;

//extern NSInteger kFUScriptErrorNumberTimeout;
extern NSInteger const kFUScriptErrorNumberInvalidArgument;
extern NSInteger const kFUScriptErrorNumberCantGoBack;
extern NSInteger const kFUScriptErrorNumberCantGoForward;
extern NSInteger const kFUScriptErrorNumberCantReload;
extern NSInteger const kFUScriptErrorNumberJavaScriptError;
extern NSInteger const kFUScriptErrorNumberXPathError;
extern NSInteger const kFUScriptErrorNumberUnixScriptError;
extern NSInteger const kFUScriptErrorNumberAppleScriptError;
extern NSInteger const kFUScriptErrorNumberAssertionFailed;
extern NSInteger const kFUScriptErrorNumberElementNotFound;
extern NSInteger const kFUScriptErrorNumberLoadFailed;
extern NSInteger const kFUScriptErrorNumberNotHTMLDocument;
extern NSInteger const kFUScriptErrorNumberCouldNotSendMail;
extern NSInteger const kFUScriptErrorNumberCSSError;
extern NSInteger const kFUScriptErrorNumberFileReadError;

NSColor *FUMainTabBackgroundColor();
NSColor *FUNonMainTabBackgroundColor();
NSColor *FUMainTabBorderColor();
NSColor *FUNonMainTabBorderColor();
NSDictionary *FUMainTabTextAttributes();
NSDictionary *FUNonMainTabTextAttributes();

NSString *FUWebKitVersionString();

void FUWriteWebURLsToPasteboard(NSString *URLString, NSString *title, NSPasteboard *pboard);
void FUWriteAllToPasteboard(NSString *URLString, NSString *title, NSPasteboard *pboard);

#define FUIsWebUndefined(obj) ([(obj) isKindOfClass:[WebUndefined class]])
#define FUIsWebScriptObject(obj) ([(obj) isKindOfClass:[WebScriptObject class]])

#pragma GCC visibility pop
