## Range Sum Queries
Problem link: https://www.geeksforgeeks.org/problems/sum-of-query-ii5310/0 



```
class Solution {
  public:
  
    void buildSegTree(int i, int l, int r, vector<int> &segTree, int arr[]){
         // Base
        if(l==r){
            segTree[i] = arr[l];
            return;
        }
      
        int mid = (l+r)/2;
            
        buildSegTree(2*i+1, l, mid, segTree, arr);
        buildSegTree(2*i+2, mid+1, r, segTree, arr);
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
  
    int query(int i, int l, int r, int ql, int qr, vector<int> &segTree){
        // Out of range
        if(r<ql || l>qr)
            return 0;

        // In Between
        if(l>=ql && r<=qr)
            return segTree[i];
        
        int mid = (l+r)/2;
        
        return query(2*i+1, l, mid, ql, qr, segTree) + query(2*i+2, mid+1, r, ql, qr, segTree);
        
    }
  
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        vector<int> segTree(4*n);
        vector<int> ans;
        
        buildSegTree(0, 0, n-1, segTree, arr);
        
        for(int i=0;i<2*q;i+=2){
            int val = query(0, 0, n-1, queries[i]-1, queries[i+1]-1, segTree);
            ans.push_back(val);
        }
        
        return ans;
        
    }
};

```
