// Douglas Hill, February 2014
// https://github.com/douglashill/DHUtilities

#import "NSDictionary+DHJSONReading.h"

@implementation NSDictionary (DHJSONReading)

- (nullable NSString *)dh_stringForKey:(nonnull NSString *)key
{
	return [self dh_objectForKey:key ofClass:[NSString class]];
}

- (nullable NSNumber *)dh_numberForKey:(nonnull NSString *)key;
{
	return [self dh_objectForKey:key ofClass:[NSNumber class]];
}

- (nullable NSArray *)dh_arrayForKey:(nonnull NSString *)key;
{
	return [self dh_objectForKey:key ofClass:[NSArray class]];
}

- (nullable NSDictionary *)dh_dictionaryForKey:(nonnull NSString *)key;
{
	return [self dh_objectForKey:key ofClass:[NSDictionary class]];
}

- (nullable NSNull *)dh_nullForKey:(nonnull NSString *)key;
{
	return [self dh_objectForKey:key ofClass:[NSNull class]];
}

- (nullable id)dh_objectForKey:(nonnull NSString *)key ofClass:(nonnull Class)class
{
	if ([self[key] isKindOfClass:class] == NO) {
		return nil;
	}
	
	return self[key];
}

@end
