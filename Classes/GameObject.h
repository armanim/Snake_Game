/**SnakeHead.h
 * The class statement for the game object
 * Snake head control the snake direction and eat the foods
 * Author: armanim
 * Version 1.0
 * Last update 7/20/2013
 */
#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#define UP 0
#define DOWN 2
#define RIGHT 1
#define LEFT 3

#include "cocos2d.h"

class GameObject : public cocos2d::CCNode
{
public:
    GameObject();

    // adjust the object size fit to screen size need the window hight (int)
    void adjustObjectSize(cocos2d::CCSprite*, const int);

    // make position to a legal positon
    cocos2d::CCPoint adjustObjectPosition(cocos2d::CCPoint);

    // set the size adjustion ratio constant
    void setSizeAdjustionRatioConstant(int);

    // set image for the object face
    void setAvatar(const char*);

    // set avatar rotation
    void setAvatarRotation(int);

    // set adjustted position
    void setObjectAdjustedPosition(cocos2d::CCPoint);

    // set the move distance for a step
    void setMoveUnitPerStep(cocos2d::CCSprite*, const int);

    // set the object rectengular
    void setObjectRectangular();

    // calculate the image scale
    float getImageScale(cocos2d::CCSprite*, const int);

    // get the one time move unit
    float getMoveUnitPerStep();

    cocos2d::CCSprite* getAvatar();

    // get adjusted image size, width and heiht
    cocos2d::CCSize getAdjustedAvatarContentSize();

    // the rectenguler
    cocos2d::CCRect areaRectangular;

private:
    // the player of the snake
    cocos2d::CCSprite* avatar;

    // for the image auto adjustment
    int sizeAdjustionRatioConstant;

    // the adjusted image scale
    float imageScale;

    // move unit for a step
    float moveUnitPerStep;
};

#endif
