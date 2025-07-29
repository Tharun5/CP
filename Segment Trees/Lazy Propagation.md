# Lazy Propagation
Lazy propagation is an optimization technique used with segment trees to efficiently handle range updates. While a standard segment tree can perform point updates and range queries in O(log N) time, range updates without lazy propagation would require updating all affected nodes, leading to O(N) time complexity in the worst case for each range update.

**Lazy Array:**<br>
An additional array, often called a **"lazy array" or "lazy tree,"** is maintained alongside the segment tree. This array stores information about pending updates that have not yet been propagated down to the child nodes. Initially, all values in the lazy array are typically set to a "no-op" value (e.g., zero for sum updates).
<br>
Update Range Sum
``` cadence
void updateRange(int i, int l, int r, int start, int end, int val, vector<int> &lazy, vector<int> &segT){

        if(lazy[i]>0){
            segT[i] += (r-l+1)*lazy[i];
            if(l!=r){
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }

        // Out of Range
        if(r<start || l>end){
            return;
        }

        // Inside Range
        if(l>=start && r<=end){
            segT[i] = (r-l+1)*val;
            if(l!=r){
                lazy[2*i+1] += val;
                lazy[2*i+2] += val;
            }
            return;
        }

        // Part of Range
        int mid = (l+r)/2;
        updateRange(2*i+1, l, mid, start, end, val, lazy, segT);
        updateRange(2*i+2, mid+1, r, start, end, val, lazy, segT);
        segT[i] = segT[2*i+1] + segT[2*i+2];
    }

 int query(int i, int l, int r, int st, int end){
        if(r<st || end<l) return 0;

        // Update current node, if it has lazy value
        if(lazy[i]>0){
            segT[i] += (r-l+1)*lazy[i];
            if(l!=r){
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }

        if(l>=st && r<=end){
            return segT[i];
        }

        int mid = (l+r)/2;
        return query(2*i+1, l, mid, st, end) + query(2*i+2, mid+1, r, st, end);
    }

```
