// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 2 - Problem 3 - classGreeting

#include <iostream>
using namespace std;

/*
 * Input parameters: course number (int)
 * Output (prints to screen): Hello, CS **** World!
 * Returns: noting
 */
void classGreeting(int course)
{
    cout << "Hello, CS " << course << " World!";
}

int main()
{
    // test 1
    // expected output
    // Hello, CS 1300 World!
    classGreeting(1300);
    
    // test 2
    // expected output
    // Hello, CS 1320 World!
    classGreeting(1320);
}