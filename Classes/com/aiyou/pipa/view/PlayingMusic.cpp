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
    SoundManager::sharedManager()->initMusicTune(90);
    inteval = CCDirector::sharedDirector()->getAnimationInterval();
    intevalTimePerBeat = (float)60/90;
    
    
    currYuepu = YuepuManager::sharedManager()->getYuepuByName(MUSIC_1_NAME);
    
    stringBtn1 = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(PlayingMusic::onNoteClicked));
    stringBtn1->setPosition(ccp(100, 200));
    stringBtn1->setOpacity(125);
    stringBtn2 = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(PlayingMusic::onNoteClicked));
    stringBtn2->setPosition(ccp(200, 200));
    stringBtn2->setOpacity(125);
    stringBtn3 = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(PlayingMusic::onNoteClicked));
    stringBtn3->setPosition(ccp(300, 200));
    stringBtn3->setOpacity(125);
    stringBtn4 = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(PlayingMusic::onNoteClicked));
    stringBtn4->setPosition(ccp(400, 200));
    stringBtn4->setOpacity(125);
    
    CCArray* imgArr = CCArray::create();
    imgArr->addObject(stringBtn1);
    imgArr->addObject(stringBtn2);
    imgArr->addObject(stringBtn3);
    imgArr->addObject(stringBtn4);
    CCMenu* highlightMenu = CCMenu::createWithArray(imgArr);
    highlightMenu->setAnchorPoint(CCPointZero);
    highlightMenu->setPosition(CCPointZero);
    
    this->addChild(highlightMenu);
    
    this->schedule(schedule_selector(PlayingMusic::onScheduleTick), inteval);
    return true;
    
}

void PlayingMusic::onScheduleTick(float dlet){
    //show music tone;
//    SoundManager::sharedManager()
    //Play sound with 4 strings, only for testing
    if(intervalSound <= 0) {
        mnote = getNextNote();
        if(mnote){
            CCLog("mnote %s", mnote->getSkill().c_str());
            float noteNum = mnote->getNote();
            intervalSound = intevalTimePerBeat* noteNum /(1*inteval);
            CCLog("intervalSound is %d", intervalSound);
            //Play note
            CCArray* scales = mnote->getScales();
            if(scales && scales->count() > 0){
                int hIndex = mnote->getHandler();
                float note = mnote->getNote();
                CCObject* pElement;
                CCARRAY_FOREACH(scales, pElement){
                    MusicScale* scale = (MusicScale*)pElement;
                    
                    if(scale){
                        //Play the note
                        int strIndex = scale->getStrINdex();
                        string scaleIndex = scale->getScale();
                        //TODO, 播放时需要考虑把位，同样的音符，声音不一样
                        SoundManager::sharedManager()->playEffect(bNoteTypeDef, strIndex, hIndex, scaleIndex, note);
                    }
                }
                
            }
        }else{
            //play all notes, show animation and return TODO-----------
            this->unschedule(schedule_selector(PlayingMusic::onScheduleTick));
            return;
        }
    }else{
        intervalSound --;
    }
    
    
}

MusicNote* PlayingMusic::getNextNote(){
    if(!currYuepu) return NULL;
    if(noteIndex < currYuepu->getContent()->count()){
        MusicNote* mnote = dynamic_cast<MusicNote* >(currYuepu->getContent()->objectAtIndex(noteIndex));
        noteIndex++;
        return mnote;
    }
    
    return NULL;
    
}

CCScene* PlayingMusic::getScene(){
    CCScene* scene = CCScene::create();
    
    CCLayer* layer = PlayingMusic::create();
    scene->addChild(layer);
    
    return scene;

}

void PlayingMusic::onNoteClicked(CCObject* pSender){
    intervalSound=120;
    noteIndex =0;
    CCLog("onNoteClicked clicked");
//    this->unschedule(schedule_selector(PlayingMusic::onScheduleTick));
    this->schedule(schedule_selector(PlayingMusic::onScheduleTick), inteval);
}