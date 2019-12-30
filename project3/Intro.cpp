// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 3

#include <iostream>
#include <time.h>
#include "Game.h"
#include "Pokemon.h"
#include "Player.h"
#include "Intro.h"

using namespace std;

// Implementation of Intro class


Intro::Intro() // Initialize Intro class
{
    
}

int Intro::gameStart()
{
    srand(time(NULL)); // New token for rand() calls
    cout << "Welcome to Pokemon!" << endl << endl;
    
    string name  = "";
    cout << "Please state your name: ";
    
    
    getline(cin, name); // Get name
    cout << endl;
    Player user = Player(name);
    
    cout << "Welcome, " << name << "! Before you can begin your Pokémon adventure, you must choose a starting Pokémon, courtesy of the Professor. Please choose from the following Pokémon:" << endl;
    cout << endl;
    
    bool test = false;
    int choice = 0;
    bool win = false;
    bool lose = false;
    
    while(test != true)
    {
        // Choose initial pokemon
        cout << "1. Bublasaur: " << endl;
        cout << "2. Charmander: " << endl;
        cout << "3. Squirtle: " << endl;
        cout << "4. Pikachu: " << endl;
        cin >> choice;
        if(choice == 1)
        {
            Pokemon starter = Pokemon(45, 49, 49, 45, 65, "Bulbasaur", "Grass", "Poison");
            starter.setActiveStatus(true);
            user.addPokemon(starter);
            user.updatePokedex(starter);
            test = true;
            
            Game g1 = Game(user);
            g1.loadMap(); // Load game map
            g1.loadPokemon(); // load Pokemon
            g1.updateLocation(12, 6); // Position of player
            while(win == false && lose == false)
            {
                return g1.gameOptions();
            }
            
        }
        else if(choice == 2)
        {
            test = true;
            Pokemon starter = Pokemon(39, 52, 43, 65, 50, "Charmander", "Fire", "");
            starter.setActiveStatus(true);
            user.addPokemon(starter);
            user.updatePokedex(starter);
            
            Game g1 = Game(user);
            g1.loadMap();
            g1.loadPokemon();
            g1.updateLocation(12, 7);
            while(win == false && lose == false)
            {
                return g1.gameOptions();
            }
        }
        else if(choice == 3)
        {
            test = true;
            Pokemon starter = Pokemon(44, 48, 65, 43, 50, "Squirtle", "Water", "");
            starter.setActiveStatus(true);
            user.addPokemon(starter);
            user.updatePokedex(starter);
            
            Game g1 = Game(user);
            g1.loadMap();
            g1.loadPokemon();
            g1.updateLocation(12, 8);
            while(win == false && lose == false)
            {
                return g1.gameOptions();
            }
            
        }
        else if(choice == 4)
        {
            test = true;
            Pokemon starter = Pokemon(35, 55, 30, 90, 50, "Pikachu", "Electric", "");
            starter.setActiveStatus(true);
            user.addPokemon(starter);
            user.updatePokedex(starter);
            Game g1 = Game(user);
            g1.loadMap();
            g1.loadPokemon();
            g1.updateLocation(12, 9);
            while(win == false && lose == false)
            {
                return g1.gameOptions();
            }
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }
}