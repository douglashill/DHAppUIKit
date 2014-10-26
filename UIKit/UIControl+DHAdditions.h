// Douglas Hill, October 2013
// https://github.com/douglashill/Objective-C-bits-and-bobs

@import UIKit;

typedef void (^DHControlEventBlock)(void);

@interface UIControl (DHBlocks)

/// Returns an opaque token object that may be passed into dh_removeBlockForToken:forControlEvents: to stop running the block.
- (id)dh_addBlock:(DHControlEventBlock)block forControlEvents:(UIControlEvents)events;

- (void)dh_removeBlockForToken:(id)token forControlEvents:(UIControlEvents)events;

@end
