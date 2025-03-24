# Longest Common Subsequence
- Problem: https://leetcode.com/problems/longest-common-subsequence/


``` cadence
Here state lcs(i,j) defines - length of lcs from (i,j) to (m,n)

// Recursion + Memo
    int lcs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i==s1.length() || j==s2.length()){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0;

        if(s1[i]==s2[j]){
            ans = 1+lcs(i+1,j+1,s1,s2, dp);
        }else{
            ans = max(lcs(i+1,j,s1,s2, dp), lcs(i,j+1,s1,s2, dp));
        }

        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return lcs(0,0,s1,s2,dp);


        //Iterative
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];

        // Space Optimised
        vector<int> next(n+1, 0);

        for(int i=m-1;i>=0;i--){
            vector<int> cur(n+1, 0);

            for(int j=n-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    cur[j] = 1 + next[j+1];
                }else{
                    cur[j] = max(next[j], cur[j+1]);
                }
            }
            next = cur;
        }

        return next[0];
    }
```
