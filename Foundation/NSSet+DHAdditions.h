// Douglas Hill, March 2014
// https://github.com/douglashill/DHUtilities

@import Foundation;

@interface NSSet (DHMap)

/// Returns the set of all objects returned by passing each of the receiver’s members to `map`. The object is omitted if `map` returns nil.
- (NSSet *)dh_setByMappingObjectsUsingMap:(id (^)(id object))map;

/// Returns a dictionary populated by calling `map` with each object in the receiver. `map` must return either an array containing a key for the dictionary at index 0 and and the coresponding value at index 1 (a tuple), or return nil to omit the object.
- (NSDictionary *)dh_dictionaryByMappingObjectsUsingMap:(NSArray *(^)(id object))map;

@end

@interface NSSet (DHExtendedSet)

/// Returns the first object found that passes the test. Stops processing on finding a match.
- (id)dh_anyObjectPassingTest:(BOOL (^)(id obj, BOOL *stop))predicate;

@end

@interface NSMutableSet (DHAdditions)

/// Returns the object that was removed.
- (id)dh_removeAnyObjectPassingTest:(BOOL (^)(id obj, BOOL *stop))predicate;

@end
