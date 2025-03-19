# Subset Sum Problems

- Uses Knapsack idea of take / not take
- Every state associated with a target sum
- State: index and target sum

``` cadence
bool check(int i, int sum, vector<int>& arr, vector<vector<int>> &dp){
    if(sum==0) return true;
    if(sum<0 || i==arr.size()) return false;

    if(dp[i][sum]!=-1) return dp[i][sum]==0?false:true;

    bool ans;
    ans = check(i+1, sum-arr[i], arr, dp) || check(i+1, sum, arr, dp);

    dp[i][sum] = ans==true?1:0;

    return ans;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return check(0,k,arr,dp);

    // Iterative
    vector<bool> next(k+1, false);
    next[0] = true;

    for(int i=n-1;i>=0;i--){
        vector<bool> cur(k+1, false);
        cur[0] = true;
        for(int j=1;j<=k;j++){

            if(j-arr[i]>=0)
                cur[j] = next[j-arr[i]];
            
            cur[j] = cur[j] || next[j];
        }
        next = cur;
    }

    return next[k];

}
```


### Problems
https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954
https://leetcode.com/problems/partition-equal-subset-sum/description/
https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532
https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628


## Meet In Middle Concept
- If generating all subsets is too long for example if n=40, TC- 2^40
- We divide the n into two halves with 20 each and then generate all subsets between them then 
take left part and map with the right part and see if it generates given sum.

Refer: https://www.youtube.com/watch?v=45TkgKy0GS0
