//
//  YuepuManager.cpp
//  mpipagame
//
//  Created by 卢珺 on 14-5-30.
//
//

#include "YuepuManager.h"
#include "Resource.h"

YuepuManager* YuepuManager::__instance = NULL;

bool YuepuManager::init(){
    CCDictionary* dict = CCDictionary::createWithContentsOfFile(SOUND_CONF_FILE_NAME);
    
    CCDictElement* _el_;
    CCDICT_FOREACH(dict, _el_){
        CCLog("_el_ key is %s, value is %s",_el_->getStrKey(), ((CCString*)_el_->getObject())->getCString());
    }
    
    this->scales = CCDictionary::createWithDictionary(dict);
    this->scales->retain();
    return true;
}

YuepuManager* YuepuManager::sharedManager(){
    if(!__instance){
        __instance =new YuepuManager();
        __instance->init();
    }
    return __instance;
}

/***根据音符返回音效文件*/
string YuepuManager::getScaleFileNameByID(string scaleId){
    if(!this->scales){
        this->init();
    }
    CCObject* value= this->scales->objectForKey(scaleId);
    CCAssert(value, "cannot get file name from conf file");
    return ((CCString*)value)->m_sString;
    
}