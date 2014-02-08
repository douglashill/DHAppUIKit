//
//  NSDictionary+DHAdditions.m
//  Douglas Hill, February 2014
//  https://github.com/douglashill/Objective-C-utilities
//

#import "NSDictionary+DHAdditions.h"

@implementation NSDictionary (DHJSONReading)

- (NSString *)dh_stringForKey:(NSString *)key
{
	return [self dh_objectForKey:key ofClass:[NSString class]];
}

- (NSNumber *)dh_numberForKey:(NSString *)key;
{
	return [self dh_objectForKey:key ofClass:[NSNumber class]];
}

- (NSArray *)dh_arrayForKey:(NSString *)key;
{
	return [self dh_objectForKey:key ofClass:[NSArray class]];
}

- (NSDictionary *)dh_dictionaryForKey:(NSString *)key;
{
	return [self dh_objectForKey:key ofClass:[NSDictionary class]];
}

- (NSNull *)dh_nullForKey:(NSString *)key;
{
	return [self dh_objectForKey:key ofClass:[NSNull class]];
}

- (id)dh_objectForKey:(NSString *)key ofClass:(Class)class
{
	if ([self[key] isKindOfClass:class] == NO) {
		return nil;
	}
	
	return self[key];
}

@end
