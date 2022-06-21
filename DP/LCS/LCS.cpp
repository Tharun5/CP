/**
 * Description: Longest Common Subsequence problem with Recursion and Memoisation and Tabulation(Top-Down)
 * Source: https://www.youtube.com/watch?v=4Urd0a0BNng&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=19
 * Problem: https://leetcode.com/problems/longest-common-subsequence/
*/


// Recursion

int lcs(string x, string y, int m, int n){
    if(m==0 || n==0){
        return 0;
    }

    if(x[m-1]==y[n-1]){
        return 1+lcs(x,y,m-1,n-1);
    }
    else{
        return max(lcs(x,y,m,n-1), lcs(x,y,m-1,n));
    }
}


//----------------------------------------------------------------------------------------------------------------------------------------------


// Recursion And Memoisation

int dp[1002][1002];
    
int lcs(string x, string y, int m, int n){
    if(m==0 || n==0){
        return 0;
    }
    if(dp[m][n]!=-1) 
        return dp[m][n];

    if(x[m-1]==y[n-1]){
        dp[m][n]=1+lcs(x,y,m-1,n-1);
    }
    else{
        dp[m][n]=max(lcs(x,y,m,n-1), lcs(x,y,m-1,n));
    }
    return dp[m][n];
}

int solve(string text1, string text2) {
    int m=text1.length();
    int n=text2.length();
    memset(dp,-1,sizeof(dp));
    return lcs(text1,text2,m,n);
}


//----------------------------------------------------------------------------------------------------------------------------------------------
  

// Tabulation (Top Down DP)

int dp[1002][1002];
    
int lcs(string x, string y, int m, int n){
    //Initialization
    for(int i=0;i<m+1;i++)
        for(int j=0;j<n+1;j++)
            if(i==0 || j==0)
                dp[i][j]=0;

    //Recursive to Iterative (m->i & n->j)
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    return dp[m][n];
}

int solve(string text1, string text2) {
    int m=text1.length();
    int n=text2.length();
    memset(dp,-1,sizeof(dp));
    return lcs(text1,text2,m,n);
}
