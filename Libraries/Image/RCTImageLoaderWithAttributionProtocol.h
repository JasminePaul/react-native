/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

#import <React/RCTImageLoaderProtocol.h>
#import <React/RCTImageURLLoaderWithAttribution.h>

RCT_EXTERN BOOL RCTImageLoadingInstrumentationEnabled(void);
RCT_EXTERN BOOL RCTImageLoadingPerfInstrumentationEnabled(void);
RCT_EXTERN void RCTEnableImageLoadingInstrumentation(BOOL enabled);
RCT_EXTERN void RCTEnableImageLoadingPerfInstrumentation(BOOL enabled);

@protocol RCTImageLoaderWithAttributionProtocol<RCTImageLoaderProtocol>

/**
 * Same as the variant in RCTImageURLLoaderProtocol, but allows passing attribution
 * information that each image URL loader can process.
 */
- (RCTImageURLLoaderRequest *)loadImageWithURLRequest:(NSURLRequest *)imageURLRequest
                                                 size:(CGSize)size
                                                scale:(CGFloat)scale
                                              clipped:(BOOL)clipped
                                           resizeMode:(RCTResizeMode)resizeMode
                                          attribution:(const facebook::react::ImageURLLoaderAttribution &)attribution
                                        progressBlock:(RCTImageLoaderProgressBlock)progressBlock
                                     partialLoadBlock:(RCTImageLoaderPartialLoadBlock)partialLoadBlock
                                      completionBlock:(RCTImageLoaderCompletionBlock)completionBlock;
/**
 * Image instrumentation - notify that the image content (UIImage) has been set on the native view.
 */
- (void)trackURLImageContentDidSetForRequest:(RCTImageURLLoaderRequest *)loaderRequest;

/**
 * Image instrumentation - start tracking the on-screen visibility of the native image view.
 */
- (void)trackURLImageVisibilityForRequest:(RCTImageURLLoaderRequest *)loaderRequest imageView:(UIView *)imageView;

/**
 * Image instrumentation - notify that the native image view was destroyed.
 */
- (void)trackURLImageDidDestroy:(RCTImageURLLoaderRequest *)loaderRequest;

@end
