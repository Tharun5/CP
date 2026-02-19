# 🧠 Graph Modeling & Ideas

------------------------------------------------------------------------

# 🔥 Core Philosophy

Most hard graph problems reduce to one of:

1.  Minimum Spanning Tree (MST)
2.  Shortest Path
3.  Maximum Flow / Min Cut
4.  Bipartite Matching

Your goal is NOT to solve problems. Your goal is to **reduce them to one
of these models.**

------------------------------------------------------------------------

# 🌉 1️⃣ Virtual Node (Super Source) Pattern

## When to Trigger This Idea

Use when you see:

-   "Either build at node OR connect via edges"
-   Node activation cost + edge cost
-   Multiple starting points
-   Must choose at least one source
-   Facility placement problems

------------------------------------------------------------------------

## 💡 Transformation

If a node has a cost to activate/build:

Convert node cost → edge from super node.

Add a virtual node `0`: - Add edge (0 → i) with weight = node activation
cost.

Then solve using: - MST (if global connection needed) - Dijkstra (if
shortest path from any source needed)

------------------------------------------------------------------------

## 📌 Example Problems

-   Water Supply in Village
-   Library or Roads (HackerRank)
-   Airport Construction
-   Power Grid Optimization
-   Minimum Cost to Connect Cities

------------------------------------------------------------------------

# 🌳 2️⃣ Minimum Spanning Tree Recognition

## Trigger Words

-   Connect all nodes
-   Minimum total cost
-   Network construction
-   Infrastructure planning

## Key Invariant

We are building ONE connected component covering all nodes with minimum
cost.

If you see: - No direction - No source-target - Global cost minimization

Think MST.

------------------------------------------------------------------------

# 🚀 3️⃣ Shortest Path Recognition

## Trigger Words

-   Minimum distance
-   Minimum time
-   From A to B
-   Distance from nearest X

If you see: - Direction matters - Path length matters - One source (or
multi-source)

Think Dijkstra or BFS.

------------------------------------------------------------------------

# 🌊 4️⃣ Multi-Source Trick

If multiple nodes act as starting points:

Add super source with 0-weight edges to all starting nodes.

Run Dijkstra or BFS.

Used in: - Nearest hospital problem - Fire spread problem - Closest
facility problem

------------------------------------------------------------------------

# ⚡ 5️⃣ Node Cost → Edge Cost Trick

Whenever you see: - Node has cost - Edge has cost

Ask:

Can I convert node cost into edge cost?

Usually YES via super node.

------------------------------------------------------------------------

# 🔄 6️⃣ Reverse Thinking

Instead of asking: - What does each node choose?

Ask: - What edges belong to the structure?

Shift perspective from node decisions → edge selection.

------------------------------------------------------------------------

# 🔥 7️⃣ Cut Property Thinking (MST Insight)

At any step: The smallest edge crossing a cut is always safe.

This is the invariant behind Prim and Kruskal.

------------------------------------------------------------------------

# 🌊 8️⃣ Flow Modeling Trigger

Trigger words: - Capacity - Maximum throughput - Assign tasks - Match
workers to jobs - Scheduling constraints

Think: - Bipartite matching - Max flow

------------------------------------------------------------------------

# 🧠 9️⃣ Graph Problem Classification Framework

Before coding, ask:

1.  Are we connecting everything globally? → MST
2.  Are we minimizing distance from source? → Shortest Path
3.  Are there capacities or assignments? → Flow
4.  Is it pairing between two groups? → Bipartite Matching

------------------------------------------------------------------------

# 🏋️ Practice Problems (Modeling Focus)

### MST Transformations

-   Water Supply in Village
-   Library and Roads (HackerRank)
-   Optimize Airport Placement
-   Connecting Cities With Minimum Cost

### Super Source + Dijkstra

-   Multi-source shortest path
-   Minimum distance to nearest facility

### Flow / Matching

-   Assign jobs to workers
-   Course scheduling with constraints
-   Maximum bipartite matching

------------------------------------------------------------------------
