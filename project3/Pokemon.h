// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 3

#include <iostream>
using namespace std;

#ifndef POKEMON_H
#define POKEMON_H

// Definiton of Pokemon class

class Pokemon {
    private:
        string name;
        int hp;
        int hpMax;
        int attack;
        int defense;
        int speed;
        int max;
        bool activeStatus;
        int level;
        string type1;
        string type2;
    
    public:
        Pokemon();
        Pokemon(int hp, int attack, int defense, int speed, int max, string name, string type1, string type2);
        int getHpMax();
        void setHpMax(int hpMax);
        int getHP();
        void setHP(int hp);
        int getAttack();
        void setAttack(int attack);
        int getDefense();
        void setDefense(int defense);
        int getSpeed();
        void setSpeed(int speed);
        int getMax();
        void setMax(int max);
        string getName();
        bool getActiveStatus();
        void setActiveStatus(bool active);
        int getLevel();
        void setLevel(int level);
        string getType1();
        string getType2();
        
    
};

#endif