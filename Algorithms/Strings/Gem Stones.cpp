#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int N;
    string line;
    cin>>N;
    string stringArray[N];
    int counter = 0;

    // Read all of the rock compositions, condense them by removing duplicate letters
    for(int i = 0; i < N; i++) {
        string line;
        cin>>line;
        char alphabetChar = 'a';
        // Remove duplicate letters in a string
        for(int i = 0; i < 26; i++) {  
            for(char& lineChar : line) {
                if(lineChar == alphabetChar) {
                    // Letter found, move on
                    stringArray[counter].push_back(alphabetChar);
                    break;
                }
            }
            alphabetChar++;
        }
        counter++;
    } 

    int smallestStringLength = stringArray[0].length();
    int indexOfSmallestString = 0;

    // Find the smallest string in stringArray
    for(int i = 1; i < N; i++) {
        if(stringArray[i].size() < smallestStringLength) {
            smallestStringLength = stringArray[i].length();
            indexOfSmallestString = i;
        }
    }

    // Now we only need to check each character belonging in the smallest string

    int commonGems = 0;

    for(int i = 0; i < smallestStringLength; i++) {
        for(int j = 0; j < N; j++) { 
            bool found = false;
            for(char& lineChar : stringArray[j]) {
                if(lineChar == stringArray[indexOfSmallestString][i]) {
                    found = true;
                    break;
                }
            }
            if(found) {
                if(j == (N-1)) {
                    commonGems++;
                }
                // Move on since char was found
                continue;
            } else {
                // Char doesn't exist in one of the strings, move on
                break;
            }
        }
    }

    cout<<commonGems;
    return 0;
}