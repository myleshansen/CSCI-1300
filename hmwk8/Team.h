// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 8 - Problem 3: Team Class

#include <iostream>
using namespace std;

// Define Player class

#ifndef TEAM_H
#define TEAM_H

class Team {
    private:
        string teamName;
        vector<Player> players;
    public:
        Team();
        Team(string teamName);
        void setTeamName(string teamName);
        void readRoster(string fileName);
        string getPlayerName(int i);
        double getPlayerPoints(int i);
        int getNumPlayers();
        string getTeamName();
};

#endif