//
//  SJShareCenter.m
//  Yunpan
//
//  Created by 陈少杰 on 15/8/4.
//  Copyright (c) 2015年 陈少杰. All rights reserved.
//

#import "SJShareCenter.h"
#import <MobClick.h>
#import "config.h"

@implementation SJShareCenter

+(void)shareTo:(ShareType)shareType url:(NSString *)url content:(NSString *)cStr{
    [MobClick event:@"03-01"];
    NSString *titleStr=APPNAME;
    NSMutableString *contentStr=[NSMutableString stringWithString:cStr];
    NSString *urlStr=url;
    
    if (shareType==ShareTypeSinaWeibo) {
        [contentStr appendString:urlStr];
    }
    
    if (shareType==ShareTypeWeixiTimeline) {
        titleStr = contentStr;
    }
    
    id<ISSCAttachment> image=(shareType==ShareTypeWeixiSession||shareType== ShareTypeWeixiTimeline)?[ShareSDK imageWithPath:[[NSBundle mainBundle]pathForResource:@"AppIcon57x57@2x" ofType:@"png"]]:[ShareSDK imageWithPath:[[NSBundle mainBundle]pathForResource:@"AppIcon57x57@2x" ofType:@"png"]];
    
    id<ISSContent> content = [ShareSDK content:contentStr
                                defaultContent:contentStr
                                         image:image
                                         title:titleStr
                                           url:urlStr
                                   description:@""
                                     mediaType:SSPublishContentMediaTypeNews];
    [ShareSDK shareContent:content type:shareType authOptions:nil shareOptions:nil statusBarTips:NO result:^(ShareType type, SSResponseState state, id<ISSPlatformShareInfo> statusInfo, id<ICMErrorInfo> error, BOOL end){
        
        if (state==SSResponseStateSuccess) {
            [MobClick event:@"03-02"];
        }
//        else{
//            alert(error.errorDescription);
//        }
    }];
}
@end
