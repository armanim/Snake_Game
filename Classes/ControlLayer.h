#ifndef CONTROLLAYER_H_INCLUDED
#define CONTROLLAYER_H_INCLUDED

#include "cocos2d.h"

//#define UP 0
//#define DOWN 2
//#define RIGHT 1
//#define LEFT 3


class ControlLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    void Moveup(CCObject* sender);
    void Movedown(CCObject* sender);
    void Moveright(CCObject* sender);
    void Moveleft(CCObject* sender);

    // implement the "static node()" method manually
    CREATE_FUNC(ControlLayer);
};


#endif // CONTROLLAYER_H_INCLUDED
