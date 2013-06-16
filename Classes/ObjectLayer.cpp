#include "ObjectLayer.h"
#include "GlobalVariables.h"

using namespace cocos2d;

extern GlobalVariables global;

bool ObjectLayer::init()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();

    //  add the snake
    snake = new SnakeHead();
    snake->setPosition(winSize.width/2, 10);
    this->addChild(snake);
    global.direction = snake->getDirection();

    int x = rand() % (int)winSize.width;
    int y = rand() % (int)winSize.height;

    Food *food = new Food(x, y);
    this->addChild(food);

    this->schedule(schedule_selector(ObjectLayer::update), 0.1);

    return true;
}

void ObjectLayer::update()
{
    snake->setDirection(global.direction);
    snake->move();
}
