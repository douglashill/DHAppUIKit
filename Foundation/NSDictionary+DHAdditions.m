//
//  NSDictionary+DHAdditions.m
//  Douglas Hill, February 2014
//  https://github.com/douglashill/Objective-C-utilities
//

#import "NSDictionary+DHAdditions.h"

@implementation NSDictionary (DHJSONReading)

- (NSString *)stringForKey:(NSString *)key
{
	return [self objectForKey:key ofClass:[NSString class]];
}

- (NSNumber *)numberForKey:(NSString *)key;
{
	return [self objectForKey:key ofClass:[NSNumber class]];
}

- (NSArray *)arrayForKey:(NSString *)key;
{
	return [self objectForKey:key ofClass:[NSArray class]];
}

- (NSDictionary *)dictionaryForKey:(NSString *)key;
{
	return [self objectForKey:key ofClass:[NSDictionary class]];
}

- (NSNull *)nullForKey:(NSString *)key;
{
	return [self objectForKey:key ofClass:[NSNull class]];
}

- (id)objectForKey:(NSString *)key ofClass:(Class)class
{
	if ([self[key] isKindOfClass:class] == NO) {
		return nil;
	}
	
	return self[key];
}

@end
