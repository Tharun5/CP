# Finding a Centroid

Given a tree of n nodes, your task is to find a centroid, i.e., 
a node such that when it is appointed the root of the tree, 
each subtree has at most \lfloor n/2 \rfloor nodes.

Problem: https://cses.fi/problemset/task/2079/

---

### Idea
- Check each node subT size

### Code (C++)
```cpp
int n;
vector<vector<int>> g;
vector<int> subT;
int centroid;

void dfs(int cur, int par){
    subT[cur] = 1;
    for(int ch:g[cur]){
        if(ch != par){
            dfs(ch, cur);
            subT[cur] += subT[ch];
        }
    }

    bool check = true;
    for(int ch:g[cur]){
        if(ch != par)
            if(2*subT[ch] > n) check = false;
    }

    if(2*(n-subT[cur]) > n) check = false;

    if(check) centroid = cur;
}

void solve(){
    cin>>n;
    g.resize(n+1);
    subT.resize(n+1);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    cout<<centroid;
}

```
