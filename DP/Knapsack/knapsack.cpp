/**
 * Description: Knapsack problem with Recursion and Memoisation and Tabulation(Top-Down)
 * Source: https://www.youtube.com/watch?v=fJbIuhs24zQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=5
           https://www.youtube.com/watch?v=ntCGbPMeqgg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=5
 * Problem: https://www.spoj.com/problems/KNAPSACK/
 * Time: O(W*n)
*/


// Recursion And Memoisation
int dp[2002][2002];

int knapsack(int wt[],int val[],int W,int n){
    //Base Cond
    if(n==0 || W==0)
        return 0;

    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    //Choice Code
    if(wt[n-1]<=W){
        int taken = val[n-1]+knapsack(wt,val,W-wt[n-1],n-1);
        int nottaken = knapsack(wt,val,W,n-1);
        dp[n][W] = max(taken,nottaken);
    }
    else{
        int nottaken = knapsack(wt,val,W,n-1);
        dp[n][W] = nottaken;
    }
    
    return dp[n][W];
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

//----------------------------------------------------------------------------------------------------------------------------------------------

// Tabulation (Top Down DP)

int dp[2002][2002];

int knapsack(int wt[],int val[],int W,int n){
    //Initialisation
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }
    //Recursive to Iterative
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else 
                dp[i][j]=dp[i-1][j];
        }
    }
    
    return dp[n][W];
}

void solve(){
    int n,W;cin>>W>>n;
    int wt[n],val[n];
    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    cout<<knapsack(wt,val,W,n);
}
