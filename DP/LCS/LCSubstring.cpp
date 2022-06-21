/**
 * Description: Longest Common Substring problem with Tabulation(Top-Down)
 * Source: https://www.youtube.com/watch?v=HrybPYpOvz0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=22
 * Problem: https://www.geeksforgeeks.org/longest-common-substring-dp-29/
*/

int dp[2002][2002];
    
int LCSubstring(string x, string y, int m, int n){
    //Initialization
    for(int i=0;i<m+1;i++)
        for(int j=0;j<n+1;j++)
            if(i==0 || j==0)
                dp[i][j]=0;
    
    int ans=0;
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else{
                dp[i][j]=0;      // If not equal continous chain will be broken and length will be 0 again from that point
            }
        }
    }
    return ans;     // Here final answer will not be in dp[m][n] it will be max of all lengths in matrix
}


void solve(){
    string s1,s2;
    cin>>s1>>s2;
    int m,n;
    m=s1.length();
    n=s2.length();
    int ans=LCSubstring(s1,s2,m,n);
    cout<<ans<<endl;
}
