// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 8 - Problem 2: Player Class

#include <iostream>
#include "Player.h"
using namespace std;

int main()
{
    // Test 1
    // Expected output
    /*
        0
    */
    Player stella;
    cout << stella.getName() << endl;
    cout << stella.getPoints() << endl;
    
    // Test 2
    // Expected output
    /*
        Stella
    */
    Player stella;
    stella.setName("Stella");
    cout << stella.getName() << endl;
}