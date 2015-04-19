// Douglas Hill, March 2014
// https://github.com/douglashill/DHUtilities

@import Foundation;

#import "DHMap.h"

@interface NSSet (DHMap)

/// Returns the set of all objects returned by passing each of the receiver’s members to `map`. The object is omitted if `map` returns nil.
- (nonnull NSSet *)dh_setByMappingObjectsUsingMap:(nonnull DHObjectMap)map;

/// Returns a dictionary populated by calling `map` with each object in the receiver. `map` must return either an array containing a key for the dictionary at index 0 and and the coresponding value at index 1 (a tuple), or return nil to omit the object.
- (nonnull NSDictionary *)dh_dictionaryByMappingObjectsUsingMap:(nonnull DHKeyValueMap)map;

@end

typedef BOOL (^DHFilterPredicate)(id __nonnull object);

@interface NSSet (DHExtendedSet)

/// Returns the first object found that passes the test. Stops processing on finding a match.
- (nullable id)dh_anyObjectPassingTest:(nonnull DHFilterPredicate)predicate;

@end

@interface NSMutableSet (DHAdditions)

/// Returns the object that was removed.
- (nullable id)dh_removeAnyObjectPassingTest:(nonnull DHFilterPredicate)predicate;

@end
