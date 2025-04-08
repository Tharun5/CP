# Longest Increasing Subsequence

``` cadence
    int LIS(int i, int last, vector<int>& nums, vector<vector<int>> &dp){
        if(i==nums.size()){
            return 0;
        }

        if(dp[i][last+1]!=-1) return dp[i][last+1];

        int ans = 0;

        if(last==-1 || nums[last]<nums[i]){
            ans = LIS(i+1, i, nums, dp) + 1;
        }

        ans = max(ans, LIS(i+1, last, nums, dp));
        return dp[i][last+1] = ans;
    }


    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return LIS(0, -1, nums, dp);

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=n-1;i>=0;i--){
            for(int j=-1;j<i;j++){
                if(j==-1 || nums[j]<nums[i]){
                    dp[i][j+1] = dp[i+1][i+1] + 1;
                }
                dp[i][j+1] = max(dp[i][j+1], dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
```

### Another variation:
**State:** dp[i] -> LIS ending at index i

``` cadence
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        int ans = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
```


### Printing LIS
``` cadence
vector<int> printLIS(vector<int> nums, int n) {
	vector<int> dp(n, 1);
	vector<int> prev(n,-1);

	int len = 1;
	int idx;

	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(nums[i]>nums[j]){
				if(1+dp[j] > dp[i]){
					dp[i] = 1+dp[j];
					prev[i]=j;
				}
			}
		}
		if(len<dp[i]){
			len = dp[i];
			idx = i;
		}
	}

	vector<int> ans;
	while(prev[idx]!=-1){
		ans.push_back(nums[idx]);
		idx = prev[idx];
	}

	ans.push_back(nums[idx]);
	reverse(ans.begin(),ans.end());

	return ans;
}
```
