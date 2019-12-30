// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 3 - Problem 6: checkLeapYear

#include <iostream>
using namespace std;

/*
 * Algorithm: Check if year is a leap year
 * 1. Check if year is divisable by 4.
 * 2. If so, check if it divisible by 400, return true
 * 3. If not, check if it is divisible by 100
 * 4. If so, make sure it is greater than 1582.
 * Input parameters: year
 * Output (prints to screen): nothing
 * Returns: True/False if year is a leap year
 */
bool checkLeapYear(int year)
{
    if(year % 4 == 0)
    {
        if(year % 400 == 0)
        {
            return true;
        }
        if(year % 100 == 0)
        {
            if(year <= 1582)
            {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int main() 
{
    // Test 1
    // Expected output
    // 0/False
    cout << checkLeapYear(1981) << endl;
    
    // Test 2
    // Expected output
    // 1/True
    cout << checkLeapYear(2000);
}