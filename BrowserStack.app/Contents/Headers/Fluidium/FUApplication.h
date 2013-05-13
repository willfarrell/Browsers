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

#ifdef HOTKEY
@class PTHotKey;
#endif

@interface FUApplication : NSApplication {
    NSString *appName;
    NSString *versionString;
    NSString *appSupportDirPath;
    NSString *ssbSupportDirPath;
    NSString *userscriptDirPath;
    NSString *userscriptFilePath;
    NSString *userstyleDirPath;
    NSString *scriptsDirPath;
    NSString *userstyleFilePath;
    NSString *bookmarksFilePath;
    NSString *downloadArchiveFilePath;
    NSString *plugInPrivateDirPath;
    NSString *plugInDirPath;
    NSString *plugInSupportDirPath;
    NSString *startupItemsDirPath;
    NSString *shutdownItemsDirPath;
    NSString *cookieStorageDirPath;
#ifdef FU_LOCAL_STORAGE_ENABLED
    NSString *localStorageDirPath;
#endif
    
#ifdef STATUSITEM
    NSStatusItem *statusItem;
    NSMenu *statusItemMenu;
    NSWindow *statusItemWindow;
    BOOL statusItemVisible;
    BOOL statusItemMenuVisible;
    CGFloat statusItemWindowFrameX;
#endif
}

+ (FUApplication *)instance;

- (IBAction)showPreferencesPanel:(id)sender;

- (IBAction)showDownloadsWindow:(id)sender;
- (IBAction)showBookmarksWindow:(id)sender;
- (IBAction)showUserscriptsWindow:(id)sender;
- (IBAction)showUserstylesWindow:(id)sender;

- (IBAction)clearHistory:(id)sender;

- (IBAction)globalShortcutActivated:(id)sender;

// font panel support
- (IBAction)changeFont:(id)sender;

- (void)showPreferencePaneForIdentifier:(NSString *)s;

- (NSString *)defaultUserAgentString;
- (NSArray *)allUserAgentStrings;

- (BOOL)isFullScreen;

- (FourCharCode)scriptSuiteFourCharCode;

- (BOOL)enforceSignedUpdates;
- (BOOL)isFluidApp;

//- (void)alertDidEnd:(NSAlert *)alert returnCode:(NSInteger)returnCode contextInfo:(void *)ctx;
- (void)runRelaunchAppDialogInWindow:(NSWindow *)win delegate:(id)delegate didEndSelector:(SEL)sel contextInfo:(void *)ctx;
- (void)relaunchApp;

@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *versionString;
@property (nonatomic, copy) NSString *appSupportDirPath;
@property (nonatomic, copy) NSString *ssbSupportDirPath;
@property (nonatomic, copy) NSString *userscriptDirPath;
@property (nonatomic, copy) NSString *userscriptFilePath;
@property (nonatomic, copy) NSString *userstyleDirPath;
@property (nonatomic, copy) NSString *scriptsDirPath;
@property (nonatomic, copy) NSString *userstyleFilePath;
@property (nonatomic, copy) NSString *bookmarksFilePath;
@property (nonatomic, copy) NSString *downloadArchiveFilePath;
@property (nonatomic, copy) NSString *plugInPrivateDirPath;
@property (nonatomic, copy) NSString *plugInDirPath;
@property (nonatomic, copy) NSString *plugInSupportDirPath;
@property (nonatomic, copy) NSString *startupItemsDirPath;
@property (nonatomic, copy) NSString *shutdownItemsDirPath;
@property (nonatomic, copy) NSString *cookieStorageDirPath;
#ifdef FU_LOCAL_STORAGE_ENABLED
@property (nonatomic, copy) NSString *localStorageDirPath;
#endif

#ifdef HOTKEY
- (PTHotKey *)globalHotKey;
- (NSString *)recorderControlAutosaveName;
- (void)registerGlobalHotKey;
- (void)unregisterGlobalHotKey;
#endif

#ifdef STATUSITEM
@property (nonatomic, retain) NSStatusItem *statusItem;
@property (nonatomic, retain) NSMenu *statusItemMenu;
@property (nonatomic, retain) NSWindow *statusItemWindow;
@property (nonatomic, assign) BOOL statusItemVisible;
@property (nonatomic, assign) BOOL statusItemMenuVisible;
@property (nonatomic, assign) CGFloat statusItemWindowFrameX;
#endif

@end
