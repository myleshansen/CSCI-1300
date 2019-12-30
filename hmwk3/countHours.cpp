// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 3 - Problem 5: countHours

#include <iostream>
using namespace std;

/*
 * Algorithm: count total hours in a month
 * 1. Take in month number
 * 2. Check which month
 * 3. Multiply by hours by appropriate days
 * 4. Return total
 * Input parameters: month number
 * Output (prints to screen): nothing
 * Returns: hours in month
 */
int countHours(int month)
{
    switch(month)
    {
        case 1:
            return 24 * 31;
        case 2:
            return 24 * 28;
        case 3:
            return 24 * 31;
        case 4:
            return 24 * 30;
        case 5:
            return 24 * 31;
        case 6:
            return 24 * 30;
        case 7:
            return 24 * 31;
        case 8:
            return 24 * 31;
        case 9:
            return 24 * 30;
        case 10:
            return 24 * 31;
        case 11:
            return 24 * 30;
        case 12:
            return 24 * 31;
    }
}

int main()
{
    // Test 1
    // Expected output
    // 744
    cout << countHours(1) << endl;
    
    // Test 2
    // Expected output
    // 720
    cout << countHours(6);
}