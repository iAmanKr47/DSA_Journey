//USE OF Sieve of Eratosthenes concept to find prime numbers

 vector<int> getPrimes(int n) {
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
 
        for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
             if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                   prime[i] = false;
             }
        }
        for (int p = 2; p <= n/2; p++)
        if(prime[p]&&prime[n-p]){
            return {p,n-p};
        }
        return {-1,-1};
    }
