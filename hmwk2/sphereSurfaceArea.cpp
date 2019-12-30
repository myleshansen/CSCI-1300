// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 2 - Problem 6 - sphereSurfaceArea

#include <iostream>
#include <math.h>
using namespace std;

/*
 * Algorithm: Calculate surface area of a sphere.
 * 1. Take the radius of a sphere
 * 2. Calculate surface area using equation for surface area of a sphere
 * 3. Print the surface area
 * Input parameters: radius (int)
 * Output (prints to screen): surface area: ***
 * Returns: noting
 */
void sphereSurfaceArea(double radius)
{
    double surfaceArea;
    surfaceArea = 4 * M_PI * pow(radius, 2); // Equation for surface area of a sphere
    cout << "surface area: " << surfaceArea << endl; // Print surface area
}

int main()
{
    // test 1
    // expected output
    // surface area: 314.159
    sphereSurfaceArea(5);
    
    // test 2
    // expected output
    // surface area: 1256.64
    sphereSurfaceArea(10);
}