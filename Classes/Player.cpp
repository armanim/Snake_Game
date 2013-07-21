#include "Player.h"


Player::Player(Snake* snake)
{
    this->mySnake = snake;
    this->headPosition = snake->getHeadPosition();
}

int Player::searchDirection(CCPoint destination)
{
    this->headPosition = mySnake->getHeadPosition();
    //  get snake head position
    int currentDirection = mySnake->getDirection();

    //  if the distance is less than unit it is ok
    float unit = mySnake->moveUnit / 2;

    //  get the distance
    float x = destination.x - headPosition.x;
    float y = destination.y - headPosition.y;

    float X = abs(x);
    float Y = abs(y);

    if ((currentDirection == UP || currentDirection == DOWN) && X > unit)
    {
        if (x > 0)
            return RIGHT;
        else if (x < 0)
            return LEFT;
        else {}
    }
    else if ((currentDirection == RIGHT || currentDirection == LEFT) && Y > unit)
    {
        if (y > 0)
            return UP;
        else if (y < 0)
            return DOWN;
        else {}
    }
    else
    {
        return currentDirection;
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
    int currentDirection = searchDirection(destination);
    setDirection(currentDirection);
}

void Player::setDirection(int currentDirection)
{
    mySnake->setDirection(currentDirection);
}

void Player::adjustDirection(int currentDirection)
{
    //if (direction == UP)
}
