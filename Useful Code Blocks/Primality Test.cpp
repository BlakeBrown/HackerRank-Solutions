// ========================================================
// ========================================================
// ============ Method 1: Use a lookup table ==============
// ========================================================
// =========================================================

// Use Sieve of Eratosthenes to generate a primality lookup table of the first 1,000,000 numbers
bool* primes = new bool[1000000];
for(long long i = 2; i < 1000000; i++) {
    primes[i] = true;
}
for(long long i = 2; i < 1000000; i++) {
    if(primes[i]) {
        for(long long j = (i*i); j < 1000000; j+=i) {
            primes[j] = false;
        }
    }
}

bool isPrime(long n) {
	if(n <= 1) {
		return false;
	}
	if(primes[n]) {
		return true;
	} else {
		return false;
	}
}