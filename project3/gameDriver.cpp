// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 3

#include <iostream>
#include "Game.h"
#include "Pokemon.h"
#include "Player.h"
#include "Intro.h"
#include <time.h>
using namespace std;


int main()
{ // Load intro class
    int playAgain = 1;
    while(playAgain != 0) // Check if user wants to play again
    {
        Intro i1 = Intro();
        playAgain = i1.gameStart(); // Prints intro and starts game
        if(playAgain == 0) // If player chose to quit
        {
            playAgain =  5;
            while(playAgain != 1 && playAgain != 0)
            {
                cout << "Do you want to to play again? (1: yes, 0: no) "; // Ask if user wants to play again
                cin >> playAgain;
                cin.ignore();
                if(playAgain != 1 && playAgain != 0)
                {
                    cout << "Invalid choice." << endl;
                }
            }
        }
        else // If player wins
        {
            playAgain =  5;
            while(playAgain != 1 && playAgain != 0)
            {
                cout << "Do you want to to play again? (1: yes, 0: no) "; // Ask if use wants to play again
                cin >> playAgain;
                cin.ignore();
                if(playAgain != 1 && playAgain != 0)
                {
                    cout << "Invalid choice." << endl;
                }
            }
        }
    }
    
}