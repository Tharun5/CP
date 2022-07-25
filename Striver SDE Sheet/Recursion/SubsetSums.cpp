
void subset(vector<int> &arr,int pos,int sum,int n,vector<int> &ans){
    if(pos==n){
        ans.push_back(sum);
        return;
    }
    //take
    subset(arr,pos+1,sum+arr[pos],n,ans);
    //not
    subset(arr,pos+1,sum,n,ans);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    subset(num,0,0,num.size(),ans);
    sort(ans.begin(),ans.end());
    return ans;
}
