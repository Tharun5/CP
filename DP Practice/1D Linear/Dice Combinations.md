## Dice Combinations
### Problem: https://cses.fi/problemset/task/1633/

``` cadence
#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;

int ways(int n, vector<int> &dp){
    if(n < 0) return 0;
    if(n == 0) return 1;

    if(dp[n]!=-1) return dp[n];

    int ans = 0;
    for(int i=1;i<=6;i++){
        ans = (ans + ways(n-i, dp)) % MOD;
    }
    return dp[n] = ans%MOD;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    int n;
    cin>>n;

    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++)
            if(i-j>=0) dp[i] = (dp[i] + dp[i-j]) % MOD;
    }

    cout<<dp[n]%MOD;
    
}

```
