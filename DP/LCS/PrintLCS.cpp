/**
 * Description: Print Longest Common Substring problem with Tabulation(Top-Down)
 * Source: https://www.youtube.com/watch?v=x5hQvnUcjiM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=23
 * Problem: https://www.geeksforgeeks.org/printing-longest-common-subsequence/
*/


int dp[2002][2002];
    
int lcs(string x, string y, int m, int n){
    //Initialization
    for(int i=0;i<m+1;i++)
        for(int j=0;j<n+1;j++)
            if(i==0 || j==0)
                dp[i][j]=0;
    
    
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    
    return dp[m][n];
}

// Print LCS func. after LCS called
string printlcs(string x,string y,int m,int n){
    int i=m,j=n;
    string ans;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            ans.push_back(x[i-1]);
            i--;j--;
        }else{
            if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


void solve(){
    string s1,s2;
    cin>>s1>>s2;
    int m,n;
    m=s1.length();
    n=s2.length();
    lcs(s1,s2,m,n);
    cout<<printlcs(s1,s2,m,n);
}
