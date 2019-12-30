// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 3 - Problem 3: chessBoard

#include <iostream>
using namespace std;

/*
 * Algorithm: print which color square on a chess board
 * 1. Take a letter and a number
 * 2. Check letter
 * 3. Check number
 * 4. Print color that matches with letter and number
 * Input parameters: letter and number
 * Output (prints to screen): color of square
 * Returns: nothing
 */
void chessBoard(char col, int row) 
{
    if(col == 'a')
    {
        if(row > 8)
        {
            cout << "Chessboard squares can only have letters between a-h and numbers between 1-8.";
        }
        else if(row % 2 == 0)
        {
            cout << "white";
        }
        else
        {
            cout << "black";
        }
    }
    else if(col == 'b')
    {
        if(row > 8)
        {
            cout << "Chessboard squares can only have letters between a-h and numbers between 1-8.";
        }
        else if(row % 2 == 0)
        {
            cout << "black";
        }
        else
        {
            cout << "white";
        }
    }
    else if(col == 'c')
    {
        if(row > 8)
        {
            cout << "Chessboard squares can only have letters between a-h and numbers between 1-8.";
        }
        else if(row % 2 == 0)
        {
            cout << "white";
        }
        else
        {
            cout << "black";
        }
    }
    else if(col == 'd')
    {
        if(row > 8)
        {
            cout << "Chessboard squares can only have letters between a-h and numbers between 1-8.";
        }
        else if(row % 2 == 0)
        {
            cout << "black";
        }
        else
        {
            cout << "white";
        }
    }
    else if(col == 'e')
    {
        if(row > 8)
        {
            cout << "Chessboard squares can only have letters between a-h and numbers between 1-8.";
        }
        else if(row % 2 == 0)
        {
            cout << "white";
        }
        else
        {
            cout << "black";
        }
    }
    else if(col == 'f')
    {
        if(row > 8)
        {
            cout << "Chessboard squares can only have letters between a-h and numbers between 1-8.";
        }
        else if(row % 2 == 0)
        {
            cout << "black";
        }
        else
        {
            cout << "white";
        }
    }
    else if(col == 'g')
    {
        if(row > 8)
        {
            cout << "Chessboard squares can only have letters between a-h and numbers between 1-8.";
        }
        else if(row % 2 == 0)
        {
            cout << "white";
        }
        else
        {
            cout << "black";
        }
    }
    else if(col == 'h')
    {
        if(row > 8)
        {
            cout << "Chessboard squares can only have letters between a-h and numbers between 1-8.";
        }
        else if(row % 2 == 0)
        {
            cout << "black";
        }
        else
        {
            cout << "white";
        }
    }
    else
    {
        cout << "Chessboard squares can only have letters between a-h and numbers between 1-8.";
    }
}

int main()
{
    // Test 1
    // Expected output
    // black
    chessBoard('a', 1);
    
    // Test 2
    // Expected output
    // white
    chessBoard('b', 3);
}