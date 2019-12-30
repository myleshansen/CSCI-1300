// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 1 - Problem 1: printCharInString
#include <iostream>
using namespace std;

/*
 * Algorithm: Prints all characters in a string on a new line
 * 1. Take the string
 * 2. Check if string is empty
 * 3. Iterate through each character in the string
 * Input parameters: 
 * Output (prints to screen): Prints all characters in a string on a new line
 * Returns: Nothing
 */
void printCharInString(string final)
{
    if(final.length() == 0)
    {
        cout << "Given string is empty!";
    }
    else
    {
        for(int i = 0; i < final.length(); i++)
        {
            cout << final[i] << endl;
        }
    }
}

int main()
{
    // test 1
    // expected output
    /*
    C
    o
    m
    p
    u
    t
    e
    r
    */
    printCharInString("Computer");
    
    // test 2
    // expected output
    /*
    S
    t
    r
    i
    n
    g
    */
    printCharInString("String");
}