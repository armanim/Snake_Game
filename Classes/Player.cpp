#include "Player.h"

#ifndef UP DOWN RIGHT LEFT

#define UP 0
#define DOWN 2
#define RIGHT 1
#define LEFT 3

#endif


Player::Player(Snake* snake)
{
    this->mySnake = snake;
    this->headPosition = snake->getHeadPosition();
}

int Player::searchDirection(CCPoint destination)
{
    this->headPosition = mySnake->getHeadPosition();
    //  get snake head position
    int direction = mySnake->getDirection();

    //  if the distance is less than unit it is ok
    float unit = mySnake->moveUnit / 2;

    //  get the distance
    float x = destination.x - headPosition.x;
    float y = destination.y - headPosition.y;

    float X = abs(x);
    float Y = abs(y);

    if ((direction == UP || direction == DOWN) && X > unit)
    {
        if (x > 0)
            return RIGHT;
        else if (x < 0)
            return LEFT;
        else {}
    }
    else if ((direction == RIGHT || direction == LEFT) && Y > unit)
    {
        if (y > 0)
            return UP;
        else if (y < 0)
            return DOWN;
        else {}
    }
    else
    {
        return direction;
    }
}

bool Player::checkUp(CCRect areaRect)
{
    float unit = mySnake->moveUnit / 2;
    upRect = CCRectMake(headPosition.x, headPosition.y + unit + unit / 2, unit, unit);

    //  if is avalible return true
    if (upRect.intersectsRect(areaRect))
        return false;
    return true;
}

bool Player::checkDown(CCRect areaRect)
{
    float unit = mySnake->moveUnit / 2;
    downRect = CCRectMake(headPosition.x, headPosition.y - unit - unit / 2, unit, unit);

    //  if is avalible return true
    if (downRect.intersectsRect(areaRect))
        return false;
    return true;
}

bool Player::checkRight(CCRect areaRect)
{
    float unit = mySnake->moveUnit / 2;
    rightRect = CCRectMake(headPosition.x  + unit + unit / 2, headPosition.y, unit, unit);

    //  if is avalible return true
    if (rightRect.intersectsRect(areaRect))
        return false;
    return true;
}

bool Player::checkLeft(CCRect areaRect)
{
    float unit = mySnake->moveUnit / 2;
    leftRect = CCRectMake(headPosition.x - unit - unit / 2, headPosition.y, unit, unit);

    //  if is avalible return true
    if (leftRect.intersectsRect(areaRect))
        return false;
    return true;
}

void Player::play(CCPoint destination)
{
    int direction = searchDirection(destination);
    setDirection(direction);
}

void Player::setDirection(int direction)
{
    mySnake->setDirection(direction);
}

void Player::adjustDirection(int direction)
{
    //if (direction == UP)
}
