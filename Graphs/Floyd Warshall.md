# 🌉 Floyd–Warshall Algorithm

The **Floyd–Warshall algorithm** is an **All-Pairs Shortest Path (APSP)** algorithm that computes the shortest distance between **every pair of vertices** in a weighted graph.

It works for:
- Directed + Undirected graphs  
- Graphs with **negative weights**  
- Detecting **negative cycles**  

But it does **NOT** work if the graph has negative cycles (distances keep decreasing).

---

# ✅ When to Use Floyd–Warshall

Use it when:
- You need shortest paths **between all pairs of nodes**  
- Graph size is small (`N ≤ 300–400`)  
- The graph may contain negative weights  
- You need to compute:  
  - Shortest distance matrix  
  - Path reconstruction  
  - Transitive closure  
  - Detect negative cycles  

---

# 🧠 Core Idea

Floyd–Warshall is a **Dynamic Programming** algorithm.

We maintain a matrix `dist[N][N]` where:

`dist[i][j] = shortest distance from i to j`

Initially:

- If there is an edge `i → j` with weight `w`: `dist[i][j] = w`  
- `dist[i][i] = 0`  
- Otherwise: `dist[i][j] = INF`  

Then we iteratively try to improve paths using intermediate nodes:

```
for k = 0 to n-1:
    for i = 0 to n-1:
        for j = 0 to n-1:
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
```

Meaning:

> Can we go from `i` → `k` → `j` better than our current best path?

---

# ❗ Detecting Negative Cycles

After the DP:

```
If dist[i][i] < 0 for any i → negative cycle exists
```

Because a path from a node back to itself became negative.

---

# 🧾 C++ Implementation

```cpp
vector<vector<int>> floyd_warshall(int n, vector<vector<int>>& edges) {
    const int INF = 1e9;

    // Step 1: Initialize distance matrix
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int wt = e[2];
        dist[u][v] = wt;   // directed edge
    }

    // Step 2: Floyd–Warshall DP
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Step 3: Detect negative cycle
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            return { { -1 } };  // negative cycle exists
        }
    }

    return dist;
}
```

### Print i->j Shortest Path
If you want to trace the shortest path for every i->j, Use parent 2d array to save the last node we came from.
i ... x ... y ... ... [node] -> j

This last node before j, we came from helps us to track the path.
Lets save this for every i->j.

```cpp

int par[101][101];

for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    par[i][j] = i;
  }
}

 // Step 2: Floyd–Warshall DP
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    par[i][j] = par[k][j];
                }
                    
            }
        }
    }

void printPath(i, j){
    if(i!=j) printPath(i, par[i][j]);
    cout<<j<<" ";
}

```
---

# ⏱️ Time & Space Complexity

| Aspect | Complexity |
|-------|------------|
| **Time** | `O(N³)` |
| **Space** | `O(N²)` |

---

# ✨ Applications

### ✔ All-Pairs Shortest Path  
Compute shortest paths between **every** pair.

### ✔ Negative Cycle Detection  
Check if `dist[i][i] < 0`.

### ✔ Transitive Closure  
Useful for reachability.

### ✔ Path Reconstruction  
Using a `next[][]` matrix.

### ✔ DP on Graphs  
Works well for dense graphs.

---
