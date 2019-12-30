// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 4 - Problem 4: swapFirstLast
#include <iostream>
using namespace std;

/*
 * Algorithm: Flips the first and last items of an array
 * 1. Make a temp array witht the same values
 * 2. Flip values and assing to new array
 * Input parameters: integer array, integer length
 * Output (prints to screen): Nothing
 * Returns: Nothing
 */
 
void swapFirstLast(int arr[], int len)
{
    int temp[len]; // Temp aray
    temp[0] = arr[len - 1]; // temp first value equals old last value
    temp[len - 1] = arr[0]; // temp last values equals old first value
    
    arr[0] = temp[0];
    arr[len - 1] = temp[len - 1];
    
}

int main()
 {
   // Test 1
   // Expected output
   // 30, 20, 10
   int arr1[3] = {10, 20, 30};
   swapFirstLast(arr1, 3);
    
   // Test 2
   // Expected output
   // 
   int arr2[] = {};
   swapFirstLast(arr2, 0);
 }