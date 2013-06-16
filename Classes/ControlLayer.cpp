#include "ControlLayer.h"
#include "ObjectLayer.h"
#include "Food.h"
#include "GlobalVariables.h"

using namespace cocos2d;

extern GlobalVariables global;

// on "init" you need to initialize your instance
bool ControlLayer::init()
{

    // add a menu item with "X" image, which is clicked to quit the program
    // you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object

    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png",
                                        this,
                                        menu_selector(ControlLayer::menuCloseCallback) );
    pCloseItem->setPosition( ccp(winSize.width-20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    CCMenuItemImage *upItem = CCMenuItemImage::create("button.png", "selected.png", this, menu_selector(ControlLayer::Moveup));
    CCMenuItemImage *downItem = CCMenuItemImage::create("button.png", "selected.png", this, menu_selector(ControlLayer::Movedown));
    CCMenuItemImage *rightItem = CCMenuItemImage::create("button.png", "selected.png", this, menu_selector(ControlLayer::Moveright));
    CCMenuItemImage *leftItem = CCMenuItemImage::create("button.png", "selected.png", this, menu_selector(ControlLayer::Moveleft));

    int bX; //the x coordination
    int bY; //the y coordination

    int ratioConstant = 4;    // for the auto adjusting size
    float bScale = winSize.height / (ratioConstant * 100); // (screenHeight / buttonHeight) * ratioConstant
    int transparence = 10;

    bX = (winSize.width / 2);
    bY = (winSize.height / 6) * 5;
    upItem->setPosition( ccp(bX, bY) );
    upItem->setOpacity(transparence);
    upItem->setScale(bScale);


    bX = (winSize.width / 2);
    bY = (winSize.height / 6) * 1;
    downItem->setPosition( ccp(bX, bY) );
    downItem->setOpacity(transparence);
    downItem->setRotation(180);
    downItem->setScale(bScale);

    bX = (winSize.width / 6) * 5;
    bY = (winSize.height / 2);
    rightItem->setPosition( ccp(bX, bY) );
    rightItem->setOpacity(transparence);
    rightItem->setRotation(90);
    rightItem->setScale(bScale);

    bX = (winSize.width / 6) * 1;
    bY = (winSize.height / 2);
    leftItem->setPosition( ccp(bX, bY) );
    leftItem->setOpacity(transparence);
    leftItem->setRotation(270);
    leftItem->setScale(bScale);


    CCMenu* moveItem = CCMenu::create(upItem, downItem, rightItem, leftItem, NULL);
    moveItem->setPosition( CCPointZero );
    this->addChild(moveItem, 0);


    return true;
}

void ControlLayer::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void ControlLayer::Moveup(CCObject* sender)
{
    global.direction = 0;
    CCLog("Moveup");
}

void ControlLayer::Movedown(CCObject* sender)
{
    global.direction = 2;
    CCLog("Movedown");
}

void ControlLayer::Moveright(CCObject* sender)
{
    global.direction = 1;
    CCLog("Moveright");
}

void ControlLayer::Moveleft(CCObject* sender)
{
    global.direction = 3;
    CCLog("Moveleft");
}

