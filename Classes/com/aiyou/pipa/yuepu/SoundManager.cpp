//
//  SoundManager.cpp
//  mpipagame
//
//  Created by 卢珺 on 14-5-30.
//
//

#include "SoundManager.h"

SoundManager* SoundManager::__instance = NULL;

void SoundManager::initMusicTune(int tempo, string beat, string tone){
//    __instance->set(<#flags#>, <#displayType#>)
}

SoundManager* SoundManager::sharedManager(){
    if(__instance == NULL){
        __instance = new SoundManager();
    }
    
    return __instance;
}



