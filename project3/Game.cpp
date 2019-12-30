// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 3

#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include "Game.h"
#include "Player.h"
#include "Pokemon.h"
using namespace std;

// Implementation of game class

Game::Game(Player &player)
{
    this->player = player;
    playerLocation[0] = 0;
    playerLocation[1] = 0;
    loadTrainers(); // Initialize trainers
    loadPokemon(); // Load all pokemon into game
    int randPartyNum = rand() % 6; // Create trainers party size
    if(randPartyNum == 0) // Make sure size is not zero
    {
        randPartyNum++;
    }
    for(int i = 0; i < 8; i++) // Initialze types array
    {
        types.push_back("");
    }
    
    int temp = 0;
    int random = 0;
    for(int i = 0; i < trainers.size(); i++) // Load trainers with their pokemon
    {   
        for(int j = 0; j < randPartyNum; j++)
        {
            random = rand() % 151;
            if(temp == random)
            {
                random++;
                temp = random;
            }
            else
            {
                temp = random;
            }
            trainers[i].addPokemon(pokeList[random]);
        }
    }
}

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

// Load map with indicators
void Game::loadMap()
{
    ifstream myfile;
    myfile.open("mapPoke.txt"); // Open map text
    if(myfile.is_open())
    {
        string line = "";
        string temp[16];
        int counter = 0;
        while(getline(myfile,line))
        {
            split(line, ',', temp, 16);
            for(int i = 0; i < 16; i++)
            {
                if(temp[i].substr(0,1) == "w")
                {
                    map[counter][i] = "~";
                }
                else if(temp[i].substr(0,1) == "p")
                {
                    map[counter][i] = "*";
                }
                else
                {
                    map[counter][i] = temp[i];
                }
            }
            counter++;
        }
    }
}

void Game::printLocation()
{ 
    // Make sure player's position is not on the edge
    int tempRow = 0;
    int tempCol = 0;
    if(playerLocation[0] - 3 < 0)
    {
        if(playerLocation[0] - 2 < 0)
        {
            tempRow = 0;
        }
        else if(playerLocation[0] - 1 < 0)
        {
            tempRow = 0;
        }
        else
        {
            tempRow = 0;
        }
    }
    else
    {
        tempRow = playerLocation[0] - 3;
    }
    
    if(playerLocation[1] - 3 < 0)
    {
        if(playerLocation[1] - 2 < 0)
        {
            tempCol = 0;
        }
        else if(playerLocation[1] - 1 < 0)
        {
            tempCol = 0;
        }
        else
        {
            tempCol = 0;
        }
    }
    else
    {
        tempCol = playerLocation[1] - 3;
    }
    
    // Load map with bars to improve user readability
    for(int i = tempRow; i < tempRow + 7; i++)
    {
        cout << "| ";
        for(int j = tempCol; j < tempCol + 7; j++)
        {
            cout << map[i][j] << " | ";
        }
        cout << endl;
    }
}

// Update the player's position after movement
int Game::updateLocation(int row, int col)
{
    if(map[row][col] == "~") // Make sure new position is not water
    {
        return -1;
    }
    else if(map[row][col] == "C") // Check if position is a Poke Center
    {
        map[row][col] = "@";
        map[playerLocation[0]][playerLocation[1]] = "C";
        playerLocation[0] = row;
        playerLocation[1] = col;
        return 0;
    }
    else if(map[row][col] == "G") // Check if position is a Gym
    {
        map[row][col] = "@";
        map[playerLocation[0]][playerLocation[1]] = "G";
        playerLocation[0] = row;
        playerLocation[1] = col;
        return 2;
    }
    else if(row < 0 || col < 0 || row > 25 || col > 16) // Check if player is in bounds
    {
        return 4;
    }
    else if(map[row][col] == "*" || map[row][col] == "P") // Check if space is grass
    {
        
        map[row][col] = "@";
        map[playerLocation[0]][playerLocation[1]] = "*";
        playerLocation[0] = row;
        playerLocation[1] = col;
        return 3;
    }
    
    /*
        Update the players location on the map.
        If the player runs into a water tile, return -1
        If the player is out of bounds, return 0
        If the player moves to a valid location return 1
    */
    
    return 1;
}

