// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 4 - Problem 2: printArrReverse
#include <iostream>
using namespace std;

/*
 * Algorithm: Print array items backwards
 * 1. Start loop at end of array
 * 2. Print each item
 * Input parameters: integer array, integer length
 * Output (prints to screen): Array contents
 * Returns: Nothing
 */
 
 void printArrReverse(int arr[], int len)
 {
     for(int i = len - 1; i >= 0; i--) // Start at length of array
     {
         cout << arr[i] << endl; // Print array item
     }
 }
 
 int main()
 {
   // Test 1
   // Expected output
   // 0
   int arr[] = {0};
   int len = 1;
   printArrReverse(arr, len);
   
   // Test 2
   // Expected output
   // 7 9 1
   int arr2[] = {1, 9, 7};
   len = 3;
   printArrReverse(arr2, len);
 }