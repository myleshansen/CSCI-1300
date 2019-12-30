// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 7 - Problem 1: User
#include <iostream>
using namespace std;

#ifndef USER_H
#define USER_H

/*
User class that allows you to get and set username, ratingAt, and number of ratings
*/

class User {
    private:
    string username;
    int ratings[50];
    int numRatings;
    int size;
    
    public:
    User();
    User(string s, int arr[], int i);
    string getUsername();
    void setUsername(string s);
    int  getRatingAt(int index);
    bool setRatingAt(int index, int value);
    int getNumRatings();
    void setNumRatings(int i);
    int getSize();
};


#endif