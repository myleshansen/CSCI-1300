// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 5 - Problem 1: getLinesFromFile
#include <iostream>
#include <fstream>
using namespace std;

/*
 * Algorithm: Reads text file and stores info in array
 * 1. Open file and check if it exists
 * 2. If file exists, loop through file
 * 3. While file is still open, add each line to array and return length
 * Input parameters: string file name, integer array, integer length
 * Output (prints to screen): Nothing
 * Returns: Length of array
*/
 
int getLinesFromFile(string fileName, int arr[], int len)
{
    ifstream myfile; 
    myfile.open(fileName); // Open file
    
    if(myfile.is_open())
    {
        string line = "";
        int index = 0;
        while(getline(myfile, line)) // Loop through file
        {
            if(line == "") // If line is empty, skip
            {
                continue;
            }
            else if(index >= len)
            {
                break;
            }
            else
            {
                arr[index] = stoi(line); // Cast string to integer
                index++;
            }
            
        }
        return index;
    }
    else
    {
        return -1; // If file does not exist return -1
    }
}

int main()
{
    // Test 1
    // Expected Output
    // 10
    int numArray[10];
    cout << getLinesFromFile("numbers.txt", numArray, 10) << endl;
    
    // Test 2
    // Expected Output
    // 4
    int numArray2[4];
    cout << getLinesFromFile("numbers.txt", numArray, 4) << endl;
    
    // Test 3
    // Expected Output
    // -1
    int numArray3[4];
    cout << getLinesFromFile("numberdds.txt", numArray, 4) << endl;
}