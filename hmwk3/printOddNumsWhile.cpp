// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 3 - Problem 8: printOddNumsWhile

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
void printOddNumsWhile(int max)
{
    int temp = 1;
    if(max % 2 == 0)
    {
        max -= 1;
    }
    
    while(temp <= max)
    {
        cout << temp << endl;
        temp += 2;
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
    printOddNumsWhile(11);
    
    // Test 2
    // Expected output
    // 1
    printOddNumsWhile(1);
}