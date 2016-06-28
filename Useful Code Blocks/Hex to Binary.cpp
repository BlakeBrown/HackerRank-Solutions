// ==== HEX TO BINARY =====
// Method 1 (recommended): O(l) memory & runtime, where l is the length of the hex string
string hexToBinary(string s) {
	string tmp;
	for(int i = 0; i < s.size(); i++) {
	    switch(toupper(aHex[i])) {
	        case '0': tmp += "0000";
	        case '1': tmp += "0001";
	        case '2': tmp += "0010";
	        case '3': tmp += "0011";
	        case '4': tmp += "0100";
	        case '5': tmp += "0101";
	        case '6': tmp += "0110";
	        case '7': tmp += "0111";
	        case '8': tmp += "1000";
	        case '9': tmp += "1001";
	        case 'A': tmp += "1010";
	        case 'B': tmp += "1011";
	        case 'C': tmp += "1100";
	        case 'D': tmp += "1101";
	        case 'E': tmp += "1110";
	        default: tmp += "1111";
	    }
	}
	return tmp;
}

// Method 2: Makes use of several libraries to perform the conversion, but involves converting
// from hex to decimal first. Fails for large hex numbers (ones that require a bitset of
// more than 64 bits) since we can't store them in memory as unsigned numbers.
#include <sstream>
#include <bitset>
#include <string>
string hexToBinary(string s) {
	stringstream ss;
	ss<<hex<<s;
	unsigned n;
	ss>>n;
	bitset<32> b(n);
	return b.to_string();
}

// ===== BINARY TO HEX (using big endian) =====
// Method 1 (recommended): O(l) memory & runtime, where l is the length of the binary string
#include <regex>
string binaryToHex(string s) {
	// Pad zeroes to ensure the string is divisible by 4
	s = string(4-s.size()%4, '0') + s;
	string tmp, bits;
	for(int i = 0; i < A.size()-3; i+=4) {
		bits = s.substr(i, 4);
		if(bits == "0000") {
			tmp += '0';
		} else if(bits == "0001") {
			tmp += '1';
		} else if(bits == "0010") {
			tmp += '2';
		} else if(bits == "0011") {
			tmp += '3';
		} else if(bits == "0100") {
			tmp += '4';
		} else if(bits == "0101") {
			tmp += '5';
		} else if(bits == "0110") {
			tmp += '6';
		} else if(bits == "0111") {
			tmp += '7';
		} else if(bits == "1000") {
			tmp += '8';
		} else if(bits == "1001") {
			tmp += '9';
		} else if(bits == "1010") {
			tmp += 'A';
		} else if(bits == "1011") {
			tmp += 'B';
		} else if(bits == "1100") {
			tmp += 'C';
		} else if(bits == "1101") {
			tmp += 'D';
		} else if(bits == "1110") {
			tmp += 'E';
		} else {
			tmp += 'F';
		}
	}
	// Removes leading zeroes, output '0' if all zeroes
	return regex_replace(tmp, regex("^0+(?!$)"), "");
}

// Method 2: Makes use of several libraries to perform the conversion, but involves converting
// from binary to decimal first. Fails for large binary numbers (ones that require a bitset of
// more than 64 bits) since we can't store them in memory as unsigned numbers.
#include <sstream>
#include <bitset>
#include <string>
string binaryToHex(string s) {
	bitset<32> set(s); 
	stringstream ss;
	ss<<hex<<uppercase<<set.to_ulong();
	return ss.str();
}
