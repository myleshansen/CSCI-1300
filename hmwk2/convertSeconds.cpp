// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 2 - Problem 7 - convertSeconds

#include <iostream>
using namespace std;

/*
 * Algorithm: calculate total hours, minutes, and seconds
 * 1. Take seconds to be converted
 * 2. Convert total seconds into hours
 * 3. Subtract from total seconds
 * 4. Convert total seconds into minutes
 * 5. Subtract from total seconds
 * 6. Left with remaining seconds
 * 7. Print total hours, minutes, and seconds
 * Input parameters: seconds (int)
 * Output (prints to screen): ** hour(s) ** minute(s) ** second(s)
 * Returns: nothing
 */
void convertSeconds(int seconds) 
{
    int total = seconds;
    int hours = total / 3600; // conversion
    total %= 3600; // total subtraction
    int minutes = total / 60; // conversion
    total %= 60; // total subtraction
    cout << hours << " hour(s) " << minutes << " minute(s) " << total << " second(s)";
}

int main ()
{
    // test 1
    // expected output
    // 1 hour(s) 1 minute(s) 11 second(s)
    convertSeconds(3671);
    
    // test 2
    // expected output
    // 0 hour(s) 1 minute(s) 0 second(s)
    convertSeconds(60);
}