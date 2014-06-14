//
//  Yuepu.h
//  mpipagame
//
//  Created by 卢珺 on 14-6-14.
//
//

#ifndef mpipagame_Yuepu_h
#define mpipagame_Yuepu_h

#include "MusicalNote.h"

#include "cocos2d.h"
#include <string>

USING_NS_CC;

using namespace std;

class Yuepu : public CCObject{
    
    CC_SYNTHESIZE(string, musicName, MusicName);
    CC_SYNTHESIZE(int, tempo, Tempo);//   52 每分钟多少拍子
    CC_SYNTHESIZE(string, tone, Tone);//  D
    CC_SYNTHESIZE(string, beat, Beat);//  4/4
    
    CC_SYNTHESIZE(CCArray*, content, Content); //谱子内容
public:
    
};

#endif
