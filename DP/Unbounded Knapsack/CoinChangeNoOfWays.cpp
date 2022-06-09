/**
 * Description: Given an array coins representing coins of different denominations and an integer amount representing a total amount of money.
                Return the number of combinations that make up that amount.
                If that amount of money cannot be made up by any combination of the coins, return 0.
                
 * Source: https://www.youtube.com/watch?v=I4UR2T6Ro3w&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=15
           https://leetcode.com/problems/coin-change-2/
*/

// Similar to Cnt no of Subset sum but this is Unbounded Knapsack variant

int dp[302][5002];

    int CntCoinChange(vector<int> &arr,int n,int sum){
        for(int i=0;i<sum+1;i++)dp[0][i]=0;
        for(int i=0;i<n+1;i++)dp[i][0]=1;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i][j-arr[i-1]] + dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }    

        return dp[n][sum];
    }
