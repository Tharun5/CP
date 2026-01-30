# DP — Form 2 (DP Ending at Index / Cell)

> **Goal:** Recognize DP problems where the answer at a position depends on *previous positions* and represents the **best / count / min / max ending exactly there**.

---

## 0) Core Philosophy

> **Instead of asking “what can I do next?”,  
Form 2 asks: “what was the best way to reach here?”**

We compute DP values **in increasing order of dependency** (left → right, top → bottom).

---

## 1) Form 2 Mental Model

Problems look like:

```
[- - - - - -]
            i
```

or in 2D:

```
(0,0) → ... → (i,j)
```

General state:

```
dp[i] = best answer ending at index i
dp[i][j] = best answer ending at cell (i,j)
```

Key idea:
> **The future does NOT matter — only past states determine dp[i].**

---

## 2) When Form 2 Applies (Recognition Cues)

Use Form 2 when:
- Sequence / path / grid problems
- Current position depends on **previous positions**
- Order matters
- No branching choice at current state — just aggregation

Typical keywords:
- *ending at*
- *maximum / minimum path*
- *subsequence / subarray*
- *grid paths*

---

## 3) Universal Steps to Solve Form 2 DP

### Step 1️⃣ Define the DP state
Ask:
> What does dp[i] or dp[i][j] represent **exactly**?

Examples:
- LIS → longest increasing subsequence ending at `i`
- Grid path → max/min sum ending at `(i,j)`
- Square of 1s → max square side ending at `(i,j)`

---

### Step 2️⃣ Identify dependencies
Which previous states can lead to this state?

Examples:
- LIS → all `j < i` where `a[j] < a[i]`
- Grid → top `(i-1,j)` and left `(i,j-1)`
- Square → top, left, diagonal

---

### Step 3️⃣ Write the transition
Combine previous states to compute current.

Examples:
```
dp[i] = max(dp[j] + 1)
dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + val
dp[i][j] = min(top, left, diag) + 1
```

---

### Step 4️⃣ Initialize base cases
Starting positions:
- dp[i] = 1 for LIS
- dp[0][0] = grid[0][0]

---

### Step 5️⃣ Iterate in correct order
Must respect dependencies:
- LIS → left to right
- Grid → top to bottom, left to right

---

## 4) Example 1 — Longest Increasing Subsequence (LIS)

### State
```
dp[i] = length of LIS ending at index i
```

### Transition
```
dp[i] = 1 + max(dp[j]) for all j < i where a[j] < a[i]
```

### Complexity
- States = N
- Transitions = N
- **O(N²)**

---

## 5) Example 2 — Grid Maximum Path Sum

### State
```
dp[i][j] = maximum sum ending at cell (i,j)
```

### Transition
```
dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1])
```

---

## 6) Example 3 — Number of Paths in Grid

### State
```
dp[i][j] = number of ways to reach (i,j)
```

### Transition
```
dp[i][j] = dp[i-1][j] + dp[i][j-1]
```

---

## 7) Example 4 — Minimum Path Sum

### State
```
dp[i][j] = minimum sum ending at (i,j)
```

### Transition
```cpp
dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
```

---

## 8) Example 5 — Maximum Square of 1s

### State
```
dp[i][j] = largest square side ending at (i,j)
```

### Transition
```cpp
dp[i][j] = min(
    dp[i-1][j],
    dp[i][j-1],
    dp[i-1][j-1]
) + 1
```

---

## 9) Relation Between Form 1 and Form 2

| Aspect | Form 1 | Form 2 |
|-----|------|------|
| Perspective | What can I do next? | How did I reach here? |
| State | dp(level, constraints) | dp[i] / dp[i][j] |
| Order | Recursive | Iterative |
| Examples | Knapsack, Staircase | LIS, Grid paths |

---

## 10) Time Complexity Rule

> **Time = (#states) × (#dependencies per state)**

Examples:
- LIS → O(N²)
- Grid DP → O(N×M)
- Max Square → O(N×M)

---

## 11) When Form 2 Does NOT Apply

Avoid when:
- Need to explore multiple future choices
- State depends on full history
- Backtracking required

Examples:
- N Queens
- Permutations

---

## 12) Common Pitfalls

- ❌ Wrong state definition (“so far” instead of “ending at”)
- ❌ Iterating in wrong order
- ❌ Missing diagonal dependency
- ❌ Mixing Form 1 and Form 2 incorrectly

---

## Final Takeaway 🔒

> **Form 2 DP builds answers forward using past results.  
If current depends only on previous, Form 2 is natural.**

