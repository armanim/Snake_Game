#include "Snake.h"
#include "SnakeHead.h"

using namespace cocos2d;

Snake::Snake()
{
    float windowHeight = CCDirector::sharedDirector()->getWinSize().height;
    //  set snake
    currentDirection = RIGHT;//rand() % 4;

    //this->layer = layer;

    // setup the head
    head = new SnakeHead("head.png");
    head->setDirection(currentDirection);
    head->setObjectAdjustedPosition(CCPoint(600, 200));
    this->addChild(head);

    //  setup the body
    body = NULL;

    //  set the ratioConstant
    /*  Ths is for the dynamic adjust to the different screen size
     * (showedHeight / windowHeight) = (1 / 20)
     * showedHeight = scale * pictureHeight
     */
    int sizeAdjustionRatioConstant = 10;
    imageScale = windowHeight / (sizeAdjustionRatioConstant * head->getAvatar()->getContentSize().height * 4);

    //  get position for tail
    CCPoint point = head->getPosition();
    point = getNextBackPosition(point, currentDirection);
    moveUnit = head->getMoveUnitPerStep();
    length = 0;

//    growUp();
//    growUp();


}

Snake::~Snake()
{
    for (int i = 0; i < length; i++)
    {
        delete bodyArr[i];
        bodyArr[i] = 0;
    }
}

void Snake::update()
{
    //  update the position for next movement
    CCPoint prePosition = head->getPosition();
    head->move();
    //prePosition = getNextBackPosition(prePosition, head->getDirection());

    //  for body
    for (int i = 0; i < length; i++)
    {
        CCPoint buff = bodyArr[i]->getPosition();
        bodyArr[i]->setPosition(prePosition);
        prePosition = buff;
    }
}

void Snake::growUp()
{
    if (length < 99 ) {
        //  get snake head position and direction
        CCPoint point = head->getPosition();

        //  create a snake body
        CCSprite* bodyItem = CCSprite::create("body.png", CCRectMake(0, 0, 100, 100));
        this->addChild(bodyItem);
        bodyItem->setScale(imageScale);

        if (length != 0)
        {
            for (int i = length; i > 0; i--)
            {
                bodyArr[i] = bodyArr[i - 1];
            }
        }

        //  set body item to head position
        bodyItem->setPosition(point);

        //  let head make a move
        point = head->getPosition();
        point = bodyItem->getPosition();

        //move head
        head->move();


        bodyArr[0] = bodyItem;

        length++;

    }

}

int Snake::getDirection()
{
    return currentDirection;
}

void Snake::setDirection(int value)
{
    currentDirection = value;
}

void Snake::move()
{
        head->setDirection(currentDirection);
        update();
}

CCPoint Snake::getNextBackPosition(CCPoint position, int currentDirection)
{
    float unit = head->getMoveUnitPerStep();
    //  get the next item position
    if (currentDirection == UP)
    {
        position.y -= unit;
    }
    else if (currentDirection == DOWN)
    {
        position.y += unit;
    }
    else if (currentDirection == RIGHT)
    {
        position.x -= unit;
    }
    else
    {
        position.x += unit;
    }
    return position;
}

CCRect Snake::getHeadRect()
{
    return head->areaRectangular;
}

bool Snake::isDead()
{
    float unit = head->getMoveUnitPerStep() / 2;

    for (int i = 0; i < length; i++)
    {
        float x = bodyArr[i]->getPosition().x;
        float y = bodyArr[i]->getPosition().y;
        CCRect areaRectangular = CCRectMake(
            x - unit / 2, y - unit / 2, unit, unit);

            if (getHeadRect().intersectsRect(areaRectangular))
            {
                CCLog("dead");
                return true;
            }
    }

    return false;
}

CCPoint Snake::getHeadPosition()
{
    CCPoint point = head->getPosition();
    return point;
}

CCPoint Snake::getBodyPosition(int index)
{
    CCPoint point = head->getPosition();
    if (index <= length && index > 0)
    {
        point = bodyArr[index]->getPosition();
    }
    return point;
}

int Snake::getLength()
{
    return length;
}
