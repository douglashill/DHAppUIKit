// Douglas Hill, February 2014
// https://github.com/douglashill/DHUtilities

@import Foundation;

@interface NSDictionary (DHJSONReading)

- (nullable NSString *)dh_stringForKey:(nonnull NSString *)key;
- (nullable NSNumber *)dh_numberForKey:(nonnull NSString *)key;
- (nullable NSArray *)dh_arrayForKey:(nonnull NSString *)key;
- (nullable NSDictionary *)dh_dictionaryForKey:(nonnull NSString *)key;
- (nullable NSNull *)dh_nullForKey:(nonnull NSString *)key;

@end
