// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 3

#include <iostream>
#include <vector>
#include "Pokemon.h"
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

// Definition of player class

class Player {
    private:
        string name;
        int pokeballs;
        int points;
        vector<Pokemon> team;
        vector<Pokemon> pokedex;
    
    public:
        Player();
        Player(string name);
        void addPokemon(Pokemon &add);
        string getName();
        int getPokeballs();
        void setPoints(int points);
        int getPoints();
        void setPokeballs(int pokeballs);
        void increasePoints(int points);
        void increaseHP();
        void setStarter(int newP);
        void setStarter(Pokemon &newP);
        Pokemon getStarter();
        vector<Pokemon> getTeam();
        void acquirePokemon(Pokemon &newPokemon);
        void printTeam();
        void updatePokedex(Pokemon &update);
        void getPokedex();
        void newActiveTeam(string choices[]);
        int teamSize();
        int getHP1();
        void setHP1(int hp);
        int getAttack1();
        int getDefense1();
        int getSpeed1();
        int getMax1();
        void increaseLevel(int choice);
        void healTeam();
        Pokemon removePokemon(int index);
        void printStats();
};

#endif