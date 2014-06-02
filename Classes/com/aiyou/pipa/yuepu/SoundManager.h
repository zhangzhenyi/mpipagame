//
//  SoundManager.h
//  mpipagame
//
//  Created by 卢珺 on 14-5-30.
//
//

#ifndef __mpipagame__SoundManager__
#define __mpipagame__SoundManager__

#include <string>

//#include "CocosDenshion.h"

#include "cocos2d.h"

using namespace std;
USING_NS_CC;

#define FRIEST_STRING 1
#define SECOND_STRING 2
#define THIRD_STRING 3
#define FORTH_STRING 4

class SoundManager :CCObject {
private:
    static SoundManager* __instance;
    //弦状态，nil, playing,
    string firstStringStatus = "nil";
    string secondStringStatus = "nil";
    string thirdStringStatus = "nil";
    string forthStringStatus = "nil";
    //四根弦正在播放的音效句柄
    int firstStringEffect;
    int secondStringEffect;
    int thirdStringEffect;
    int forthStringEffect;
    
    CC_SYNTHESIZE(string, tone, Tone);
    CC_SYNTHESIZE(string, beat, Beat);
    CC_SYNTHESIZE(int, tempo, Tempo);
public:
    static SoundManager* sharedManager();
    //初始化乐曲，设置节拍，速度（每分钟多少拍）,音调
    void initMusicTune(int tempo, string beat, string tone);
    //弦位置，音符，音符长度
    void playEffect(int, string, float);
    /**每32个音符调一次，用于控制停播每个弦的结束*/
    void onTick(float delt);
    
    
    
};

#endif /* defined(__mpipagame__SoundManager__) */
