//==================
//====== C++ =======
//==================

// C++ 11 gives us some nice functions to use for this
// NTS: May want to use Java (StringBuilder) or Python for future string questions?

// String to integer
string s;
int number = stoi(s); // For long to string or long long to string, we can use stol or stoll respectively
// Integer to string
int number;
string s = to_string(number);
// Char to number
char a = '4';
int inta = a - '0'; // Sets a = 4

//===================
//====== Java =======
//===================

// String to integer
String s;
int number = Integer.parseInt(s);
// Integer to string
int number;
String s = number.toString();