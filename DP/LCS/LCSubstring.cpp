/**
 * Description: Longest Common Substring problem with Tabulation(Top-Down)
 * Source: https://www.youtube.com/watch?v=HrybPYpOvz0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=22
 * Problem: https://www.geeksforgeeks.org/longest-common-substring-dp-29/
*/

int rec(int i, int j, string &s1, string &s2, int m, int n, int &ans, vector<vector<int>> &dp){
    if(i==m || j==n) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int cur = 0;

    if(s1[i]==s2[j]){
        cur = 1+rec(i+1, j+1,s1,s2,m,n,ans,dp);
    }

    // If not equal continous chain will be broken and length will be 0 again from that point

    ans = max(ans, cur);

    rec(i,j+1,s1,s2,m,n,ans,dp);
    rec(i+1,j,s1,s2,m,n,ans,dp);
    
    return dp[i][j]=cur;
}



int lcs(string &s1, string &s2){
    
    int m = s1.length();
    int n = s2.length();

    int ans = 0;

    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // rec(0,0,s1,s2,m,n,ans,dp);

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(s1[i]==s2[j]){
                dp[i][j] = 1+dp[i+1][j+1];
                ans = max(ans, dp[i][j]);
            }
        }
    }

    return ans;

}
