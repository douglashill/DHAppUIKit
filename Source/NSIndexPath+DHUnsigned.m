// Douglas Hill, April 2015
// https://github.com/douglashill/DHAppUIKit

#import "NSIndexPath+DHUnsigned.h"

@import DHFoundation.DHIntegerConversion;
@import UIKit.UICollectionView;
@import UIKit.UITableView;

@implementation NSIndexPath (DHUnsigned)

+ (NSIndexPath *)dh_indexPathForItem:(NSUInteger)item inSection:(NSUInteger)section
{
	return [self indexPathForItem:sign(item) inSection:sign(section)];
}

+ (NSIndexPath *)dh_indexPathForRow:(NSUInteger)row inSection:(NSUInteger)section
{
	return [self indexPathForRow:sign(row) inSection:sign(section)];
}

- (NSUInteger)dh_section
{
	return unsign([self section]);
}

- (NSUInteger)dh_item
{
	return unsign([self item]);
}

- (NSUInteger)dh_row
{
	return unsign([self row]);
}

@end
