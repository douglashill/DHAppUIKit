// Douglas Hill, October 2013
// https://github.com/douglashill/DHUtilities

@import UIKit;

typedef void (^DHControlEventBlock)(void);

@interface UIControl (DHBlocks)

/**
 @brief Adds a block to be run for a particular event (or events) to an internal dispatch table.
 @warning It is easy to cause retain cycles by referencing objects in block which own the control, whether directly or indirectly.
 @param block  The block to run when the event is sent, which is retained by the control.
 @param events A bitmask specifying the control events for which the block is run.
 @return An opaque token that may be passed to @c dh_removeBlockForToken:forControlEvents: to remove the block.
 */
- (nonnull id)dh_addBlock:(nonnull DHControlEventBlock)block forControlEvents:(UIControlEvents)events;

/**
 @brief Removes a block for a particular event (or events) from an internal dispatch table.
 @param token  An opaque object returned from @c dh_addBlock:forControlEvents: when adding the block to be removed.
 @param events A bitmask specifying the control events associated with the block.
 */
- (void)dh_removeBlockForToken:(nonnull id)token forControlEvents:(UIControlEvents)events;

@end
