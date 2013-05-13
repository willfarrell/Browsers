//
//  TDTabController.h
//  TDAppKit
//
//  Created by Todd Ditchendorf on 11/10/10.
//  Copyright 2010 Todd Ditchendorf. All rights reserved.
//

#import <TDAppKit/TDViewController.h>

@class TDTabModel;

@interface TDTabViewController : TDViewController {
    TDTabModel *tabModel;
}

@property (nonatomic, assign) TDTabModel *tabModel; // weakref
@end
