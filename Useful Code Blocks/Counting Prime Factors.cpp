// Example 1: Find the # of prime factors of a given number (optimized)
int numPrimeFactors = 0;
if(number == 1) {
    // Edge case
    numPrimeFactors = 0;
} else if(((number != 0) && !(number & (number - 1)))) {
    // If the number is a power of 2, we immediately know how many prime factors it has
    numPrimeFactors = number/2;
} else {
    // Main algorithm: Calculate # of prime factors using division method
    while(number > 1) {
        bool foundFactor = false;
        for(long j = 3; j*j <= number; j+=2) {
            if(number%j == 0) {
                numPrimeFactors++;
                number /= j;
                foundFactor = true;
                break;
            }
        }
        if(!foundFactor) {
            // number is prime
            numPrimeFactors++;
            break;
        }
    }
}
