# Segment Trees

A segment tree is a tree-based data structure used to efficiently perform range queries and updates on an array. Each node in the segment tree represents an interval or segment of the original array.

**Variations:**<br>
Segement tree can be used for various operations like sum, max, min, xor... which follows associative property.<br>
(A+B)+C = A+(B+C)

## Range Sum Queries
Problem link: https://www.geeksforgeeks.org/problems/sum-of-query-ii5310/0 

<br>

``` cadence
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


## Point Update value at given index
Problem link: https://leetcode.com/problems/range-sum-query-mutable/description/

``` cadence
  void updateSegT(int i, int l, int r, int index, int val){
        if(l==index && r==index){
            segT[i] = val;
            return;
        }

        // Out of current range
        if(index<l || index >r) return;

        int mid = (l+r)/2;
        updateSegT(2*i+1, l, mid, index, val);
        updateSegT(2*i+2, mid+1, r, index, val);
        segT[i] = segT[2*i+1] + segT[2*i+2];
    }

```

