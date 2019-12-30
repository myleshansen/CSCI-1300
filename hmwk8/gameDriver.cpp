// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 8 - Problem 4: game

#include <iostream>
#include "Team.h"
#include "Player.h"
using namespace std;

/*
 * Algorithm: Find the result of a game
 * 1. Check if teams have enough players
 * 2. Add up scores
 * 3. print winner or draw
 * Input parameters: Team 1 and Team 2
 * Output (prints to screen): forfeit, draw, or team winner
 * Returns: Nothing
 */
string game(Team t1, Team t2)
{
    if(t1.getNumPlayers() < 4 || t2.getNumPlayers() < 4)
    {
        return "forfeit";
    }
    else
    {
        int score1 = 0;
        int score2 = 0;
        for(int i = 0; i < 4; i++)
        {
            score1 += t1.getPlayerPoints(i);
            score2 += t2.getPlayerPoints(i);
        }
        if(score1 == score2)
        {
            return "draw";
        }
        else if(score1 > score2)
        {
            return t1.getTeamName();
        }
        else
        {
            return t2.getTeamName();
        }
    }
}

int main()
{
    // Test 1
    // Expected output
    /*
        The winner is: Seg Faultline
    */
    Team team1("Seg Faultline");
    team1.readRoster("roster1.txt");
    Team team2("Team Maim");
    team2.readRoster("roster2.txt");
    string winner = game(team1, team2);
    cout << "The winner is: " << winner << endl;
    
    // Test 2
    // Expected output
    /*
        The winner is: draw
    */
    Team team4("Thats so Ravenclaw");
    team4.readRoster("roster1.txt");
    Team team5("Planes on a Snake");
    team5.readRoster("roster1.txt");
    string winner = game(team4, team5);
    cout << "The winner is: " << winner << endl;
}