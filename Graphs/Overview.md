# 🗺️ Graphs – Overview

## 1. **Graph Basics**
- Directed / Undirected  
- Weighted / Unweighted  
- Representation: Adjacency List, Matrix, Edge List  
- Graph properties: degree, components, density  

---

## 2. **Traversal Algorithms**

### 2.1 DFS – Depth First Search
- Recursive / Iterative (Stack)
- Applications: Conected Components, cycle detection, toposort, pathfinding  
- Grid DFS, flood-fill  

### 2.2 BFS – Breadth First Search
- Level order  
- Applications: shortest path (unweighted), bipartite, multi-state BFS  
- Grid BFS  

### 2.3 Multi-Source BFS
- Queue initialized with multiple sources starting points. 
- Used in rotting oranges, fire spread, word ladder  

---

## 3. **Graph Classification**

### Bipartite Graph  
- BFS/DFS 2-coloring
- Detect Odd cycles
- For Directed Graphs, Bipartite check rarely occurs
  
### Cycle Detection  
- Directed: using DFS recursion stack  
- Undirected: using parent tracking 
- With weights: negative cycle (Bellman Ford)
  
  
### Topological Sort (DFS & Kahn’s Algorithm)
- DFS based using Stack post recursion
- Khans Algo (BFS + indeg)  
- DAG Scheduling, Finding DAG

---

## 4. **Shortest Path Algorithms**

### 4.1 SSSP
#### 0–1 BFS
- Deque based, for Edges with weight (0, 1)

#### Dijkstra
- Using PQ & Set 

#### Bellman-Ford
- Handles negative weights
- Detects negative cycles
- Work for directed & undirected (carefully)

### 4.2 APSP (All-Pairs Shortest Path)
#### Floyd–Warshall
- DP Based
- O(N^3)

---

## 5. **DSU – Disjoint Set Union**
- Union by rank  
- Path compression  
- Used in Kruskal / cycle detection  

---

## 6. **Minimum Spanning Tree**
- Kruskal (with DSU)
- Prim’s Algorithm (PQ)
- Applications: Designing Netwoks, Clustering Problems

---

## 7. **SCC – Strongly Connected Components**
- Kosaraju  
- Tarjan (Low-link)  
- Applications: Condensed Graph (DAG of SCCs), Graph contraction, 2-SAT Problems
---

## 8. **Advanced Graph Topics**
- Bridges & Articulation Points  
- Euler Tour / Euler Path (Hierholzer)  
- Topological DP  
- Tree algorithms (LCA, Diameter, Subtree, Centroid)  
- Graph modeling patterns  

---

## 9. **Grid / Matrix as Graph**
- BFS/DFS  
- Weighted grids → Dijkstra  
- State BFS (row, col, mask)  

---

## 10. **Key Patterns**
- BFS → shortest path (unweighted)  
- Dijkstra → weighted non-negative  
- Bellman-Ford → negative weights  
- Toposort → DAG only  
- DSU → merging components  
- SCC → directed connectivity  

---
