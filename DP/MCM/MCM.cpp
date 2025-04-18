/**
 * Description: Matrix Chain Multiplication with Recursion and Memoisation
                Given a sequence of matrices, find the most efficient way to multiply these matrices together.
                The problem is not actually to  perform the multiplications, but merely to decide in which order to perform the multiplications.
 * Source: https://www.youtube.com/watch?v=kMK148J9qEE&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=33
 * Problem: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
*/



// Recursion

int MCM(int i, int j, vector<int>& arr, vector<vector<int>> &dp){
    if(i==j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = INT_MAX;

    for(int k=i;k<j;k++){
        ans = min(ans, MCM(i,k,arr, dp) + MCM(k+1,j,arr, dp) + arr[i-1]*arr[k]*arr[j]);
    }

    return dp[i][j] = ans;
}


int matrixMultiplication(vector<int> &arr, int N)
{   
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return MCM(1, N-1, arr, dp);
}



// Iteration

int matrixMultiplication(vector<int> &arr, int N)
{   
    vector<vector<int>> dp(N, vector<int>(N));

    for(int i=1;i<N;i++){
        dp[i][i] = 0;
    }

    for(int i=N-1;i>=1;i--){
        for(int j=i+1;j<N;j++){
            
            int ans = INT_MAX;
            for(int k=i;k<j;k++){
                ans = min(ans, dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
            }

            dp[i][j] = ans;
        }
    }

    return dp[1][N-1];
}


//----------------------------------------------------------------------------------------------------------------------------------------------


// Recursion And Memoisation

int dp[1001][1001];

int MCM(int arr[],int i,int j){
    //Base Cond.
    if(i>=j)
        return 0;

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans=INT_MAX;
    //k range, which divides the array
    for(int k=i;k<=j-1;k++){
        int tmpans=MCM(arr,i,k)+MCM(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        ans=min(ans,tmpans);
    }
    
    dp[i][j]=ans;
    return dp[i][j];
}


void solve(){
    int n;
    cin>>n;
    int arr[n];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<MCM(arr,1,n-1);
}
