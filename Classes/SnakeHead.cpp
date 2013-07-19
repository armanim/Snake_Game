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
    // is not moving
    isMoving = false;

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
    float moveUnit = getMoveUnitPerStep();

    //  make rectenguler
    areaRect = CCRectMake(
                      getPosition().x - moveUnit/2,
                      getPosition().y - moveUnit/2,
                      moveUnit, moveUnit);
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

bool SnakeHead::isLegalDirection(int value)
{
    if (value >= 0 && value <= 3 && (direction - value != 0))
        return true;
    return false;
}

void SnakeHead::setDirection(int value)
{
    //  check the value
    if (isLegalDirection(value))
        if ((value - direction != 2) && (direction - value != 2))
        {
            direction = value;
            switch(direction)
            {
                case UP:
                    getAvatar()->setRotation(0);
                    break;
                case DOWN:
                    getAvatar()->setRotation(180);
                    break;
                case RIGHT:
                    getAvatar()->setRotation(90);
                    break;
                case LEFT:
                    getAvatar()->setRotation(270);
                default:
                    break;
            }
        }

}

int SnakeHead::getDirection()
{
    return direction;
}

void SnakeHead::move()
{
    isMoving = true;
    float moveUnit = getMoveUnitPerStep();

    float x = this->getPosition().x;
    float y = this->getPosition().y;
    //  change position
    switch(direction)
    {
        case UP:
            y += moveUnit;
            break;
        case DOWN:
            y -= moveUnit;
            break;
        case RIGHT:
            x += moveUnit;
            break;
        case LEFT:
            x -= moveUnit;
        default:
            break;
    }


    setPosition(ccp(x, y));
    CCPoint point = getPosition();

    //  update rectenguler
    areaRect = CCRectMake(
                      point.x - moveUnit/2,
                      point.y - moveUnit/2,
                      moveUnit/2, moveUnit/2);
    isMoving = false;

}

bool SnakeHead::isLegalPosition()
{
    //  get self position
    CCPoint position = getPosition();
    float x = position.x;
    float y = position.y;

    //  get window size and self size
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();

    float width = getAvatar()->getContentSize().width / 2;
    float height = getAvatar()->getContentSize().height / 2;

    if (x >= winSize.width  - width)
        return false;
    if (x < 0  + width)
        return false;
    if (y >= winSize.height - height)
        return false;;
    if (y < 0 + height)
        return false;
    return true;
}

CCPoint SnakeHead::adjustPosition()
{
    float moveUnit = getMoveUnitPerStep();
    //  get self position
    CCPoint position = getPosition();
    float x = position.x;
    float y = position.y;
    float width = moveUnit / 2;
    float height = moveUnit / 2;

    // adjust position to legal
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    float top = winSize.height - width;
    float floor = 0 + height;
    float right = winSize.width - width;
    float left = 0  + width;

    //  check position and give new value
    if (y > top + height)
        position.setPoint(x, floor);
    else if (y < floor - height)
        position.setPoint(x, top);
    else if (x > right + width)
        position.setPoint(left, y);
    else if (x < left - width)
        position.setPoint(right, y);
    else
    {
        x = x / (int)moveUnit;
        y = y / (int)moveUnit;

        x = ((int)x) * moveUnit + moveUnit / 2;
        y = ((int)y) * moveUnit + moveUnit / 2;

        position.setPoint(x, y);
    }

    CCNode::setPosition(position);
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

void SnakeHead::setPosition(CCPoint point)
{
    CCNode::setPosition(point);
    //if (!isLegalPosition())
    adjustPosition();
}

