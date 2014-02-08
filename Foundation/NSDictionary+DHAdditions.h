//
//  NSDictionary+DHAdditions.h
//  Douglas Hill, February 2014
//  https://github.com/douglashill/Objective-C-utilities
//

#import <Foundation/Foundation.h>

@interface NSDictionary (DHJSONReading)

- (NSString *)dh_stringForKey:(NSString *)key;
- (NSNumber *)dh_numberForKey:(NSString *)key;
- (NSArray *)dh_arrayForKey:(NSString *)key;
- (NSDictionary *)dh_dictionaryForKey:(NSString *)key;
- (NSNull *)dh_nullForKey:(NSString *)key;

@end
