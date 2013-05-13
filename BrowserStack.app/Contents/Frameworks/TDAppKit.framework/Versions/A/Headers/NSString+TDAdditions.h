//
//  NSString+TDAdditions.h
//  TDAppKit
//
//  Created by Todd Ditchendorf on 7/11/10.
//  Copyright 2010 Todd Ditchendorf. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSString (TDAdditions)
- (NSString *)stringByCollapsingWhitespace;
- (NSString *)stringByReplacingWhitespaceWithStars;
- (NSString *)stringByTrimmingFirstAndLastChars;
@end
