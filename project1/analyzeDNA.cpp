// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 1 - Problem 7: analyzeDNA
#include <iostream>
using namespace std;


/*
 * Algorithm: Compares genomes and evaluates which has the best match
 * 1. Take the set of 3 genomes and one sequence
 * 2. Check if any are empty, if so print warning
 * 4. Check if lengths of genomes are the same, if not print warning
 * 5. Else, iterate through genomes and compare to sequence
 * 6. Calculate and print which genomes are the best match
 * Input parameters: set of three string genomes and a string sequence
 * Output (prints to screen): Genome () is the best match.
 * Returns: Nothing
 */
void findMatchedGenome(string g1, string g2, string g3, string sequence)
{
    double hammingDistance;
    double length = g1.length();
    double score1 = 0;
    double score2 = 0;
    double score3 = 0;
    double tempScore = 0;
    
    if(g1.length() == 0 || g2.length() == 0 || g3.length() == 0 || sequence.length() == 0)
    {
        cout << "Genomes or sequence is empty.";
    }
    else if(g1.length() != g2.length() || g2.length() != g3.length() || g1.length() != g3.length())
    {
        cout << "Lengths of genomes are different.";
    }
    else
    {
        if(g1.length() == sequence.length())
        {
            for(int i = 0; i < length; i++)
            {
                if(g1[i] != sequence[i]) {
                    hammingDistance++;
                }
            }
            score1 = (length - hammingDistance) / length;
        }
        else
        {
            int temp;
            for(int i = 0; i < length - sequence.length() + 1; i++)
            {
                temp = i;
                for(int j = 0; j < sequence.length(); j++)
                {
                    if(g1[temp] != sequence[j])
                    {
                        hammingDistance++;
                    }
                    temp++;
                }
                tempScore = (sequence.length() - hammingDistance) / (double)sequence.length();
                if(tempScore > score1)
                {
                    score1 = tempScore;
                }
                hammingDistance = 0;
            }
        }
        
        
        if(g2.length() == sequence.length())
        {
            for(int i = 0; i < length; i++)
            {
                if(g2[i] != sequence[i]) {
                    hammingDistance++;
                }
            }
            score2 = (length - hammingDistance) / length;
        }
        else
        {
            int temp;
            for(int i = 0; i < length - sequence.length() + 1; i++)
            {
                temp = i;
                for(int j = 0; j < sequence.length(); j++)
                {
                    if(g2[temp] != sequence[j])
                    {
                        hammingDistance++;
                    }
                    temp++;
                }
                tempScore = (sequence.length() - hammingDistance) / (double)sequence.length();
                if(tempScore > score2)
                {
                    score2 = tempScore;
                }
                hammingDistance = 0;
            }
        }
        
        if(g3.length() == sequence.length())
        {
            for(int i = 0; i < length; i++)
            {
                if(g3[i] != sequence[i]) {
                    hammingDistance++;
                }
            }
            score3 = (length - hammingDistance) / length;
        }
        else
        {
            int temp;
            for(int i = 0; i < length - sequence.length() + 1; i++)
            {
                temp = i;
                for(int j = 0; j < sequence.length(); j++)
                {
                    if(g3[temp] != sequence[j])
                    {
                        hammingDistance++;
                    }
                    temp++;
                }
                tempScore = (sequence.length() - hammingDistance) / (double)sequence.length();
                if(tempScore > score3)
                {
                    score3 = tempScore;
                }
                hammingDistance = 0;
            }
        }
        if(score1 > score2)
        {
            if(score1 > score3)
            {
                cout << "Genome 1 is the best match." << endl;
            }
            else if(score3 > score1)
            {
                cout << "Genome 3 is the best match." << endl;
            }
            else if(score3 == score1)
            {
                cout << "Genome 1 is the best match." << endl;
                cout << "Genome 3 is the best match." << endl;
            }
        }
        else if(score1 > score3)
        {
            if(score1 > score2)
            {
                cout << "Genome 1 is the best match." << endl;
            }
            else if(score2 > score1)
            {
                cout << "Genome 2 is the best match." << endl;
            }
            else if(score2 == score1)
            {
                cout << "Genome 1 is the best match." << endl;
                cout << "Genome 2 is the best match." << endl;
            }
        }
        else if(score2 > score3 || score3 > score2)
        {
            if(score2 > score3)
            {
                cout << "Genome 2 is the best match." << endl;
            }
            else if(score3 > score2)
            {
                cout << "Genome 3 is the best match." << endl;
            }
        }
        else if(score2 == score3 && score1 != score2)
        {
            cout << "Genome 2 is the best match." << endl;
            cout << "Genome 3 is the best match." << endl;
        }
        else
        {
            cout << "Genome 1 is the best match." << endl;
            cout << "Genome 2 is the best match." << endl;
            cout << "Genome 3 is the best match." << endl;
        }
    }
}

