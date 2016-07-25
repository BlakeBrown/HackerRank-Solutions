#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <string>
#include <regex>
using namespace std;

char binaryToHex(string s) {
	if(s == "0000") {
		return '0';
	} else if(s == "0001") {
		return '1';
	} else if(s == "0010") {
		return '2';
	} else if(s == "0011") {
		return '3';
	} else if(s == "0100") {
		return '4';
	} else if(s == "0101") {
		return '5';
	} else if(s == "0110") {
		return '6';
	} else if(s == "0111") {
		return '7';
	} else if(s == "1000") {
		return '8';
	} else if(s == "1001") {
		return '9';
	} else if(s == "1010") {
		return 'A';
	} else if(s == "1011") {
		return 'B';
	} else if(s == "1100") {
		return 'C';
	} else if(s == "1101") {
		return 'D';
	} else if(s == "1110") {
		return 'E';
	} else {
		return 'F';
	}
}

const char* hexToBinary(char c) {
    switch(toupper(c)) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        default: return "1111";
    }
}

// Removes leading zeroes from answer, or outputs one '0' if s is all zeroes
void outputAnswer(string s) {
	cout<<regex_replace(s, regex("^0+(?!$)"), "")<<"\n";
}

int main() {
	int Q;
	cin>>Q;
	while(Q > 0) {
		int k;
		cin>>k;
		string aHex, bHex, cHex;
		cin>>aHex>>bHex>>cHex;
		string A, B, C;
		// Convert aHex, bHex, cHex to binary with the most significant bit first (big endian)
		for(int i = 0; i < aHex.size(); i++) {
			A += hexToBinary(aHex[i]);
		}
		for(int i = 0; i < bHex.size(); i++) {
			B += hexToBinary(bHex[i]);
		}
		for(int i = 0; i < cHex.size(); i++) {
			C += hexToBinary(cHex[i]);
		}

		// Make all strings the same size (since they could have a different number of bits)
		int longestString;
		if(A.size() >= B.size() && A.size() >= C.size()) {
			longestString = A.size();
		} else if(B.size() >= A.size() && B.size() >= C.size()) {
			longestString = B.size();
		} else if(C.size() >= A.size() && C.size() >= B.size()) {
			longestString = C.size();
		}
		A = string(longestString-A.size(), '0') + A;
		B = string(longestString-B.size(), '0') + B;
		C = string(longestString-C.size(), '0') + C;

		// Step 1: Check if A | B = C is possible in less than K steps
		for(int i = 0; i < A.size(); i++) {
			if(C[i] == '0') {
				// We require both A[i] and B[i] to be 0
				if(A[i] != '0') {
					A[i] = '0';
					k--;
				}
				if(B[i] != '0') {
					B[i] = '0';
					k--;
				}
			} else {
				// We require at least one of A[i] or B[i] to be 1
				if(A[i] == '0' && B[i] == '0') {
					B[i] = '1'; // Since we require a '1' and A to be as small as possible
					k--;
				}
			}
		}
		if(k < 0) {
			cout<<"-1\n";
			Q--;
			continue;
		}
		// Step 2: Make A and B as small as possible
		for(int i = 0; i < A.size(); i++) {
			if(k == 0) {
				break;
			}
			if(C[i] == '1' && A[i] == '1') {
				if(k > 1 && B[i] == '0') {
					// Swap to make A smaller
					A[i] = '0';
					B[i] = '1';
					k -= 2;
				} else if(B[i] == '1') {
					// Reduce A
					A[i] = '0';
					k--;
				}
			}
		}
		string answerA, answerB;
		for(int i = 0; i < A.size()-3; i+=4) {
			answerA += binaryToHex(A.substr(i, 4));
			answerB += binaryToHex(B.substr(i, 4));
		}
		outputAnswer(answerA);
		outputAnswer(answerB);
		Q--;
	}
    return 0;
}
