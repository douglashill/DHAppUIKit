// Douglas Hill, February 2014
// https://github.com/douglashill/DHUtilities

@import Foundation;

@interface NSDictionary (DHJSONReading)

/**
 Returns the string associated with a given key.
 @param key The key for which to return the corresponding string.
 @return The string associated with key, or nil if no value is associated with key or the value associated with key is not a string.
 */
- (nullable NSString *)dh_stringForKey:(nonnull NSString *)key;

/**
 Returns the number associated with a given key.
 @param key The key for which to return the corresponding number.
 @return The number associated with key, or nil if no value is associated with key or the value associated with key is not a number.
 */
- (nullable NSNumber *)dh_numberForKey:(nonnull NSString *)key;

/**
 Returns the array associated with a given key.
 @param key The key for which to return the corresponding array.
 @return The array associated with key, or nil if no value is associated with key or the value associated with key is not a array.
 */
- (nullable NSArray *)dh_arrayForKey:(nonnull NSString *)key;

/**
 Returns the dictionary associated with a given key.
 @param key The key for which to return the corresponding dictionary.
 @return The dictionary associated with key, or nil if no value is associated with key or the value associated with key is not a dictionary.
 */
- (nullable NSDictionary *)dh_dictionaryForKey:(nonnull NSString *)key;

/**
 Returns the NSNull object if it is associated with a given key.
 @param key The key to check for NSNull.
 @return The NSNull object if it is associated with key, or nil if no value is associated with key or the value associated with key is not the NSNull object.
 */
- (nullable NSNull *)dh_nullForKey:(nonnull NSString *)key;

@end
