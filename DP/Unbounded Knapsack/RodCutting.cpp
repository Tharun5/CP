/**
 * Description: Given a rod of length n and a list of rod prices of length i, where 1 <= i <= n,
                find the optimal way to cut the rod into smaller rods to maximize profit.
 * Source: https://www.youtube.com/watch?v=SZqAQLjDsag&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=14
           https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
           https://www.techiedelight.com/rod-cutting/
*/

// In Unbounded Knapsack If item is taken, It can be taken again (We mhave multiple instances)

int dp[2002][2002];

int rodcut(int len[],int prices[],int n,int N){
    for(int i=0;i<n+1;i++)dp[i][0]=0;
    for(int i=0;i<N+1;i++)dp[0][i]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<N+1;j++){
            if(len[i-1]<=j){
                // Change from 0-1 knapscak is for taken case: dp[i-1][] to dp[i][] as we consider i item again in unbounded knapsack
                dp[i][j]=max(dp[i][j-len[i-1]]+prices[i-1], dp[i-1][j]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }    

    return dp[n][N];
}


void solve(){
    //n->array length
    //N->Requried rod length to cut to get max price
    int n,N;cin>>n;
    int len[n],prices[n];
    for(int i=0;i<n;i++){
        cin>>len[i];
    }
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    cin>>N;

    cout<<rodcut(len,prices,n,N);

}
