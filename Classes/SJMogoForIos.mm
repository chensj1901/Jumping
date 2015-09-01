//
//  SJMogoForIos.cpp
//  bounceBall
//
//  Created by 陈少杰 on 15/7/15.
//
//

#include "SJMogoForIos.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "SJAdsController.h"
#import <UIKit/UIKit.h>
#import "SJShareCenter.h"
#import "config.h"
#import <MobClick.h>
#import "SJButtonActionSheet.h"
#import <QQApi.h>
#import <WXApi.h>
#endif

MOGOAdForIos::MOGOAdForIos(){}
MOGOAdForIos::~MOGOAdForIos(){}

void MOGOAdForIos::showBanner(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) //􏱜􏱝􏱞􏱟􏰤􏰥􏰌 Android 􏱠􏰵
    [SJAdsController showAdsBanner];
#endif
}

void MOGOAdForIos::hideBanner()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) //􏱜􏱝􏱞􏱟􏰤􏰥􏰌 Android 􏱠􏰵
    [SJAdsController removeAdsBanner];
#endif
}


void MOGOAdForIos::showFullScreen(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) //􏱜􏱝􏱞􏱟􏰤􏰥􏰌 Android 􏱠􏰵
    [SJAdsController showAdsFullScreen];
#endif
}

void MOGOAdForIos::hideFullScreec()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) //􏱜􏱝􏱞􏱟􏰤􏰥􏰌 Android 􏱠􏰵
    [SJAdsController removeAdsFullScreen];
#endif
}


void MOGOAdForIos::rankApp()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) //􏱜􏱝􏱞􏱟􏰤􏰥􏰌 Android 􏱠􏰵
    [MobClick event:@"02-01"];
    NSString *str;
    if (([[[UIDevice currentDevice]systemVersion]doubleValue])>=7.0) {
        str=[NSString stringWithFormat: @"http://itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?id=%@&pageNumber=0&sortOrdering=2&type=Purple+Software&mt=8",APPLEID];
    }else{
        str = [NSString stringWithFormat: @"itms-apps://ax.itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?type=Purple+Software&id=%@",APPLEID];
    }
    
    [[UIApplication sharedApplication]openURL:[NSURL URLWithString:str]];
#endif
}



void MOGOAdForIos::shareMe(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) //
    NSString *appIndexURL;
    if (([[[UIDevice currentDevice]systemVersion]doubleValue])>=7.0) {
        appIndexURL = [NSString stringWithFormat:@"itms-apps://itunes.apple.com/app/id%@",APPLEID];
    } else {
        appIndexURL = [NSString stringWithFormat:@"itms-apps://ax.itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?type=Purple+Software&id=%@", APPLEID];
    }
    
    SJButtonActionSheet *actionSheet=[[SJButtonActionSheet alloc]initWithTitle:@""];
    
    [actionSheet addButtonWithTitle:@"复制链接" image:[UIImage imageNamed:@"更多_复制链接"] block:^{
        [MobClick event:@"02-03"];
        UIPasteboard *pb=[UIPasteboard generalPasteboard];
        [pb setString:appIndexURL];
    }];
    
    if ([WXApi isWXAppInstalled]) {
        [actionSheet addButtonWithTitle:@"微信好友" image:[UIImage imageNamed:@"更多_icon_微信"] block:^{
            [SJShareCenter shareTo:ShareTypeWeixiSession url:appIndexURL content:SHARE_DESC];
        }];
        
        [actionSheet addButtonWithTitle:@"朋友圈" image:[UIImage imageNamed:@"更多_icon_朋友圈"] block:^{
            [SJShareCenter shareTo:ShareTypeWeixiTimeline url:appIndexURL content:SHARE_DESC];
        }];
    }
    
    if ([QQApi isQQInstalled]) {
        [actionSheet addButtonWithTitle:@"QQ" image:[UIImage imageNamed:@"更多_icon_QQ空间"] block:^{
            [SJShareCenter shareTo:ShareTypeQQ url:appIndexURL content:SHARE_DESC];
        }];
    }
    
    [actionSheet showInView:nil];
#endif
}