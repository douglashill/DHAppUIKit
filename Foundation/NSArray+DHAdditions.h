// Douglas Hill, February 2015
// https://github.com/douglashill/DHUtilities

@import Foundation;

#import "DHMap.h"

@interface NSArray (DHMap)

/**
 Returns an array containing the results of calling map with each of the receiving array’s objects.
 @param map The block that maps from an object in the receiving array to an object to be included in the returned array. The block may return nil to skip adding a corresponding object to the returned array.
 @return An array containing the results of calling map with each of the receiving array’s objects.
 */
- (nonnull NSArray *)dh_arrayByMappingObjectsUsingMap:(nonnull DHObjectMap)map;

/**
 Returns a dictionary containing the results of calling map with each of the receiving array’s objects.
 @param map The block that maps from an object in the receiving array to a keys-value pair to be included in the returned dictionary. The block must return either an array containing a key for the dictionary at index 0 and and the corresponding value at index 1 (a tuple with two members), or return nil to to skip adding a corresponding key-value pair to the returned dictionary.
 @return A dictionary containing the results of calling map with each of the receiving array’s objects.
 */
- (nonnull NSDictionary *)dh_dictionaryByMappingObjectsUsingMap:(nonnull DHKeyValueMap)map;

@end

typedef BOOL (^DHIndexedCollectionFilterPredicate)(id __nonnull object, NSUInteger idx, BOOL *__nonnull stop);

@interface NSArray (DHExtendedArray)

/**
 @brief Returns an array containing the objects in the receiving array that pass a test in a given block.
 The returned objects are in the same order that they appear in the receiving array.
 @param predicate The block to test the elements in the array, which returns YES if the object argument passes the test; otherwise NO.
 @return An array containing the objects in the receiving array that pass the test, which will be empty if no objects pass the test.
 */
- (nonnull NSArray *)dh_objectsPassingTest:(nonnull DHIndexedCollectionFilterPredicate)predicate;

/**
 Returns the first object in the array that passes a test in a given block.
 @param predicate The block to test the elements in the array, which returns YES if the object argument passes the test; otherwise NO.
 @return The object with the lowest index in the array that passes the test, or nil if no objects in the array pass the test.
 */
- (nullable id)dh_objectPassingTest:(nonnull DHIndexedCollectionFilterPredicate)predicate;

@end
