#include "Food.h"

Food::Food(int x, int y)
{
    //get the window height
    int windowHeight = cocos2d::CCDirector::sharedDirector()->getWinSize().height;

    //  set the image
    setAvatar("food.png");

    //  set the ratioConstant
    setSizeAdjustionRatioConstant(40);

    // adjust size
    adjustObjectSize(getAvatar(), windowHeight);

    setPosition(x, y);

    //  add to node
    addChild(getAvatar());

    setObjectRectangular();
}

Food::~Food()
{
}


void Food::setPosition(int x, int y)
{
    // get windiw size
    int windowHeight = cocos2d::CCDirector::sharedDirector()->getWinSize().height;
    int windowWidth = cocos2d::CCDirector::sharedDirector()->getWinSize().width;

    // make first adjastion
    x %= windowWidth;
    y %= windowHeight;

    // create new position
    cocos2d::CCPoint newPosition = cocos2d::CCPoint(x, y);

    // set adjusted position
    setObjectAdjustedPosition(newPosition);
}
