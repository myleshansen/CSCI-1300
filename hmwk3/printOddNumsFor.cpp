// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 3 - Problem 9: printOddNumsFor

#include <iostream>
using namespace std;

/*
 * Algorithm: prints all odd numbers before input
 * 1. Check if number is divisible by 2
 * 2. If so, subtract 1
 * 3. Then print numbers leading up to max
 * Input parameters: maximum
 * Output (prints to screen): prints all odd numbers before input
 * Returns: nothing
 */
void printOddNumsFor(int max)
{
    if(max % 2 == 0)
    {
        max -= 1;
    }
    
    for(int i = 1; i <= max; i += 2)
    {
        cout << i << endl;
    }
}

int main() 
{
    // Test 1
    // Expected output
    /*
    1
    3
    5
    7
    9
    11
    */
    printOddNumsFor(11);
    
    // Test 2
    // Expected output
    // 
    printOddNumsFor(0);
}