/*
 * Algorithm: Compares genome and evaluates which has the best match
 * 1. Check if lengths are zero
 * 2. If not, loop thorugh the genome and sequence
 * 3. Increase hamming distance if not a match
 * 4. Calculate and return score
 * Input parameters: set of a string genome and a string sequence
 * Output (prints to screen): Nothng
 * Returns: Best similarity score
 */
double findBestSimScore(string genome, string sequence)
{
    double hammingDistance;
    double score = 0;
    double tempScore = 0;
    double length = genome.length();
    
    if (sequence.length() > length || length == 0)
    {
        return 0;
    }
    else
    {
        if(sequence.length() == length)
        {
            for(int i = 0; i < length; i++)
            {
                if(genome[i] != sequence[i]) {
                    hammingDistance++;
                }
            }
            return (length - hammingDistance) / length;
        }
        else
        {
            int temp;
            for(int i = 0; i < length - sequence.length(); i++)
            {
                temp = i;
                for(int j = 0; j < sequence.length(); j++)
                {
                    if(genome[temp] != sequence[j])
                    {
                        hammingDistance++;
                    }
                    temp++;
                }
                tempScore = (sequence.length() - hammingDistance) / (double)sequence.length();
                if(tempScore > score)
                {
                    score = tempScore;
                }
                hammingDistance = 0;
            }
            return score;
        }
    }
}

/*
 * Algorithm: Calculate similarity scores of sequences
 * 1. Take sequences
 * 2. Check if either equal 0 or if they are not equal
 * 3. If not, loop through string
 * 4. If a letter does not equal, increasing hamming distance
 * 5. Return similarity score
 * Input parameters: 2 string sequences
 * Output (prints to screen): Nothing
 * Returns: Similarity score of sequences
 */
double calcSimScore(string sequence1, string sequence2)
{
    double length = sequence1.length();
    double hammingDistance;
    if (length != sequence2.length() || length == 0)
    {
        return 0;
    }
    else
    {
        for(int i = 0; i < length; i++)
        {
            if(sequence1[i] != sequence2[i])
            {
                hammingDistance += 1;
            }
        }
        return (length - hammingDistance) / length;
    }
}

void showMenu()
{
    int input;
    while(input != 4)
    {
        cout << "Select a numerical option:" << endl;
        cout << "=== menu ===" << endl;
        cout << "1. Find similarity score" << endl;
        cout << "2. Find the best similarity score" << endl;
        cout << "3. Analyze the genome sequences" << endl;
        cout << "4. Quit" << endl;
        cin >> input;
        
        if (input == 1)
        {
            cout << "Enter sequence 1:" << endl;
            string s1;
            cin >> s1;
            cout << "Enter sequence 2:" << endl;
            string s2;
            cin >> s2;
            cout << "Similarity score: " << calcSimScore(s1, s2) << endl;
        }
        else if(input == 2)
        {
            cout << "Enter genome:" << endl;
            string g;
            cin >> g;
            cout << "Enter sequence:" << endl;
            string s;
            cin >> s;
            cout << "Best similarity score: " << findBestSimScore(g, s) << endl;
        }
        else if(input == 3)
        {
            cout << "Enter genome 1:" << endl;
            string g1;
            cin >> g1;
            cout << "Enter genome 2:" << endl;
            string g2;
            cin >> g2;
            cout << "Enter genome 3:" << endl;
            string g3;
            cin >> g3;
            cout << "Enter sequence:" << endl;
            string s;
            cin >> s;
            
            findMatchedGenome(g1, g2, g3, s);
        }
        else if(input != 4)
        {
            cout << "Invalid option." << endl;
        }
    }
    cout << "Good bye!";
}

int main() {
    // Test 1
    /* Input
    1. 3
    2. AATGACTCAC
    3. GATGCACTAA
    4. AATGCTGCTC
    5. ATGC
    6. 4
    */
    // Expected Output
    /*
    Select a numerical option:
    === menu ===
    1. Find similarity score
    2. Find the best similarity score
    3. Analyze the genome sequences
    4. Quit
    Enter genome 1:
    Enter genome 2:
    Enter genome 3:
    Enter sequence:
    Genome 2 is the best match.
    Genome 3 is the best match.
    Select a numerical option:
    === menu ===
    1. Find similarity score
    2. Find the best similarity score
    3. Analyze the genome sequences
    4. Quit
    Good bye!
    */
    showMenu();
    
}