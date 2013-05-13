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

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

NSString *TDJSStringGetNSString(JSStringRef str);
JSStringRef TDJSStringCreateWithNSString(NSString *nsstring);

JSValueRef TDCFTypeToJSValue(JSContextRef ctx, CFTypeRef value, JSValueRef *ex);
JSValueRef TDCFStringToJSValue(JSContextRef ctx, CFStringRef cfStr, JSValueRef *ex);
JSValueRef TDNSStringToJSValue(JSContextRef ctx, NSString *nsStr, JSValueRef *ex);
JSObjectRef TDCFArrayToJSObject(JSContextRef ctx, CFArrayRef cfArray, JSValueRef *ex);
JSObjectRef TDNSArrayToJSObject(JSContextRef ctx, NSArray *nsArray, JSValueRef *ex);
JSObjectRef TDCFDictionaryToJSObject(JSContextRef ctx, CFDictionaryRef cfDict, JSValueRef *ex);
JSObjectRef TDNSDictionaryToJSObject(JSContextRef ctx, NSDictionary *nsDict, JSValueRef *ex);

CFTypeRef TDJSValueCopyCFType(JSContextRef ctx, JSValueRef value, JSValueRef *ex);
id TDJSValueGetId(JSContextRef ctx, JSValueRef value, JSValueRef *ex);
CFStringRef TDJSValueCopyCFString(JSContextRef ctx, JSValueRef value, JSValueRef *ex);
NSString *TDJSValueGetNSString(JSContextRef ctx, JSValueRef value, JSValueRef *ex);
CFArrayRef TDJSObjectCopyCFArray(JSContextRef ctx, JSObjectRef obj, JSValueRef *ex);
CFDictionaryRef TDJSObjectCopyCFDictionary(JSContextRef ctx, JSObjectRef obj, JSValueRef *ex);

JSObjectRef TDNSErrorToJSObject(JSContextRef ctx, NSError *nsErr, JSValueRef *ex);
bool TDJSValueIsInstanceOfClass(JSContextRef ctx, JSValueRef value, char *className, JSValueRef* ex);

JSValueRef TDEvaluateScript(JSGlobalContextRef ctx, NSString *script, NSString *sourceURLString, NSString **outErrMsg);
BOOL TDBooleanForScript(JSGlobalContextRef ctx, NSString *script, NSString *sourceURLString, NSString **outErrMsg);