/*
    Main game loop,
    Allows the player to move and generates main game functions
*/
int Game::gameOptions()
{
    loadRandomPokemon(); // Load random pokemon positions on the map
    int choice = 0;
    int encounterNumber = 0;
    while(choice != 4)
    {
        if(badges >= 6) // Check if player has enough badges to win
        {
            endGame(1);
            return 1;
        }
        else if(typeCount >= 2) // Check if player has enough types to win
        {
            endGame(1);
            return 1;
        }
        //scatterPokemon(); // Random movement of pokemon every turn
        printLocation(); // Print smaller map with player's position
        int pokePosition[2];
        if(checkPokemon(pokePosition, 5) == 1) // Check if a pokemon is within the vicinity
        {
            randomBattle(randoms[pokePosition[0]][pokePosition[1]], encounterNumber);
            randoms[pokePosition[0]][pokePosition[1]] = Pokemon();
            map[pokePosition[0]][pokePosition[1]] = "*";
            encounterNumber++;
        }
        
        cout << "The sun is shining, " << player.getName() << "! It’s a beautiful day, we have "<< player.getPokeballs() << " Pokéball(s) left and your Pokémon are strong." << endl << endl;
        
        player.printStats();
        
        cout << "Please choose from the following options:" << endl << endl;
        cout << "1. Travel: " << endl;
        cout << "2. Rest: " << endl;
        cout << "3. Try your luck: " << endl;
        cout << "4. Quit the game: " << endl;
        cin >> choice;
        
        if(choice == 1)
        {
            string direction = "";
            while(true)
            {
                cout << "Would you like to travel north, south, east, or west? ";
                cin >> direction;
                cout << endl;
                if(direction == "north")
                {
                    int result = updateLocation(playerLocation[0] -1, playerLocation[1]);
                    if(result == -1) // Water
                    {
                        cout << "This is water pick a new direction." << endl;
                    }
                    else if(result == 0) // Poke Center
                    {
                        pokeCenter();
                    }
                    else if(result == 2) // Gym
                    {
                        gymEncounter();
                    }
                    else if(result == 4) // Out of bounds
                    {
                        cout << "This is out of bounds pick a new direction." << endl;
                    }
                    else if(result == 3) // Valid position
                    {
                        
                    }
                    break;
                }
                else if(direction == "south")
                {
                    int result = updateLocation(playerLocation[0] + 1, playerLocation[1]);
                    if(result == -1) // Water
                    {
                        cout << "This is water pick a new direction." << endl;
                    }
                    else if(result == 0) // Poke Center
                    {
                        pokeCenter();
                    }
                    else if(result == 2) // Gym
                    {
                        gymEncounter();
                    }
                    else if(result == 4) // Out of bounds
                    {
                        cout << "This is out of bounds pick a new direction." << endl;
                    }
                    else if(result == 3) // Valid position
                    {
                        
                    }
                    break;
                }
                else if(direction == "east")
                {
                    int result = updateLocation(playerLocation[0], playerLocation[1] + 1);
                    if(result == -1) // Water
                    {
                        cout << "This is water pick a new direction." << endl;
                    }
                    else if(result == 0) // Poke Center
                    {
                        pokeCenter();
                    }
                    else if(result == 2) // Gym
                    {
                        gymEncounter();
                    }
                    else if(result == 4) // Out of bounds
                    {
                        cout << "This is out of bounds pick a new direction." << endl;
                    }
                    else if(result == 3) // Valid position
                    {
                        
                    }
                    break;
                }
                else if(direction == "west")
                {
                    int result = updateLocation(playerLocation[0], playerLocation[1] - 1);
                    if(result == -1) // Water
                    {
                        cout << "This is water pick a new direction." << endl;
                    }
                    else if(result == 0) // Poke Center
                    {
                        pokeCenter();
                    }
                    else if(result == 2) // Gym
                    {
                        gymEncounter();
                    }
                    else if(result == 4) // Out of bounds
                    {
                        cout << "This is out of bounds pick a new direction." << endl;
                    }
                    else if(result == 3) // Valid position
                    {
                        
                    }
                    break;
                }
                else
                {
                    cout << "Invalid choice." << endl;
                    continue;
                }
            }
            // call update location and continue based on results   
        }
        else if(choice == 2) // Rest option
        {
            player.increaseHP();
            player.setPokeballs(-1);
            // Rest option, increase HP and decrese pokeballs
        }
        else if(choice == 3) // Try their luck option
        {
            luck();
        }
        else if(choice == 4) // Quit game
        {
            endGame(0);
            return 0;
            // Quit game
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
        // Update location of pokemon
        endTurn(); // Random events at the end of each turn
    }
}

// Battle sequence with random pokemon
void Game::randomBattle(Pokemon &randomBattlePokemon, int encounterNumber1)
{
    int encounterNumber = encounterNumber1;
    int escapeTries = 1;
    int flee = 0;
    bool escape = false;
    int teamSize = player.teamSize();
    int partyNumber = 0;
    if(encounterNumber < 0) // Make sure this is not the first encounter, if not acquire pokemon
    {
        encounterNumber++;
        cout << "You ran into a wild Pokemon!" << endl;
        cout << randomBattlePokemon.getName() << ", HP: " << randomBattlePokemon.getHP() << ", A: " << randomBattlePokemon.getAttack() << ", D: " << randomBattlePokemon.getDefense() << ", S: " << randomBattlePokemon.getSpeed() << ", M: " << randomBattlePokemon.getMax() << endl;
        
        
        cout << endl<< "Your ACTIVE Pokemon is:" << endl;
        cout << player.getStarter().getName() << ", HP: " << player.getHP1() << ", A: " << player.getAttack1() << ", D: " << player.getDefense1() << ", S: " << player.getSpeed1() << ", M: " << player.getMax1() << endl << endl;
        int tempRow = 0;
        int tempCol = 0;
        if(playerLocation[0] - 3 < 0)
        {
            if(playerLocation[0] - 2 < 0)
            {
                tempRow = 0;
            }
            else if(playerLocation[0] - 1 < 0)
            {
                tempRow = 0;
            }
            else
            {
                tempRow = 0;
            }
        }
        else
        {
            tempRow = playerLocation[0] - 3;
        }
        
        if(playerLocation[1] - 3 < 0)
        {
            if(playerLocation[1] - 2 < 0)
            {
                tempCol = 0;
            }
            else if(playerLocation[1] - 1 < 0)
            {
                tempCol = 0;
            }
            else
            {
                tempCol = 0;
            }
        }
        else
        {
            tempCol = playerLocation[1] - 3;
        }
        
        player.setPokeballs(-1);
        player.increasePoints(10);
        cout << "They have been added to your party because this is one of your first encounters!" << endl << endl;
        player.acquirePokemon(randomBattlePokemon);
        player.updatePokedex(randomBattlePokemon);
        
    }
    else // Else, begin battle
    {
        int win = 0;
        int pokeEscape = rand() % 100;
        cout << "You ran into a wild Pokemon!" << endl;
        cout << randomBattlePokemon.getName() << ", HP: " << randomBattlePokemon.getHP() << ", A: " << randomBattlePokemon.getAttack() << ", D: " << randomBattlePokemon.getDefense() << ", S: " << randomBattlePokemon.getSpeed() << ", M: " << randomBattlePokemon.getMax() << endl;
        
        
        cout << endl<< "Your ACTIVE Pokemon is:" << endl;
        cout << player.getStarter().getName() << ", HP: " << player.getHP1() << ", A: " << player.getAttack1() << ", D: " << player.getDefense1() << ", S: " << player.getSpeed1() << ", M: " << player.getMax1() << endl;
        
        int choice = 0;
        while(escape == false)
        {
            if(win == 1) // If pokemon wins, increase level
            {
                teamSize--;
                partyNumber++;
                randomBattlePokemon.setLevel(randomBattlePokemon.getLevel() + 1);
                randomBattlePokemon.setAttack(ceil(randomBattlePokemon.getAttack() + randomBattlePokemon.getAttack() * 0.02));
                randomBattlePokemon.setSpeed(ceil(randomBattlePokemon.getSpeed() + randomBattlePokemon.getSpeed() * 0.02));
                randomBattlePokemon.setHpMax(ceil(randomBattlePokemon.getHpMax() + randomBattlePokemon.getHpMax() * 0.02));
                randomBattlePokemon.setHP(randomBattlePokemon.getHpMax());
                randomBattlePokemon.setDefense(ceil(randomBattlePokemon.getDefense() + randomBattlePokemon.getDefense() * 0.02));
                if(teamSize <= 0) // If no more pokemon remain in your party, transport to nearest center
                {
                    findNearestCenter();
                    pokeCenter();
                    break; 
                }
                else // Else, move on to next pokemon
                {
                    player.setStarter(partyNumber);
                }
            }
            else if(win == 2) // If player wins, acquire pokemon and increase level
            {
                randomBattlePokemon.setHP(randomBattlePokemon.getHpMax());
                player.acquirePokemon(randomBattlePokemon);
                player.updatePokedex(randomBattlePokemon);
                player.increaseLevel(0);
                break;
            }
            
            // Battle options
            cout << endl << "What do you want to do (pick 1, 2, or 3): " << endl;
            cout << "   1. Fight: " << endl;
            cout << "   2. Switch Active Pokemon: " << endl;
            cout << "   3. Run: " << endl;
            cin >> choice;
            if(pokeEscape <= 40) // Check if pokemon can flee
            {
                cout << endl << "The pokemon fled." << endl << endl;
                int randomP = 0;
                int randomP2 = 0;
                // Move pokemon to random location
                for(int i = 0; i < 25; i++)
                {
                    for(int j = 0; j < 16; j++)
                    {
                        if(randoms[i][j].getName() == randomBattlePokemon.getName())
                        {
                            randoms[i][j] = Pokemon();
                            randomP = rand() % 25;
                            randomP2 = rand() % 16;
                            while(map[randomP][randomP2] != "*") // Check if new position is grass
                            {
                                randomP = rand() % 25;
                                randomP2 = rand() % 16;
                            }
                            randoms[randomP][randomP2] = randomBattlePokemon;
                        }
                    }
                }
                break;
            }
            
            if(choice == 1) // If player chooses to fight
            {
                win = fight(randomBattlePokemon);
            }
            else if(choice == 2) // If player chooses to switch pokemon
            {
                int activePokemon;
                cout << "Pick another Active Pokemon:" << endl;
                player.printTeam();
                cin >> activePokemon;
                player.setStarter(activePokemon - 1);
                cout << endl<< "Your ACTIVE Pokemon is:" << endl;
                cout << player.getStarter().getName() << ", HP: " << player.getHP1() << ", A: " << player.getAttack1() << ", D: " << player.getDefense1() << ", S: " << player.getSpeed1() << ", M: " << player.getMax1() << endl << endl;
            }
            else if(choice == 3) // If player decides to flee, calculate chance
            {
                flee = ((randomBattlePokemon.getSpeed() * 32) / player.getSpeed1()) + 30 * escapeTries;
                if (flee > 255 || player.getSpeed1() > randomBattlePokemon.getSpeed())
                {
                    escape = true;
                    cout << "You have escaped!" << endl;
                }
                else
                {
                    int escape2 = rand() % 256;
                    if(escape2 < flee)
                    {
                        escape = true;
                    }
                    else
                    {
                        escapeTries++;
                        cout << "Escape unsuccessful" << endl;
                    }
                }
            }
            else
            {
                cout << "Invalid choice." << endl;
            }
        }
    }
    
}

// Poke center options
void Game::pokeCenter()
{
    
    char change = ' ';
    player.healTeam(); // Heal pokemon
    cout << "Welcome to the Pokémon Center. All Pokémon in your party have been healed. Do you want to change the members of your party (Y/N): ";
    cin >> change;
    
    string choices = "";
    if(change == 'Y' || change == 'y') // Check if player wants to change pokemon
    {
        cout << "Here are all the Pokémon in your Pokédex. Choose at most 6 numbers, followed by Q for quit:" << endl;
        player.getPokedex();
        cin.ignore(1000, '\n');
        getline(cin,choices);
        string choices2[6];
        split(choices, ' ', choices2, 6);
        player.newActiveTeam(choices2);
    }
}

// Intiliaze pokemon text file and load them into game
void Game::loadPokemon()
{
    ifstream myfile;
    myfile.open("pokemon.txt"); // Open text file
    if(myfile.is_open())
    {
        string line = "";
        string temp[9];
        int counter = 0;
        while(getline(myfile,line))
        {
            split(line, ',', temp, 9);
            for(int i = 0; i < 9; i++)
            {
                // Import and split pokemon stats
                pokeList[counter] = Pokemon(stoi(temp[2]), stoi(temp[3]), stoi(temp[4]), stoi(temp[5]), stoi(temp[6]), temp[1], temp[7], temp[8]);
            }
            counter++;
        }
    }
}

// Generate random positions for pokemon
void Game::loadRandomPokemon()
{
    int counter = 0;
    int random;
    for(int i = 0; i < 25; i++)
    {
        
        for(int j = 0; j < 16; j++)
        {
            random = rand() % 151;
            if(map[i][j] == "*")
            {
                if(random > 135 && counter < 20)
                {
                    randoms[i][j] = pokeList[rand() % 151];
                    map[i][j] = "P";
                    counter++;
                }
                else
                {
                    randoms[i][j] = Pokemon();
                    continue;
                    
                }
            }
            else
            {
                randoms[i][j] = Pokemon();
                continue;
            }
        }
    }
}

// Check if a pokemon is in the general vicinity
int Game::checkPokemon(int pokePosition[], int size)
{
    int tempRow = 0;
    int tempCol = 0;
    // Make sure you are not checking out of bounds
    if(playerLocation[0] - 3 < 0)
    {
        if(playerLocation[0] - 2 < 0)
        {
            tempRow = 0;
        }
        else if(playerLocation[0] - 1 < 0)
        {
            tempRow = 0;
        }
        else
        {
            tempRow = 0;
        }
    }
    else
    {
        tempRow = playerLocation[0] - 3;
    }
    
    if(playerLocation[1] - 3 < 0)
    {
        if(playerLocation[1] - 2 < 0)
        {
            tempCol = 0;
        }
        else if(playerLocation[1] - 1 < 0)
        {
            tempCol = 0;
        }
        else
        {
            tempCol = 0;
        }
    }
    else
    {
        tempCol = playerLocation[1] - 3;
    }
    
    
    for(int i = tempRow; i < tempRow + size; i++)
    {
        for(int j = tempCol; j < tempCol + size; j++)
        {
            if(randoms[i][j].getName() != "")
            {
                pokePosition[0] = i;
                pokePosition[1] = j;
                return 1;
            }
        }
    }
    return 0;
}

// Random movement of pokemon every round
void Game::scatterPokemon()
{
    int rand1 = 0;
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            rand1 = rand() % 4; // Generate random direction
            if(map[i][j] == "P" && i + 1 != 25 && i - 1 != -1 && j + 1 != 16 && j - 1 != -1) // Make sure pokemon does not move out of bounds
            {
                if(map[i + 1][j] == "*" && rand1 == 0)
                {
                    map[i][j] = "*";
                    map[i + 1][j] = "P";
                    randoms[i + 1][j] = randoms[i][j];
                    randoms[i][j] = Pokemon();
                }
                else if(map[i - 1][j] == "*" && rand1 == 1)
                {
                    map[i][j] = "*";
                    map[i - 1][j] = "P";
                    randoms[i - 1][j] = randoms[i][j];
                    randoms[i][j] = Pokemon();
                }
                else if(map[i][j + 1] == "*" && rand1 == 2)
                {
                    map[i][j] = "*";
                    map[i][j + 1] = "P";
                    randoms[i][j + 1] = randoms[i][j];
                    randoms[i][j] = Pokemon();
                    
                }
                else if(map[i][j - 1] == "*" && rand1 == 3)
                {
                    map[i][j] = "*";
                    map[i][j - 1] = "P";
                    randoms[i][j - 1] = randoms[i][j];
                    randoms[i][j] = Pokemon();
                }
            }
        }
    }
}

