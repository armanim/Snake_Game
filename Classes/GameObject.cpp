/**SnakeHead.h
 * The class implement for the game object
 * Snake head control the snake direction and eat the foods
 * Author: armanim
 * Version 1.0
 * Last update 7/18/2013
 */

#include "GameObject.h"

GameObject::GameObject()
{
    sizeAdjustionRatioConstant = 1;
}

void GameObject::setSizeAdjustionRatioConstant(int constant)
{
    sizeAdjustionRatioConstant = constant;
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

float GameObject::getMoveUnitPerStep(cocos2d::CCSprite* avatar, const int windowHeight)
{
    return avatar->getContentSize().height * GameObject::getImageScale(avatar, windowHeight);
}
