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
#include "SimpleAudioEngine.h"

#include "cocos2d.h"

using namespace std;
USING_NS_CC;
using namespace CocosDenshion;

#define FRIEST_STRING 1
#define SECOND_STRING 2
#define THIRD_STRING 3
#define FORTH_STRING 4

#define STRING_STATUS_NIL "nil"
#define STRING_STATUS_PLAYING "_playing"

enum NoteTypeDef {
    bNoteTypeDef,//basic
    fNoteTypeDef,//Fanyin
    rNoteTypeDef, //roll
};

class SoundManager :CCObject {
private:
    static SoundManager* __instance;
    //弦状态，nil, playing,
    string firstStringStatus = STRING_STATUS_NIL;
    string secondStringStatus = STRING_STATUS_NIL;
    string thirdStringStatus = STRING_STATUS_NIL;
    string forthStringStatus = STRING_STATUS_NIL;
    //四根弦正在播放的音效句柄
    unsigned int firstStringEffect;
    unsigned int secondStringEffect;
    unsigned int thirdStringEffect;
    unsigned int forthStringEffect;
    
    CC_SYNTHESIZE(string, tone, Tone);
    CC_SYNTHESIZE(string, beat, Beat);
    CC_SYNTHESIZE(int, tempo, Tempo);
    /**停止播放制定弦序的声音, @param stringIndex*/
    void stopPlayingOfSpecialStringIndex(int);
public:
    static SoundManager* sharedManager();
    //初始化乐曲，设置节拍，速度（每分钟多少拍）,音调
    void initMusicTune(int tempo = 52, string beat = "4/4", string tone ="D");
    /**基本音／泛音／轮指；弦位置；把位（不同把位音符标准音不一样）；音符；音符长度 */
    void playEffect(NoteTypeDef,int,int, string, float);
    /**每32分之一音符调一次，用于控制停播每个弦的结束*/
    void onTick(float delt);
    
    
    
};

#endif /* defined(__mpipagame__SoundManager__) */
