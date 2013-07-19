/**SnakeHead.h
 * The class implement for the game object
 * Snake head control the snake direction and eat the foods
 * Author: armanim
 * Version 1.0
 * Last update 7/20/2013
 */

#include "GameObject.h"

GameObject::GameObject()
{
    // initialize the varibles
    sizeAdjustionRatioConstant = 1;
    moveUnitPerStep = 1;
}

void GameObject::setSizeAdjustionRatioConstant(int constant)
{
    sizeAdjustionRatioConstant = constant;
}

// add a avatar (image face) to the node
void GameObject::setAvatar(const char* imageFileName)
{
    avatar = cocos2d::CCSprite::create(imageFileName, cocos2d::CCRectMake(0, 0, 100, 100));
}

void GameObject::setMoveUnitPerStep(cocos2d::CCSprite* avatar, const int windowHeight)
{
    // see the "getImageScale" fuction
    moveUnitPerStep = avatar->getContentSize().height * getImageScale(avatar, windowHeight);
}
void GameObject::adjustObjectSize(cocos2d::CCSprite* avatar, const int windowHeight)
{
    float imageScale = GameObject::getImageScale(avatar, windowHeight);
    avatar->setScale(imageScale);
}

float GameObject::getImageScale(cocos2d::CCSprite* avatar, const int windowHeight)
{
    //  set the ratioConstant
    /*  Ths is for the dynamic adjust to the different screen size
     * (showedHeight / windowHeight) = (1 / 20)
     * showedHeight = scale * pictureHeight
     */
    return windowHeight / (sizeAdjustionRatioConstant * avatar->getContentSize().height * 4);
}

float GameObject::getMoveUnitPerStep()
{
    return moveUnitPerStep;
}

cocos2d::CCSprite* GameObject::getAvatar()
{
    return avatar;
}
