/**
 * Description: Knapsack problem with recursion and memoisation
 * Source: https://www.youtube.com/watch?v=fJbIuhs24zQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=5
 * Problem: https://www.spoj.com/problems/KNAPSACK/
 * Time: O(W*n)
*/

int dp[2002][2002];

int knapsack(int wt[],int val[],int W,int n){
    if(n==0 || W==0)
        return 0;
    if(dp[W][n]!=-1){
        return dp[W][n];
    }
    if(wt[n-1]<=W){
        int taken = val[n-1]+knapsack(wt,val,W-wt[n-1],n-1);
        int nottaken = knapsack(wt,val,W,n-1);
        dp[W][n] = max(taken,nottaken);
    }
    else{
        int nottaken = knapsack(wt,val,W,n-1);
        dp[W][n] = nottaken;
    }
    return dp[W][n];
}

void solve(){
    int n,W;cin>>W>>n;
    int wt[n],val[n];
    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(wt,val,W,n);
}
