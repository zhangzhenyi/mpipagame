//
//  MainScene.cpp
//  mpipagame
//
//  Created by 卢珺 on 14-5-19.
//
//

#include "MainScene.h"
#include "PlayingMusic.h"

#include "Resource.h"

#include "VisibleRect.h"

bool MainScene::init(){
    if(!CCScene::init())
    {
        return false;
    }
    
    CCMenuItemFont* startMenuItem = CCMenuItemFont::create("Play game");
    startMenuItem->setPosition(VisibleRect::center());
    startMenuItem->setTarget(this, menu_selector(MainScene::callbackMenuSelected));
    CCMenu* menu = CCMenu::create(startMenuItem, NULL);
    
    menu->setAnchorPoint(CCPointZero);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    
    return true;
}

void MainScene::callbackMenuSelected(CCObject* pSender){
    CCScene* scene = PlayingMusic::getScene();
    const ccColor3B color2b = {125, 125,125};
    CCTransitionFade* fadeTransition = CCTransitionFade::create(0.5f, scene, color2b);
    CCDirector::sharedDirector()->replaceScene(fadeTransition);
}