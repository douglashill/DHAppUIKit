//
//  UIControl+DHAdditions.h
//  DHTweak
//
//  Created by Douglas Hill on 06/10/2013.
//  Copyright (c) 2013 Douglas Hill. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^DHControlEventBlock)(void);

@interface UIControl (DHBlocks)

- (id)dh_addBlock:(DHControlEventBlock)block forControlEvents:(UIControlEvents)events; // Returns an opaque token object that may be passed into dh_removeBlockForToken:forControlEvents: to stop running the block.
- (void)dh_removeBlockForToken:(id)token forControlEvents:(UIControlEvents)events;

@end
