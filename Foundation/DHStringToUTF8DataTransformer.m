// Douglas Hill, August 2014
// https://github.com/douglashill/DHUtilities

#import "DHStringToUTF8DataTransformer.h"

@implementation DHStringToUTF8DataTransformer

+ (Class)transformedValueClass
{
	return [NSData class]; 
}

+ (BOOL)allowsReverseTransformation
{
	return YES;
}

- (NSData *)transformedValue:(NSString *)string
{
	return [string dataUsingEncoding:NSUTF8StringEncoding];
}

- (NSString *)reverseTransformedValue:(NSData *)data
{
	return [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
}

@end
