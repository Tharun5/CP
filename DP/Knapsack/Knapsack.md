# Knapsack Idea

 * Description: Knapsack problem with Recursion and Memoisation and Tabulation(Top-Down)
 * Source: https://www.youtube.com/watch?v=fJbIuhs24zQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=5
           https://www.youtube.com/watch?v=ntCGbPMeqgg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=5
 * Problem: https://www.spoj.com/problems/KNAPSACK/
 * Time: O(W*n)

``` cadence
    int maxValues(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>> &dp){
        if(i==wt.size() || W==0){
            return 0;
        }
        
        if(dp[i][W]!=-1) return dp[i][W];
        
        int ans=0;
        
        //Take
        if(W-wt[i]>=0)
            ans = max(ans, maxValues(i+1, W-wt[i], wt, val, dp) + val[i]);
        
        //Not take
        ans = max(ans, maxValues(i+1, W, wt, val, dp));
        
        return dp[i][W] = ans;
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        // vector<vector<int>> dp(n, vector<int>(W+1, -1));
        // return maxValues(0, W, wt, val, dp);
        
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=W;j++){
                if(j-wt[i]>=0){
                    dp[i][j] = dp[i+1][j-wt[i]]+val[i];
                }
                dp[i][j] = max(dp[i][j], dp[i+1][j]);
            }
        }

        return dp[0][W];
        
    }

```

- Further you can space optimize to next and cur arrays
- Upon further you only depend on the next and that too only left values when I am at i
- So we can also store the cur in same next array to reduce further to single array optimise.
