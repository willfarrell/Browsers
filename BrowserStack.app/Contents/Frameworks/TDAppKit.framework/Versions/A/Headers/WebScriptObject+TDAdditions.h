//
//  WebScriptObject+TDAdditions.h
//  TDAppKit
//
//  Created by Todd Ditchendorf on 9/16/10.
//  Copyright 2010 Todd Ditchendorf. All rights reserved.
//

#import <WebKit/WebKit.h>

@interface WebScriptObject (TDAdditions)
- (NSMutableArray *)asMutableArray;
- (NSArray *)asArray;
@end
