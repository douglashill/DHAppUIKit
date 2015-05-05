// Douglas Hill, April 2015
// https://github.com/douglashill/DHAppUIKit

@import Foundation;

@interface NSIndexPath (DHUnsigned)

/**
 @brief Returns an index-path object initialised with the indexes of a specific item and section in a collection view.
 @param item An index number identifying an item in a UICollectionView object in a section identified by the section parameter.
 @param section An index number identifying a section in a UICollectionView object.
 @return An NSIndexPath object or nil if the object could not be created.
 */
+ (NSIndexPath *)dh_indexPathForItem:(NSUInteger)item inSection:(NSUInteger)section;

/**
 @brief Returns an index-path object initialised with the indexes of a specific row and section in a table view.
 @param row	An index number identifying a row in a UITableView object in a section identified by section.
 @param section An index number identifying a section in a UITableView object.
 @return An NSIndexPath object or nil if the object could not be created.
 */
+ (NSIndexPath *)dh_indexPathForRow:(NSUInteger)row inSection:(NSUInteger)section;

/**
 @brief An index number identifying a section in a table view or collection view. (read-only)
 */
@property (nonatomic, readonly) NSUInteger dh_section;

/**
 @brief An index number identifying an item in a section of a collection view. (read-only)
 The section the item is in is identified by the value of section.
 */
@property (nonatomic, readonly) NSUInteger dh_item;

/**
 @brief An index number identifying a row in a section of a table view. (read-only)
 The section the row is in is identified by the value of section.
 */
@property (nonatomic, readonly) NSUInteger dh_row;

@end
