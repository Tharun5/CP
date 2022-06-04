/**
 * Description: Kadanes Algorithm to find max subarray sum
 * Source: https://www.youtube.com/watch?v=umt7t1_X8Rc
 * Time: O(n)
*/
int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int a=0,res=INT_MIN;
        for(int i=0;i<n;i++){
            a+=nums[i];
            res=max(res,a);
            a=max(0,a);
        }
        return res;
    }
