/**
 * Problem: https://leetcode.com/problems/target-sum/
 * Source: https://www.youtube.com/watch?v=Hw6Ygp3JBYw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=12
*/

// Same as Count no of subsets with given difference

int dp[202][2002];
    
    int cntsubsetsum(vector<int> arr,int sum,int n){

        for(int i=0;i<sum+1;i++)
            dp[0][i]=0;
        
        dp[0][0]=1;  // Here we have 0's in input array so more than 1 subset may occur for sum=0 and n>1

        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=(dp[i-1][j-arr[i-1]] + dp[i-1][j]);
                }
                else 
                    dp[i][j]=dp[i-1][j];
            }
        }

        return dp[n][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if(abs(target)>sum) return 0;  //Edge Cases
        if((target+sum) % 2 != 0 ) return 0;  //Edge Cases
        return cntsubsetsum(nums,(target+sum)/2,n);
        
    }
