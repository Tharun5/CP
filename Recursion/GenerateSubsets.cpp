//Problem: https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> ans;

    void subset(vector<int> &arr,int pos,int n,vector<int> a){
        if(pos==n){
            ans.push_back(a);
            return;
        }
        
        subset(arr,pos+1,n,a);
        a.push_back(arr[pos]);
        subset(arr,pos+1,n,a);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;
        subset(nums,0,nums.size(),a);
        return ans;
    }
};
