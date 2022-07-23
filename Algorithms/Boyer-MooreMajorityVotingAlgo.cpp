/*
Problem: Given an integer array of size n, find the majority element that appeared more than ⌊ n/2 ⌋ times.
         Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Refer:(n/2) - https://leetcode.com/problems/majority-element/discuss/543431/Majority-vote-algorithm-EXPLAINED-(with-pictures)
      (n/3) - https://leetcode.com/problems/majority-element-ii/discuss/543672/BoyerMoore-majority-vote-algorithm-EXPLAINED
      
Problems: (n/2) - https://leetcode.com/problems/majority-element/
          (n/3) - https://leetcode.com/problems/majority-element-ii/
          
Time: O(n)
Space: O(1)
*/

// (n/2) majority
int majorityElement(vector<int>& nums) {
        int cnt=0;
        int ele;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==0){
                ele=nums[i];
            }
            if(nums[i]==ele)cnt++;
            else cnt--;
        }
        return ele;
    }


// (n/3) majority
vector<int> majorityElement(vector<int>& nums) {
        int c1=0;
        int c2=0;
        int e1=-1;
        int e2=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==e1) c1++;
            else if(nums[i]==e2) c2++;
            else if(c1==0){
                e1=nums[i];
                c1++;
            }else if(c2==0){
                e2=nums[i];
                c2++;
            }else{
                c1--;c2--;
            }
        }
        
        c1=c2=0;
        for(auto x:nums){
            if(x==e1)c1++;
            else if(x==e2)c2++;
        }
        
        vector<int> ans;
        if(c1> n/3)ans.push_back(e1);
        if(c2> n/3)ans.push_back(e2);
        
        return ans;
    }

