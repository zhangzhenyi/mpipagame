//
//  YuepuManager.h
//  mpipagame
//
//  Created by 卢珺 on 14-5-30.
//
//

#ifndef __mpipagame__YuepuManager__
#define __mpipagame__YuepuManager__

#include <iostream>

#include "cocos2d.h"
#include <string>

#include "Yuepu.h"
#include "MusicalNote.h"

USING_NS_CC;
using namespace std;

#define MUSIC_1_NAME "little_baby"
#define MUSIC_2 2

#define MUSIC_1_FILE_NAME "musicpu/LittleBaby.plist"


class YuepuManager{
private:
    CCDictionary* scales;//音符与音效文ß件的对应关系
    static YuepuManager* __instance;
    
    CCDictionary* yuepuContainer;
    
    /**load music pu**/
    void loadYuepu();
    /***parse yuepu and then save it into yuepuContainer***/
    void parseYuepu(CCDictionary*, string musicId);
    
public:
    static YuepuManager* sharedManager();
//    CREATE_FUNC(YuepuManager);
    bool init();
    /***根据音符返回音效文件*/
    string getScaleFileNameByID(string scaleId);
    
    /***根据音乐名获取乐谱数据*/
    Yuepu* getYuepuByName(string musicName);
    
    
};

#endif /* defined(__mpipagame__YuepuManager__) */
