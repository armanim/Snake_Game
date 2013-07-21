/**SnakeHead.h
 * The class statement for the snake head
 * Snake head control the snake direction and eat the foods
 * Author: armanim
 * Version 2.0
 * Last update 7/20/2013
 */
#ifndef SNAKEHEAD_H_INCLUDED
#define SNAKEHEAD_H_INCLUDED

#include "GameObject.h"


class SnakeHead : public GameObject
{
public:
    int sizeAdjustionRatioConstant;     // for the image auto adjustment
    bool die;                           // if the snake is living

    SnakeHead(const char*);             // constractor
    ~SnakeHead();                       //distractor

    void setDirection(int);             // set the direction for nex movement

    int getDirection();                 // get the current diraction
    int getBackDirection();
    int getWindowHight();
    cocos2d::CCPoint getNewPosition();
    bool isLegalDirection(int);         //check the inout diractiom
    void move();                        // move a step

protected:
    int currentDirection;                      //direction for nex movement
};

#endif // SNAKE_H_INCLUDED
