#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED

#include "cocos2d.h"
#include "GameObject.h"

class Food : public GameObject
{
public:
    Food(int, int);
    ~Food();

    cocos2d::CCSprite *player;    // the player of the snake
    int sizeAdjustionRatioConstant;  //for the image auto adjustment

    void setPosition(int, int); //set the position py unit
};

#endif // FOOD_H_INCLUDED
