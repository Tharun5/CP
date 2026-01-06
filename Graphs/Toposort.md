# ➡️ Topological Sort — Notes


## 📌 0. Big Picture

Topological Sort (Topo) is **not just an algorithm** — it is a **reasoning framework** for problems involving:

- dependencies
- prerequisites
- ordering constraints
- workflows
- scheduling
- propagation of information in directed graphs

If a problem has **directed edges** and talks about *order*, *before/after*, or *depends on*,  
👉 **Topo is almost always involved**.

---

## 🧠 1. What Topo Sort REALLY Means

Forget the textbook definition for a moment.

> **Topo answers:  
“In what order can things happen so that no rule is violated?”**

- Nodes = tasks / items / entities
- Edge `u → v` = `u` must happen **before** `v`

If such an order exists → graph is a **DAG**  
If no such order exists → graph has a **cycle**

So topo is both:
- an **ordering tool**
- a **cycle detector**

---

## 🔗 2. Relationship with SCC

Directed graph cases:

```
Directed Graph
│
├── DAG → Topo directly
│
└── Has cycles
     └── SCC → Condensed DAG → Topo
```

This is why SCC and Topo always appear together.

---

## ⚙️ 3. Two Types of Topo Sort (and WHEN to use them)

### 🔹 A. DFS-based Topo (Postorder)

**Idea**
- DFS deeply
- Add node after all children are processed
- Reverse postorder gives topo

**Use when**
- DAG is guaranteed
- You want a simple ordering
- You are already doing DFS

**Cycle detection**
- Use recursion stack (`pathVis`)

---

### 🔹 B. Kahn’s Algorithm (BFS / Indegree)

**Idea**
- Repeatedly take nodes with `indeg = 0`
- “Peel” the graph layer by layer

**Use when**
- Cycles may exist
- You want cycle detection
- You want DP / greedy propagation
- You want trimming / pruning

This is the **interview favorite**.

---

## 🧠 4. Topo is NOT BFS (Important!)

Even though Kahn uses a queue:
- ❌ It is **not level-order BFS**
- ✔ It is **dependency-order BFS**

Queue order does NOT imply shortest/longest path order.

Therefore:
> **Topo gives correct dependency order,  
but DP must still aggregate using max/min/etc.**

---

## 🔥 5. Topo + DP (Most Important Pattern)

Topo is usually just the **ordering**.  
The real power is **DP on topo order**.

### Generic template
```cpp
while (!q.empty()) {
    u = q.front(); q.pop();

    // finalize dp[u]

    for (v : g[u]) {
        dp[v] = combine(dp[v], transform(dp[u]));
        indeg[v]--;
        if (indeg[v] == 0) q.push(v);
    }
}
```

### Common combine rules
| Goal | DP rule |
|----|--------|
| Longest path | `max` |
| Shortest path | `min` |
| Count paths | `+` |
| Boolean reachability | `or` |
| Set propagation | `union / bitset` |

---

## 🧩 6. Topo Trimming / Peeling Pattern

**Idea**
- Remove nodes that are “safe / leaves”
- What remains is the **core (cycles)**

Used for:
- cycle detection
- isolating SCC cores
- functional graphs
- safe states

Examples:
- LC 802 — Eventual Safe States
- LC 2127 — Maximum Employees
- LC 310 — Minimum Height Trees

---

## 🔄 7. Functional Graph Special Case

When **outdegree = 1** for every node:
- Graph = cycles + trees feeding into cycles
- SCC is overkill
- Use topo trimming + DP

Patterns:
- find cycles
- handle 2-cycles specially
- propagate chain lengths

---

## 🧠 8. Unique Topo Order Pattern

Sometimes problem asks:
> “Is the order uniquely determined?”

Rule:
```cpp
if (queue.size() > 1) → multiple valid choices → NOT unique
```

Used in:
- LC 444 — Sequence Reconstruction

---

## 🧩 9. Multi-level Topo (Layered Constraints)

When constraints exist at **multiple levels**:
- items + groups
- tasks + modules

Approach:
- build DAG for each layer
- topo each independently
- combine results

Used in:
- LC 1203 — Sort Items by Groups

---

## 🧩 10. Two Independent Topos → 2D Placement

When you have:
- row constraints
- column constraints

Topo both, then place:

```cpp
rowPos[x], colPos[x]
ans[rowPos[x]][colPos[x]] = x
```

Used in:
- LC 2392 — Build a Matrix With Conditions

---

## 🌳 11. Undirected Topo Trimming (Cousin Pattern)

Topo-like idea in undirected graphs:
- peel leaves (`deg = 1`)
- last nodes left are centers

Used in:
- LC 310 — Minimum Height Trees

---

## 🧠 12. Recognition Checklist (USE THIS)

When reading a problem, ask:

1. Is there direction?
2. Are there dependencies / prerequisites?
3. Is cycle allowed?
4. Do I need ordering, scheduling, propagation?
5. Do I need DP on paths?
6. Is there trimming / peeling behavior?

If YES → **Topo is involved**

---

## 🧪 13. Problems Mapped (What You Solved)

### Core Topo + DP
- LC 1857 — Largest Color Value
- LC 2050 — Parallel Courses III

### Layered / Advanced
- LC 1203 — Sort Items by Groups
- LC 2392 — Build Matrix With Conditions

### Uniqueness
- LC 444 — Sequence Reconstruction

### Trimming / Peeling
- LC 802 — Eventual Safe States
- LC 2127 — Maximum Employees
- LC 310 — Minimum Height Trees

---

## 🎯 Final Takeaways

- Topo is a **thinking tool**, not just sorting
- Kahn’s algorithm is extremely powerful
- DP on topo order is the real work
- SCC + Topo go hand in hand
- Many graph problems reduce to “identify constraints → topo → DP”
