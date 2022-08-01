// Use Sieve of Eratosthenes to generate a list of primes up to N: 
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
bool* prime = new bool[N];
// Initialize array
for(long long i = 0; i < N; i++) {
    prime[i] = true;
}
// Perform sieve
for(long long i = 2; i*i < N; i++) {
    if(prime[i]) {
        for(long long j = i*i; j < N; j+=i) {
            prime[j] = false;
        }
    }
}
// Print primes
for(long long i = 2; i < N; i++) {
    if(prime[i]) {
    	cout<<i<<" is prime!\n";
    }
}



// Note: Since every even number >= 4 is not prime, the sieve can be optimized 
// memory-wise by transforming indices. We can transform the array like so: 
//   [1, 2, 3, 4 , 5]... i 
// ->[3, 5, 7, 9, 11]... j = 2i+1 
// This removes almost half the array and saves us from checking even numbers for primality