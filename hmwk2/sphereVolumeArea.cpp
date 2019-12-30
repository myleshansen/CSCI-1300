// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 2 - Problem 4 - sphereVolumeArea

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    cout << "Enter a radius: " << endl;
    double radius;
    cin >> radius;
    double volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    cout << "volume: " << volume << endl;
    double surfaceArea;
    surfaceArea = 4 * M_PI * pow(radius, 2);
    cout << "surface area: " << surfaceArea;
   
}