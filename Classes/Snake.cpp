#include "Snake.h"
#include "ObjectLayer.h"
#include "GlobalVariables.h"

using namespace cocos2d;

extern GlobalVariables global;

Snake::Snake()
{
    direction = 0;

    //get the window height
    int winHeight = CCDirector::sharedDirector()->getWinSize().height;

    //  set the ratioConstant
    //  Ths is for the dynamic adjust to the different screen size
    ratioConstant = 10;
    float bScale = winHeight / (ratioConstant * 40);

    //  set the image
    head = CCSprite::create("Projectile.png", CCRectMake(0, 0, 20, 20));
    head->setScale(bScale);

    //  add to node
    this->addChild(head);

    // the size of one step
    moveUnit = head->getContentSize().height;
}

Snake::~Snake()
{
    delete head;
}

bool Snake::isLegalDirection(int value)
{
    int a = global.direction;
    int b = value;
    if (value >= 0 && value <= 3 && (direction - value != 0))
        return true;
    return false;
}

void Snake::setDirection(int value)
{
    //  check the value
    if (isLegalDirection(value))
        if ((value - direction != 2) && (direction - value != 2) && (direction - value != 0))
            direction = value;
}

int Snake::getDirection()
{
    return direction;
}

void Snake::move()
{
    float x = this->getPosition().x;
    float y = this->getPosition().y;

    //  change position
    switch(this->getDirection())
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

    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCSize contentSize = head->getContentSize();

    if (x >= winSize.width  + contentSize.width)
        this->setPosition(0 - contentSize.width / 2, y);
    else if (x <= 0  - contentSize.width)
        this->setPosition(0 - winSize.width + contentSize.width / 2, y);
    else if (y >= winSize.height + contentSize.height)
        this->setPosition(x, 0 - contentSize.height / 2);
    else if (y <= 0 - contentSize.height)
        this->setPosition(x, winSize.height + contentSize.height / 2);
    else
    {

        //  set action dueation time
        float duration = 0.3;

        //  set action
        CCFiniteTimeAction* actionMove =  CCMoveTo::create(duration, ccp(x, y));
        this->runAction(actionMove);

    }
}


