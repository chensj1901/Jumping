//
//  SJMogoForIos.h
//  bounceBall
//
//  Created by 陈少杰 on 15/7/15.
//
//

#ifndef __bounceBall__SJMogoForIos__
#define __bounceBall__SJMogoForIos__

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>
#endif

#include "SJShareTypeDef.h"


using namespace cocos2d;
class MOGOAdForIos
{
public:
    MOGOAdForIos();
    virtual ~MOGOAdForIos();
    static void showBanner();//
    static void hideBanner();//
    static void showFullScreen();//
    static void hideFullScreec();//
    static void rankApp();
    static void shareMe();
};
#endif /* defined(__bounceBall__SJMogoForIos__) */
