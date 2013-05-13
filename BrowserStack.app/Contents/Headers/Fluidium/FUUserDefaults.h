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

// Browser
#ifndef APP_STORE
extern NSString *const kFUWebIconDatabaseDirectoryDefaultsKey;
#endif
extern NSString *const kFURecentURLStringsKey;
extern NSString *const kFUUserAgentStringKey;
extern NSString *const kFUHasLaunchedOnLionOrLaterKey;

// WebKit
extern NSString *const kFUContinuousSpellCheckingEnabledKey;
extern NSString *const kFUZoomTextOnlyKey;

// Cookies
#ifdef COOKIE_JAR
extern NSString *const kFUUseSeparateCookieJarKey;
#endif
extern NSString *const kFUHasLaunchedUnlicensedKey;

// UI
extern NSString *const kFUToolbarShownKey;
extern NSString *const kFUBookmarkBarShownKey;
extern NSString *const kFUBookmarkBarShowsFaviconsKey;
extern NSString *const kFUStatusBarShownKey;
extern NSString *const kFUTabBarHiddenAlwaysKey;
extern NSString *const kFUWindowFrameStringKey;
extern NSString *const kFUWindowScreenIndexKey;

// General Prefs
extern NSString *const kFUNewWindowsOpenWithKey;
extern NSString *const kFUHomeURLStringKey;
extern NSString *const kFUDownloadDirPathKey;

#ifdef STATUSITEM
extern NSString *const kFUPinToStatusBarKey;
extern NSString *const kFUStatusItemWindowFrameStringKey;
extern NSString *const kFULionWindowAnimationEnabledKey;
extern NSString *const kFUBackupLionWindowAnimationEnabledKey;
#endif

#ifdef FLUIDAPP
extern NSString *const kFUFluidAppNameKey;
extern NSString *const kFUShowDockBadgeLabelsKey;
#endif

#ifdef HOTKEY
extern NSString *const kFUGlobalShortcutKeyComboCodeKey;
extern NSString *const kFUGlobalShortcutKeyComboFlagsKey;
#endif

// Appearance Prefs
extern NSString *const kFUWindowLevelKey;
extern NSString *const kFUWindowsHaveShadowKey;
extern NSString *const kFUWindowOpacityKey;
extern NSString *const kFUStandardFontFamilyKey;
extern NSString *const kFUDefaultFontSizeKey;
extern NSString *const kFUFixedFontFamilyKey;
extern NSString *const kFUDefaultFixedFontSizeKey;    
extern NSString *const kFULoadsImagesAutomaticallyKey;

// Behavior Prefs
extern NSString *const kFUSpacesBehaviorKey;
extern NSString *const kFUTargetedClicksCreateTabsKey;
extern NSString *const kFULinksSentToOtherApplicationsOpenInBackgroundKey;
extern NSString *const kFUOpenLinksFromApplicationsInKey;
extern NSString *const kFUHideLastClosedWindowKey;
extern NSString *const kFUSessionsEnabledKey;
extern NSString *const kFUSessionInfoKey;

// Tabs Prefs
extern NSString *const kFUTabbedBrowsingEnabledKey;
extern NSString *const kFUSelectNewWindowsOrTabsAsCreatedKey;
extern NSString *const kFUConfirmBeforeClosingMultipleTabsOrWindowsKey;
extern NSString *const kFUTabBarHiddenForSingleTabKey;
extern NSString *const kFUSelectPriorSelectedTabOnTabCloseKey;
extern NSString *const kFUTabBarCellOptimumWidthKey;

// Security Prefs
extern NSString *const kFUPlugInsEnabledKey;
extern NSString *const kFUJavaEnabledKey;
extern NSString *const kFUJavaScriptEnabledKey;
extern NSString *const kFUJavaScriptCanOpenWindowsAutomaticallyKey;
extern NSString *const kFUCookieAcceptPolicyKey;

// Shortcut Prefs
extern NSString *const kFUShortcutsKey;

// Handlers Prefs
extern NSString *const kFUHandlersKey;

// Whitelist Prefs
extern NSString *const kFUAllowBrowsingToAnyDomainKey;
extern NSString *const kFUInvertWhitelistKey;
extern NSString *const kFUWhitelistURLPatternStringsKey;

// PlugIns Prefs
extern NSString *const kFUShowVisiblePlugInsInNewWindowsKey;
extern NSString *const kFUVisiblePlugInIdentifiersKey;
extern NSString *const kFUNumberOfBrowsaPlugInsKey;
extern NSString *const kFUPlugInDrawerContentSizeStringKey;

@interface FUUserDefaults : NSObject {

}

