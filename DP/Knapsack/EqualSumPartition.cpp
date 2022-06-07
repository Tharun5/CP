/**
 * Description: Given an array, determine if there is a partion of the given array elements with equal sum.
 * Source: https://www.youtube.com/watch?v=UmMh7xp07kY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=8
*/

int dp[202][20002];

int eqsumpar(vector<int> &arr, int n, int sum){
    if(sum==0){
        return 1;
    }
    if(n==0) return 0;

    if(dp[n][sum]!=-1)return dp[n][sum];

    bool notak=eqsumpar(arr,n-1,sum);

    bool tak=false;
    if(sum-arr[n-1] >= 0)
    tak=eqsumpar(arr,n-1,sum-arr[n-1]);

    dp[n][sum]= tak || notak;

    return dp[n][sum];

}

void solve(){
    int n,sum=0;cin>>n;
    int arr[n];
    vector<int> tmp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    memset(dp,-1,sizeof(dp));
    if(sum%2!=0) cout<<"No"<<endl;
    else{
        if(eqsumpar(arr,n,sum/2)){
            cout<<"Yes"<<endl;
        }else cout<<"No"<<endl;
    }    
}


//Method 2 Using SubsetSum Code
void solve(){
    int n,sum=0;cin>>n;
    int arr[n];
    vector<int> tmp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum%2!=0) cout<<"No"<<endl;
    else{
        if(subsetsum(arr,sum/2,n)){
            cout<<"Yes"<<endl;
        }else cout<<"No"<<endl;
    }    
}

