//
//  MessageBubbleController.h
//  MessagingKit
//
//  GitHub
//  https://github.com/DevonBoyer/MessagingKit
//
//  Created by Devon Boyer on 2014-10-14.
//  Copyright (c) 2014 Devon Boyer. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MessagingCollectionView;

/**
 *  An instance of 'MessageBubbleController' is a convenience object for managing complex message bubble layouts.
 *  The logic is based on the idea of 'consecutive' message groups in which multiple messages are sent by the
 *  same sentByUserID consecutively.
 *
 * A 'MessageBubbleController' handles creation of message bubbles using the 'MessageBubbleFactory'.
 */
@interface MessageBubbleController : NSObject

/**
 *  The messaging collection view object currently using this message bubble controller.
 */
@property (weak, nonatomic, readonly) MessagingCollectionView *collectionView;

/**
 * Returns the color for incoming message bubbles.
 */
@property (strong, nonatomic) UIColor *incomingMessageBubbleColor;

/**
 * Returns the color for outgoing message bubbles.
 */
@property (strong, nonatomic) UIColor *outgoingMessageBubbleColor;

/**
 *  Initializes a 'MessageBubbleController' with the default message bubble colors and the passed 'MessagingCollectionView' that will utilize the message bubble controller. The 'MessagingCollectionView' utilizes the 'MessagingCollectionView' instance in order to access the appropriate dataSource and
 *  delegate methods needed to determine the appropriate message bubbles returned by messageBubbleForIndexPath:.
 *
 *  @param collectionView The messaging collection view that will utilize the 'MessageBubbleController'.
 *
 *  @discussion If not specified the default message bubble will be used instead.
 *
 *  @warning The collectionView cannot be 'nil' and must be an instance of a 'MessagingCollectionView'.
 *
 *  @see 'MessagingCollectionView'
 */
- (instancetype)initWithCollectionView:(MessagingCollectionView *)collectionView;

/**
 *  Initializes a 'MessageBubbleController' with the default message bubble colors and the passed 'MessagingCollectionView' that will utilize the message bubble controller. The 'MessagingCollectionView' utilizes the 'MessagingCollectionView' instance in order to access the appropriate dataSource and
 *  delegate methods needed to determine the appropriate message bubbles returned by messageBubbleForIndexPath:
 *
 *  @param collectionView The messaging collection view that will utilize the 'MessageBubbleController'.
 *  @param outgoingChatBubbleColor The color to use for outgoing message bubbles.
 *  @param incomingChatBubbleColor The color to use for incoming message bubbles.
 *
 *  @discussion If not specified the default message bubble will be used instead.
 *
 *  @warning The collectionView cannot be 'nil' and must be an instance of a 'MessagingCollectionView'.
 *
 *  @see 'MessagingCollectionView'
 */
- (instancetype)initWithCollectionView:(MessagingCollectionView *)collectionView outgoingBubbleColor:(UIColor *)outgoingChatBubbleColor incomingBubbleColor:(UIColor *)incomingChatBubbleColor;

/**
 *  Creates and configures a message bubble that will be used for the bottom message in a consecutive group
 *  of messages with the same sentByUserID.
 *
 *  @param templateImage The image to use as a template.
 *
 *  @discussion If not specified the default message bubble will be used instead.
 *
 *  @warning The templateImage must not be 'nil'.
 */
- (void)setBottomTemplateForConsecutiveGroup:(UIImage *)templateImage;

/**
 *  Creates and configures a message bubble that will be used for messages in the middle of a consecutive group
 *  of messages with the same sentByUserID.
 *
 *  @param templateImage The image to use as a template .
 *
 *  @discussion If not specified the default message bubble will be used instead.
 *
 *  @warning The templateImage must not be 'nil'.
 */
- (void)setMiddleTemplateForConsecutiveGroup:(UIImage *)templateImage;

/**
 *  Creates and configures a message bubble that will be used for the top message in a consecutive group
 *  of messages with the same sentByUserID.
 *
 *  @param templateImage The image to use as a template .
 *
 *  @discussion If not specified the default message bubble will be used instead.
 *
 *  @warning The templateImage must not be 'nil'.
 */
- (void)setTopTemplateForConsecutiveGroup:(UIImage *)templateImage;

/**
 *  Creates and configures the default message bubble to use in for messages that are not part of a consecutive
 *  group or where a more specific message bubble has not been specified.
 *
 *  @param templateImage The image to use as a template .
 *
 *  @discussion If not specified the default message bubble will be used instead.
 *
 *  @warning The templateImage must not be 'nil'. The default message bubble must not be 'nil'.
 */
- (void)setDefaultTemplate:(UIImage *)templateImage;

/**
 *  Returns the appropriate message bubble for the given indexPath.
 *
 *  @param indexPath The index path that specifies the location of the item.
 *
 *  @return A configured message bubble for the given indexPath.
 */
- (UIImageView *)messageBubbleForIndexPath:(NSIndexPath *)indexPath;

/**
 *  Begins a consecutive group at the specified indexPath.
 */
- (void)beginMessageGroupAtIndexPath:(NSIndexPath *)indexPath;

@end
