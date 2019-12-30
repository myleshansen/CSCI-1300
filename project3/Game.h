// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 3

#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;

#ifndef GAME_H
#define GAME_H

// Definition of Game class

class Game {
    private:
        string map[25][16];
        Player player;
        vector<Player> trainers;
        Pokemon randoms[25][16];
        Pokemon pokeList[151];
        vector<string> types;
        int playerLocation[2];
        int active = 0;
        int encounterNumber = 0;
        int badges = 0;
        int typeCount = 0;
        
    public:
        Game(Player &player);
        int updateLocation(int row, int col);
        void loadMap();
        void printLocation();
        int gameOptions();
        void randomBattle(Pokemon &randomBattlePokemon, int encounterNumber);
        void pokemonList();
        void gymEncounter();
        void pokeCenter();
        void endGame(int result);
        void loadPokemon();
        void scatterPokemon();
        void loadRandomPokemon();
        int randomNumber();
        int checkPokemon(int pokePosition[], int size);
        int fight(Pokemon &random);
        int gymFight(Player &trainer);
        void luck();
        void endTurn();
        void loadTrainers();
        int findNearestCenter();
        int checkTypes(string type);
};

#endif