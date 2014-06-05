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

#include "cocos2d.h"


#include <string>
USING_NS_CC;
using namespace std;

class PlayingMusic :public CCLayer{
    int intervalSound = 15;
    
private:
    void onScheduleTick(float dlet);
public:
    static CCScene* getScene();
    
    CREATE_FUNC(PlayingMusic);
    
    bool init();
    
    
};

#endif /* defined(__mpipagame__PlayingMusic__) */
