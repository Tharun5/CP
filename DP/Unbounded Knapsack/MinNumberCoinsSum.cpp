/**
 * Description: Return the minimum number of coins that you need to make up that amount(sum).
                If that amount of money cannot be made up by any combination of the coins, return -1.
                
 * Source: https://www.youtube.com/watch?v=I-l6PBeERuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=16
           https://leetcode.com/problems/coin-change/
*/




int dp[2002][2002];

int MinCoinSum(int arr[],int n,int sum){
    for(int i=0;i<sum+1;i++)dp[0][i]=INT_MAX-1;  //Intialise with INT_MAX
    for(int i=1;i<n+1;i++)dp[i][0]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=min(1+dp[i][j-arr[i-1]], dp[i-1][j]);  // Take min & 1+ to count the coins if coin is taken
            }
            else dp[i][j]=dp[i-1][j];
        }
    }    

    return dp[n][sum];
}


void solve(){
    int n,sum;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>sum;

    int ans=MinCoinSum(arr,n,sum);
    if(ans>sum)
        cout<<-1<<endl;
    else cout<<ans<<endl;

}
