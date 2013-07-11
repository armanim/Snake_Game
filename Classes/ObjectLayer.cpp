#include "ObjectLayer.h"
#include "GlobalVariables.h"

using namespace cocos2d;

extern GlobalVariables global;

bool ObjectLayer::init()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    //  add the snake
    snake = new Snake();
    this->addChild(snake);

    //  add robot snake
    robot = new Snake();
    this->addChild(robot);

    //  add player (computer)
    player = new Player(robot);

    global.direction = snake->getDirection();

    food = NULL;

    addFood();

    //this->schedule(schedule_selector(ObjectLayer::update), 1 / 60);
    this->schedule(schedule_selector(ObjectLayer::update), 0.1);

    return true;
}

void ObjectLayer::update()
{
    if (snake->getHeadRect().intersectsRect(food->rect))
    {
        addFood();
        snake->growUp();
    }

    if (robot->getHeadRect().intersectsRect(food->rect))
    {
        addFood();
        robot->growUp();
    }

    if (!snake->isDead() && !robot->isDead())
    {
        snake->setDirection(global.direction);
        player->play(food->getPosition());
        snakeMove();
    }
}

void ObjectLayer::addFood()
{
    if (food != NULL)
        this->removeChild(food, true);

    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    int x = rand() % (int)winSize.width;
    int y = rand() % (int)winSize.height;

    food = new Food(x, y);
    this->addChild(food);
}

void ObjectLayer::snakeMove()
{
    snake->move();
    robot->move();
}

