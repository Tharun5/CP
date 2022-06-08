/**
 * Description: Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ 
                and the difference between ‘S1’ and ‘S2’ is equal to ‘D’.
 * Source: https://www.youtube.com/watch?v=ot_XBHyqpFc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=11
*/

int dp[2002][2002];

/*
s1-s2=diff  
s1+s2=sum
2s1-sum=diff
s1=(diff+sum)/2
cnt subsets with sum as s1
*/

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
    int n,dif;cin>>n>>dif;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=abs(arr[i]);
    }

    memset(dp,-1,sizeof(dp));
    cout<<cntsubsetsum(arr,(dif+sum)/2,n);
}
