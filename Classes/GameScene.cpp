#include "GameScene.h"

GlobalVariables global;

cocos2d::CCScene* GameScene::init()
{
    // 'scene' is an autorelease object
    cocos2d::CCScene* scene = cocos2d::CCScene::create();

    // 'layer' is an autorelease object
    //the background layer
    BackgroundLayer* bLayer = BackgroundLayer::create();
    scene->addChild(bLayer);

    //the objectLayer
    ObjectLayer* oLayer = ObjectLayer::create();
    scene->addChild(oLayer);

    //the Control layer
    ControlLayer* cLayer = ControlLayer::create();
    scene->addChild(cLayer);

    // return the scene
    return scene;
}
