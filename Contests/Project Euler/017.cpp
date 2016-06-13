#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string::iterator it;

// 0 to 19
string small(long long n) {
	if(n == 1) {
		return "One";
	} else if(n == 2) {
		return "Two";
	} else if(n == 3) {
		return "Three";
	} else if(n == 4) {
		return "Four";
	} else if(n == 5) {
		return "Five";
	} else if(n == 6) {
		return "Six";
	} else if(n == 7) {
		return "Seven";
	} else if(n == 8) {
		return "Eight";
	} else if(n == 9) {
		return "Nine";
	} else if(n == 10) {
		return "Ten";
	} else if(n == 11) {
		return "Eleven";
	} else if(n == 12) {
		return "Twelve";
	} else if(n == 13) {
		return "Thirteen";
	} else if(n == 14) {
		return "Fourteen";
	} else if(n == 15) {
		return "Fifteen";
	} else if(n == 16) {
		return "Sixteen";
	} else if(n == 17) {
		return "Seventeen";
	} else if(n == 18) {
		return "Eighteen";
	} else {
		return "Nineteen";
	} 
}

// 20 to 99
string tens(long long n) {
	string result, s = to_string(n);
	int firstDigit = (int) s[0]-'0';
	int secondDigit = (int) s[1]-'0'; 
	if(firstDigit == 2) {
		result = "Twenty";
	} 
	if(firstDigit == 3) {
		result = "Thirty";
	} 
	if(firstDigit == 4) {
		result = "Forty";
	} 
	if(firstDigit == 5) {
		result = "Fifty";
	} 
	if(firstDigit == 6) {
		result = "Sixty";
	} 
	if(firstDigit == 7) {
		result = "Seventy";
	} 
	if(firstDigit == 8) {
		result = "Eighty";
	}
	if(firstDigit == 9) {
		result = "Ninety";
	} 
	if(secondDigit == 0) {
		return result;
	} else {
		return result + " " + small(secondDigit);
	}
}

// 100 to 999
string hundreds(long long n) {
	string result, s = to_string(n);
	int firstDigit = (int) s[0]-'0';
	int remainingDigits = stoi(s.substr(1, 2));
	result = small(firstDigit);
	if(remainingDigits == 0) {
		return result + " " + "Hundred";
	} else if(remainingDigits < 20) {
		return result + " " + "Hundred" + " " + small(remainingDigits);
	} else {
		return result + " " + "Hundred" + " " + tens(remainingDigits);
	}
}

// 1000 to 999,999
string thousands(long long n) {
	string result, s = to_string(n);
	int startingDigits, remainingDigits;
	if(s.length() == 4) {
		// 1000 to 9999
		startingDigits = (int) s[0]-'0';
		remainingDigits = stoi(s.substr(1, 3));
		result = small(startingDigits);
	} else if(s.length() == 5) {
		// 10,000 to 99,999
		startingDigits = stoi(s.substr(0, 2));
		remainingDigits = stoi(s.substr(2, 3));	
		if(startingDigits < 20) {
			result = small(startingDigits);
		} else {
			result = tens(startingDigits);
		}
	} else if(s.length() == 6) {
		// 100,000 to 999,999
		startingDigits = stoi(s.substr(0, 3));
		remainingDigits = stoi(s.substr(3, 3));	
		result = hundreds(startingDigits);
	}
	if(remainingDigits == 0) {
		return result + " " + "Thousand";
	} else if(remainingDigits < 20) {
		return result + " " + "Thousand" + " " + small(remainingDigits);
	} else if(remainingDigits < 100) {
		return result + " " + "Thousand" + " " + tens(remainingDigits);
	} else {
		return result + " " + "Thousand" + " " + hundreds(remainingDigits);
	}
}

// 1,000,000 to 999,999,999
string millions(long long n) {
	string result, s = to_string(n);
	int startingDigits, remainingDigits;
	if(s.length() == 7) {
		// 1,000,000 to 9,999,999
		startingDigits = (int) s[0]-'0';
		remainingDigits = stoi(s.substr(1, 6));
		result = small(startingDigits);
	} else if(s.length() == 8) {
		// 10,000,000 to 99,999,999
		startingDigits = stoi(s.substr(0, 2));
		remainingDigits = stoi(s.substr(2, 6));	
		if(startingDigits < 20) {
			result = small(startingDigits);
		} else {
			result = tens(startingDigits);
		}
	} else if(s.length() == 9) {
		// 100,000,000 to 999,999,999
		startingDigits = stoi(s.substr(0, 3));
		remainingDigits = stoi(s.substr(3, 6));	
		result = hundreds(startingDigits);
	}
	if(remainingDigits == 0) {
		return result + " " + "Million";
	} else if(remainingDigits < 20) {
		return result + " " + "Million" + " " + small(remainingDigits);
	} else if(remainingDigits < 100) {
		return result + " " + "Million" + " " + tens(remainingDigits);
	} else if(remainingDigits < 1000) {
		return result + " " + "Million" + " " + hundreds(remainingDigits);
	} else {
		return result + " " + "Million" + " " + thousands(remainingDigits);
	}
}

// 1,000,000,000 to 999,999,999,999
string billions(long long n) {
	string result, s = to_string(n);
	int startingDigits, remainingDigits;
	if(s.length() == 10) {
		// 1,000,000,000 to 9,999,999,999
		startingDigits = (int) s[0]-'0';
		remainingDigits = stoi(s.substr(1, 9));
		result = small(startingDigits);
	} else if(s.length() == 11) {
		// 10,000,000,000 to 99,999,999,999
		startingDigits = stoi(s.substr(0, 2));
		remainingDigits = stoi(s.substr(2, 9));	
		if(startingDigits < 20) {
			result = small(startingDigits);
		} else {
			result = tens(startingDigits);
		}
	} else if(s.length() == 12) {
		// 100,000,000,000 to 999,999,999,999
		startingDigits = stoi(s.substr(0, 3));
		remainingDigits = stoi(s.substr(3, 9));	
		result = hundreds(startingDigits);
	}
	if(remainingDigits == 0) {
		return result + " " + "Billion";
	} else if(remainingDigits < 20) {
		return result + " " + "Billion" + " " + small(remainingDigits);
	} else if(remainingDigits < 100) {
		return result + " " + "Billion" + " " + tens(remainingDigits);
	} else if(remainingDigits < 1000) {
		return result + " " + "Billion" + " " + hundreds(remainingDigits);
	} else if(remainingDigits < 1000000) {
		return result + " " + "Billion" + " " + thousands(remainingDigits);
	} else {
		return result + " " + "Billion" + " " + millions(remainingDigits);
	}
}

string numberToString(long long n) {
	if(n == 0) {
		return "Zero";
	}
	if(n < 20) {
		return small(n);
	} 
	if(n < 100) {
		return tens(n);
	}
	if(n < 1000) {
		return hundreds(n);
	}
	if(n < 1000000) {
		return thousands(n);
	}
	if(n < 1000000000) {
		return millions(n);
	}
	if(n < 1000000000000) {
		return billions(n);
	}
	return "One Trillion";
}


int main() {
    int T;
    cin>>T;
    while(T--) {
    	if(T < 0) {
    		break;
    	}
    	long long n;
    	cin>>n;
    	cout<<numberToString(n)<<"\n";
    }
    return 0;
}