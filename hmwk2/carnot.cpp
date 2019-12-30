// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 2 - Problem 9 - carnot

#include <iostream>
using namespace std;

/*
 * Algorithm: calculate carnot efficieny.
 * 1. Return carnot effiency using the algorithm while casting one value to a double
 * Input parameters: absolute hot and absolute cold (all ints)
 * Output (prints to screen): nothing
 * Returns: carnot efficiency (double)
 */
double carnot(int absoluteC, int absoluteH)
{
    return 1 - absoluteC / (double)absoluteH; // returns carnot effiency as double
}

int main()
{
    // test 1
    // expected output
    // 0.854545
    cout << carnot(160, 1100) << endl;
    
    // test 2
    // expected output
    // -1.2
    cout << carnot(22, 10);
}