// Main fight sequence for random pokemon
int Game::fight(Pokemon &random)
{
    int a = 0;
    int d = 0;
    if(player.getSpeed1() > random.getSpeed()) // Check who fights first
    {
        cout << player.getStarter().getName() << " attacks first" << endl;
        a = rand() % player.getAttack1();
        d = rand() % random.getDefense();
        if(a > d)
        {
            cout << player.getStarter().getName() << " deals " << a << " damage" << endl;
            random.setHP(random.getHP() - a);
        }
        else
        {
            cout << "Attack Missed!" << endl;
        }
        
        if(random.getHP() <= 0) // Check if pokemon has no HP
        {
            a = 0;
            d = 0;
            cout << random.getName() << ", HP: " << random.getHP() << ", A: " << random.getAttack() << ", D: " << random.getDefense() << ", S: " << random.getSpeed() << ", M: " << random.getMax() << endl;
            cout << player.getStarter().getName() << ", HP: " << player.getHP1() << ", A: " << player.getAttack1() << ", D: " << player.getDefense1() << ", S: " << player.getSpeed1() << ", M: " << player.getMax1() << endl;
            return 2;
        }
        
        cout << random.getName() << " attacks" << endl;
        a = rand() % random.getAttack();
        d = rand() % player.getDefense1();
        if(a > d)
        {
            cout << random.getName() << " deals " << a << " damage" << endl;
            player.setHP1(player.getHP1() - a);
        }
        else
        {
            cout << "Attack Missed!" << endl;
        }
        if(player.getHP1() <= 0) // Check if player's pokemon is out of HP
        {
            a = 0;
            d = 0;
            cout << random.getName() << ", HP: " << random.getHP() << ", A: " << random.getAttack() << ", D: " << random.getDefense() << ", S: " << random.getSpeed() << ", M: " << random.getMax() << endl;
            cout << player.getStarter().getName() << ", HP: " << player.getHP1() << ", A: " << player.getAttack1() << ", D: " << player.getDefense1() << ", S: " << player.getSpeed1() << ", M: " << player.getMax1() << endl;
            return 1;
        }
    }
    else
    {
        cout << random.getName() << " attacks first" << endl;
        a = rand() % random.getAttack();
        d = rand() % player.getDefense1();
        if(a > d)
        {
            cout << random.getName() << " deals " << a << " damage" << endl;
            player.setHP1(player.getHP1() - a);
        }
        else
        {
            cout << "Attack Missed!" << endl;
        }
        if(player.getHP1() <= 0)
        {
            a = 0;
            d = 0;
            cout << random.getName() << ", HP: " << random.getHP() << ", A: " << random.getAttack() << ", D: " << random.getDefense() << ", S: " << random.getSpeed() << ", M: " << random.getMax() << endl;
            cout << player.getStarter().getName() << ", HP: " << player.getHP1() << ", A: " << player.getAttack1() << ", D: " << player.getDefense1() << ", S: " << player.getSpeed1() << ", M: " << player.getMax1() << endl;
            return 1;
        }
        cout << player.getStarter().getName() << " attacks" << endl;
        a = rand() % player.getAttack1();
        d = rand() % random.getDefense();
        if(a > d)
        {
            cout << player.getStarter().getName() << " deals " << a << " damage" << endl;
            random.setHP(random.getHP() - a);
        }
        else
        {
            cout << "Attack Missed!" << endl;
        }
        if(random.getHP() <= 0)
        {
            a = 0;
            d = 0;
            cout << random.getName() << ", HP: " << random.getHP() << ", A: " << random.getAttack() << ", D: " << random.getDefense() << ", S: " << random.getSpeed() << ", M: " << random.getMax() << endl;
            cout << player.getStarter().getName() << ", HP: " << player.getHP1() << ", A: " << player.getAttack1() << ", D: " << player.getDefense1() << ", S: " << player.getSpeed1() << ", M: " << player.getMax1() << endl;
            return 2;
        }
    }
    
    a = 0;
    d = 0;
    cout << random.getName() << ", HP: " << random.getHP() << ", A: " << random.getAttack() << ", D: " << random.getDefense() << ", S: " << random.getSpeed() << ", M: " << random.getMax() << endl;
    cout << player.getStarter().getName() << ", HP: " << player.getHP1() << ", A: " << player.getAttack1() << ", D: " << player.getDefense1() << ", S: " << player.getSpeed1() << ", M: " << player.getMax1() << endl;
    return 0;
}

