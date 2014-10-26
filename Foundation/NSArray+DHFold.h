// Douglas Hill, August 2014
// https://github.com/douglashill/Objective-C-bits-and-bobs

@import Foundation;

@interface NSArray (DHFold)

- (id)dh_foldWithInitialValue:(id)initialValue options:(NSEnumerationOptions)options usingBlock:(id (^)(id obj, id value))function;

@end
