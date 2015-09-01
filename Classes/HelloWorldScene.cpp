#include "HelloWorldScene.h"
#include <cocos/ui/UIWebView.h>
#include "config.h"
#include "SJMogo.h"

USING_NS_CC;
using namespace experimental::ui;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    std::string path=FileUtils::getInstance()->getWritablePath();
    path+="ip.recode";
    String *s=String::createWithContentsOfFile(path);
//    CCLog("%@",s);
    WebView *_webView = WebView::create();
    _webView->setPosition(Vec2(WIDTH/2,HEIGHT/2));
    _webView->setContentSize(Size(WIDTH,HEIGHT));
//
    _webView->loadURL(s->getCString());
    _webView->setScalesPageToFit(true);
    _webView->setOnDidFinishLoading([](WebView *sender, const std::string &url){
        float width,height;
        if (WIDTH==2048) {
            width=1024;
            height=768;
        }else{
            width=WIDTH;
            height=HEIGHT;
        }
        String *s=String::createWithFormat("window.width=%f,window.height=%f",width,height);
        sender->evaluateJS(s->getCString());
    });
    _webView->setOnDidFailLoading([](WebView *sender, const std::string &url){
        CCLog("%s",url.c_str());
    });
    _webView->setOnShouldStartLoading([](WebView *sender, const std::string &url){
        int index=url.find("htsg://rankme");
        if (index>-1) {
            MOGOAd::showRank();
            return false;
        }
        index=url.find("htsg://home");
        if (index>-1) {
            sender->loadFile("res/index.html");
            return false;
        }
        index=url.find("htsg://shareme");
        if (index>-1) {
            MOGOAd::shareMe();
            return false;
        }
        
        index=url.find("htsg://showFullScreen");
        if (index>-1) {
            MOGOAd::showFullScreen();
            return false;
        }
        return true;
    });


    this->addChild(_webView,5);
    
//    auto layer=LayerColor::create(ccc4(128, 183, 180, 255));
//    layer->setTag(888);
//    this->addChild(layer,10);
    
    
    MOGOAd::showFullScreen();
    return true;
}

void HelloWorld::finishLoaded(){
//    this->getChildByTag(888)->removeFromParent();
}

//void HelloWorld::menuCloseCallback(Ref* pSender)
//{
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//}
