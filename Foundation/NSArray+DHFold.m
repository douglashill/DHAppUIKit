// Douglas Hill, August 2014
// https://github.com/douglashill/DHUtilities

#import "NSArray+DHFold.h"

@implementation NSArray (DHFold)

- (id)dh_foldWithInitialValue:(id)initialValue options:(NSEnumerationOptions)options usingBlock:(id (^)(id obj, id value))function
{
	if (options & NSEnumerationConcurrent) {
		[NSException raise:NSInvalidArgumentException format:@"Bad things will happen if you try to fold concurrently."];
	}
	
	__block id value = initialValue;
	
	[self enumerateObjectsWithOptions:options usingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
		value = function(obj, value);
	}];
	
	return value;
}

@end
