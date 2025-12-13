# 🧠 **Disjoint Set Union (DSU) — Notes**  

---

# 📘 **0. Introduction**
Disjoint Set Union (DSU), also called **Union-Find**, is a data structure that tracks dynamic connectivity between elements.  
It supports two main operations:

- **find(x)** → returns the representative (root) of x  
- **union(x, y)** → merges the components containing x and y  

This structure powers a wide range of problems in interviews and competitive programming:  
- Connectivity in graphs  
- Detecting cycles  
- Grouping related items  
- Grid & island problems  
- Minimum Spanning Trees (Kruskal)  
- Weighted relations  
- Logical / modular relationships  
- Dynamic connectivity problems  

---

# 🟦 **LEVEL 1 — DSU Fundamentals**
## 🔹 1.1 What is DSU?
A system that maintains a partition of elements into disjoint sets.

Each set has a **root**, and DSU maintains:
- parent[x] → who x points to  
- root is when parent[x] = x  

## 🔹 1.2 find(x)
Recursively walks up until root.

### Basic Version:
```cpp
int find(int x){
    if(parent[x] == x) return x;
    return find(parent[x]);
}
```

## 🔹 1.3 union(x, y)
Merge two sets by linking their roots.

### Basic Version:
```cpp
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y) parent[y] = x;
}
```

## 🔹 1.4 Use cases
- Counting connected components  
- Cycle detection  
- Grouping items  

**Problems:**
- LC 547 – Number of Provinces  
- LC 1319 – Make Network Connected  

---

# 🟦 **LEVEL 2 — Optimized DSU**
DSU becomes extremely fast with two optimizations:

## 🔹 2.1 Path Compression
Flatten the tree during find.

```cpp
int find(int x){
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
```

## 🔹 2.2 Union by Size/Rank
Attach smaller subtree under larger root.

```cpp
void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
}
```

## 🔹 2.3 Component Tracking
DSU can track number of components.

```cpp
int comp = n;
if(find(a) != find(b)){
    unite(a,b);
    comp--;
}
```

**Problems:**
- LC 990 – Satisfiability of Equality Equations  
- LC 684 – Redundant Connection  

---

# 🟦 **LEVEL 3 — DSU on Graphs**
## 🔹 3.1 Cycle Detection
If `find(u) == find(v)` before union → edge creates cycle.

## 🔹 3.2 Minimum Spanning Tree (Kruskal)
Steps:
1. Sort edges by weight  
2. Add smallest edge that doesn’t form cycle  
3. Stop after n-1 edges  

DSU handles cycle checks efficiently.

**Template:**
```cpp
sort(edges.begin(), edges.end());
for(auto &e : edges){
    if(find(e.u) != find(e.v)){
        unite(e.u, e.v);
        mst += e.w;
    }
}
```

**Problems:**
- LC 1584 – Min Cost to Connect Points  
- LC 1168 – Optimize Water Distribution


1. Sum of Minimum Weight of Paths Between All Pairs in a Graph
   - Edge Contribution Technique using DSU:  https://codeforces.com/blog/entry/131735

---

# 🟦 **LEVEL 4 — Multi-DSU & Edge Types**
Some problems require *multiple DSU instances*.

Example: LC 1579 (Alice & Bob).

Rules:
- Process shared edges first  
- Maintain two DSUs  
- Count redundant edges  
- Check final connectivity  

This level tests deep DSU thinking.

---

# 🟦 **LEVEL 5 — DSU on Grids (2D → 1D Mapping)**

## 🔹 5.1 Mapping Trick
Convert grid cell `(r, c)` into DSU index:

```
id = r * cols + c
```

## 🔹 5.2 Static Islands
Union neighbors if both are land.

**Problems:**
- LC 200 – Number of Islands (DSU version)

## 🔹 5.3 Dynamic Islands (Realtime DSU)
Add land one by one and track components.

Pattern:
```
comp++
for each active neighbor:
    if unite → comp--
```

**Problems:**
- LC 305 – Number of Islands II  

## 🔹 5.4 Largest Island (Component Sizes)
Track island sizes using size[root].

**Problems:**
- LC 827 – Making a Large Island  

## 🔹 5.5 Reverse DSU (Very Important)
Reverse activation, union neighbors, detect special structure.

**Problems:**
- LC 1970 – Last Day Where You Can Still Cross  

---

# 🟦 **LEVEL 6 — Weighted DSU (Equation Solving)**

Used when relationships involve ratios (like division).

## 🔹 6.1 Store weight between node & parent
```
wt[x] = x / parent[x]
```

## 🔹 6.2 Weighted Find
```cpp
int find(int x){
    if(parent[x] != x){
        int p = parent[x];
        parent[x] = find(parent[x]);
        wt[x] *= wt[p];
    }
    return parent[x];
}
```

## 🔹 6.3 Weighted Union
Maintain `x / y = value`.

```
parent[rootX] = rootY
wt[rootX] = (wt[y] * val) / wt[x]
```

**Problems:**
- LC 399 – Evaluate Division  

---

# 🟦 **LEVEL 7 — Modulo / Logic DSU**
Used in Food Chain / relation graph problems.

Store:
```
rel[x] = (type[x] - type[parent[x]]) mod 3
```

During find:
```
rel[x] += rel[parent[x]];
```

Used for problems where relationships cycle in mod space.

**Problems:**
- SPOJ CHAIN  

---

# 🟦 **LEVEL 8 — Virtual Nodes**
When needing to connect a whole row/column/group:

- Create a **virtual node**
- Union all nodes in group with it
- Check DSU connectivity via virtual nodes

Used in:
- LC 1970 (Top ↔ Bottom cross checking)  

---

# 🟦 **LEVEL 9 — Common DSU Patterns**

## 🔹 Mapping Arbitrary Entities
Map:
- Strings  
- Coordinates  
- Emails  
to integers.

## 🔹 Avoiding Re-scans
Union neighbors only in one direction to reduce work.

## 🔹 Handling Repeated Activations
If already active → skip.

## 🔹 Only roots hold valid extra info
Never use `parent[x]` directly to access metadata.  
Always use `find(x)` first.

---

# 🟦 **LEVEL 10 — DSU Templates (Production Ready)**

## 🔹 Basic DSU Template
```cpp
struct DSU {
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.assign(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    void unite(int a,int b){
        a = find(a); b = find(b);
        if(a==b) return;
        if(size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
};
```

## 🔹 Weighted DSU Template
(As built earlier)

## 🔹 Grid DSU Template
- id mapping  
- union neighbors  

---

# 🟦 **LEVEL 11 — DSU Problem Map**

### Connectivity:
- 547  
- 1319  

### Cycle Detection:
- 684  
- 685  

### MST:
- 1584  
- 1168  

### Multi-DSU:
- 1579  

### String Mapping:
- 1202  
- 721  

### Logic Constraints:
- 990  

### Weighted:
- 399  

### Grid Static/Dynamic:
- 200  
- 305  
- 827  
- 1970  

### Modulo DSU:
- CHAIN  

---

