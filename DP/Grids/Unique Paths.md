# Find Unique Paths in grid

- Problem: https://leetcode.com/problems/unique-paths/description/

``` cadence
class Solution {
public:

    int paths(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans;
        ans = paths(i,j+1,m,n, dp) + paths(i+1,j,m,n, dp);

        return dp[i][j] = ans;
    }


    int uniquePaths(int m, int n) {

        // 1. Using Recursion + Memo
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return paths(0,0,m,n, dp);


        // 2. Using Iteration with Space m*n
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[m-1][n-1]=1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;

                dp[i][j] = dp[i][j+1]+dp[i+1][j];
            }
        }

        return dp[0][0];


        // 3. Space Optimization
        vector<int> next(n+1, 0);

        for(int i=m-1;i>=0;i--){
            vector<int> cur(n+1, 0);
            for(int j=n-1;j>=0;j--){
                
                if(i==m-1 && j==n-1){ 
                    cur[j]=1;
                    continue;
                }

                cur[j] = cur[j+1] + next[j];
            }
            next = cur;
        }

        return next[0];
    }
};

```
