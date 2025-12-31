# 🔗 SCC, Bridges & Articulation Points

---

## 📌 0. Big Picture

1. **Strongly Connected Components (SCC)** — directed graphs  
2. **Bridges (Cut Edges)** — undirected graphs  
3. **Articulation Points (Cut Vertices)** — undirected graphs  

All three rely on **DFS + discovery time (`dis`) + low-link values (`low`)**.

Once you understand one deeply, the others follow naturally.

---

## 🧠 1. Strongly Connected Components (SCC)

### Definition
In a **directed graph**, an SCC is a **maximal set of nodes** such that:
```
for every u, v in SCC:
    u → v AND v → u
```

### Key properties
- SCCs **partition** the graph
- SCCs never overlap
- Any directed cycle is fully contained inside one SCC
- Compressing SCCs gives a **DAG** (condensation graph)

> SCCs are to directed graphs  
> what connected components are to undirected graphs

---

## 2. SCC Algorithms

### 2.1 Kosaraju’s Algorithm (2 DFS)

**Idea**
1. DFS on original graph, push nodes by finish time
2. Reverse all edges
3. Pop nodes from stack, DFS on reversed graph
   - Each DFS gives one SCC

**Why it works**
- Finish order corresponds to topo order of SCC-DAG
- Reversing edges prevents DFS from escaping an SCC

**Time**
```
O(V + E)
```

**Code**
```cpp
vector<vector<int>> g, rev_g;
vector<bool> vis;
stack<int> stk;
vector<vector<int>> scc;

void dfs1(int u) {
    vis[u] = true;
    for(int v : g[u])
        if(!vis[v]) dfs1(v);
    stk.push(u);
}

void dfs2(int u, vector<int> &comp) {
    vis[u] = true;
    comp.push_back(u);
    for(int v : rev_g[u])
        if(!vis[v]) dfs2(v, comp);
}

void kosaraju(int n){
    // 1. DFS1 to get the order
    g.resize(n);
    vis.assign(n, false);

    for(int i=0;i<n;i++){
        if(!vis[i])
            dfs1(i);
    }

    // 2. Reverse the edges
    rev_g.resize(n);
    vis.assign(n, false);

    for(int i=0;i<n;i++){
        for(int v:g[i]){
            rev_g[v].push_back(i);
        }
    }

    // 3. DFS2 based on the order and print the SCC
    while(!stk.empty()){
        int u = stk.top();
        stk.pop();

        if(!vis[u]){
            vector<int> comp;
            dfs2(u, comp);
            scc.push_back(comp);
        }
    }
    
    // no of components
    cout<<scc.size();  
}
```

**When to use**
- Easy to explain
- Interview-friendly
- Clear logic

---

### 2.2 Tarjan’s SCC Algorithm (1 DFS)

**Core arrays**
- `dis[u]` → discovery time
- `low[u]` → earliest reachable ancestor
- `stack + inStack[]`

**Key rule**
```
if low[u] == dis[u]:
    u is root of an SCC
```

**Low-link updates**
- Tree edge: `low[u] = min(low[u], low[v])`
- Back edge: `low[u] = min(low[u], dis[v])`

**Why it works**
Low-link captures how far back the subtree can reach.
If it cannot go above `u`, then `u` is the SCC boundary.

**Time**
```
O(V + E)
```

**Code**
```cpp
vector<vector<int>> g;

vector<int> dis;
vector<int> low;
vector<bool> inStack;
stack<int> stk;
int timer;
vector<vector<int>> scc;

// Tarjan's Algo
void dfs(int u){
    dis[u] = low[u] = timer++;
    stk.push(u);
    inStack[u] = true;

    for(int v:g[u]){
        if(dis[v] == -1){
            // Tree edge
            dfs(v);
            low[u] = min(low[u], low[v]);
        }else if(inStack[v]){
            // Back edge to ancestor in current SCC
            low[u] = min(low[u], dis[v]);
        }
    }

    // If u is root of SCC
    if(dis[u] == low[u]){
        vector<int> comp;
        while(true){
            int cur = stk.top();
            stk.pop();
            inStack[cur] = false;
            comp.push_back(cur);
            if(cur == u) break;
        }
        scc.push_back(comp);  
    }
}

vector<vector<int>> tarjan(int n) {
    g.resize(n);
    dis.assign(n, -1);
    low.assign(n, -1);
    inStack.assign(n, false);
    timer = 0;

    for (int i = 0; i < n; i++) {
        if (dis[i] == -1) {
            dfs(i);
        }
    }
    return sccs;
}
```

