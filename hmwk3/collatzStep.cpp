// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 3 - Problem 1: collatzStep

#include <iostream>
using namespace std;

/*
 * Algorithm: calculate carnot efficieny.
 * 1. Return carnot effiency using the algorithm while casting one value to a double
 * Input parameters: absolute hot and absolute cold (all ints)
 * Output (prints to screen): nothing
 * Returns: carnot efficiency (double)
 */
int collatzStep(int n)
{
    if (n % 2 == 0)
    {
        return n / 2;
    }
    else if(n % 3 == 0 || n == 1)
    {
        return 3 * n + 1;
    }
    else 
    {
        return 0;
    }
}

int main()
{
    // test 1
    // expected output
    // 2
    cout << collatzStep(4) << endl;
    
    // test 2
    // expected output
    // 0
    cout << collatzStep(-5);
}