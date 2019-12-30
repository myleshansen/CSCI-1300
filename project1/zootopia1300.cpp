// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 1 - Problem 3: zootopia1300
#include <iostream>
using namespace std;

/*
 * Algorithm: Caclulate scores for each animal
 * 1. Check which animal
 * 2. Enter scores
 * 3. Calculate score and print
 * Input parameters: None
 * Output (prints to screen): Hire score: _____
 * Returns: Nothing
 */
void printMenu()
{
    double agility;
    double strength;
    double speed;
    int selection;
    
    while(selection != 4)
    {
    	cout<<"Select a numerical option:"<<endl;
    	cout<<"=== menu ==="<<endl;
    	cout<<"1. Fox"<<endl;
    	cout<<"2. Bunny"<<endl;
    	cout<<"3. Sloth"<<endl;
    	cout<<"4. Quit"<<endl;
    	cin >> selection;
    	
    	if(selection == 1) 
    	{
    	    cout << "Enter agility:" << endl;
    	    cin >> agility;
    	    cout << "Enter strength:" << endl;
    	    cin >> strength;
    	    cout << "Hire score: " << 1.8 * agility + 2.16 * strength + 3.24 * speed << endl;
    	}
    	else if(selection == 2) 
    	{
    	    cout << "Enter agility:" << endl;
    	    cin >> agility;
    	    cout << "Enter speed:" << endl;
    	    cin >> speed;
    	    cout << "Hire score: " << 1.8 * agility + 2.16 * strength + 3.24 * speed << endl;
    	}
    	else if(selection == 3) 
    	{
    	    cout << "Enter strength:" << endl;
    	    cin >> strength;
    	    cout << "Enter speed:" << endl;
    	    cin >> speed;
    	    cout << "Hire score: " << 1.8 * agility + 2.16 * strength + 3.24 * speed << endl;
    	}
    	agility = 0;
    	strength = 0;
    	speed = 0;
    }
}

int main() 
{
    printMenu();
}