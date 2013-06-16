#ifndef BACKGROUNDLAYER_H_INCLUDED
#define BACKGROUNDLAYER_H_INCLUDED

#include "cocos2d.h"

class BackgroundLayer : public cocos2d::CCLayerColor
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static node()" method manually
    CREATE_FUNC(BackgroundLayer);
};

#endif // BACKGROUNDLAYER_H_INCLUDED
