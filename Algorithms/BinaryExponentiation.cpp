// Problem: https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        long long nn=abs(n);
        double ans=1.0;
        while(nn){
            if(nn&1){
                ans*=x;
                nn-=1;
            }else{
                x=x*x;
                nn/=2;
            }
        }
        
        if(n<0)ans=1.0/ans;
        return ans;
    }
};
