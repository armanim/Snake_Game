/**SnakeHead.h
 * The class statement for the game object
 * Snake head control the snake direction and eat the foods
 * Author: armanim
 * Version 1.0
 * Last update 7/18/2013
 */
#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include "cocos2d.h"

class GameObject
{
public:
    GameObject();

    // adjust the object size fit to screen size need the window hight (int)
    void adjustObjectSize(cocos2d::CCSprite*, const int);

    // set the size adjustion ratio constant
    void setSizeAdjustionRatioConstant(int);

    // calculate the image scale
    float getImageScale(cocos2d::CCSprite*, const int);

    // get the one time move unit
    float getMoveUnitPerStep(cocos2d::CCSprite*, const int);

private:
    // for the image auto adjustment
    int sizeAdjustionRatioConstant;
};

#endif
