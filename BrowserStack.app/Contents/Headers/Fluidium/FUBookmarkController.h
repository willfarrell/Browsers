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

@class FUBookmark;

@interface FUBookmarkController : NSObject 
#if FU_BUILD_TARGET_SNOW_LEOPARD
<NSMenuDelegate>
#endif
{
    NSMutableArray *bookmarks;
}

+ (FUBookmarkController *)instance;

- (IBAction)openBookmarkInNewWindow:(id)sender;
- (IBAction)openBookmarkInNewTab:(id)sender;
- (IBAction)copyBookmark:(id)sender;
- (IBAction)deleteBookmark:(id)sender;
- (IBAction)editBookmarkTitle:(id)sender;
- (IBAction)editBookmarkContent:(id)sender;

- (void)save;

- (void)appendBookmark:(FUBookmark *)bmark;
- (void)insertBookmark:(FUBookmark *)bmark atIndex:(NSInteger)i;
- (void)removeBookmark:(FUBookmark *)bmark;

- (NSMenu *)contextMenuForBookmark:(FUBookmark *)bmark;

@property (nonatomic, retain) NSMutableArray *bookmarks;
@end
