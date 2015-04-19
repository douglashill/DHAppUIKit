// Douglas Hill, February 2015
// https://github.com/douglashill/DHUtilities

@import Foundation;

@interface NSArray (DHMap)

- (NSArray *)dh_arrayByMappingObjectsUsingMap:(id (^)(id object))map;

- (NSDictionary *)dh_dictionaryByMappingObjectsUsingMap:(NSArray *(^)(id object))map;

@end

@interface NSArray (DHExtendedArray)

- (NSArray *)dh_objectsPassingTest:(BOOL (^)(id object, NSUInteger idx, BOOL *stop))predicate;
- (id)dh_firstObjectPassingTest:(BOOL (^)(id, NSUInteger))predicate;
- (NSUInteger)dh_indexOfFirstObjectPassingTest:(BOOL (^)(id, NSUInteger))predicate;

@end
