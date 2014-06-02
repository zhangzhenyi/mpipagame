//
//  LoadScene.cpp
//  mpipagame
//
//  Created by 卢珺 on 14-5-19.
//
//

#include "LoadScene.h"
#include "Resource.h"
#include "MainScene.h"
#include "VisibleRect.h"

bool LoadScene:: init(){
    if(!CCLayer::init()){
        return false;
    }
    
    CCProgressTo* progressAction = CCProgressTo::create(2, 100);
    
    progressBar = CCProgressTimer::create(CCSprite::create(LOAD_BAR_IMG));
    progressBar->setPosition(VisibleRect::center());
//    progressBar->setMidpoint(<#cocos2d::CCPoint var#>)
    progressBar->setType(kCCProgressTimerTypeBar);
    //    Setup for a bar starting from the left since the midpoint is 0 for the x
    progressBar->setMidpoint(ccp(0,0));
    //    Setup for a horizontal bar since the bar change rate is 0 for y meaning no vertical change
    progressBar->setBarChangeRate(ccp(1, 0));
    addChild(progressBar);

    progressBar->runAction(progressAction);
    
    this->schedule(schedule_selector(LoadScene::tick), 0.2f);
    return true;
}

CCScene* LoadScene::getScene(){
    CCScene* scene = CCScene::create();
    
    CCLayer* layer = LoadScene::create();
    scene->addChild(layer);
    
    return scene;
}

void LoadScene::tick(float delt){
    CCLog("current percent %f ", progressBar->getPercentage());
    
    if(progressBar->getPercentage() >= 100){
        CCScene* scene = MainScene::create();
        CCTransitionShrinkGrow* transition = CCTransitionShrinkGrow::create(0.6f, scene);
        CCDirector::sharedDirector()->replaceScene(transition);
    }
}

