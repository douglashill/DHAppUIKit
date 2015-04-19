// Douglas Hill, March 2014
// https://github.com/douglashill/DHUtilities

#import "NSSet+DHAdditions.h"

#import "DHExceptionCreation.h"

@implementation NSSet (DHMap)

- (NSSet *)dh_setByMappingObjectsUsingMap:(id (^)(id object))map
{
	NSMutableSet *mappedSet = [NSMutableSet setWithCapacity:[self count]];
	
	for (id object in self) {
		id mappedObject = map(object);
		if (mappedObject) [mappedSet addObject:mappedObject];
	}
	
	return mappedSet;
}

- (NSDictionary *)dh_dictionaryByMappingObjectsUsingMap:(NSArray *(^)(id object))map
{
	NSMutableDictionary *mappedDictionary = [NSMutableDictionary dictionaryWithCapacity:[self count]];
	
	for (id object in self) {
		NSArray *const result = map(object);
		// Omit objects that map to nil.
		if ([result count] >= 2) {
			mappedDictionary[result[0]] = result[1];
		}
	}
	
	return mappedDictionary;
}

@end

@implementation NSSet (DHExtendedSet)

- (id)dh_anyObjectPassingTest:(BOOL (^)(id, BOOL *))predicate
{
	if (predicate == nil) {
		@throw DH_EXCEPTION(NSInvalidArgumentException, @"%s: predicate cannot be nil", __PRETTY_FUNCTION__);
	}
	
	return [[self objectsPassingTest:^BOOL(id obj, BOOL *stop) {
		if (predicate(obj, stop)) {
			*stop = YES;
			return YES;
		}
		return NO;
	}] anyObject];
}

@end

@implementation NSMutableSet (DHAdditions)

- (id)dh_removeAnyObjectPassingTest:(BOOL (^)(id obj, BOOL *stop))predicate
{
	id object = [self dh_anyObjectPassingTest:predicate];
	
	if (object == nil) {
		return nil;
	}
	
	[self removeObject:object];
	
	return object;
}

@end
