// Douglas Hill, October 2013
// https://github.com/douglashill/DHUtilities

@import UIKit;

typedef void (^DHControlEventBlock)(void);

@interface UIControl (DHBlocks)

/// Returns an opaque token object that may be passed into dh_removeBlockForToken:forControlEvents: to stop running the block.
- (nonnull id)dh_addBlock:(nonnull DHControlEventBlock)block forControlEvents:(UIControlEvents)events;

- (void)dh_removeBlockForToken:(nonnull id)token forControlEvents:(UIControlEvents)events;

@end
