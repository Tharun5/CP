/**
 * Description: Check whether b is scrambled string of a
 * Source: https://www.youtube.com/watch?v=SqA0o-DGmEw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=40
 * Problem: https://leetcode.com/problems/scramble-string
*/


//Memoised
unordered_map<string,bool> mp;
    bool isScramble(string a, string b) {
        int n=a.length();
        //base
        if(a==b) return true;
        if(n<=1)
            return false;
        string tmp=a+" "+b;
        if(mp.count(tmp)){
            return mp[tmp];
        }

        bool ans=false;
        for(int k=1;k<=n-1;k++){
            //swap -> gr eat | eat gr
            bool tmp1 = isScramble(a.substr(0,k),b.substr(n-k,k)) && isScramble(a.substr(k,n-k),b.substr(0,n-k));
            //no swap -> gr eat | gr eat
            bool tmp2 = isScramble(a.substr(0,k),b.substr(0,k)) && isScramble(a.substr(k,n-k),b.substr(k,n-k));
            ans = tmp1 || tmp2;
            if(ans) break;
        }
        mp[tmp]=ans;
        return ans;
    }
