//
//  NSData+AESKey.h
//  This NSData represents the AES key. Data to en/decrypt is passed in.
//
//  Created by Robert C. Nix on 10/04/10.
//  Copyright 2010 nicerobot.org. All rights reserved.
//

#import "NSData+AES.h"

@interface NSData (AESKey)

-(NSData*) encryptValue:(NSData*) value;
-(NSData*) encryptValue:(NSData*) value usingPadding:(CCOptions)options;
-(NSData*) decryptValue:(NSData*) value;
-(NSData*) decryptValue:(NSData*) value usingPadding:(CCOptions)options;

@end
