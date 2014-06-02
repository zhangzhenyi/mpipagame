//
//  PlayingMusic.cpp
//  mpipagame
//
//  Created by 卢珺 on 14-5-19.
//
//

#include "PlayingMusic.h"

bool PlayingMusic::init(){
    if(!CCLayer::init()){
        return false;
    }
    SoundManager* manager = SoundManager::sharedManager();
    
    return true;
    
}

CCScene* getScene(){
    CCScene* scene = CCScene::create();
    
    CCLayer* layer = PlayingMusic::create();
    scene->addChild(layer);
    
    return scene;

}