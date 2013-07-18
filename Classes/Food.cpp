#include "Food.h"
#include <iostream>

Food::Food(int x, int y)
{
    //get the window height
    int windowHeight = CCDirector::sharedDirector()->getWinSize().height;

    //  set the image
    player = CCSprite::create("food.png", CCRectMake(0, 0, 100, 100));

    //  set the ratioConstant
    /*  Ths is for the dynamic adjust to the different screen size
     * (showedHeight / windowHeight) = (1 / 20)
     * showedHeight = scale * pictureHeight
     */
    sizeAdjustionRatioConstant = 1;
    float scale = windowHeight / (sizeAdjustionRatioConstant * (player->getContentSize().height) * 40);
    moveUnit = player->getContentSize().height * scale;
    player->setScale(scale);

    this->setPosition(x, y);

    //  make rectenguler
    areaRect = CCRectMake(
                      getPosition().x - moveUnit/2,
                      getPosition().y - moveUnit/2,
                      moveUnit/2, moveUnit/2);

    //  add to node
    this->addChild(player);
}

Food::~Food()
{
}


void Food::setPosition(int x, int y)
{
    //this is an adjustment to make food and snake in same road
    //
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    float top = winSize.height - moveUnit - moveUnit / 2;
    float floor = 0 + moveUnit + moveUnit / 2;
    float right = winSize.width - moveUnit - moveUnit / 2;
    float left = 0 + moveUnit + moveUnit / 2;

    x = (x > right) ? right : x;
    x = (x < left) ? left : x;
    y = (y > top) ? top : y;
    y = (y < floor) ? floor : y;

    //adjust the food position make it in the same way of snake
    x = x / (int)moveUnit;
    y = y / (int)moveUnit;

    float X = x * moveUnit + moveUnit / 2;
    float Y = y * moveUnit + moveUnit / 2;

    this->CCNode::setPosition(X, Y);
}
