//
//  NSMutableData+AES.h
//  Bases
//
//  Created by Robert C. Nix on 10/04/10.
//  Copyright 2010 nicerobot.org. All rights reserved.
//

#import "NSData+AES.h"

@interface NSMutableData (AES)

-(NSData*) encryptInPlace:(NSData*) key;
-(NSData*) encryptInPlace:(NSData*) key withPadding:(CCOptions)options;
-(NSData*) decryptInPlace:(NSData*) key;
-(NSData*) decryptInPlace:(NSData*) key withPadding:(CCOptions)options;

@end
