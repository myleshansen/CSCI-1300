// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 7 - Problem 6: put them together
#include <iostream>
#include <fstream>
#include User.h
#include Book.h
using namespace std;


void printMenu(){
    cout << "======Main Menu=====" << endl;
    cout << "1. Read books" << endl;
    cout << "2. Read ratings" << endl;
    cout << "3. Get rating" << endl;
    cout << "4. Find number of books user rated" << endl;
    cout << "5. Get average rating" << endl;
    cout << "6. Quit" << endl;
}

int main()
{
    int input;
    string fileName;
    string userName;
    string book;
    Book books[50];
    User users[100];
    int total = 0;
    int temp = 0;
    int temp2 = 0;
    int total2 = 0;
    int total3 = 0;
    int total4 = 0;
    double total5 = 0;
    while(input != 6)
    {
        printMenu();
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
            total = readBooks(fileName, books, temp, 50);
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
            total2 = readRatings(fileName, users, temp2, 100, 50);
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
            cout << "Enter a user name: ";
            cin >> userName;
            cout << endl;
            cout << "Enter a book title: ";
            cin.ignore(1000, '\n');
            getline(cin, book);
            cout << endl;
            total3 = getRating(userName, book, users, books, 100, 50);
            if(total3 == 0)
            {
                cout << userName << " has not rated " << book << endl;
            }
            else if(total3 == -3)
            {
                cout << userName << " or " << book << " does not exist." << endl;
            }
            else
            {
                cout << userName << " rated " << book << " with " << total3 << endl;
            }
        }
        else if(input == 4)
        {
            cout << "Enter a user name: ";
            cin >> userName;
            cout << endl;
            total4 = getCountReadBooks(userName, users, 100, 50);
            if(total4 == -3)
            {
                cout << userName << " does not exist." << endl;
            }
            else if(total4 == 0)
            {
                cout << userName << " has not rated any books." << endl;
            }
            else
            {
                
                cout << userName << " rated " << total4 << " books." << endl;
            }
        }
        else if(input == 5)
        {
            cout << "Enter a book title: ";
            cin.ignore(1000, '\n');
            getline(cin, book);
            cout << endl;
            total5 = calcAverageRating(users, books, 100, 50, book);
            if(total5 == -3)
            {
                cout << book << " does not exist." << endl;
            }
            else
            {
                cout << "The average rating for " << book << " is " << total5 << endl;
            }
        }
        else
        {
            if(input == 6)
            {
                break;
            }
            else
            {
                cout << "Invalid input." << endl;
            }
        }
    }
    cout << "Good bye!";
}