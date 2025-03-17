# Find Subarray with max Product

Problem - https://leetcode.com/problems/maximum-product-subarray/description/

Idea:
- Consider a subproblem of index i, need to find ans for subarray starts with i
- Here we can directly depend on max product of i+1 and multiply with a[i] 
- Bcoz if a[i] is -ve then max Product can go -ve, in this case with need to multiply with -ve product so far
- Thus it depends on -ve and +ve value of a[i], we need to maintain both min and max products so far.

``` cadence
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        vector<int> dpmax(n+1);
        vector<int> dpmin(n+1);
        dpmax[n-1] = nums[n-1]; 
        dpmin[n-1] = nums[n-1]; 

        for(int i=n-2;i>=0;i--){
            if(nums[i]>=0){
                dpmax[i] = max(nums[i], nums[i]*dpmax[i+1]);
                dpmin[i] = min(nums[i], nums[i]*dpmin[i+1]);
            }else{
                dpmax[i] = max(nums[i], nums[i]*dpmin[i+1]);
                dpmin[i] = min(nums[i], nums[i]*dpmax[i+1]);
            }
        }

        int ans = -1e9;
        for(int i=0;i<n;i++) ans = max(ans, dpmax[i]);

        return ans;
    }
};
```
