//
//  MusicalNote.h
//  mpipagame
//
//  Created by 卢珺 on 14-5-30.
//
//

#ifndef mpipagame_MusicalNote_h
#define mpipagame_MusicalNote_h


#include "cocos2d.h"
#include <string>

USING_NS_CC;

using namespace std;

class MusicNote: public CCObject {
    CC_SYNTHESIZE(int, handler, Handler); //把位
    CC_SYNTHESIZE(string, skil, Skill); //技法
    CC_SYNTHESIZE(float, note, Note);//播放拍子长度 0.25  1/4
    CC_SYNTHESIZE(CCArray*, scales, Scales);//🎵 音符数组，琵琶最多可以4弦同时弹
    
public:
    
};

class MusicScale:public CCObject {
    CC_SYNTHESIZE(string, scale, Scale);//🎵，音符，'.'表示高音，','表示低音
    CC_SYNTHESIZE(int, strIndex, StrINdex); //弦序， 用于显示所在弦的位置
    
public:
    
};


#endif
