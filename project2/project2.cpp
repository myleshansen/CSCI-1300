// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 2

#include <iostream>
#include <fstream>
#include "Library.h"
#include "Book.h"
#include "User.h"
using namespace std;

void displayMenu(){
    cout << "Select a numerical option:" << endl;
    cout << "======Main Menu=====" << endl;
    cout << "1. Read books" << endl;
    cout << "2. Read ratings" << endl;
    cout << "3. Print all books" << endl;
    cout << "4. Print books by author" << endl;
    cout << "5. Get rating" << endl;
    cout << "6. Find number of books user rated" << endl;
    cout << "7. View ratings" << endl;
    cout << "8. Get average rating" << endl;
    cout << "9. Get average rating by author" << endl;
    cout << "10. Add a user" << endl;
    cout << "11. Checkout a book" << endl;
    cout << "12. Get recommendations" << endl;
    cout << "13. Quit" << endl;
}

int main()
{
    int input;
    string fileName;
    string userName;
    string book;
    string author;
    Book books[50];
    User users[100];
    int rating = 0;
    int total = 0;
    int temp = 0;
    int temp2 = 0;
    int total2 = 0;
    int result = 0;
    double resultD = 0;
    double total5 = 0;
    Library l = Library();
    while(input != 13)
    {
        displayMenu();
        cin >> input;
        if(input == 1)
        {
            cout << "Enter a book file name: ";
            cin >> fileName;
            cout << endl;
            if(total < 0)
            {
                
            }
            else
            {
                temp = total;
            }
            total = l.readBooks(fileName);
            if(total > -1)
            {
                if(total >= 50)
                {
                    cout << "Database is full. Some books may have not been added." << endl;
                }
                else
                {
                    cout << "Total books in the database: " << total << endl;
                }
            }
            else if(total == -1)
            {
                cout << "No books saved to the database." << endl;
            }
            else 
            {
                cout << "Database is already full. No books were added." << endl;
            }
        }
        else if(input == 2)
        {
            cout << "Enter a user file name: " << endl;
            cin >> fileName;
            if(total2 < 0)
            {
                
            }
            else
            {
                temp2 = total2;
            }
            total2 = l.readRatings(fileName);
            if(total2 > -1)
            {
                if(total2 >= 100)
                {
                    cout << "Database is full. Some users may have not been added." << endl;
                }
                else
                {
                    cout << "Total users in the database: " << total2 << endl;
                }
            }
            else if(total2 == -1)
            {
                cout << "No users saved to the database." << endl;
            }
            else 
            {
                cout << "Database is already full. No users were added." << endl;
            }
        }
        else if(input == 3)
        {
            if(l.getNumBooks() == 0)
            {
                cout << "Database has not been fully initialized." << endl;
            }
            else
            {
                l.printAllBooks();
            }
            
        }
        else if(input == 4)
        {
            if(l.getNumBooks() == 0)
            {
                cout << "Database has not been fully initialized." << endl;
            }
            else
            {
                cout << "Enter an author name: ";
                cin.ignore(1000, '\n');
                getline(cin, author);
                cout << endl;
                l.printBooksByAuthor(author);
            }
        }
        else if(input == 5)
        {
            
            if(l.getNumBooks() == 0)
            {
                cout << "Database has not been fully initialized." << endl;
            }
            else
            {
                cout << "Enter a user name:";
                cin >> userName;
                cout << endl;
                cout << "Enter a book title: ";
                cin.ignore(1000, '\n');
                getline(cin, book);
                cout << endl;
                rating = l.getRating(userName, book);
                if(rating == 0)
                {
                    cout << userName << " has not rated " << book << endl;
                }
                else if(rating == -3)
                {
                    cout << userName << " or " << book << " does not exist." << endl;
                }
                else
                {
                    cout << userName << " rated " << book << " with " << rating << endl;
                }
            }
        }
        else if(input == 6)
        {
            if(l.getNumBooks() == 0)
            {
                cout << "Database has not been fully initialized." << endl;
            }
            else
            {
                cout << "Enter a user name:";
                cin >> userName;
                cout << endl;
                result = l.getCountReadBooks(userName);
                if(result == 0)
                {
                    cout << userName << " has not rated any books." << endl;
                }
                else if(result == -3)
                {
                    cout << userName << " does not exist." << endl;
                }
                else
                {
                    cout << userName << " rated " << result << " books."<< endl;
                }
            }
        }
        else if(input == 7)
        {
            int min = 0;
            if(l.getNumBooks() == 0)
            {
                cout << "Database has not been fully initialized." << endl;
            }
            else
            {
                cout << "Enter a user name:";
                cin >> userName;
                cout << endl;
                cout << "Enter a minimum rating:";
                cin >> min;
                cout << endl;
                l.viewRatings(userName, min);
            }
        }
        else if(input == 8)
        {
            if(l.getNumBooks() == 0)
            {
                cout << "Database has not been fully initialized." << endl;
            }
            else
            {
                cout << "Enter a book title: ";
                cin.ignore(1000, '\n');
                getline(cin, book);
                cout << endl;
                resultD = l.calcAvgRating(book);
                if(resultD == -3)
                {
                    cout << book << " does not exist." << endl;
                }
                else
                {
                    cout << "The average rating for " << book << " is " << resultD << endl;
                }
            }
        }
        else if(input == 9)
        {
            if(l.getNumBooks() == 0)
            {
                cout << "Database has not been fully initialized." << endl;
            }
            else
            {
                cout << "Enter an author name:";
                cin.ignore(1000, '\n');
                getline(cin, author);
                cout << endl;
                resultD = l.calcAvgRatingByAuthor(author);
                if(resultD == -3)
                {
                    cout << author << " does not exist." << endl;
                }
                else
                {
                    cout << "The average rating by " << author << " is " << resultD << endl;
                }
            }
        }
        else if(input == 10)
        {
            cout << "Enter a user name:";
            cin >> userName;
            cout << endl;
            result = l.addUser(userName);
            if(result == -2)
            {
                cout << "Database is already full. " << userName << " was not added." << endl;
            }
            else if(result == 0)
            {
                cout << userName << " already exists in the database." << endl;
            }
            else
            {
                cout << "Welcome to the library " << userName << endl;
            }
            result = 0;
        }
        else if(input == 11)
        {
            if(l.getNumBooks() == 0)
            {
                cout << "Database has not been fully initialized." << endl;
            }
            else
            {
                cout << "Enter a user name:";
                cin >> userName;
                cout << endl;
                cout << "Enter a book title: ";
                cin.ignore(1000, '\n');
                getline(cin, book);
                cout << endl;
                cout << "Enter a new rating: ";
                cin >> rating;
                cout << endl;
                result = l.checkOutBook(userName, book, rating);
                if(result == -4)
                {
                    cout << rating << " is not valid." << endl;
                }
                else if(result == -3)
                {
                    cout << userName << " or " << book << " does not exist." << endl;
                }
                else
                {
                    cout << "We hope you enjoyed your book. The rating has been updated." << endl;
                }
            }
        }
        else if(input == 12)
        {
            if(l.getNumBooks() == 0)
            {
                cout << "Database has not been fully initialized." << endl;
            }
            else
            {
                cout << "Enter a user name:";
                cin >> userName;
                cout << endl;
                l.getRecommendations(userName);
            }
        }
        else
        {
            if(input == 13)
            {
                break;
            }
            else
            {
                cout << "Invalid input." << endl;
                
            }
        }
        cout << endl;
    }
    cout << "Good bye!";
}