#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
using namespace std;

map<long,long>::iterator map_it;
list<long>::iterator vector_it;

// Use dynamic programming (memoization)
int main() {
	// array[sequence starting number] = length of sequence
	long* array = new long[5000001];
	for (int i = 1; i <= 5000000; ++i)
	{
		array[i] = 0;
	}
	// Pre-calculate all of the powers of two less than 5,000,000 (since if the number is a power of two, we know immediately when the sequence will end)
	long powerOfTwo = 1;
	long sequenceLength = 1;
	while(powerOfTwo <= 5000000) {
		array[powerOfTwo] = sequenceLength;
		powerOfTwo*=2;
		sequenceLength++;
	}
	for(long i = 1; i <= 5000000; i++) {
		list<long> sequence;
		long long start = i;
        sequenceLength = 0;
		// Generate a new sequence
		while(start != 1) {
			// If we've already calculated the sequenceLength of start, we can break
			if(start <= 5000000 && array[start] != 0) {
                sequenceLength += array[start];
				break;
			} else {
				// Add the new sequence value to map
				sequence.push_back(start);
			}
			if(start%2 == 0) {
				// even
				start/=2;
			} else {
				// odd
				start = 3*start + 1;
			}
			sequenceLength++;
		}
		while(!sequence.empty()) {
			if(sequence.front() <= 5000000) {			
				array[sequence.front()] = sequenceLength;
			}
			sequence.pop_front();
			sequenceLength--;
		}
	}

	// Pre-calculate the start of the longest sequence from 1 to 5,000,000
	long* collatz = new long[5000001];
    long startOfLongestChain = 0;
    long longestChain = 0;
    for(int i = 1; i <= 5000000; i++) {
        if(array[i] >= longestChain) {
            startOfLongestChain = i;
            longestChain = array[i];
        }
        collatz[i] = startOfLongestChain;
    }

    int T;
    cin>>T;
    while(T--) {
    	if(T < 0) {
    		break;
    	}
    	long N;
    	cin>>N;
    	cout<<collatz[N]<<"\n";
    }
    return 0;
}