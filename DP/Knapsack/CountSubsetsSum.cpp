/**
 * Description: Given an array and sum, count no of subsets of the given array elements with sum equal to given sum.
 * Source: https://www.youtube.com/watch?v=F7wqWbqYn9g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=9 
           https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532
*/


// Variation of SubsetSum problem (change in return type)
int dp[2002][2002];

int cntsubsetsum(int arr[],int sum,int n){
    //Initialisation
    for(int i=0;i<sum+1;i++)
        dp[0][i]=0;
    for(int i=0;i<n+1;i++)
        dp[i][0]=1;

    //Choice Code
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=(dp[i-1][j-arr[i-1]] + dp[i-1][j]);
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
    cout<<cntsubsetsum(arr,sum,n);
}
