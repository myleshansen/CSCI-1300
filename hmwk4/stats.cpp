// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 4 - Problem 3: stats
#include <iostream>
using namespace std;

/*
 * Algorithm: Calculate the min max and average values in the array
 * 1. Iterate through the length of the array
 * 2. Compare the min and max values
 * 3. Print out values
 * Input parameters: double array, integer length
 * Output (prints to screen): Min, max, and average values
 * Returns: Nothing
 */
 
void stats(double arr[], int len)
{
    double min = arr[0];
    double max = arr[0];
    double avg = arr[0];
    for(int i = 1; i < len; i++) // Iterate through array
    {
        avg += arr[i]; // Average total
        if(arr[i] > max) // Check max values
        {
            max = arr[i];
        }
        else if(arr[i] < min) // Check min values
        {
            min = arr[i];
        }
    }
    
    cout << "Min: " << fixed << setprecision(2) << min << endl;
    cout << "Max: " << setprecision(2) << max << endl;
    cout << "Avg: " << setprecision(2) << avg / len << endl; // Divide total by number of values
}

int main()
 {
   // Test 1
   // Expected output
   // Min: 0, Max: 0, Avg: 0
   double arr[] = {0};
   int len = 1;
   cout << stats(arr, len) << endl;
   
   // Test 2
   // Expected output
   // Min: 1.4, Max: 9.8, Avg: 4.6 
   double arr2[] = {1.4, 9.8, 2.6};
   len = 3;
   cout << stats(arr2, len) << endl;
 }