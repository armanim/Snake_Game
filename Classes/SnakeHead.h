#ifndef SNAKEHEAD_H_INCLUDED
#define SNAKEHEAD_H_INCLUDED

#include "cocos2d.h"
#ifndef UP DOWN RIGHT LEFT

#define UP 0
#define DOWN 2
#define RIGHT 1
#define LEFT 3

#endif


using namespace cocos2d;

class SnakeHead : public cocos2d::CCNode
{
public:

    CCSprite *player;    //the player of the snake
    int ratioConstant;  //for the image auto adjustment
    int length; //the length of snake
    bool die;   //if the snake is living
    float moveUnit; //the one time moving distance
    bool moving; //  the flag for running state
    CCRect rect;    //the rectenguler

    SnakeHead(const char*);
    ~SnakeHead();

    void move();    // move a step
    void setDirection(int); //set the direction for nex movement
    int getDirection(); //get the current diraction
    int getBackDirection();
    bool isLegalPosition();
    void setPosition(CCPoint);  //  set adjustted position
    CCPoint adjustPosition();

protected:
    int direction;  //direction for nex movement
    bool isLegalDirection(int); //check the inout diractiom
};

#endif // SNAKE_H_INCLUDED
