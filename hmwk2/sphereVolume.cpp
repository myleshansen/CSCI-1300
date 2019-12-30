// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 2 - Problem 5 - sphereVolume

#include <iostream>
#include <math.h>
using namespace std;

/*
 * Algorithm: Calculate volume of a sphere
 * 1. Take the radius of the sphere
 * 2. Calculate volume using equation for volume of a sphere
 * 3. Print the calculated volume
 * Input parameters: number of rainy, cold, and sunny days (all ints)
 * Output (prints to screen): volume: **
 * Returns: nothing
 */
void sphereVolume(double radius)
{
    double volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3); // Equation for volume of a sphere
    cout << "volume: " << volume << endl; // Print the volume
}

int main()
{
    // test 1
    // expected output
    // volume 523.599
    sphereVolume(5);
    
    // test 2
    // expected output
    // volume 4188.79
    sphereVolume(10);
}