#include "Food.h"
#include <iostream>

Food::Food(int x, int y)
{
    //get the window height
    int winHeight = CCDirector::sharedDirector()->getWinSize().height;

    //  set the image
    player = CCSprite::create("Projectile.png", CCRectMake(0, 0, 20, 20));

    //  set the ratioConstant
    /*  Ths is for the dynamic adjust to the different screen size
     * (showedHeight / windowHeight) = (1 / 20)
     * showedHeight = scale * pictureHeight
     */
    ratioConstant = 1;
    float bScale = winHeight / (ratioConstant * (player->getContentSize().height) * 20);

    player->setScale(bScale);

    this->setPosition(x, y);

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
    float top = winSize.height - player->getContentSize().height;
    float floor = 0 + player->getContentSize().height;
    float right = winSize.width - player->getContentSize().width;
    float left = 0 + player->getContentSize().width;

    x = (x > right) ? right : x;
    x = (x < left) ? left : x;
    y = (y > top) ? top : y;
    y = (y < floor) ? floor : y;

    //adjust the food position make it in the same way of snake
    x = x / (int)player->getContentSize().width;
    y = y / (int)player->getContentSize().height;

    float X = x * player->getContentSize().width + player->getContentSize().width / 2;
    float Y = y * player->getContentSize().height + player->getContentSize().height / 2;
    CCNode::setPosition(X, Y);
}
