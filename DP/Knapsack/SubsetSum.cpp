/**
 * Description: Given an array and sum, determine if there is a subset of the given array elements with sum equal to given sum.
 * Source: https://www.youtube.com/watch?v=_gPcYovP7wc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=7
           https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
*/

// Recursive with memoisation
int dp[2002][2002];

int subsetsum(int arr[],int sum,int n){
    if(sum==0)
        return 1;//true
    if(n==0)
        return 0;//false
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    if(arr[n-1]<=sum){
        dp[n][sum]=(subsetsum(arr,sum-arr[n-1],n-1) || subsetsum(arr,sum,n-1));
    }
    else 
        dp[n][sum]=subsetsum(arr,sum,n-1);

    return dp[n][sum];
}

void solve(){
    int n,sum;cin>>sum>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    if(subsetsum(arr,sum,n))
        cout<<"Yes";
    else 
        cout<<"No";
}

//----------------------------------------------------------------------------------------------------------------------------------------------

//Tabluation Top-Down DP
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
    int n,sum;cin>>sum>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    if(subsetsum(arr,sum,n))
        cout<<"Yes";
    else 
        cout<<"No";
}