**When to use**
- One DFS
- Competitive programming
- Extends naturally to bridges/AP

---

## 3. Bridges (Cut Edges)

### Definition
In an **undirected graph**, an edge `(u, v)` is a **bridge** if:
> removing `(u, v)` increases the number of connected components

Also called: **Cut Edge**

---

### Bridge condition (Tarjan)
For a DFS tree edge `u → v`:
```
(u, v) is a bridge  ⇔  low[v] > dis[u]
```

**Intuition**
- Subtree of `v` has no back-edge reaching `u` or above
- Edge `(u, v)` is the only connection

---

### DFS rules (undirected)
```cpp
vector<vector<int>> g;
vector<int> dis, low;
int timer;
vector<vector<int>> bridges;

void dfs(int u, int par){
    dis[u] = low[u] = timer++;

    for(int v:g[u]){
        if(v!=par){
            if(dis[v]==-1){
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if(low[v] > dis[u]){
                    bridges.push_back({u,v});
                }
            }else{
                low[u] = min(low[u], dis[v]);
            }
        }
    }
}

void findBridges(int n) {
    dis.assign(n, -1);
    low.assign(n, -1);
    vis.assign(n, false);
    timer = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(i, -1);
    }
}
```

**Time**
```
O(V + E)
```

---

## 4. Articulation Points (Cut Vertices)

### Definition
In an **undirected graph**, a node `u` is an articulation point if:
> removing `u` (and its edges) increases the number of connected components

Also called: **Cut Vertex**

---

### Articulation conditions

#### Non-root node `u`
For DFS child `v`:
```
low[v] >= dis[u]  ⇒  u is articulation point
```

#### Root node
```
children > 1  ⇒  root is articulation point
```

---

### DFS template (AP)
```cpp
vector<vector<int>> g;
vector<int> dis, low;
vector<bool> isArt;
int timer;
int cnt;
 
void dfs(int u, int par){
    dis[u] = low[u] = timer++;
    int chld = 0;

    for(int v:g[u]){
        if(v!=par){
            if(dis[v]==-1){
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                // articulation condition (non-root)
                if(par!=-1 && low[v] >= dis[u]){
                    isArt[u] = true;
                }
                chld++;
            }else{
                low[u] = min(low[u], dis[v]);
            }
        }
    }

    // root articulation condition
    if(par==-1 && chld > 1) 
        isArt[u] = true;
}
 
void findArticulationPoints(int n) {
    dis.assign(n, -1);
    low.assign(n, -1);
    vis.assign(n, false);
    isArt.assign(n, false);
    timer = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(i, -1);
    }
}
```

---

## 5. Key Comparisons (Lock-in Table)

| Concept | Condition |
|------|----------|
| Bridge (u,v) | `low[v] > dis[u]` |
| Articulation u (non-root) | `low[v] >= dis[u]` |
| SCC root u | `low[u] == dis[u]` |

Same DFS, same low-link — different meaning.

---

## 6. Directed vs Undirected

| Undirected | Directed |
|-----------|----------|
| Connected Component | Strongly Connected Component |
| Bridge (Cut Edge) | Strong Bridge (advanced) |
| Articulation Point | Strong Articulation Point (advanced) |

---

## 7. Functional Graph Insight (Bonus)

When **outdegree = 1** for every node:
- Graph = cycles + trees feeding into cycles
- SCC is overkill
- Use topo trimming + DP

---

## 8. Problem Mapping (Solved)

### SCC
- LC 2360 — Longest Cycle
- LC 802 — Eventual Safe States
- CF 427C — Checkposts
- LC 207 / 210 — Course Schedule
- LC 1462 — Course Schedule IV
- LC 2115 — Recipes
- LC 928 — Malware Spread II

### Bridges
- LC 1192 — Critical Connections

### Articulation Points
- SPOJ SUBMERGE
- LC 1568 — Min Days to Disconnect Island

---

