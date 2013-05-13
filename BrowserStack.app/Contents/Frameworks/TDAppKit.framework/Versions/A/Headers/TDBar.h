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

@interface TDBar : NSView {
    NSGradient *mainBgGradient;
    NSGradient *nonMainBgGradient;
    NSColor *mainTopBorderColor;
    NSColor *nonMainTopBorderColor;
    NSColor *mainTopBevelColor;
    NSColor *nonMainTopBevelColor;
    NSColor *mainBottomBevelColor;
    NSColor *nonMainBottomBevelColor;
}

- (BOOL)shouldDrawTopBorder;

@property (nonatomic, retain) NSGradient *mainBgGradient;
@property (nonatomic, retain) NSGradient *nonMainBgGradient;
@property (nonatomic, retain) NSColor *mainTopBorderColor;
@property (nonatomic, retain) NSColor *nonMainTopBorderColor;
@property (nonatomic, retain) NSColor *mainTopBevelColor;
@property (nonatomic, retain) NSColor *nonMainTopBevelColor;
@property (nonatomic, retain) NSColor *mainBottomBevelColor;
@property (nonatomic, retain) NSColor *nonMainBottomBevelColor;
@end
