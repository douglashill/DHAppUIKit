//
//  NSDictionary+DHAdditions.h
//  Douglas Hill, February 2014
//  https://github.com/douglashill/Objective-C-utilities
//

#import <Foundation/Foundation.h>

@interface NSDictionary (DHJSONReading)

- (NSString *)stringForKey:(NSString *)key;
- (NSNumber *)numberForKey:(NSString *)key;
- (NSArray *)arrayForKey:(NSString *)key;
- (NSDictionary *)dictionaryForKey:(NSString *)key;
- (NSNull *)nullForKey:(NSString *)key;

@end
