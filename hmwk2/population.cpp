// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 2 - Problem 8 - population

#include <iostream>
using namespace std;

/*
 * Algorithm: Calculate total population after one year
 * 1. Take the starting population
 * 2. Calculate births
 * 3. Calculate deaths
 * 4. Calculate immigrants
 * 5. Return inital population + population in one year
 * Input parameters: inital population (int)
 * Output (prints to screen): nothing
 * Returns: population after one year (int)
 */
int population(int initialPopulation)
{
    int seconds = 365 * 24 * 3600; // Seconds in one year
    int birth = seconds / 8; // Total births
    int death = seconds / 12; // Total deaths
    int immigrant = seconds / 27; // Total immigrants
    return initialPopulation + birth - death + immigrant; // Total population after 1 year
}

int main()
{
    // test 1
    // expected output
    // 3482000
    cout << population(1000000) << endl;
    
    // test 2
    // expected output
    // 14847478
    cout << population(12365478);
    
}