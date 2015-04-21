// Douglas Hill, August 2014
// https://github.com/douglashill/DHUtilities

@import Foundation;

@interface NSArray (DHFold)

/**
 @brief Returns an object obtained by running a given block for each object in the array, where the results of each application of the block is input for the next. This operation is also know as accumulate or reduce.
 @param initialValue The object to pass as value for the first application of the block.
 @param options      A bitmask specifiying enumeration options, which may be used to reverse the order. (This is sometimes called a right fold rather than a left fold.) Concurrent enumeration is not supported, and an exception is raised if that option is specified.
 @param function     The block to apply to each object in the array.
 @return The object returned by the block when applied to the last object in the array, or initialValue if the array is empty.
 */
- (id)dh_foldWithInitialValue:(id)initialValue options:(NSEnumerationOptions)options usingBlock:(id (^)(id obj, id value))function;

@end
