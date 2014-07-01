#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
    
    //TODO set auto suit for screen size
    //自适应尺寸
    CCSize screenSize=pEGLView->getFrameSize();
    CCSize designSize = CCSizeMake(768,1366);
	CCSize frameSize = pDirector->getWinSize();
    
	float scaleX = (float)frameSize.width/designSize.width;
    float scaleY = (float)frameSize.height/designSize.height;
    float scale = 0.0f;
    if(scaleX > scaleY){
	    scale = scaleX/(frameSize.height/(float)designSize.height);
    }else{
	    scale = scaleY/(frameSize.width/(float)designSize.width);
    }
    
    pEGLView->setDesignResolutionSize(designSize.width * scale,
                                      designSize.height * scale, kResolutionNoBorder);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = HelloWorld::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
