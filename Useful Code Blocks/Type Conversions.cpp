// ===== String <-> Integer =====

// String to integer
string s;
int number = stoi(s); // For long to string or long long to string, we can use stol or stoll respectively
// Integer to string
int number;
string s = to_string(number);

// ===== Char <-> Integer =====

// Chars & ints are converted implicity, so the following will work as long as int is between 0-127

// Char to integer
char a = 'a';
int aInteger = a;
// Integer to char
int aInteger = 97;
char a = aInteger;

// Note: If you want to convert a numerical char to it's actual value (i.e '4' -> 4), we need
// to subtract '0' to get the non-ascii integer value.
char a = '4';
int inta = a - '0'; // Sets a = 4, if we didn't subtract '0' we would have a = 52 which is the ascii value of '4'

// ===================
// ====== Java =======
// ===================

// ===== String <-> Integer =====

// String to integer
String s;
int number = Integer.parseInt(s);
// Integer to string
int number;
String s = number.toString();