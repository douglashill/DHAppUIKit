// Douglas Hill, October 2014
// https://github.com/douglashill/DHUtilities

@import Foundation;

/**
 @brief DHCompositeTransformer is an abstract class that chains an ordered collection of other value transformers.
 */
@interface DHCompositeTransformer : NSValueTransformer

/**
 @brief Returns the classes of an instance’s sub-transformers.
 Subclasses must override this method without calling super.
 @return An array of class objects which are subclasses of NSValueTransformer.
 */
+ (nonnull NSArray *)transformerClasses;

/**
 @brief Initialises a composite transformer with an array of value transformers.
 This is the designated initialiser.
 @param transformers An array of NSValueTransformer subclasses whose classes correspond to the classes returned by the class method transformerClasses. This may be nil if all the sub-transformers may be initialised with init or new.
 @return An initialised composite transformer.
 */
- (nonnull instancetype)initWithTransformers:(nullable NSArray *)transformers;

/**
 @brief The sub-transformers which form a chain used to transform values.
 */
@property (nonatomic, nonnull, copy, readonly) NSArray *transformers;

@end
