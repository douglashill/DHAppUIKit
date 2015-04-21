// Douglas Hill, March 2014
// https://github.com/douglashill/DHUtilities

@import Foundation;

#import "DHMap.h"

@interface NSSet (DHMap)

/**
 Returns a set containing the results of calling map with each of the receiving set’s members.
 @param map The block that maps from a member of the receiving set to an object to be included in the returned set. The block may return nil to skip adding a corresponding object to the returned set.
 @return A set containing the results of calling `map` with each of the receiving set’s members.
 */
- (nonnull NSSet *)dh_setByMappingObjectsUsingMap:(nonnull DHObjectMap)map;

/**
 Returns a dictionary containing the results of calling map with each of the receiving set’s members.
 @param map The block that maps from a member of the receiving set to a keys-value pair to be included in the returned dictionary. The block must return either an array containing a key for the dictionary at index 0 and and the corresponding value at index 1 (a tuple with two members), or return nil to to skip adding a corresponding key-value pair to the returned dictionary.
 @return A dictionary containing the results of calling map with each of the receiving set’s members.
 */
- (nonnull NSDictionary *)dh_dictionaryByMappingObjectsUsingMap:(nonnull DHKeyValueMap)map;

@end

typedef BOOL (^DHFilterPredicate)(id __nonnull object);

@interface NSSet (DHExtendedSet)

/**
 Returns one of the objects in the set that passes the given test, or nil if the set contains no matching objects. Stops processing on finding a match.
 @param predicate The block to test the elements in the set, which returns a Boolean value that indicates whether the object passed the test.
 @return One of the objects in the set, or nil if the set contains no matching objects.
 */
- (nullable id)dh_anyObjectPassingTest:(nonnull DHFilterPredicate)predicate;

@end

@interface NSMutableSet (DHAdditions)

/**
 Removes and returns one of the objects in the set that passes the given test, or returns nil without modifying the set if it contains no matching objects.
 @param predicate The block to test the elements in the set, which returns a Boolean value that indicates whether the object passed the test.
 @return The object that was removed from the set, or nil if the set contains no matching objects.
 */
- (nullable id)dh_removeAnyObjectPassingTest:(nonnull DHFilterPredicate)predicate;

@end
