#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED

#include "cocos2d.h"

using namespace cocos2d;

class Food : public cocos2d::CCNode
{
public:
    Food(int, int);
    ~Food();

    CCSprite *player;    //the player of the snake
    int sizeAdjustionRatioConstant;  //for the image auto adjustment
    float moveUnit; //the one time moving distance
    CCRect areaRect;

    void setPosition(int, int); //set the position py unit
};

#endif // FOOD_H_INCLUDED
