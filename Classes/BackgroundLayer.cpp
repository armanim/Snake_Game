#include "BackgroundLayer.h"
#include "Food.h"

using namespace cocos2d;

// on "init" you need to initialize your instance
bool BackgroundLayer::init()
{
    // 1. super init first
    if ( !CCLayerColor::initWithColor( ccc4(255, 255, 255, 255) ) )
    {
        return false;
    }

    return true;

}
