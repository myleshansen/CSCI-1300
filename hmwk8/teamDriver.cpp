// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 2 - Problem 0: Library Class

#include <iostream>
#include "Team.h"
#include "Player.h"
using namespace std;

int main()
{
    // Test 1
    // Expected output
    /*
    
     0
    */
    Team team1;
    cout << team1.getTeamName() << endl;
    cout << team1.getNumPlayers() << endl;
    
    // Test 2
    // Expected output
    /*
        Llamas Pajamas
        0
    */
    Team team2;
    team2.setTeamName("Llamas Pajamas");
    cout << team2.getTeamName() << endl;
    cout << team2.getNumPlayers() << endl;
}