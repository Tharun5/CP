/**
 * Description: Computes all prime numbers less than n in linear time.
 * Source: https://cp-algorithms.com/algebra/prime-sieve-linear.html
 * Time: O(n)
*/

const int N = 1e7;
int spf[N];
vector<int> primes;

void seive(){
    for(int i=0;i<N;i++){
        spf[i]=i;
    }

    for(int i=2;i*i<N;i++){
        if(spf[i]==i){
            primes.pb(i);
        
            for(int j=i*i;j<N;j+=i){
                if(spf[j]==j)
                    spf[j]=i;
            }

        }
    }
}

// For Factorization of number
void primefact(int n){
    while(n>1){
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }
}

//To check if number is prime, Its spf should equal to number itself

/**
 * Related Sources:
 * Divisors Sieve: https://codeforces.com/blog/entry/22229#introducing-a-problem
*/
