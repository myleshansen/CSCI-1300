// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 5 - Problem 3: printAllBooks
#include <iostream>
using namespace std;

/*
 * Algorithm: 
 * 1. Check if amount of books is 0 or less
 * 2. If not loop throug array and print books
 * Input parameters: string array of titles, string array of authors, integer of books
 * Output (prints to screen): No books are stored, or list of books
 * Returns: 
*/

void printAllBooks(string titles[], string authors[], int books)
{
    if(books <= 0) // If there are no books
    {
        cout << "No books are stored";
    }
    else
    {
        cout << "Here is a list of books" << endl;
        for(int i = 0; i < books; i++) // Loop through books and print each
        {
            cout << titles[i] << " by " << authors[i] << endl;
        }
    }
}

int main()
{
    // Test 1
    // Expected Output
    // No books are stored
    string book_titles[] = {};
    string book_authors[] = {};
    printAllBooks(book_titles, book_authors, 0);
    cout << endl;
    
    // Test 2
    // Expected Output
    /* Here is a list of books
       Calculus1 by Gottfried Leibniz
    */
    string book_titles2[] = {"Calculus1"};
    string book_authors2[] = {"Gottfried Leibniz"};
    printAllBooks(book_titles2, book_authors2, 1);
    
}