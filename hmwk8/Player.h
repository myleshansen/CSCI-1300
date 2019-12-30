// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 8 - Problem 2: Player Class

#include <iostream>
using namespace std;

// Define Player class

#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        string name;
        double points;
    public:
        Player();
        Player(string name, double points);
        string getName();
        double getPoints();
        void setName(string name);
        void setPoints(double points);
}

#endif