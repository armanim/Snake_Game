#include "SnakeHead.h"
#include "GlobalVariables.h"

using namespace cocos2d;

SnakeHead::SnakeHead(const char* image)
{
    //get the window height
    int winHeight = CCDirector::sharedDirector()->getWinSize().height;

    //  set the image
    player = CCSprite::create(image, CCRectMake(0, 0, 100, 100));
    setDirection(RIGHT);

    //  set the ratioConstant
    /*  Ths is for the dynamic adjust to the different screen size
     * (showedHeight / windowHeight) = (1 / 20)
     * showedHeight = scale * pictureHeight
     */
    ratioConstant = 10;
    float imageScale = winHeight / (ratioConstant * player->getContentSize().height * 4);
    player->setScale(imageScale);

    //  add to node
    this->addChild(player);

    // the size of one step
    moveUnit = player->getContentSize().height * imageScale;

    //  is not moving
    moving = false;

    //  make rectenguler
    rect = CCRectMake(
                      getPosition().x - moveUnit/2,
                      getPosition().y - moveUnit/2,
                      moveUnit, moveUnit);

}

SnakeHead::~SnakeHead()
{
    delete player;
    player = 0;
}


bool SnakeHead::isLegalDirection(int value)
{
    if (value >= 0 && value <= 3 && (direction - value != 0))
        return true;
    return false;
}

void SnakeHead::setDirection(int value)
{
    //  check the value
    if (isLegalDirection(value))
        if ((value - direction != 2) && (direction - value != 2))
        {
            direction = value;
            switch(direction)
            {
                case UP:
                    player->setRotation(0);
                    break;
                case DOWN:
                    player->setRotation(180);
                    break;
                case RIGHT:
                    player->setRotation(90);
                    break;
                case LEFT:
                    player->setRotation(270);
                default:
                    break;
            }
        }

}

int SnakeHead::getDirection()
{
    return direction;
}

void SnakeHead::move()
{
    moving = true;

    float x = this->getPosition().x;
    float y = this->getPosition().y;
    //  change position
    switch(direction)
    {
        case UP:
            y += moveUnit;
            break;
        case DOWN:
            y -= moveUnit;
            break;
        case RIGHT:
            x += moveUnit;
            break;
        case LEFT:
            x -= moveUnit;
        default:
            break;
    }


    setPosition(ccp(x, y));
    CCPoint point = getPosition();

    //  update rectenguler
    rect = CCRectMake(
                      point.x - moveUnit/2,
                      point.y - moveUnit/2,
                      moveUnit/2, moveUnit/2);
    moving = false;

}

bool SnakeHead::isLegalPosition()
{
    //  get self position
    CCPoint position = getPosition();
    float x = position.x;
    float y = position.y;

    //  get window size and self size
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCSize contentSize = player->getContentSize();

    float width = player->getContentSize().width / 2;
    float height = player->getContentSize().height / 2;

    if (x >= winSize.width  - width)
        return false;
    if (x < 0  + width)
        return false;
    if (y >= winSize.height - height)
        return false;;
    if (y < 0 + height)
        return false;
    return true;
}

CCPoint SnakeHead::adjustPosition()
{
    //  get self position
    CCPoint position = getPosition();
    float x = position.x;
    float y = position.y;
    float width = moveUnit / 2;
    float height = moveUnit / 2;

    // adjust position to legal
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    float top = winSize.height - width;
    float floor = 0 + height;
    float right = winSize.width - width;
    float left = 0  + width;

    //  check position and give new value
    if (y > top + height)
        position.setPoint(x, floor);
    else if (y < floor - height)
        position.setPoint(x, top);
    else if (x > right + width)
        position.setPoint(left, y);
    else if (x < left - width)
        position.setPoint(right, y);
    else
    {
        x = x / (int)moveUnit;
        y = y / (int)moveUnit;

        x = ((int)x) * moveUnit + moveUnit / 2;
        y = ((int)y) * moveUnit + moveUnit / 2;

        position.setPoint(x, y);
    }

    CCNode::setPosition(position);
}

int SnakeHead::getBackDirection()
{
    switch(this->getDirection())
    {
        case UP:
            return DOWN;
        case DOWN:
            return UP;
        case RIGHT:
            return LEFT;
        case LEFT:
            return RIGHT;
    }
}

void SnakeHead::setPosition(CCPoint point)
{
    CCNode::setPosition(point);
    //if (!isLegalPosition())
    adjustPosition();
}

