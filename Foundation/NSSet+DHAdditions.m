// Douglas Hill, March 2014
// https://github.com/douglashill/DHUtilities

#import "NSSet+DHAdditions.h"

@implementation NSSet (DHMap)

- (nonnull NSSet *)dh_setByMappingObjectsUsingMap:(nonnull DHObjectMap)map
{
	NSMutableSet *mappedSet = [NSMutableSet setWithCapacity:[self count]];
	
	for (id object in self) {
		id mappedObject = map(object);
		if (mappedObject) [mappedSet addObject:mappedObject];
	}
	
	return mappedSet;
}

- (nonnull NSDictionary *)dh_dictionaryByMappingObjectsUsingMap:(nonnull DHKeyValueMap)map
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

- (nullable id)dh_anyObjectPassingTest:(nonnull DHFilterPredicate)predicate
{
	return [[self objectsPassingTest:^BOOL(id obj, BOOL *stop) {
		if (predicate(obj)) {
			*stop = YES;
			return YES;
		}
		return NO;
	}] anyObject];
}

@end

@implementation NSMutableSet (DHAdditions)

- (nullable id)dh_removeAnyObjectPassingTest:(nonnull DHFilterPredicate)predicate
{
	id const object = [self dh_anyObjectPassingTest:predicate];
	
	if (object == nil) {
		return nil;
	}
	
	[self removeObject:object];
	
	return object;
}

@end
