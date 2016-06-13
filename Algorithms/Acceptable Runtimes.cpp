// Acceptable Runtimes for Given Values of N: 

// General rule: Try to keep the number of iterations under a few million

// 1) when N <= 10, then both O(N!) and O(2^N) are will run fine  (for 2^N, N <= 20 )    
// 2) when N <= 100 ; then O(N^3).
// 3) when N <= 1,000 ; then O(N^2) is also ok
// 4) when N <= 1,000,000; then O(N) is fine 
// 5) when N = 1.000.000.000 then O(N) is NOT fine. Search for a better option.
// Also, these values depends upon what are you doing in the loop. Costly statements may result in slow program.