+ (FUUserDefaults *)instance;

// Browser
#ifndef APP_STORE
@property (nonatomic, copy) NSString *webIconDatabaseDirectoryDefaults;
#endif
@property (nonatomic, copy) NSArray *recentURLStrings;
@property (nonatomic, copy) NSString *userAgentString;
@property (nonatomic) BOOL hasLaunchedOnLionOrLater;

// WebView
@property (nonatomic) BOOL continuousSpellCheckingEnabled;
@property (nonatomic) BOOL zoomTextOnly;

// Cookies
#ifdef COOKIE_JAR
@property (nonatomic) BOOL useSeparateCookieJar;
#endif
@property (nonatomic) BOOL hasLaunchedUnlicensed;

// UI
@property (nonatomic) BOOL toolbarShown;
@property (nonatomic) BOOL statusBarShown;
@property (nonatomic) BOOL bookmarkBarShown;
@property (nonatomic) BOOL bookmarkBarShowsFavicons;
@property (nonatomic) BOOL tabBarHiddenAlways;
@property (nonatomic, copy) NSString *windowFrameString;
@property (nonatomic) NSInteger windowScreenIndex;

// General Prefs
@property (nonatomic) NSInteger newWindowsOpenWith;
@property (nonatomic, copy) NSString *homeURLString;
@property (nonatomic, copy) NSString *downloadDirPath;

#ifdef STATUSITEM
@property (nonatomic) BOOL pinToStatusBar;
@property (nonatomic, copy) NSString *statusItemWindowFrameString;
@property (nonatomic) BOOL lionWindowAnimationEnabled;
@property (nonatomic) BOOL backupLionWindowAnimationEnabled;
#endif

#ifdef FLUIDAPP
@property (nonatomic, copy) NSString *fluidAppName;
@property (nonatomic) BOOL showDockBadgeLabels;
#endif

#ifdef HOTKEY
@property (nonatomic) NSUInteger globalShortcutKeyComboFlags;
@property (nonatomic) NSInteger globalShortcutKeyComboCode;
#endif

// Appearance Prefs
@property (nonatomic) NSInteger windowLevel;
@property (nonatomic) BOOL windowsHaveShadow;
@property (nonatomic) CGFloat windowOpacity;
@property (nonatomic, copy) NSString *standardFontFamily;
@property (nonatomic) int defaultFontSize;
@property (nonatomic, copy) NSString *fixedFontFamily;
@property (nonatomic) int defaultFixedFontSize;
@property (nonatomic) BOOL loadsImagesAutomatically;

// Behavior Prefs
@property (nonatomic) NSInteger spacesBehavior;
@property (nonatomic) BOOL targetedClicksCreateTabs;
@property (nonatomic) BOOL linksSentToOtherApplicationsOpenInBackground;
@property (nonatomic) NSInteger openLinksFromApplicationsIn;
@property (nonatomic) BOOL hideLastClosedWindow;
@property (nonatomic) BOOL sessionsEnabled;
@property (nonatomic, copy) NSArray *sessionInfo;

// Tabs Prefs
@property (nonatomic) BOOL tabbedBrowsingEnabled;
@property (nonatomic) BOOL selectNewWindowsOrTabsAsCreated;
@property (nonatomic) BOOL confirmBeforeClosingMultipleTabsOrWindows;
@property (nonatomic) BOOL tabBarHiddenForSingleTab;
@property (nonatomic) BOOL selectPriorSelectedTabOnTabClose;
@property (nonatomic) NSInteger tabBarCellOptimumWidth;

// Security Prefs
@property (nonatomic) BOOL plugInsEnabled;
@property (nonatomic) BOOL javaEnabled;
@property (nonatomic) BOOL javaScriptEnabled;
@property (nonatomic) BOOL javaScriptCanOpenWindowsAutomatically;
@property (nonatomic) NSInteger cookieAcceptPolicy;

// Shortcuts
@property (nonatomic, copy) NSArray *shortcuts;

// Handlers
@property (nonatomic, copy) NSArray *handlers;

// Whitelist Prefs
@property (nonatomic) BOOL allowBrowsingToAnyDomain;
@property (nonatomic) BOOL invertWhitelist;
@property (nonatomic, copy) NSArray *whitelistURLPatternStrings;

// All Plugins
@property (nonatomic) BOOL showVisiblePlugInsInNewWindows;
@property (nonatomic, copy) NSArray *visiblePlugInIdentifiers;
@property (nonatomic) NSInteger numberOfBrowsaPlugIns;
@property (nonatomic, copy) NSString *plugInDrawerContentSizeString;
@end
