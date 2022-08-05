// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        //0 1 2 3 4 5 6 7 8
        int left,right;
        int ans;
        left=0;right=x;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(mid*mid > x){
                right=mid-1;
            }else{
                ans=mid;
                left=mid+1;
            }
        }
        return ans;       
    }
};
