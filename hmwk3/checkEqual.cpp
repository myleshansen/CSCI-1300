// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 3 - Problem 2: checkEqual
#include <iostream>
using namespace std;

/*
 * Algorithm: checks if a set of three numbers is eqal or not
 * 1. Take the set of 3 integers.
 * 2. Check if they are all equal.
 * 3. If not, check if they are not all equal.
 * 4. If not, print neither.
 * Input parameters: set of three integers
 * Output (prints to screen): All same, All different, or Neither
 * Returns: Nothing
 */
void checkEqual(int state1, int state2, int state3)
{
    if (state1 == state2 && state2 == state3)
    {
        cout << "All same" << endl;
    }
    else if(state1 != state2 && state2 != state3 && state1 != state3)
    {
        cout << "All different" << endl;
    }
    else
    {
        cout << "Neither" << endl;
    }
}

int main()
{
    // Test 1
    // Expected output
    // All same
    checkEqual(1,1,1);
    
    // Test 2
    // Expected output
    // All different
    checkEqual(1,2,3);
}