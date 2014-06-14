//
//  PlayingMusic.cpp
//  mpipagame
//
//  Created by 卢珺 on 14-5-19.
//
//

#include "PlayingMusic.h"

#include "../yuepu/SoundManager.h"

bool PlayingMusic::init(){
    if(!CCLayer::init()){
        return false;
    }
    SoundManager::sharedManager()->initMusicTune(62);
    double inteval = CCDirector::sharedDirector()->getAnimationInterval();
    this->schedule(schedule_selector(PlayingMusic::onScheduleTick), inteval);
    
    currYuepu = YuepuManager::sharedManager()->getYuepuByName(MUSIC_1_NAME);
    return true;
    
}

void PlayingMusic::onScheduleTick(float dlet){
    //show music tone;
//    SoundManager::sharedManager()
    //Play sound with 4 strings, only for testing
    if(intervalSound <= 0) intervalSound = 10;
    intervalSound --;
    
    if(intervalSound ==0 ){
        //Play a random scale
        float r = CCRANDOM_0_1();
//        int ss = (int)(r*5);//note
        int hIndex = r*4 +1;
        float r1 = CCRANDOM_0_1();
        int strIndex = r1*4 +1;
        
        CCArray* array = CCArray::create();
        array->addObject(CCString::create("1"));
        array->addObject(CCString::create("2"));
        array->addObject(CCString::create("3"));
        array->addObject(CCString::create("4"));
        array->addObject(CCString::create("5"));
        array->addObject(CCString::create("6"));
        array->addObject(CCString::create("7"));
        array->addObject(CCString::create("1,"));
        array->addObject(CCString::create("2,"));
        array->addObject(CCString::create("3,"));
        array->addObject(CCString::create("4,"));
        array->addObject(CCString::create("5,"));
        array->addObject(CCString::create("6,"));
        array->addObject(CCString::create("7,"));
        array->addObject(CCString::create("1."));
        array->addObject(CCString::create("2."));
        array->addObject(CCString::create("3."));
        array->addObject(CCString::create("4."));
        array->addObject(CCString::create("5."));
        array->addObject(CCString::create("6."));
        array->addObject(CCString::create("7."));
        CCString* scaleId = (CCString*)array->randomObject();
        string scaleIndex = scaleId->m_sString;
        
        
        MusicNote* mnote = getNextNote();
        if(mnote){
            CCLog("mnote %s", mnote->getSkill().c_str());
        }
        
        
        SoundManager::sharedManager()->playEffect(bNoteTypeDef, strIndex, hIndex, scaleIndex, 1);
        
    }
    
}

MusicNote* PlayingMusic::getNextNote(){
    if(!currYuepu) return NULL;
    if(noteIndex < currYuepu->getContent()->count()){
        MusicNote* mnote = dynamic_cast<MusicNote* >(currYuepu->getContent()->objectAtIndex(noteIndex));
        return mnote;
    }
    
    
    noteIndex++;
}

CCScene* PlayingMusic::getScene(){
    CCScene* scene = CCScene::create();
    
    CCLayer* layer = PlayingMusic::create();
    scene->addChild(layer);
    
    return scene;

}