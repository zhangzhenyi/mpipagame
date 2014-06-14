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
    this->scales = CCDictionary::createWithDictionary(dict);
    this->scales->retain();
    
    
    CCDictElement* _el_;
    CCDICT_FOREACH(dict, _el_){
        CCLog("_el_ key is %s, value is %s",_el_->getStrKey(), ((CCString*)_el_->getObject())->getCString());
    }
    
    loadYuepu();
    
    
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

void YuepuManager::loadYuepu(){
    CCDictionary* yuepu = CCDictionary::createWithContentsOfFile(MUSIC_1_FILE_NAME);
    yuepu->retain();
    if(!yuepuContainer){
        yuepuContainer = CCDictionary::create();
        yuepuContainer->retain();
    }
    parseYuepu(yuepu, MUSIC_1_NAME);
}

/***parse yuepu and then save it into yuepuContainer***/
void YuepuManager::parseYuepu(CCDictionary* yuepu, string musicName){
    if(yuepu){
        string name = dynamic_cast<CCString*>(yuepu->objectForKey("name"))->m_sString;
        string tone = dynamic_cast<CCString*>(yuepu->objectForKey("tone"))->m_sString;
        string beat = dynamic_cast<CCString*>(yuepu->objectForKey("beat"))->m_sString;
        CCLog("beat is %s, tempo is %s", beat.c_str(), typeid(yuepu->objectForKey("tempo")).name());
        CCString* tempo = dynamic_cast<CCString*>(yuepu->objectForKey("tempo"));

        Yuepu* pu = new Yuepu();
        pu->setBeat(beat);
        pu->setMusicName(name);
        pu->setTempo(tempo->intValue());
        pu->setTone(tone);
//        pu->setContent(<#cocos2d::CCArray *var#>);
        //Parse note content
        CCArray* notesParsed = CCArray::create();
        notesParsed->retain();
        
        pu->setContent(notesParsed);
        CCArray* notes = dynamic_cast<CCArray*>(yuepu->objectForKey("contents"));
        if(notes){
            CCObject* _ele;
            CCObject* _ele_;
            
            MusicNote* mnote;
            CCARRAY_FOREACH(notes, _ele){
                CCDictionary* noteE = (CCDictionary*)_ele;
                mnote = new MusicNote();
                int handler = dynamic_cast<CCString*>(noteE->objectForKey("handler"))->intValue(); //把位
                string skill = dynamic_cast<CCString*>(noteE->objectForKey("skill"))->m_sString;
                float note =  dynamic_cast<CCString*>(noteE->objectForKey("note"))->floatValue();
                CCArray* scales =dynamic_cast<CCArray*>(noteE->objectForKey("scales"));
                
                mnote->setHandler(handler);
                mnote->setSkill(skill);
                mnote->setNote(note);
                
                CCArray* scalesParsed = CCArray::create();
                scalesParsed->retain();
                mnote->setScales(scalesParsed);
                notesParsed->addObject(mnote);
                
                CCARRAY_FOREACH(scales, _ele_){
                    CCDictionary* nd =(CCDictionary*)_ele_;
                    string scale = dynamic_cast<CCString*>(nd->objectForKey("scale"))->m_sString;
                    int stringIndex = dynamic_cast<CCString*>(nd->objectForKey("string_index"))->intValue();
                    MusicScale* mscale = new MusicScale();
                    mscale->setScale(scale);
                    mscale->setStrINdex(stringIndex);
                    
                    scalesParsed->addObject(mscale);
                    
                }
                
            }
        }
        
        yuepuContainer->setObject(pu, musicName);
    }
}

Yuepu* YuepuManager::getYuepuByName(string musicName){
    if(yuepuContainer){
        CCObject* temp = yuepuContainer->objectForKey(musicName);
        if(temp){
            Yuepu* yuepu = (Yuepu*)temp ;
            if(yuepu){
                return yuepu;
            }
            
        }
        
    }
    return NULL;
}