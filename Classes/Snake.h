#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include "cocos2d.h"
#include "SnakeHead.h"
#include "Food.h"

class Snake : public cocos2d::CCNode
{
public:
    Snake();
    ~Snake();
    void update();  //  update the snake states
    void growUp();  //  after eating snake will grow up
    void setDirection(int);
    int getDirection();
    void move();
    cocos2d::CCPoint getHeadPosition();  //  return the head position
    cocos2d::CCPoint getBodyPosition(int);  //  return the body position by index
    cocos2d::CCPoint getNextBackPosition(cocos2d::CCPoint, int);      //  get next back position by directiom
                                                    //  use for the grow up
    cocos2d::CCRect getHeadRect();   //  return the head rectangular
    int getLength();
    bool isDead();

    bool isMoving;
    float imageScale;
    float moveUnit;

private:
    int length;
    int currentDirection;  //  the snake moving direction
    bool isRunning;
    SnakeHead *head;   //  the handle(head) of snake
    cocos2d::CCSprite* bodyArr[100];
    cocos2d::CCSprite* body;    //  the frist element in the array

};


#endif // SNAKE_H_INCLUDED
