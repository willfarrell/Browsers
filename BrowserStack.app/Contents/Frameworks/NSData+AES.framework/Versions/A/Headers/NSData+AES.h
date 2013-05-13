//
//  NSData+AES.h
//  Bases
//
//  Created by Robert C. Nix on 10/04/10.
//  Copyright 2010 nicerobot.org. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <CommonCrypto/CommonCryptor.h>

@interface NSData (AES)

-(NSData*) encrypt:(NSData*) key;
-(NSData*) encryptWithString:(NSString*) key;
-(NSData*) encrypt:(NSData*) key
       withPadding:(CCOptions) options;
-(NSData*) encrypt:(NSData*) key
       withInitial:(NSData*) iv;
-(NSData*) encrypt:(NSData*) key
       withInitial:(NSData*) iv
        andPadding:(CCOptions) options;

-(NSData*) decrypt:(NSData*) key;
-(NSData*) decryptWithString:(NSString*) key;
-(NSData*) decrypt:(NSData*) key
       withPadding:(CCOptions) options;
-(NSData*) decrypt:(NSData*) key
       withInitial:(NSData*) iv;
-(NSData*) decrypt:(NSData*) key
       withInitial:(NSData*) iv
        andPadding:(CCOptions) options;

@end
