/**SnakeHead.cpp
 * The class implementation for the snake head
 * Snake head control the snake direction and eat the foods
 * Author: armanim
 * Version 2.0
 * Last update 7/20/2013
 */

#include "SnakeHead.h"
#include "GlobalVariables.h"

using namespace cocos2d;

SnakeHead::SnakeHead(const char* imageFileName)
{

    // get the window height
    int windowHeight = getWindowHight();

    // set the imageFileName
    setAvatar(imageFileName);
    //  add to node
    this->addChild(getAvatar());

    setDirection(RIGHT);

    //  set the ratioConstant
    setSizeAdjustionRatioConstant(10);
    adjustObjectSize(getAvatar(), windowHeight);

    // the size of one step
    setMoveUnitPerStep(getAvatar(), windowHeight);

    // make rectenguler
    setObjectRectengular();
}

SnakeHead::~SnakeHead()
{
    CCSprite* buff = getAvatar();
    delete buff;
    buff = 0;
}

int SnakeHead::getWindowHight()
{
    return CCDirector::sharedDirector()->getWinSize().height;
}

bool SnakeHead::isLegalDirection(int directionValue)
{
    // the last one is validate that the next dierction can not be same as currnent direction
    if (directionValue >= 0 && directionValue <= 3 && (currentDirection - directionValue != 0))
        return true;
    return false;
}

void SnakeHead::setDirection(int newDirection)
{
    //  check the value
    if (isLegalDirection(newDirection))
        if ((newDirection - currentDirection != 2) && (currentDirection - newDirection != 2))
        {
            currentDirection = newDirection;
            // change the avatar face to the corresponding rotation
            setAvatarRotation(currentDirection);
        }

}

int SnakeHead::getDirection()
{
    return currentDirection;
}

void SnakeHead::move()
{
    // set new pozition
    setObjectAdjustedPosition(getNewPosition());

    //  update rectenguler
    setObjectRectengular();

}


int SnakeHead::getBackDirection()
{
    switch(this->getDirection())
    {
        case UP:
            return DOWN;
        case DOWN:
            return UP;
        case RIGHT:
            return LEFT;
        case LEFT:
            return RIGHT;
    }
}

cocos2d::CCPoint SnakeHead::getNewPosition()
{
    float moveUnit = getMoveUnitPerStep();

    // get the snake head current position
    cocos2d::CCPoint currentPosition = getPosition();

    //  change position
    switch(currentDirection)
    {
        case UP:
            currentPosition.y += moveUnit;
            break;
        case DOWN:
            currentPosition.y -= moveUnit;
            break;
        case RIGHT:
            currentPosition.x += moveUnit;
            break;
        case LEFT:
            currentPosition.x -= moveUnit;
        default:
            break;
    }

    return currentPosition;
}

