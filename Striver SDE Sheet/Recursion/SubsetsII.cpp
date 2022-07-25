//Refer :https://www.youtube.com/watch?v=Vn2v6ajA7U0

class Solution {
public:
    vector<vector<int>> ans;
    void subsetdup(vector<int> &nums,int pos,int n,vector<int> a){
        //Base
        if(pos==n){
            ans.push_back(a);
            return;
        }
        
        //Choice
        //Taken
        a.push_back(nums[pos]);
        subsetdup(nums,pos+1,n,a);
        
        a.pop_back();
        
        //Not taken
        while(pos+1 < n && nums[pos+1]==nums[pos]){
            pos++;
        }
        subsetdup(nums,pos+1,n,a);
        
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> a;
        subsetdup(nums,0,nums.size(),a);
        return ans;
    }
};
