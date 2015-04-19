// Douglas Hill, April 2015
// https://github.com/douglashill/DHUtilities

@import Foundation;

static inline NSUInteger unsign(NSInteger value)
{
	if (value < 0) [NSException raise:NSRangeException format:@"The signed integer, %ld, is negative, so can not be converted to an unsigned integer.", (long)value];
	return (NSUInteger)value;
}

static inline NSInteger sign(NSUInteger value)
{
	if (value > NSIntegerMax) [NSException raise:NSRangeException format:@"The unsigned integer, %lu, is greater than the largest signed integer, so can not be converted to a signed integer.", (unsigned long)value];
	return (NSInteger)value;
}