// Luck of catching a random pokemon in 1 7x7 area
void Game::luck()
{
    int chance = rand() % 100;
    Pokemon random = pokeList[rand() % 151];
    int pokePosition[2];
    if(checkPokemon(pokePosition, 7) == 1) // Check if a pokemon is in the vicinity
    {
        if(chance < 50) // Check if chance is successful
        {
            player.acquirePokemon(randoms[pokePosition[0]][pokePosition[1]]);
            player.updatePokedex(randoms[pokePosition[0]][pokePosition[1]]);
            randoms[pokePosition[0]][pokePosition[1]] = Pokemon();
        }
        else
        {
            cout << "Sorry, the pokemon was not caught." << endl;
        }
    }
    else // No pokemon in vicinity
    {
        cout << "Sorry, there are no pokemon in the vicinity." << endl << endl;
    }
}

// Main gym encounter option
void Game::gymEncounter()
{
    Player trainer = trainers[badges];
    int team1 = player.teamSize();
    
    int team2 = trainer.teamSize();
    int win = 0;
    
    cout << "You arrived at the Gym and the trainer is there. She wants to fight." << endl;
    cout << "Her ACTIVE Pokemon is:" << endl;
    cout << trainer.getStarter().getName() << ", HP: " << trainer.getHP1() << ", A: " << trainer.getAttack1() << ", D: " << trainer.getDefense1() << ", S: " << trainer.getSpeed1() << ", M: " << trainer.getMax1() << endl;
    
    cout << "Your ACTIVE Pokemon is:" << endl;
    cout << player.getStarter().getName() << ", HP: " << player.getHP1() << ", A: " << player.getAttack1() << ", D: " << player.getDefense1() << ", S: " << player.getSpeed1() << ", M: " << player.getMax1();
    
    int choice = 0;
    while(choice != 3)
    {
        if(win == 1) // If trainer wins
        {
            
            team1--;
            
            if(team1 <= 0) // Transport to pokecenter if you lose
            {
                findNearestCenter();
                pokeCenter();
                break;
            }
            else
            {
                player.setStarter(1);
            }
            
        }
        else if(win == 2) // If you win the battle
        {
            if(trainer.teamSize() > 1) 
            {
                team2--;
                trainer.setStarter(1);
            }
            else
            {
                team2--;
            }
            
            if(team2 <= 0) // IF the trainer has no more pokemon remaining, acquire all of them
            {
                player.increaseLevel(0);
                player.setPokeballs(5);
                player.increasePoints(60);
                badges++;
                if(trainer.teamSize() < 2)
                {
                    Pokemon newP = trainer.getStarter();
                    newP.setHP(0);
                    player.acquirePokemon(newP);
                    newP.setHP(newP.getHpMax());
                    player.updatePokedex(newP);
                }
                else
                {
                    int temp = trainer.teamSize();
                    for(int i = 0; i < temp; i++)
                    {
                        Pokemon newP = trainer.removePokemon(1);
                        newP.setHP(0);
                        player.acquirePokemon(newP);
                        newP.setHP(newP.getHpMax());
                        player.updatePokedex(newP);
                    }
                }
                // Make gym go away after win
                if(map[playerLocation[0] + 1][playerLocation[1]] == "G")
                {
                    map[playerLocation[0] + 1][playerLocation[1]] = "*";
                }
                else if(map[playerLocation[0] - 1][playerLocation[1]] == "G")
                {
                    map[playerLocation[0] - 1][playerLocation[1]] = "*";
                }
                else if(map[playerLocation[0]][playerLocation[1] + 1] == "G")
                {
                    map[playerLocation[0]][playerLocation[1] + 1] = "*";
                }
                else
                {
                    map[playerLocation[0]][playerLocation[1] - 1] = "*";
                }
                break;
            }
        }
        
        cout << endl << "What do you want to do (pick 1, 2, or 3): " << endl;
        cout << "   1. Fight: " << endl;
        cout << "   2. Switch Active Pokemon: " << endl;
        cin >> choice;
        
        if(choice == 1) // If player chooses to fight
        {
            win = gymFight(trainer);
        }
        else if(choice == 2) // If player chooses to change pokemon
        {
            int activePokemon;
            cout << "Pick another Active Pokemon:" << endl;
            player.printTeam();
            cin >> activePokemon;
            player.setStarter(activePokemon - 1);
            cout << endl<< "Your ACTIVE Pokemon is:" << endl;
            cout << player.getStarter().getName() << ", HP: " << player.getHP1() << ", A: " << player.getAttack1() << ", D: " << player.getDefense1() << ", S: " << player.getSpeed1() << ", M: " << player.getMax1() << endl << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
        
    }
    
    if(win == 1) // Add badge to collection
    {
        badges++;
    }
    /*
        If the player wins the fight, they 
        1. keep the all the pokemon
        2. level up active pokemon
        3. earn a badge, 5 pokeballs, and 60 points
        4. not be able to battle this gym again
        
        Else, they get transported to the nearest pokemon center
        and trainer's active pokemon levels up
    */
}

// Fight gym sequence
int Game::gymFight(Player &trainer)
{
    int a = 0;
    int d = 0;
    if(player.getSpeed1() > trainer.getSpeed1()) // Decide who attacks first
    {
        cout << player.getStarter().getName() << " attacks first" << endl;
        a = rand() % player.getAttack1();
        d = rand() % trainer.getDefense1();
        if(a > d) // Compute if attack lands
        {
            cout << player.getStarter().getName() << " deals " << a << " damage" << endl;
            trainer.setHP1(trainer.getHP1() - a);
        }
        else
        {
            cout << "Attack Missed!" << endl;
        }
        
        if(trainer.getHP1() <= 0)
        {
            a = 0;
            d = 0;
            cout << trainer.getStarter().getName() << ", HP: " << trainer.getHP1() << ", A: " << trainer.getAttack1() << ", D: " << trainer.getDefense1() << ", S: " << trainer.getSpeed1() << ", M: " << trainer.getMax1() << endl;
            cout << player.getStarter().getName() << ", HP: " << player.getHP1() << ", A: " << player.getAttack1() << ", D: " << player.getDefense1() << ", S: " << player.getSpeed1() << ", M: " << player.getMax1() << endl;
            return 2;
        }
        
        cout << trainer.getStarter().getName() << " attacks" << endl;
        a = rand() % trainer.getAttack1();
        d = rand() % player.getDefense1();
        if(a > d)
        {
            cout << trainer.getStarter().getName() << " deals " << a << " damage" << endl;
            player.setHP1(player.getHP1() - a);
        }
        else
        {
            cout << "Attack Missed!" << endl;
        }
        if(player.getHP1() <= 0)
        {
            a = 0;
            d = 0;
            cout << trainer.getStarter().getName() << ", HP: " << trainer.getHP1() << ", A: " << trainer.getAttack1() << ", D: " << trainer.getDefense1() << ", S: " << trainer.getSpeed1() << ", M: " << trainer.getMax1() << endl;
            cout << player.getStarter().getName() << ", HP: " << player.getHP1() << ", A: " << player.getAttack1() << ", D: " << player.getDefense1() << ", S: " << player.getSpeed1() << ", M: " << player.getMax1() << endl;
            return 1;
        }
    }
    else
    {
        cout << trainer.getStarter().getName() << " attacks first" << endl;
        a = rand() % trainer.getAttack1();
        d = rand() % player.getDefense1();
        if(a > d)
        {
            cout << trainer.getStarter().getName() << " deals " << a << " damage" << endl;
            player.setHP1(player.getHP1() - a);
        }
        else
        {
            cout << "Attack Missed!" << endl;
        }
        
        if(player.getHP1() <= 0)
        {
            a = 0;
            d = 0;
            cout << trainer.getStarter().getName() << ", HP: " << trainer.getHP1() << ", A: " << trainer.getAttack1() << ", D: " << trainer.getDefense1() << ", S: " << trainer.getSpeed1() << ", M: " << trainer.getMax1() << endl;
            cout << player.getStarter().getName() << ", HP: " << player.getHP1() << ", A: " << player.getAttack1() << ", D: " << player.getDefense1() << ", S: " << player.getSpeed1() << ", M: " << player.getMax1() << endl;
            return 1;
        }
        cout << player.getStarter().getName() << " attacks" << endl;
        a = rand() % player.getAttack1();
        d = rand() % trainer.getDefense1();
        if(a > d)
        {
            cout << player.getStarter().getName() << " deals " << a << " damage" << endl;
            trainer.setHP1(trainer.getHP1() - a);
        }
        else
        {
            cout << "Attack Missed!" << endl;
        }
        if(trainer.getHP1() <= 0)
        {
            a = 0;
            d = 0;
            cout << trainer.getStarter().getName() << ", HP: " << trainer.getHP1() << ", A: " << trainer.getAttack1() << ", D: " << trainer.getDefense1() << ", S: " << trainer.getSpeed1() << ", M: " << trainer.getMax1() << endl;
            cout << player.getStarter().getName() << ", HP: " << player.getHP1() << ", A: " << player.getAttack1() << ", D: " << player.getDefense1() << ", S: " << player.getSpeed1() << ", M: " << player.getMax1() << endl;
            return 2;
        }
    }
    a = 0;
    d = 0;
    cout << trainer.getStarter().getName() << ", HP: " << trainer.getHP1() << ", A: " << trainer.getAttack1() << ", D: " << trainer.getDefense1() << ", S: " << trainer.getSpeed1() << ", M: " << trainer.getMax1() << endl;
    cout << player.getStarter().getName() << ", HP: " << player.getHP1() << ", A: " << player.getAttack1() << ", D: " << player.getDefense1() << ", S: " << player.getSpeed1() << ", M: " << player.getMax1() << endl;
    return 0;
}

// Random events at the end of each turn
void Game::endTurn()
{
    int chance = rand() % 100;
    int r = rand() % 151;
    Pokemon randomPokemon = pokeList[r];
    int choice = 0;
    string choice2 = "";
    if(chance < 30) // Random cahnce of player finding a pokemon
    {
        while(choice != 1 && choice != 2)
        {
            cout << "Suddenly, " << randomPokemon.getName() << " appears in your path. Do you want to:" << endl;
            cout << "   1. Catch it" << endl;
            cout << "   2. Release it" << endl;
            cin >> choice;
            if(choice != 1 && choice != 2)
            {
                cout << "Invalid choice." << endl;
            }
            else
            {
                break;
            }
        }
        if(choice == 1)
        {
            player.setPokeballs(-1);
            player.increasePoints(10);
            player.acquirePokemon(randomPokemon);
            player.updatePokedex(randomPokemon);
        }
    }
    else if(chance >= 30 && chance < 55) // Random cahcne of player leveling up okemon or gaining pokeballs
    {
        int rand50 = rand() % 100;
        if(rand50 > 50)
        {
            player.setPokeballs(2);
            cout << "Great news! You have stumbled upon a hidden stash of Pokéballs. Your reserves increased to " << player.getPokeballs() << " Pokéballs." << endl;
        }
        else
        {
            
            cout << "Great news! You have stumbled upon a hidden stash of Poffins. Your Pokémon are delighted. Choose one of them to feast on the Poffins and Level Up: " << endl;
            player.printTeam();
            cin >> choice;
            cout << endl;
            player.increaseLevel(choice - 1);
            // Increase pokemon level
        }
    }
    
    else if(chance >= 55 && chance < 75 && player.teamSize() > 1) // Random chance of one of the players pokemon dying
    {
        int removeR = rand() % player.teamSize();
        if(removeR == 0)
        {
            removeR++;
            Pokemon removed = player.removePokemon(removeR);
            cout << "Oh no! After years of legendary battles, " << removed.getName() << " died of old age. Thank you for your companionship, dear friend." << endl;
        }
        else
        {
            Pokemon removed = player.removePokemon(removeR);
            cout << "Oh no! After years of legendary battles, " << removed.getName() << " died of old age. Thank you for your companionship, dear friend." << endl;
        }
        
    }
}

// Initialize trainers and their names
void Game::loadTrainers()
{
    
    Player trainer1 = Player("Trainer 1");
    trainers.push_back(trainer1);
    Player trainer2 = Player("Trainer 2");
    trainers.push_back(trainer2);
    Player trainer3 = Player("Trainer 3");
    trainers.push_back(trainer3);
    Player trainer4 = Player("Trainer 4");
    trainers.push_back(trainer4);
    Player trainer5 = Player("Trainer 5");
    trainers.push_back(trainer5);
    Player trainer6 = Player("Trainer 6");
    trainers.push_back(trainer6);
    Player trainer7 = Player("Trainer 7");
    trainers.push_back(trainer7);
    Player trainer8 = Player("Trainer 8");
    trainers.push_back(trainer8);
    Player trainer9 = Player("Trainer 9");
    trainers.push_back(trainer9);
    Player trainer10 = Player("Trainer 10");
    trainers.push_back(trainer10);
    Player trainer11 = Player("Trainer 11");
    trainers.push_back(trainer11);
    Player trainer12 = Player("Trainer 12");
    trainers.push_back(trainer12);
    Player trainer13 = Player("Trainer 13");
    trainers.push_back(trainer13);
    Player trainer14 = Player("Trainer 14");
    trainers.push_back(trainer14);
    Player trainer15 = Player("Trainer 15");
    trainers.push_back(trainer15);
    
}

// Look for the closest pokemon center
int Game::findNearestCenter()
{
    int tempRow = 0;
    int tempCol = 0;
    // Check if you are looking out of bounds
    if(playerLocation[0] - 3 < 0)
    {
        if(playerLocation[0] - 2 < 0)
        {
            tempRow = 0;
        }
        else if(playerLocation[0] - 1 < 0)
        {
            tempRow = 0;
        }
        else
        {
            tempRow = 0;
        }
    }
    else
    {
        tempRow = playerLocation[0] - 3;
    }
    
    if(playerLocation[1] - 3 < 0)
    {
        if(playerLocation[1] - 2 < 0)
        {
            tempCol = 0;
        }
        else if(playerLocation[1] - 1 < 0)
        {
            tempCol = 0;
        }
        else
        {
            tempCol = 0;
        }
    }
    else
    {
        tempCol = playerLocation[1] - 3;
    }
    
    // Transport player's location
    for(int i = tempRow; i < tempRow + 7; i++)
    {
        for(int j = tempCol; j < tempCol + 7; j++)
        {
            if(map[i][j] == "C")
            {
                map[playerLocation[0]][playerLocation[1]] = "*";
                playerLocation[0] = i + 1;
                playerLocation[1] = j;
                map[playerLocation[0]][playerLocation[1]] = "@";
                return 1;
            }
        }
    }
    return 0;
}

// Check if player has enough types of pokemon to win game
int Game::checkTypes(string type)
{
    int exist = 0;
    for(int i = 0; i < 8; i++)
    {
        if(type == types[i])
        {
            exist = 1;
        }
    }
    if(exist != 1)
    {
        for(int i = 0; i < 8; i++)
        {
            if(types[i] == "");
            {
                types[i] = type;
                break;
            }
        }
    }
}

// End game
void Game::endGame(int result)
{
    string won = "";
    ofstream outfile;
    outfile.open("resultsPokemon.txt", ios::out | ios::ate | ios::app); // Create text file for stats
    if(result == 0)
    {
        won = "N";
        won.append(14, ' ');
    }
    else
    {
        won = "Y";
        won.append(14, ' ');
    }
    // Add points name and whether they won to text file
    string points = to_string(player.getPoints());
    points.append(15 - points.length(), ' ');
    string name = player.getName();
    name.append(15 - name.length(), ' ');
    
    outfile << endl << name << won << points;
    
    outfile.close();
}