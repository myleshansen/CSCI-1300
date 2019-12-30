// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 4 - Problem 1: arrayPilgrimage
#include <iostream>
using namespace std;

/*
 * Algorithm: Prints information based on type of array
 * 1. Loop through each array and add items while printing each
 * Input parameters: None
 * Output (prints to screen): 
 * Returns: Nothing
 */
 
 int main()
 {
     double temps[10];
     for(int i = 0; i < 10; i++)
     {
         temps[i] = -459.67; // Add values
         cout << temps[i] << endl; // Print array values
     }
     cout << endl;
     
     string colors[] = {"Red", "Blue", "Green", "Cyan", "Magenta"};
     for(int i = 0; i < 5; i++)
     {
         cout << colors[i] << endl; // Print each item in array
     }
     cout << endl;
     
     int sequence[100];
     for(int i = 1; i <= 100; i++)
     {
         sequence[i] = i; // Add values to array
         cout << sequence[i] << endl; // Print array values
     }
     cout << endl;
     
     char letters[52];
     int temp;
     for(int i = 0; i < 26; i++)
     {
             temp = 65 + i; 
             letters[i] = char(temp);
             temp += 32;
             letters[i + 26] = char(temp);
     }
     
     for(int i = 0; i < 26; i++)
     {
         cout << letters[i] << " " << letters[i + 26] <<  endl;
     }
 }
