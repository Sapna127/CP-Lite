// Sieve of Eratosthenes is an algorithm for finding all the prime numbers in a segment [1:n] using nloglogn operations.
// https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#different-optimizations-of-the-sieve-of-eratosthenes

int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}

// seiving till root 

int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}


