# 📘 Sieve Notes

A collection of important **sieve algorithms** used in competitive programming and number theory.

---

## 1. Sieve of Eratosthenes (Prime Numbers)

### Idea
- Mark multiples of primes as composite.  
- Remaining unmarked numbers are primes.

### Code (C++)
```cpp
vector<int> sievePrimes(int N) {
    vector<bool> isPrime(N+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= N; i++)
        if (isPrime[i]) primes.push_back(i);
    return primes;
}
```

### Complexity
- **Time:** O(N log log N)  
- **Space:** O(N)  

### Applications
- Generate primes up to N.  
- Base for other sieve variants.  

---

## 2. Smallest Prime Factor (SPF) Sieve

### Idea
- For every number, store its **smallest prime divisor**.  
- Allows fast prime factorization in O(log N).

### Code (C++)
```cpp
vector<int> spfSieve(int N) {
    vector<int> spf(N+1);
    for (int i = 0; i <= N; i++) spf[i] = i;
    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j <= N; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
    return spf;
}

// Factorization using spf
vector<int> getFactors(int x, vector<int>& spf) {
    vector<int> res;
    while (x != 1) {
        res.push_back(spf[x]);
        x /= spf[x];
    }
    return res;
}
```

### Complexity
- **Time:** O(N log log N)  
- **Factorization:** O(log N) per query  
- **Space:** O(N)  

### Applications
- Fast prime factorization.  
- Multiplicative function precomputations.  

---

## 3. Prime Factor Sieve (All Prime Factors)

### Idea
- For each prime `i`, push it into factor list of its multiples.  

### Code (C++)
```cpp
void primeFactorSieve(int N, vector<vector<int>>& primeFactors) {
    for (int i = 2; i <= N; i++) {
        if (primeFactors[i].empty()) { // i is prime
            for (int j = i; j <= N; j += i) {
                primeFactors[j].push_back(i);
            }
        }
    }
}
```

### Complexity
- **Time:** O(N log log N)  
- **Space:** O(N log N)  

### Applications
- Precompute **prime factors only** for all numbers.  

---

## 4. Divisor Sieve (All Divisors)

### Idea
- For each `i`, push it into all multiples’ factor list.  

### Code (C++)
```cpp
void divisorSieve(int N, vector<vector<int>>& divisors) {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divisors[j].push_back(i);
        }
    }
}
```

### Complexity
- **Time:** O(N log N)  
- **Space:** O(N log N)  

### Applications
- Precompute divisors for all numbers.  
- Useful in GCD/LCM and divisor-related problems.  

---

## 5. Euler’s Totient Function (φ) Sieve

### Idea
- φ(n) = count of numbers ≤ n that are coprime to n.  
- Multiplicative function, can be computed with sieve.  

### Code (C++)
```cpp
vector<int> phiSieve(int N) {
    vector<int> phi(N+1);
    for (int i = 0; i <= N; i++) phi[i] = i;
    for (int i = 2; i <= N; i++) {
        if (phi[i] == i) { // i is prime
            for (int j = i; j <= N; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}
```

### Complexity
- **Time:** O(N log log N)  
- **Space:** O(N)  

### Applications
- Modular arithmetic.  
- Number theory problems.  

---

## 6. Mobius Function (μ) Sieve [Advanced]

### Idea
- μ(n) =  
  - 1 if n = 1  
  - (−1)^k if n is product of k distinct primes  
  - 0 if n has squared prime factor  

### Code (C++)
```cpp
vector<int> mobiusSieve(int N) {
    vector<int> mu(N+1, 1), primes;
    vector<bool> isPrime(N+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            mu[i] = -1;
        }
        for (int p : primes) {
            if (i * p > N) break;
            isPrime[i * p] = false;
            if (i % p == 0) {
                mu[i * p] = 0;
                break;
            } else {
                mu[i * p] = -mu[i];
            }
        }
    }
    return mu;
}
```

### Complexity
- **Time:** O(N)  
- **Space:** O(N)  

### Applications
- Advanced number theory (inclusion-exclusion, multiplicative functions).  

---

# ✅ Summary Table

| Sieve | Purpose | Time | Space |
|-------|---------|------|-------|
| Eratosthenes | Find primes | O(N log log N) | O(N) |
| SPF | Fast factorization | O(N log log N) | O(N) |
| Prime Factor Sieve | Prime factors | O(N log log N) | O(N log N) |
| Divisor Sieve | All divisors | O(N log N) | O(N log N) |
| φ Sieve | Euler totient | O(N log log N) | O(N) |
| μ Sieve | Mobius function | O(N) | O(N) |

---
