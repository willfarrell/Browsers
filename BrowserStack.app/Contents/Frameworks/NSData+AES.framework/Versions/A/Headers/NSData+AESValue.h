//
//  NSData+AES.h
//  This NSData represents the data to en/decrypt. The key is passed in.
//
//  Created by Robert C. Nix on 10/04/10.
//  Copyright 2010 nicerobot.org. All rights reserved.
//

#import "NSData+AES.h"

@interface NSData (AESValue)

-(NSData*) encryptWithKey:(NSData*) key;
-(NSData*) encryptWithKey:(NSData*) key usingPadding:(CCOptions)options;
-(NSData*) decryptWithKey:(NSData*) key;
-(NSData*) decryptWithKey:(NSData*) key usingPadding:(CCOptions)options;

@end
