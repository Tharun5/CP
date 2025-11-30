# 🚀 Bellman–Ford Algorithm

Bellman–Ford is a **Single Source Shortest Path (SSSP)** algorithm that works even when the graph has **negative edge weights** and can also **detect negative weight cycles** reachable from the source.

---

## ✅ When to Use Bellman–Ford

Use Bellman–Ford when:

- The graph has **negative edge weights**.
- You need to **detect negative cycles**.
- The graph is **not too large** (Time: `O(V * E)`).

If all edge weights are non-negative, **Dijkstra** is usually better.

---

## 🧠 Core Idea

- Start with a distance array `dis[]`, initialized to `INF` for all nodes except `src`, which is `0`.
- Relax **all edges** `V - 1` times.
- Each *relaxation* tries to **improve** the current best known distance using an edge.

> **Relaxation:**  
> If `dis[u] + wt < dis[v]`, then we found a better path to `v` via `u`,  
> so we set `dis[v] = dis[u] + wt`.

---

## ❓ Why Relax Exactly `V - 1` Times?

- In a graph with `V` vertices, the **longest simple path** (no repeating nodes) has at most `V - 1` edges.
- Shortest paths never need to use a cycle (if there’s no negative cycle), so:
  - Any shortest path from `src` to any vertex is at most `V - 1` edges long.
- On each full iteration (over all edges), the shortest paths with up to a certain number of edges get finalized:
  - After 1st iteration → shortest paths using ≤ 1 edge.
  - After 2nd iteration → shortest paths using ≤ 2 edges.
  - …
  - After `(V - 1)` iterations → shortest paths using ≤ `V - 1` edges.

So by the end of `V - 1` relaxations over all edges, all possible shortest paths (without cycles) must be found.

If any distance can still be improved **after** `V - 1` iterations →  
there must be a **negative weight cycle** reachable from the source.

---

## 🔍 Negative Cycle Detection

After doing `V - 1` relaxations:

- Run **one more pass** over all edges.
- If any edge `(u, v, wt)` can still be relaxed, i.e.  
  `dis[u] + wt < dis[v]`,  
  then there exists a **negative cycle reachable** from the source.

---

## 🧩 Graph Representation

Bellman–Ford is easiest with an **edge list**:

```cpp
// edges: vector of {u, v, wt}
vector<vector<int>> edges;
```

Each entry is a directed edge: `u -> v` with weight `wt`.

---

## 🧾 C++ Implementation

```cpp
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int src) {
    int INF = 1e8;
    vector<int> dis(V, INF);
    dis[src] = 0;

    // Step 1: Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        bool changed = false;
        for (auto &edg : edges) {
            int u = edg[0];
            int v = edg[1];
            int wt = edg[2];

            if (dis[u] != INF && dis[u] + wt < dis[v]) {
                dis[v] = dis[u] + wt;
                changed = true;
            }
        }
        // Optional optimization: if no update in this pass, break early
        if (!changed) break;
    }

    // Step 2: Check for negative weight cycle
    for (auto &edg : edges) {
        int u = edg[0];
        int v = edg[1];
        int wt = edg[2];

        if (dis[u] != INF && dis[u] + wt < dis[v]) {
            // Negative cycle detected
            return { -1 };
        }
    }

    return dis;
}
```

---

## ⏱️ Time & Space Complexity

- **Time:** `O(V * E)`
- **Space:** `O(V)`

---
