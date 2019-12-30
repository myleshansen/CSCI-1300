// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 3

#include <iostream>
#include <array>
#include <math.h>
#include "Player.h"
#include "Pokemon.h"
using namespace std;

// Implementation of Player class

Player::Player()
{
    name = "";
}
// Initialize Player
Player::Player(string name)
{
    this->name = name;
    pokeballs = 10;
    points = 0;
}
// Adding a pokemon to the team
void Player::addPokemon(Pokemon &add)
{
    team.push_back(add);
}

string Player::getName()
{
    return name;
}

int Player::getPokeballs()
{
    return pokeballs;
}

void Player::setPoints(int points)
{
    this->points = points;
}

int Player::getPoints()
{
    return points;
}

void Player::setPokeballs(int pokeballs)
{
    this->pokeballs += pokeballs;
}

void Player::increasePoints(int points)
{
    this->points += points;
}
// Increase HP of each pokemon in team
void Player::increaseHP()
{
    for(int i = 0; i < team.size(); i++)
    {
        if(team[i].getHP() >= team[i].getHpMax())
        {
            continue;
        }
        else
        {
            team[i].setHP(team[i].getHP() + 1);
        }
        
    }
}

void Player::setStarter(int newP)
{
    Pokemon temp = team[0];
    team[0] = team[newP];
    team.erase(team.begin() + newP - 1);
    team.push_back(temp);
}

void Player::setStarter(Pokemon &newP)
{
    Pokemon temp = team[0];
    team[0] = newP;
    team.push_back(temp);
}

Pokemon Player::getStarter()
{
    return team[0];
}

vector<Pokemon> Player::getTeam()
{
    return team;
}
// Add new pokemon to team with options
void Player::acquirePokemon(Pokemon &newPokemon)
{
    if(team.size() < 6)
    {
        
        team.push_back(newPokemon);
        cout << endl << "Awesome! You acquired " << newPokemon.getName() << " , who joins the Pokédex." << endl;
        cout << "Here is your active party:" << endl;
        for(int i = 0; i < team.size(); i++)
        {
            cout << i + 1 << ". " <<  team[i].getName() << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "Awesome! You acquired " << newPokemon.getName() << " , who joins the Pokédex. Your battle party is full. Do you want to add " << newPokemon.getName() << " to your Active Party? (Y/N): ";
        
        string choice;
        cin >> choice;
        if(choice == "Y" || choice == "y")
        {
            int choice2;
            cout << "Which Pokémon should not be part of the Active Party anymore:" << endl;
            for(int i = 0; i < 6; i++)
            {
                cout << i + 1 << ". " <<  team[i].getName() << endl;
            }
            cin >> choice2;
            team[choice2 - 1] = newPokemon;
            
            int active = 0;
            cout << "Great! The following Pokémon are now in your Active Party. Choose one of them to be your Active Pokémon: " << endl;
            for(int i = 0; i < 6; i++)
            {
                cout << i + 1 << ". " <<  team[i].getName() << endl;
            }
            cin >> active;
            setStarter(active - 1);
        }
    }
}

void Player::printTeam()
{
    for(int i = 0; i < team.size(); i++)
    {
        cout << i + 1 << ". " <<  team[i].getName() << endl;
    }
    cout << endl;
    
}

void Player::updatePokedex(Pokemon &update)
{
    pokedex.push_back(update);
}

void Player::getPokedex()
{
    for(int i = 0; i < pokedex.size(); i++)
    {
        cout << i + 1 << ". " <<  pokedex[i].getName() << endl;
    }
    cout << endl;
}

// Update team after Poke Center call
void Player::newActiveTeam(string choices[])
{
    int teamSize = team.size();
    team.clear();
    int count = 0;
    for(int i = 0; i < teamSize; i++)
    {
        if(choices[i] == "")
        {
            break;
        }
        team.push_back(pokedex[stoi(choices[i]) - 1]);
        count++;
    }
    
    int active = 0;
    cout << "You have chosen the " << count << " Pokémon below. Please choose which one should bethe ACTIVE Pokémon: " << endl;
    for(int i = 0; i < count; i++)
    {
        cout << i + 1 << ". " <<  team[i].getName() << endl;
    }
    cout << endl;
    cin >> active;
    if(active == 1)
    {
        
    }
    else
    {
        Pokemon starter = removePokemon(active);
        for(int i = 0; i < count; i++)
        {
            cout << i + 1 << ". " <<  team[i].getName() << endl;
        }
        team.push_back(team[0]);
        team[0] = starter;
    }
    
}

int Player::teamSize()
{
    return team.size();
}

int Player::getHP1()
{
    return team[0].getHP();
}

void Player::setHP1(int hp)
{
    team[0].setHP(hp);
}

int Player::getAttack1()
{
    return team[0].getAttack();
}

int Player::getDefense1()
{
    return team[0].getDefense();
}

int Player::getSpeed1()
{
    return team[0].getSpeed();
}

int Player::getMax1()
{
    return team[0].getMax();
}

void Player::increaseLevel(int choice)
{
    cout << "Level UP! Here are your new stats: " << endl;
    team[choice].setLevel(team[choice].getLevel() + 1);
    if(team[choice].getAttack() < team[choice].getMax() && team[choice].getDefense() < team[choice].getMax())
    {
        team[choice].setAttack(ceil(team[choice].getAttack() + team[choice].getAttack() * 0.02));
        team[choice].setSpeed(ceil(team[choice].getSpeed() + team[choice].getSpeed() * 0.02));
        team[choice].setHpMax(ceil(team[choice].getHpMax() + team[choice].getHpMax() * 0.02));
        team[choice].setHP(team[choice].getHpMax());
        team[choice].setDefense(ceil(team[choice].getDefense() + team[choice].getDefense() * 0.02));
    }
    
    cout << team[choice].getName() << " - Level " << team[choice].getLevel() << endl;
    cout << "HP: " << team[choice].getHP() << ", A: " << team[choice].getAttack() << ", D: " << team[choice].getDefense() << ", S: " << team[choice].getSpeed() << ", M: " << team[choice].getMax() << endl << endl;
}

void Player::healTeam()
{
    for(int i = 0; i < team.size(); i++)
    {
        team[i].setHP(team[i].getHpMax());
    }
}

Pokemon Player::removePokemon(int index)
{
    Pokemon removed = team[index - 1];
    team.erase(team.begin() + index - 1);
    return removed;
}

void Player::printStats()
{
    for(int i = 0; i < team.size(); i++)
    {
        cout << "Name: " << team[i].getName() << " (ACTIVE), HP: " << team[i].getHP() << ", A: " << team[i].getAttack() << ", D: " << team[i].getDefense() << ", S: " << team[i].getSpeed() << ", M: " << team[i].getMax() << endl;
    }
}


