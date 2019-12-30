// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 8 - Problem 2: Player Class

#include <iostream>
#include "Player.h"
using namespace std;

// Implementation of Player class

Player::Player()
{
    name = "";
    points = 0;
}

Player::Player(string name, double points)
{
    this->name = name;
    this->points = points;
}

string Player::getName()
{
    return name;
}

double Player::getPoints()
{
    return points;
}

void Player::setName(string name)
{
    this->name = name;
}

void Player::setPoints(double points)
{
    this->points = points;
}