//
//  LoadScene.h
//  mpipagame
//
//  Created by 卢珺 on 14-5-19.
//
//

#ifndef __mpipagame__LoadScene__
#define __mpipagame__LoadScene__

#include <iostream>

#include "cocos2d.h"

USING_NS_CC;

class LoadScene :public CCLayer{
    
    CCProgressTimer* progressBar;
    
    void tick(float delt);
public:
    
    CREATE_FUNC(LoadScene);
    
    bool init();
    
    static CCScene* getScene();
    
};

#endif /* defined(__mpipagame__LoadScene__) */
