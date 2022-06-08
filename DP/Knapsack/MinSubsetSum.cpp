/**
 * Description: Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
 * Source: https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=11
*/

bool dp[2002][2002];

bool subsetsum(int arr[],int sum,int n){
    //Initialisation
    for(int i=0;i<sum+1;i++)
        dp[0][i]=false;
    for(int i=0;i<n+1;i++)
        dp[i][0]=true;

    //Choice Code
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else 
                dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][sum];
}

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=abs(arr[i]);
    }

    memset(dp,-1,sizeof(dp));
    subsetsum(arr,sum,n);

    int ans=INT_MAX;

    for(int i=sum/2;i>=0;i--){
        if(dp[n][i]){
            ans=sum-2*i;
            break;
        }
    }
    cout<<ans;
}
