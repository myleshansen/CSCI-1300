// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 2 - Problem 0: Library Class

#include <iostream>
#include "Book.h"
#include "User.h"
using namespace std;

#ifndef LIBRARY_H
#define LIBRARY_H

/*
Library class definition
*/

class Library {
    private:
        int sizeBook = 50;
        int sizeUser = 100;
        Book books[50];
        User users[100];
        int numBooks;
        int numUsers;
    public:
        Library();
        int getSizeBook();
        int getSizeUser();
        int getNumBooks();
        int getNumUsers();
        string getbookArray(Book books[], int index);
        int readBooks(string fileName);
        void printAllBooks();
        void printBooksByAuthor(string author);
        int readRatings(string filename);
        int getRating(string username, string book);
        int getCountReadBooks(string username);
        void viewRatings(string username, int minRating);
        double calcAvgRating(string book);
        double calcAvgRatingByAuthor(string author);
        int addUser(string username);
        int checkOutBook(string username, string book, int rating);
        void getRecommendations(string username);
};

#endif