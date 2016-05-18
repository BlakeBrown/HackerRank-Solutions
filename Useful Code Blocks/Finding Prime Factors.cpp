// === Example 1: Find the # of prime factors === 

// Optimized version
int numPrimeFactors = 0;
if(number == 1) {
    numPrimeFactors = 0;
} else if(((number != 0) && !(number & (number - 1)))) {
    // If number is a power of 2
    numPrimeFactors = number/2;
} else {
    // Calculate # of prime factors
    while(number > 1) {
        bool foundFactor = false;
        for(long j = 2; j*j <= number; j++) {
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
