//
//  SJMogo.cpp
//  bounceBall
//
//  Created by 陈少杰 on 15/7/14.
//
//

#include "SJMogo.h"

MOGOAd::MOGOAd(){}
MOGOAd::~MOGOAd(){}

void MOGOAd::showBanner(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) //􏱜􏱝􏱞􏱟􏰤􏰥􏰌 Android 􏱠􏰵
    JniMethodInfo showBanner;
    bool isHave = JniHelper::getStaticMethodInfo(showBanner,"org/cocos2dx/cpp/AppActivity","showBannerStatic","()V");
    if (!isHave) {
        
    }else{
        showBanner.env->CallStaticVoidMethod(showBanner.classID, showBanner.methodID);
    }
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MOGOAdForIos::showBanner();
    #endif
}

void MOGOAd::hideBanner()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) //􏱜􏱝􏱞􏱟􏰤􏰥􏰌 Android 􏱠􏰵
    JniMethodInfo hideBanner;

    bool isHave = JniHelper::getStaticMethodInfo(hideBanner,"org/cocos2dx/cpp/AppActivity","hideBannerStatic","()V");
    if (!isHave) {
    }else{
        hideBanner.env->CallStaticVoidMethod(hideBanner.classID, hideBanner.methodID);
    }
    
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MOGOAdForIos::hideBanner();
#endif
}

void MOGOAd::showFullScreen(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) //
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MOGOAdForIos::showFullScreen();
#endif
}


void MOGOAd::hideFullScreen()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) //
    
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MOGOAdForIos::hideFullScreec();
#endif
}




void MOGOAd::showRank(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MOGOAdForIos::rankApp();
#endif
}

void MOGOAd::shareMe(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MOGOAdForIos::shareMe();
#endif
}