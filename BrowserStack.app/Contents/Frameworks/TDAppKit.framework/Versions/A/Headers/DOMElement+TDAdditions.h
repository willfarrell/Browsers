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

#import <WebKit/WebKit.h>

@interface DOMElement (TDAdditions)
- (NSString *)defaultXPath;
- (void)dispatchClickEvent;
- (void)simulateClickEventInWebView:(WebView *)webView;
- (void)dispatchChangeEvent;

- (void)dispatchMouseEventType:(NSString *)type 
                    clickCount:(NSInteger)clickCount 
                       ctrlKey:(BOOL)cntrlKeyPressed 
                        altKey:(BOOL)altKeyPressed 
                      shiftKey:(BOOL)shiftKeyPressed 
                       metaKey:(BOOL)metaKeyPressed 
                        button:(NSInteger)button 
                 relatedTarget:(id)relatedTarget
                       webView:(WebView *)webView;

- (BOOL)isTextField;
- (BOOL)isTextArea;
- (BOOL)isFileChooser;
- (BOOL)isRadio;
- (BOOL)isCheckbox;
- (BOOL)isSelect;
- (BOOL)isMultiSelect;
@end
