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

// This simple bean class represents a user <click> (including middle button click) or <return>/<enter> press in a browser chrome text field.
// It represents a UI activation event that should cause some type of page load.
// It is used to equalize the different ways in which this common idiom is represented in Cocoa and WebKit.

@interface FUActivation : NSObject {
    BOOL commandKeyPressed;
    BOOL shiftKeyPressed;
    BOOL optionKeyPressed;
}

+ (id)activationFromEvent:(NSEvent *)evt;
+ (id)activationFromModifierFlags:(NSUInteger)flags;
+ (id)activationFromWebActionInfo:(NSDictionary *)info;

@property (nonatomic, readonly, getter=isCommandKeyPressed) BOOL commandKeyPressed;
@property (nonatomic, readonly, getter=isShiftKeyPressed) BOOL shiftKeyPressed;
@property (nonatomic, readonly, getter=isOptionKeyPressed) BOOL optionKeyPressed;
@end
