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

#import <WebKit/WebKit.h>

@class FUJavaScriptBridge;
@class FUJavaScriptMenuItem;
@class FUJavaScriptGrowlNotification;

@protocol FUJavaScriptBridgeDelegate
@required
- (WebScriptObject *)windowScriptObjectForBridge:(FUJavaScriptBridge *)b;
- (void)bridge:(FUJavaScriptBridge *)bridge didReceivePushState:(id)stateObj title:(NSString *)title fragment:(NSString *)frag;
@end

@interface FUJavaScriptBridge : NSObject {
    id <FUJavaScriptBridgeDelegate> delegate;
    BOOL privilegedAccessAllowed;
    NSString *applicationPath;
    NSString *resourcePath;
    NSString *userscriptPath;
    id dockBadge;
    BOOL isGrowlRunning;
    NSMutableArray *dockMenuItems;
    WebScriptObject *onclick;
    NSMutableDictionary *growls;
    
    WebScriptObject *oldPushState;
}

- (id)initWithDelegate:(id <FUJavaScriptBridgeDelegate>)d;

- (void)dockMenuItemClick:(FUJavaScriptMenuItem *)jsItem;

// JavaScript methods
- (void)showGrowlNotification:(id)arg;
- (FUJavaScriptGrowlNotification *)growlNotificationWithClickContext:(NSString *)identifier;
- (void)growlNotificationTimedOut:(FUJavaScriptGrowlNotification *)note;
- (void)growlNotificationWasClicked:(FUJavaScriptGrowlNotification *)note;

- (void)addDockMenuItemWithTitle:(NSString *)title function:(WebScriptObject *)func;
- (void)removeDockMenuItemWithTitle:(NSString *)title;

- (void)beep;
- (void)playSoundNamed:(id)obj;
- (void)include:(id)obj;
- (void)requestUserAttention:(BOOL)critical;

- (void)pushState:(id)stateObj title:(id)title fragment:(id)frag;

@property (nonatomic, assign) id <FUJavaScriptBridgeDelegate> delegate;
@property (getter=isPrivilegedAccessAllowed) BOOL privilegedAccessAllowed;

@property (nonatomic, copy) NSString *applicationPath;
@property (nonatomic, copy) NSString *resourcePath;
@property (nonatomic, copy) NSString *userscriptPath;
@property (nonatomic, copy) id dockBadge;
@property (nonatomic, readonly) BOOL isGrowlRunning;
@property (nonatomic, retain) NSMutableArray *dockMenuItems;
@property (nonatomic, retain) WebScriptObject *onclick;
@property (nonatomic, retain) NSMutableDictionary *growls;
@property (nonatomic, retain) WebScriptObject *oldPushState;
@end
