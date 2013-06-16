#ifndef OBJECTLAYER_H_INCLUDED
#define OBJECTLAYER_H_INCLUDED

#include "cocos2d.h"
#include "SnakeHead.h"
#include "Food.h"

class ObjectLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    void update();  //update the layer

    SnakeHead* snake;   //  the handle of snake
    Food* food; //  the handle of food


    // implement the "static node()" method manually
    CREATE_FUNC(ObjectLayer);
};

#endif // OBJECTLAYER_H_INCLUDED
