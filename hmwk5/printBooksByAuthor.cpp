// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 5 - Problem 4: printBooksByAuthor
#include <iostream>
using namespace std;

/*
 * Algorithm: Prints the books by a specific author
 * 1. Check if file is empty, if not loop through file
 * 2. Count books by author
 * 3. Print each book by author
 * Input parameters: string array of titles, string array of authors, integer og books, string of author name
 * Output (prints to screen): There are no books by , or Here is a list of books by
 * Returns: Nothing
*/

void printBooksByAuthor(string titles[], string authors[], int books, string author)
{
    if(books <= 0)
    {
        cout << "No books are stored";
    }
    else
    {
        string temp[books];
        int count = 0;
        for(int i = 0; i < books; i++) // Loop through books and check if book by author
        {
            if(authors[i] == author) // Check if book is by author
            {
                temp[count] = titles[i];
                count++;
            }
        }
        if(count == 0)
        {
            cout << "There are no books by " << author;
        }
        else
        {
            cout << "Here is a list of books by " << author << endl;
            for(int i = 0; i < count; i++) // Print books by author
            {
                cout << temp[i] << endl;
            }
        }
    }
}

int main()
{
    // Test 1
    // Expected Output
    // No books are stored
    Book listOfBooks[] = {};
    int numberOfBooks = 0;
    string author = "Dan Brown";
    printBooksByAuthor(listOfBooks, numberOfBooks, author);
    // Test 2
    // Expected Output
    // There are no books by Author A
    Book book1 = Book("Book 1", "Author B");
    Book book2 = Book("Book 2", "Author C");
    Book book3 = Book("Book 3", "Author D");
    Book listOfBooks[] = {book1, book2, book3};
    int numberOfBooks2 = 3;
    string author2 = "Author A";
    printBooksByAuthor(listOfBooks, numberOfBooks2, author2);
    
    // Test 3
    // Expected output
    /*
    
    */
}