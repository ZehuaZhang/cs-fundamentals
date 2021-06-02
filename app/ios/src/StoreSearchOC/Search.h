//
//  Search.h
//  StoreSearchOC
//
//  Created by ZhangZehua on 2/23/17.
//  Copyright © 2017 ZhangZehua. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^SearchBlock)(BOOL success);

@interface Search : NSObject

@property (nonatomic, assign) BOOL isLoading;
@property (nonatomic, readonly, strong) NSMutableArray* searchResults;

- (void)performSearchForText:(NSString *)text category:(NSInteger)category completion:(SearchBlock)block;

@end
