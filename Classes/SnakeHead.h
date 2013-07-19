/**SnakeHead.h
 * The class statement for the snake head
 * Snake head control the snake direction and eat the foods
 * Author: armanim
 * Version 2.0
 * Last update 7/20/2013
 */
#ifndef SNAKEHEAD_H_INCLUDED
#define SNAKEHEAD_H_INCLUDED

#ifndef UP DOWN RIGHT LEFT

#define UP 0
#define DOWN 2
#define RIGHT 1
#define LEFT 3

#endif

#include "cocos2d.h"
#include "GameObject.h"

using namespace cocos2d;


class SnakeHead : public cocos2d::CCNode, public GameObject
{
public:
    int sizeAdjustionRatioConstant;     // for the image auto adjustment
    bool die;                           // if the snake is living
    bool isMoving;                      // the flag for running state

    SnakeHead(const char*);             // constractor
    ~SnakeHead();                       //distractor

    void setDirection(int);             // set the direction for nex movement
    void setPosition(CCPoint);          // set adjustted position
    int getDirection();                 // get the current diraction
    int getBackDirection();
    int getWindowHight();
    bool isLegalPosition();
    CCPoint adjustPosition();
    void move();                        // move a step

protected:
    int direction;                      //direction for nex movement
    bool isLegalDirection(int);         //check the inout diractiom
};

#endif // SNAKE_H_INCLUDED
