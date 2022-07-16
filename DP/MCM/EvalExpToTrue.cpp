/**
 * Description: No of ways to parentheise to Evaluate Exp to True
 * Source: https://www.youtube.com/watch?v=pGVguAcWX4g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=38
*/


//Recursive
int eval(string s,int i,int j,bool isTrue){
    //Base 
    if(i>j)return 0;
    if(i==j){
        if(isTrue)
            return s[i]=='T';
        else
            return s[i]=='F'; 
    }

    //K loop to break
    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2){

        int lt = eval(s,i,k-1,true);
        int lf = eval(s,i,k-1,false);
        int rt = eval(s,k+1,j,true);
        int rf = eval(s,k+1,j,false);

        //and
        if(s[k]=='&')
        {
            if(isTrue)
                ans+=lt*rt;
            else 
                ans+=lt*rf+lf*rt+lf*rf;
        }else if(s[k]=='|'){
            if(isTrue)
                ans+=lt*rt+lt*rf+lf*rt;
            else
                ans+=lf*rf;
        }else if(s[k]=='^'){
            if(isTrue)
                ans+=lt*rf+lf*rt;
            else 
                ans+=lt*rt+lf*rf;
        }

    }
    return ans;
}

void solve(){
    int n;cin>>n;
    string s;
    cin>>s;    
    cout<<eval(s,0,n-1,true);
}


//----------------------------------------------------------------------------------------------------------------------------------------------


//Memoisation using map instead of 3d Matrix

map<string,int> dp;

int eval(string s,int i,int j,bool isTrue){
    //Base 
    if(i>j)return 0;
    if(i==j){
        if(isTrue)
            return s[i]=='T';
        else
            return s[i]=='F'; 
    }

    //dp
    string tmp=to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
    if(dp.count(tmp)){
        return dp[tmp];
    }

    //K loop to break
    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2){

        int lt = eval(s,i,k-1,true);
        int lf = eval(s,i,k-1,false);
        int rt = eval(s,k+1,j,true);
        int rf = eval(s,k+1,j,false);

        //and
        if(s[k]=='&')
        {
            if(isTrue)
                ans+=lt*rt;
            else 
                ans+=lt*rf+lf*rt+lf*rf;
        }else if(s[k]=='|'){
            if(isTrue)
                ans+=lt*rt+lt*rf+lf*rt;
            else
                ans+=lf*rf;
        }else if(s[k]=='^'){
            if(isTrue)
                ans+=lt*rf+lf*rt;
            else 
                ans+=lt*rt+lf*rf;
        }

    }
    dp[tmp]=ans;
    return ans;
}

void solve(){
    int n;cin>>n;
    string s;
    cin>>s;
    cout<<eval(s,0,n-1,true);
}
