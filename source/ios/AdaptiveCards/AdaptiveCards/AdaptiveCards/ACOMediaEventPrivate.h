//
//  ACOMediaEventPrivate.h
//  ACOMediaEventPrivate
//
//  Copyright © 2018 Microsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACOMediaEvent.h"
#import "SharedAdaptiveCard.h"
#import "Media.h"
#import "MediaSource.h"

using namespace AdaptiveCards;

@interface ACOMediaSource()

- (instancetype)initWithMediaSource:(std::shared_ptr<MediaSource> const &)mediaSource;

@end

@interface ACOMediaEvent()

- (instancetype)initWithMedia:(std::shared_ptr<Media> const &)media;

@end
