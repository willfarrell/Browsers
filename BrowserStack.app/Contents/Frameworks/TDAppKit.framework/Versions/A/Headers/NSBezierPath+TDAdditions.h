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

//
//  NSBezierPath+PXRoundedRectangleAdditions.h
//  Pixen
//
//  Created by Andy Matuschak on 7/3/05.
//  Copyright 2005 Open Sword Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>

typedef enum {
    TDCornerTopLeft = 1,
    TDCornerBottomLeft = 2,
    TDCornerTopRight = 4,
    TDCornerBottomRight = 8
} TDCorner;

#define TDCornersAll TDCornerTopLeft|TDCornerTopRight|TDCornerBottomLeft|TDCornerBottomRight
#define TDCornersLeft TDCornerTopLeft|TDCornerBottomLeft
#define TDCornersRight TDCornerTopRight|TDCornerBottomRight
#define TDCornersTop TDCornerTopLeft|TDCornerTopRight
#define TDCornersBottom TDCornerBottomLeft|TDCornerBottomRight

@interface NSBezierPath (TDAdditions)
+ (NSBezierPath *)bezierPathWithRoundRect:(NSRect)r radius:(CGFloat)radius;
+ (NSBezierPath *)bezierPathWithRoundRect:(NSRect)r radius:(CGFloat)radius corners:(TDCorner)corners;
@end
