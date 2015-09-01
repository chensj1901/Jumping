//
//  SJMogo.h
//  bounceBall
//
//  Created by 陈少杰 on 15/7/14.
//
//

#ifndef __bounceBall__SJMogo__
#define __bounceBall__SJMogo__

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "SJMogoForIos.h"
#endif

#include "SJShareTypeDef.h"

using namespace cocos2d;
class MOGOAd
{
public:
    MOGOAd();
    virtual ~MOGOAd();
    static void showBanner();//
    static void hideBanner();//
    static void showFullScreen();//
    static void hideFullScreen();//
    static void showRank();
    static void shareMe();
};
#endif 

/* defined(__bounceBall__SJMogo__) */
