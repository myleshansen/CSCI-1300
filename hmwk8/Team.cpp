// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 8 - Problem 3: Team Class

#include <iostream>
#include <fstream>
#include "Team.h"
#include "Player.h"
using namespace std;

// Implementation of Team class

Team::Team()
{
    teamName = "";
}

Team::Team(string teamName)
{
    this->teamName = teamName;
    this->players = players;
}

void Team::setTeamName(string teamName)
{
    this->teamName = teamName;
}

/*
 * Algorithm: 
 * 1. Check if string is empty
 * 2. If not, loop through string
 * 3. If the character in string does not equal the delimeter add it to temp string
 * 4. Else, add string to array if it is not the delimeter
 * Input parameters: string sentence, char delimeter, string array, integer length
 * Output (prints to screen): Nothing
 * Returns: Words in array seperated by delimeter
 */
int split(string s, char delim, string words[], int len)
{
    string temp = ""; // Temp string
    int count= 0;
    if(s == "") // If string is empty return 0
    {
        return 0;
    }
    else
    {
        s += delim;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != delim) // If string is not delim add to temp string
            {
                temp += s[i];
            }
            else
            {
                if(temp == "") // If temp string is empty, move on
                {
                    continue;
                }
                else
                {
                    words[count] = temp; // Add temp string to array of words
                    temp = "";
                    count++;
                }
                
            }
        }
    }
    return count;
}

/*
 * Algorithm: Add users to roster
 * 1. Check if file exists
 * 2. Loop through file
 * 3. Add players to roster
 * Input parameters: string file name
 * Output (prints to screen): Nothing
 * Returns: Nothing
 */
void Team::readRoster(string fileName)
{
    ifstream myfile;
    myfile.open(fileName);
    
    if(myfile.is_open())
    {
        string line = "";
        string temp[2];
        int count = getNumPlayers();
        while(getline(myfile, line))
        {
            split(line, ',', temp, 2);
            players.push_back(Player(temp[0], stod(temp[1])));
        }
    }
}

string Team::getPlayerName(int i)
{
    if(i >= players.size() || i < 0) // Check if players is full
    {
        return "ERROR";
    }
    else
    {
        return players[i].getName();
    }
    
}

double Team::getPlayerPoints(int i)
{
    if(i >= players.size() || i < 0) // Check if players is full 
    {
        return -1;
    }
    else
    {
        return players[i].getPoints();
    }
    
}

int Team::getNumPlayers()
{
    return players.size();
}

string Team::getTeamName()
{
    return this-> teamName;
}