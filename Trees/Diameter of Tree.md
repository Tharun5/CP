# Diameter of Tree

The diameter of a tree is the maximum distance between two nodes.

Proof Link & Tutorial: https://codeforces.com/blog/entry/101271 <br>
Problem: https://cses.fi/problemset/task/1131/

---

### Idea
- Do DFS from any node, the node which is farthest is one end of the diameter.
- Then Perform DFS from that node to get the another end of diameter which is the farthest.

### Code (C++)
```cpp

vector<vector<int>> g;
vector<int> dis;

void dfs(int cur, int par, int d){
    dis[cur] = d;
    for(int ch:g[cur]){
        if(ch != par){
            dfs(ch, cur, d+1);
        }
    }
}

void solve(){
    int n; cin>>n;
    g.resize(n+1);
    dis.resize(n+1);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0);

    int maxi1 = 1; // One end of diameter
    for(int i=1;i<=n;i++){
        if(dis[i] > dis[maxi1]) maxi1 = i;
    }
    dfs(maxi1, 0, 0);

    int maxi2 = 1;
    for(int i=1;i<=n;i++){
        if(dis[i] > dis[maxi2]) maxi2 = i;
    }

    cout<<dis[maxi2];
}
```



### Center of Tree
- Center is the node which is mid of diameter.
- If the diameter len is odd, then there is 1 center else we have 2.
- From Center we can get the no of diameters exist in tree, by two cases based on 1 or 2 centers, calculating left&right side nodes.
