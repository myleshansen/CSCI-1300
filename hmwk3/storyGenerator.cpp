// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 3 - Extra credit: storyGenerator

#include <iostream>
using namespace std;

/*
 * Algorithm: prints first story
 * 1. Take input
 * 2. Print with sentence
 * Input parameters: None
 * Output (prints to screen): prints first story with input
 * Returns: nothing
 */
void story1()
{
    cout << "Enter a noun:" << endl;
    string noun;
    cin >> noun;
    cout << "Be careful not to vacuum the " << noun << " when you clean under your bed." << endl;
}

/*
 * Algorithm: prints second story
 * 1. Take input
 * 2. Print with sentence
 * Input parameters: None
 * Output (prints to screen): prints second story with input
 * Returns: nothing
 */
void story2()
{
    cout << "Enter a name:" << endl;
    string name;
    cin >> name;
    
    cout << "Enter an occupation:" << endl;
    string occupation;
    cin >> occupation;
    
    cout << "Enter a place:" << endl;
    string place;
    cin >> place;
    
    cout << name <<" is a " << occupation << " who lives in " << place << "." << endl;
}

/*
 * Algorithm: prints third story
 * 1. Take input
 * 2. Print with sentence
 * Input parameters: None
 * Output (prints to screen): prints third story with input
 * Returns: nothing
 */
void story3()
{
    cout << "Enter a plural noun:" << endl;
    string pluralNoun;
    cin >> pluralNoun;
    
    cout << "Enter an occupation:" << endl;
    string occupation;
    cin >> occupation;
    
    cout << "Enter an animal:" << endl;
    string animal;
    cin >> animal;
    
    cout << "Enter a place:" << endl;
    string place;
    cin >> place;
    
    cout << "In the book War of the " << pluralNoun <<", the main character is an anonymous "<< occupation << " who records the arrival of the " << animal << "s in "<< place <<"." << endl;
}

int main()
{
    int response = 0;
    while(response < 4)
    {
        cout << "Which story would you like to play? Enter the number of the story (1, 2, or 3) or type 4 to quit" << endl;
        cin >> response;
    
        if(response == 1)
        {
            story1();
            cout << endl;
        }
        else if (response == 2)
        {
            story2();
            cout << endl;
        }
        else if(response == 3)
        {
            story3();
            cout << endl;
        }
    }
    cout << "Good bye!";
}
