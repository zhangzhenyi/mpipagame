//
//  PlayingMusic.h
//  mpipagame
//
//  Created by 卢珺 on 14-5-19.
//
//

#ifndef __mpipagame__PlayingMusic__
#define __mpipagame__PlayingMusic__

#include <iostream>

//#include "SoundManager.h"
#include "../yuepu/MusicalNote.h"
#include "../yuepu/Yuepu.h"
#include "../yuepu/YuepuManager.h"

#include "cocos2d.h"


#include <string>
USING_NS_CC;
using namespace std;

class PlayingMusic :public CCLayer{
    int intervalSound = 15;//播放下一个音符需要间隔tick数量
    Yuepu* currYuepu;
    
    MusicNote* mnote;//当前要播放的音节内容
    
    CCMenuItemImage *stringBtn1;
    CCMenuItemImage *stringBtn2;
    CCMenuItemImage *stringBtn3;
    CCMenuItemImage *stringBtn4;
    
private:
    void onScheduleTick(float dlet);
    
    /***音符索引位置，每次取出一个音符，数量加一**/
    int noteIndex =0;
    MusicNote* getNextNote();
    
    double inteval;//schedule间隔时间
    double intevalTimePerBeat;//每一拍的时间
    
    void onNoteClicked(CCObject* pSender);
    
public:
    static CCScene* getScene();
    
    CREATE_FUNC(PlayingMusic);
    
    bool init();
    
    
};

#endif /* defined(__mpipagame__PlayingMusic__) */
