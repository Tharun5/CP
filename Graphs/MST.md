
# 🌲 Minimum Spanning Tree (MST)
*Prim’s + Kruskal’s algorithms explained clearly with templates and intuition*

---

# 📘 **1. What is an MST?**

A **Minimum Spanning Tree (MST)** of a connected, undirected, weighted graph:

- Connects **all V nodes**
- Has **exactly V − 1 edges**
- Has **no cycles**
- Has **minimum possible total weight**

Every MST question boils down to:  
> How to select edges that keep graph connected without forming cycles while minimizing total cost?

Two classical greedy algorithms solve MST:

- **Kruskal** → Edge-based, sorts edges  
- **Prim** → Node-based, grows tree outward

Both must be understood for interviews.

---

# 🌟 **2. Kruskal’s Algorithm (DSU-Based MST)**  
### ✔ Best for:  
- Edge list input  
- DSU lovers  
- Graphs where edges need filtering or processing in special order  
- Sparse or heavy edge-based problems  

### ✔ Idea:
1. Sort edges by weight  
2. Add smallest edge that **does not create a cycle**  
3. Use DSU to check if adding edge makes a cycle  
4. Stop when MST has **V−1 edges**

This is extremely clean with DSU.

---

# 🔧 **2.1 Kruskal’s Template (with DSU + MST edges)**

```cpp
struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a); 
        b = find(b);
        if(a == b) return false;
        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

struct Edge {
    int u, v, w;
};

pair<long long, vector<Edge>> kruskalMST(int n, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), 
         [](const Edge &a, const Edge &b) {
             return a.w < b.w;
         });

    DSU dsu(n);
    long long total = 0;
    vector<Edge> mstEdges;

    for(auto &e : edges){
        if(dsu.unite(e.u, e.v)){
            total += e.w;
            mstEdges.push_back(e);
            if((int)mstEdges.size() == n - 1) break;
        }
    }

    return {total, mstEdges};
}
```

### ✔ What this gives you:
- `total` → cost of MST  
- `mstEdges` → the actual tree (paths can be reconstructed)

---

# 🧠 **2.2 Kruskal’s Correctness (Interview-Safe Explanation)**

The **cut property** ensures:

> For any partition of the graph, the minimum weight edge crossing the cut **must** be in every MST.

Kruskal repeatedly picks the minimum “safe” edge.  
DSU guarantees safety by preventing cycles.

If asked why Kruskal is optimal:
- Mention **cut property**  
- Mention **greedy choice is always safe**  

That’s all interviewers expect.

---

# 🌟 **3. Prim’s Algorithm (Heap-Based MST)**  
### ✔ Best for:
- Adjacency list input  
- Dense graphs  
- When you want MST as a tree structure directly  
- When implementing Dijkstra feels natural (Prim is Dijkstra-like)

### ✔ Idea:
1. Pick any start node  
2. Always expand the MST using the smallest edge leaving the current tree  
3. Track visited nodes  
4. Repeat until all nodes included

---

# 🔧 **3.1 Prim’s Template (Priority Queue)**

```cpp
long long primMST(int V, vector<vector<pair<int,int>>> &adj) {
    vector<bool> inMST(V, false);
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);

    priority_queue<pair<int,int>, 
                   vector<pair<int,int>>, 
                   greater<pair<int,int>>> pq;

    key[0] = 0;
    pq.push({0, 0}); // {weight, node}

    long long total = 0;

    while(!pq.empty()) {
        auto [wt, u] = pq.top();
        pq.pop();

        if(inMST[u]) continue;
        inMST[u] = true;
        total += wt;

        for(auto &[v, w] : adj[u]) {
            if(!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }

    return total;
}
```

### ✔ Output:  
- `total` → MST weight  
- `parent[]` → MST structure (tree)

---

# 🆚 **4. Kruskal vs Prim — Which to Use?**

| Scenario | Use Kruskal | Use Prim |
|---------|-------------|----------|
| Edge list input | ✅ Best | — |
| Adjacency list | — | ✅ Best |
| Graph dense | — | ⭐ Better |
| Graph sparse | ⭐ Better | — |
| Need DSU tricks | ✅ YES | — |
| Need actual MST tree | Good | ⭐ Very direct |

### Real Interview Tip:
If the interviewer gives **edges**, use **Kruskal**.  
If they give **graph adjacency**, use **Prim**.

---

# 🌟 **5. MST + DSU Problems You Should Know**

### ✔ Standard MST:
- **LC 1584 – Min Cost to Connect All Points**  
- **LC 1168 – Optimize Water Distribution**

### ✔ Multi-DSU Edge-Type Problems:
- **LC 1579 – Remove Max Number of Edges**

### ✔ Grid + MST Variant:
- Rare in interviews but good for contests.

---

# 🧨 **6. MST Pitfalls (Avoid These!)**

- ❌ Forgetting graph must be **connected** (Prim/Kruskal produce forest otherwise)  
- ❌ Using DSU incorrectly (union without checking root size)  
- ❌ Sorting edges wrong (sort by weight only!)  
- ❌ Forgetting `parent` structure when reconstructing MST  
- ❌ Using Prim on extremely sparse edge-list graphs  

---

# 🎯 **7. Final Interview Summary**

If you need to explain MST in an interview:

### ✔ What is MST?
A minimum-weight set of edges connecting all nodes without cycles.

### ✔ Kruskal summary:
> Sort edges, add smallest that doesn’t form a cycle.  
> Use DSU to detect cycles.  
> Greedy choice is safe because of cut property.

### ✔ Prim summary:
> Start anywhere, grow tree by always picking smallest outgoing edge.  
> Use min-heap to get O(E log V).

---
