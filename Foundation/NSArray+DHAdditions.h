// Douglas Hill, February 2015
// https://github.com/douglashill/DHUtilities

@import Foundation;

#import "DHMap.h"

@interface NSArray (DHMap)

- (nonnull NSArray *)dh_arrayByMappingObjectsUsingMap:(nonnull DHObjectMap)map;

- (nonnull NSDictionary *)dh_dictionaryByMappingObjectsUsingMap:(nonnull DHKeyValueMap)map;

@end

typedef BOOL (^DHIndexedCollectionFilterPredicate)(id __nonnull object, NSUInteger idx, BOOL *__nonnull stop);

@interface NSArray (DHExtendedArray)

- (nonnull NSArray *)dh_objectsPassingTest:(nonnull DHIndexedCollectionFilterPredicate)predicate;
- (nullable id)dh_objectPassingTest:(nonnull DHIndexedCollectionFilterPredicate)predicate;

@end
