# Find Subarray with max Product

Problem - https://leetcode.com/problems/maximum-product-subarray/description/

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
