// Douglas Hill, October 2013
// https://github.com/douglashill/DHUtilities

#import "UIControl+ DHBlocks.h"

#import <objc/runtime.h>

static char DHUIControlEventBlocksKey;

@interface DHUIControlBlockKeeper : NSObject

+ (instancetype)blockKeeperWithBlock:(DHControlEventBlock)block;

@property (nonatomic, copy) DHControlEventBlock block;

- (void)runBlock:(id)sender;

@end

@implementation DHUIControlBlockKeeper

+ (instancetype)blockKeeperWithBlock:(DHControlEventBlock)block
{
	DHUIControlBlockKeeper *blockKeeper = [[self alloc] init];
	[blockKeeper setBlock:block];
	return blockKeeper;
}

- (void)runBlock:(id)sender
{
	[self block]();
}

@end

@interface UIControl (DHBlocks_private)

@property (nonatomic, strong, readonly) NSMutableSet *dh_eventBlocks;

@end

@implementation UIControl (DHBlocks_private)

- (NSMutableSet *)dh_eventBlocks
{
	NSMutableSet *eventBlocks = objc_getAssociatedObject(self, &DHUIControlEventBlocksKey);
	
	if (eventBlocks) return eventBlocks;
	
	eventBlocks = [NSMutableSet set];
	objc_setAssociatedObject(self, &DHUIControlEventBlocksKey, eventBlocks, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
	
	return eventBlocks;
}

@end

@implementation UIControl (DHBlocks)

- (id)dh_addBlock:(DHControlEventBlock)block forControlEvents:(UIControlEvents)events
{
	if (block == nil) return nil;
	
	DHUIControlBlockKeeper *keeper = [DHUIControlBlockKeeper blockKeeperWithBlock:block];
	
	[[self dh_eventBlocks] addObject:keeper];
	
	[self addTarget:keeper action:@selector(runBlock:) forControlEvents:events];
	
	return keeper;
}

- (void)dh_removeBlockForToken:(id)token forControlEvents:(UIControlEvents)events
{
	if (token == nil) return;
	
	NSParameterAssert([[self dh_eventBlocks] containsObject:token]);
	
	[self removeTarget:token action:@selector(runBlock:) forControlEvents:events];
	
	[[self dh_eventBlocks] removeObject:token];
}

@end
