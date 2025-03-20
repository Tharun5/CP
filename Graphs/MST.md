# Minimum Spanning Tree

## Prims Algo:
``` cadence
  int spanningTree(int V, vector<vector<int>> adj[]) {      
        int ans = 0;
        
        vector<bool> inMST(V, false); // Like vis
        vector<int> parent(V, -1);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({0,0,-1});
        
        while(!pq.empty()){
            vector<int> ele = pq.top();
            int cost = ele[0];
            int node = ele[1];
            int par = ele[2];
            pq.pop();

            if(inMST[node]) continue;
            
            inMST[node] = true; 
            parent[node] = par;
            ans += cost;
            
            for(auto edg:adj[node]){
                if(!inMST[edg[0]]){
                    pq.push({edg[1], edg[0], node});
                }
            }
        }
        
        for(int i=0;i<V;i++)
            cout<<i<<" "<<parent[i]<<endl;
        
        return ans;
    }
```
