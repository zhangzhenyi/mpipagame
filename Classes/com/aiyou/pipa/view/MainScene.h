//
//  MainScene.h
//  mpipagame
//
//  Created by 卢珺 on 14-5-19.
// Used to show game main scene, start game, score, rank etc play background music
//

#ifndef __mpipagame__MainScene__
#define __mpipagame__MainScene__

#include <iostream>

#include "cocos2d.h"

USING_NS_CC;

class MainScene :public CCScene {
    void callbackMenuSelected(CCObject* pSender);
    
public:
    bool init();
    
    CREATE_FUNC(MainScene);
};

#endif /* defined(__mpipagame__MainScene__) */
