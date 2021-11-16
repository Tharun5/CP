/**
 * Description: Computes all prime numbers less than n in linear time.
 * Source: https://cp-algorithms.com/algebra/prime-sieve-linear.html
 * Time: O(n)
*/

const int N = 1e7;
vector<int> spf(N+1); //stores smallest prime factor of a number
vector<int> prm; //contains list of primes

void linearSieve(){
    for (int i=2; i <= N; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            prm.push_back(i);
        }   
        for (int j=0; j < (int)prm.size() && prm[j] <= spf[i] && i*prm[j] <= N; ++j) {
            spf[i * prm[j]] = prm[j];
        }
    }
}

//To check if number is prime, Its spf should equal to number itself
