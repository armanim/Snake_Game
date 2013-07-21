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
    imageScale = GameObject::getImageScale(avatar, windowHeight);
    avatar->setScale(imageScale);
}

float GameObject::getImageScale(cocos2d::CCSprite* avatar, const int windowHeight)
{
    //  set the ratioConstant
    /*  Ths is for the dynamic adjust to the different screen size
     * (showedHeight / windowHeight) = (1 / 20)
     * showedHeight = scale * pictureHeight
     */
    return windowHeight / (sizeAdjustionRatioConstant * avatar->getContentSize().height);
}

float GameObject::getMoveUnitPerStep()
{
    return moveUnitPerStep;
}

cocos2d::CCSprite* GameObject::getAvatar()
{
    return avatar;
}

void GameObject::setAvatarRotation(int currentDirection)
{
    switch(currentDirection)
    {
        case UP:
            avatar->setRotation(0);
            break;
        case DOWN:
            avatar->setRotation(180);
            break;
        case RIGHT:
            avatar->setRotation(90);
            break;
        case LEFT:
            avatar->setRotation(270);
        default:
            break;
    }
}

void GameObject::setObjectAdjustedPosition(cocos2d::CCPoint newPosition)
{
    cocos2d::CCPoint adjustedPosition = adjustObjectPosition(newPosition);
    cocos2d::CCNode::setPosition(adjustedPosition);
}

cocos2d::CCPoint GameObject::adjustObjectPosition(cocos2d::CCPoint newPosition)
{
    float objectWidth = getAdjustedAvatarContentSize().width;
    float objectHeight = getAdjustedAvatarContentSize().height;

    float halfObjectWidth = objectWidth / 2;
    float halfObjectHeight = objectHeight / 2;

    // adjust newPosition to legal
    cocos2d::CCSize winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    float top = winSize.height - halfObjectHeight;
    float floor = 0 + halfObjectHeight;
    float right = winSize.width - halfObjectWidth;
    float left = 0  + halfObjectWidth;

    //  check newPosition and give new value
    if (newPosition.y > top + halfObjectHeight)
        newPosition.setPoint(newPosition.x, floor);

    else if (newPosition.y < floor - halfObjectHeight)
        newPosition.setPoint(newPosition.x, top);

    else if (newPosition.x > right + halfObjectWidth)
        newPosition.setPoint(left, newPosition.y);

    else if (newPosition.x < left - halfObjectWidth)
        newPosition.setPoint(right, newPosition.y);

    else
    {
        newPosition.x = newPosition.x / (int)objectWidth;
        newPosition.y = newPosition.y / (int)objectHeight;

        newPosition.x = ((int)newPosition.x) * objectWidth + halfObjectWidth;
        newPosition.y = ((int)newPosition.y) * objectHeight + halfObjectHeight;
    }

    return newPosition;
}

void GameObject::setObjectRectangular()
{
    float halfObjectWidth = getAdjustedAvatarContentSize().width / 2;
    float halfobjectHeight = getAdjustedAvatarContentSize().height / 2;

    // make rectenguler
    areaRectangular = cocos2d::CCRectMake(
                      cocos2d::CCNode::getPosition().x - halfObjectWidth / 2,
                      cocos2d::CCNode::getPosition().y - halfobjectHeight / 2,
                      halfObjectWidth, halfobjectHeight);
}

cocos2d::CCSize GameObject::getAdjustedAvatarContentSize()
{
    cocos2d::CCSize adjustedAvatarContentSize;
    adjustedAvatarContentSize.width = avatar->getContentSize().width * imageScale;
    adjustedAvatarContentSize.height = avatar->getContentSize().height * imageScale;

    return adjustedAvatarContentSize;
}
