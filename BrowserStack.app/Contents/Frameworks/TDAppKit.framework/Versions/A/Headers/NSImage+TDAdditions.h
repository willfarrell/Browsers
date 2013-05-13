//  Copyright 2010 Todd Ditchendorf
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
#import <TDAppKit/TDUtils.h>

@interface NSImage (TDAdditions)
+ (NSImage *)imageNamed:(NSString *)name inBundleForClass:(Class)cls;

- (NSImage *)scaledImageOfSize:(NSSize)size; // alpha=1, hiRez=YES
- (NSImage *)scaledImageOfSize:(NSSize)size alpha:(CGFloat)alpha; // hiRez=YES
- (NSImage *)scaledImageOfSize:(NSSize)size alpha:(CGFloat)alpha hiRez:(BOOL)hiRez;
- (NSImage *)scaledImageOfSize:(NSSize)size alpha:(CGFloat)alpha hiRez:(BOOL)hiRez cornerRadius:(CGFloat)radius;
- (NSImage *)scaledImageOfSize:(NSSize)size alpha:(CGFloat)alpha hiRez:(BOOL)hiRez clip:(NSBezierPath *)path;

- (void)drawStretchableInRect:(NSRect)rect edgeInsets:(TDEdgeInsets)insets operation:(NSCompositingOperation)op fraction:(CGFloat)delta;
@end
