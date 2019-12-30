// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 1 - Problem 5: printCharInString
#include <iostream>
using namespace std;

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

int main()
{
    // test 1
    // expected output
    // 0.66
    cout << findBestSimScore("ATACGC", "ACT") << endl;
    
    // test 2
    // expected output
    // 1
    cout << findBestSimScore("AG", "AG") << endl;
}