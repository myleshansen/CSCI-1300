// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 2 - Problem 10 - calculateSalary

#include <iostream>
using namespace std;

/*
 * Algorithm: calculate total salary earned for the week.
 * 1. Take the days worked for each weather condition.
 * 2. Multiply days worked by hours allowed for each weather.
 * 3. Return total hours worked multiplied by $ per hours
 * Input parameters: number of rainy, cold, and sunny days (all ints)
 * Output (prints to screen): nothing
 * Returns: total salary (int)
 */
int calculateSalary(int rainy, int cold, int sunny)
{
    int total = 0; // Total hours worked
    total += 5 * rainy; // conversion
    total += 4 * cold; // conversion
    total += 8 * sunny; // conversion
    return total * 10; // returns the value * the amount earned per hour
}

int main()
{
    // test 1
    // expected output
    // 2090
    cout << calculateSalary(5, 8, 19) << endl;
    
    // test 2
    // expected output
    // 170
    cout << calculateSalary(1, 1, 1);
}