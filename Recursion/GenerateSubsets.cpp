//Problem: https://leetcode.com/problems/subsets

class Solution {
public:
    void solve(int i, vector<int> &nums, vector<int> &cur, vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(cur);
            return;
        }

        //Take
        cur.push_back(nums[i]);
        solve(i+1, nums, cur, ans);
        cur.pop_back();

        //Not take
        solve(i+1, nums, cur, ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        solve(0, nums, cur, ans);
        return ans;
    }
};
