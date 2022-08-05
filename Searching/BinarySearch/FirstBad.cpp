// Problem: https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //0 0 0 0 1 1 1 1 1
        //        ^
        int ans;
        int left,right;
        left=1,right=n;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isBadVersion(mid)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};
