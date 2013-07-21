#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "cocos2d.h"
#include "Snake.h"

class Player
{
public:
    Player(Snake*);

    void play(cocos2d::CCPoint);    //  play game

private:
    void setDirection(int);    //  set a direction for snake
    int searchDirection(cocos2d::CCPoint);  //  search next direction
    bool checkUp(cocos2d::CCRect); //  check if up direcrion is avalible
    bool checkDown(cocos2d::CCRect);   //  check if down direction is avalible
    bool checkRight(cocos2d::CCRect);  //  check if right direction is avalible
    bool checkLeft(cocos2d::CCRect);   //  check if left direcrion is avalible
    void adjustDirection(int);

    Snake* mySnake;
    cocos2d::CCPoint headPosition;
    cocos2d::CCPoint nexPosition;
    cocos2d::CCRect upRect;
    cocos2d::CCRect downRect;
    cocos2d::CCRect rightRect;
    cocos2d::CCRect leftRect;
};

#endif // PLAYER_H_INCLUDED
