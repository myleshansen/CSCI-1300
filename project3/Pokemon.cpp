// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 3

#include <iostream>
#include "Pokemon.h"
using namespace std;

// Implementation of Pokemon class

Pokemon::Pokemon()
{
    hp = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    max = 0;
    name = "";
    activeStatus = false;
    level = 1;
}

// Initialize pokemon
Pokemon::Pokemon(int hp, int attack, int defense, int speed, int max, string name, string type1, string type2)
{
    this->hp = hp;
    this->hpMax = hp;
    this->attack = attack;
    this->defense = defense;
    this->speed = speed;
    this->max = max;
    this->name = name;
    this->type1 = type1;
    this->type2 = type2;
    level = 1;
}

int Pokemon::getHpMax()
{
    return hpMax;
}

void Pokemon::setHpMax(int hpMax)
{
    this->hpMax = hpMax;
}

int Pokemon::getHP()
{
    return this->hp;
}

void Pokemon::setHP(int hp)
{
    this->hp = hp;
}

int Pokemon::getAttack()
{
    return attack;
}

void Pokemon::setAttack(int attack)
{
    this->attack = attack;
}

int Pokemon::getDefense()
{
    return defense;
}

void Pokemon::setDefense(int defense)
{
    this->defense = defense;
}

int Pokemon::getSpeed()
{
    return speed;
}

void Pokemon::setSpeed(int speed)
{
    this->speed = speed;
}

int Pokemon::getMax()
{
    return max;
}

void Pokemon::setMax(int max)
{
    this->max = max;
}

string Pokemon::getName()
{
    return name;
}

bool Pokemon::getActiveStatus()
{
    return activeStatus;
}

void Pokemon::setActiveStatus(bool active)
{
    this->activeStatus = activeStatus;
}

int Pokemon::getLevel()
{
    return level;
}

void Pokemon::setLevel(int level)
{
    this->level = level;
}

string Pokemon::getType1()
{
    return type1;
}
string Pokemon::getType2()
{
    return type2;
}