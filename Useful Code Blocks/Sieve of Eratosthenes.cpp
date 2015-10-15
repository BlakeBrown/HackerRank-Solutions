// Use Sieve of Eratosthenes to generate a list of primes up to N: 
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
bool* primes = new bool[N];
// Initialize array
for(long long i = 0; i < N; i++) {
    primes[i] = true;
}
// Perform sieve
for(long long i = 2; i < (long long) sqrt((double)N); i++) {
    if(primes[i]) {
        for(long long j = (i*i); j < N; j+=i) {
            primes[j] = false;
        }
    }
}
// Print primes
for(long long i = 2; i < N; i++) {
    if(primes[i]) {
    	cout<<i<<" is prime!\n";
    }
}