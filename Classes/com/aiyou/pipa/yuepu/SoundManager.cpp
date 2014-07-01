//
//  SoundManager.cpp
//  mpipagame
//
//  Created by 卢珺 on 14-5-30.
//
//

#include "SoundManager.h"
#include "YuepuManager.h"

SoundManager* SoundManager::__instance = NULL;

void SoundManager::initMusicTune(int tempo, string beat, string tone){
//    __instance->set(<#flags#>, <#displayType#>)
    this->setTempo(tempo);
    this->setBeat(beat);
    this->setTone(tone);
}

SoundManager* SoundManager::sharedManager(){
    if(__instance == NULL){
        __instance = new SoundManager();
    }
    
    return __instance;
}

void SoundManager::playEffect(NoteTypeDef noteType, int stringIndex, int hIndex, string scale, float note){
    CCLog("stringIndex is %d",stringIndex);
    stopPlayingOfSpecialStringIndex(stringIndex);
    
    string hStr = "";
    switch (hIndex) {
        case 0:
            break;
        case 1:
            hStr = "_60";
            break;
        case 2:
            hStr = "_80";
            break;
        case 3:
            hStr = "_100";
            break;
        case 4:
            hStr = "_127";
            break;
            
        default:
            hStr = "_60";
            break;
    }
    string ntStr = "B";
    if(noteType == fNoteTypeDef){
        ntStr = "F";
    }else if(noteType == bNoteTypeDef){
        ntStr = "B";
    }else{
        ntStr = "R";
    }
    CCLog("scale is %s", scale.c_str());
    string nStr = YuepuManager::sharedManager()->getScaleFileNameByID(scale);
    
    string fileName = "sound/";
    fileName.append(ntStr);
    fileName.append(nStr);
    fileName.append(hStr);
    fileName.append(".wav");
//    float r = CCRANDOM_0_1();
//    int mfi = r*5 + 58;
    
//    CCString * fileNameNew = CCString::createWithFormat("%s%d%s",fileName.c_str(), mfi, "_60.wav");
    
    
    CCLog("fileName is %s", fileName.c_str());
    unsigned int handler = SimpleAudioEngine::sharedEngine()->playEffect(fileName.c_str(), false);
    switch (stringIndex) {
        case 1:
            firstStringEffect = handler;
            firstStringStatus = STRING_STATUS_PLAYING;
            break;
        case 2:
            secondStringEffect = handler;
            secondStringStatus = STRING_STATUS_PLAYING;
            break;
        case 3:
            thirdStringEffect = handler;
            thirdStringStatus = STRING_STATUS_PLAYING;
            break;
        case 4:
            forthStringEffect = handler;
            forthStringStatus = STRING_STATUS_PLAYING;
            break;
        default:
            break;
    }
    
    
}

void SoundManager::stopPlayingOfSpecialStringIndex(int stringIndex){
    int handler = -1;
    string status = STRING_STATUS_NIL;
    switch (stringIndex) {
        case 1:
            handler = firstStringEffect;
            status = firstStringStatus;
            firstStringStatus = STRING_STATUS_NIL;
            break;
        case 2:
            handler = secondStringEffect;
            status = secondStringStatus;
            secondStringStatus = STRING_STATUS_NIL;
            break;
        case 3:
            handler = thirdStringEffect;
            status = thirdStringStatus;
            thirdStringStatus = STRING_STATUS_NIL;
            break;
        case 4:
            handler = forthStringEffect;
            status = forthStringStatus;
            forthStringStatus = STRING_STATUS_NIL;
            break;
        default:
            break;
    }
    
    if(status != STRING_STATUS_NIL){
        if(handler > 0){
            SimpleAudioEngine::sharedEngine()->stopEffect(handler);
        }
    }
    
}



