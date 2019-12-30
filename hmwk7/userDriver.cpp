// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 7 - Problem 1: User
#include <iostream>
#include "User.h"
using namespace std;

int main()
{
    // Test 1
    // Expected output
    /*
        0  
    */
    User u2 = User();
    cout << u2.getNumRatings() << endl;
    
    // Test 2 
    // Expected output
    /*
        set/get setRatingAt(40,3) [numRating=45]
        Setting rating at 40 to 3
        setRatingAt(40,3) returned: true
        getRatingAt(40) returned: 3
    */
    User u1 = User();
    int nRating = 45;
    u1.setNumRatings(nRating);
    int rating = 3;
    int idx = 40;
    cout << "set/get setRatingAt(" << idx << "," << rating << ") [numRating=" << nRating  << "]" << endl;
    cout << "Setting rating at " << idx << " to " << rating << endl;
    string ratingset = u1.setRatingAt(idx,rating) ? "true": "false";
    cout << "setRatingAt(" << idx << "," << rating << ") returned: " << ratingset << endl;
    cout << "getRatingAt(" << idx << ") returned: " << u1.getRatingAt(idx) << endl;
}