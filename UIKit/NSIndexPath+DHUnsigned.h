// Douglas Hill, April 2015
// https://github.com/douglashill/DHUtilities

@import Foundation;

@interface NSIndexPath (DHUnsigned)

+ (NSIndexPath *)dh_indexPathForItem:(NSUInteger)item inSection:(NSUInteger)section;
+ (NSIndexPath *)dh_indexPathForRow:(NSUInteger)row inSection:(NSUInteger)section;

@property (nonatomic, readonly) NSUInteger dh_section;
@property (nonatomic, readonly) NSUInteger dh_item;
@property (nonatomic, readonly) NSUInteger dh_row;

@end
