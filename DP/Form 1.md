# Dynamic Programming — Form 1 (Level / Choice / Constraints)

> **Goal:** Recognize and solve DP problems that are direct extensions of recursion, where at each level we make choices, move forward, and memoize overlapping subproblems.

---

## 0) Core Philosophy

> **DP is recursion with memory.**

Always start by thinking recursively:
- What is the current level?
- What choices do I have?
- What constraints limit those choices?
- Do subproblems repeat?

If subproblems repeat → **DP**.

---

## 1) Form 1 Mental Model

Problems look like:

```
We are at level i
We have some constraints remaining
We choose an action
We move to level i+1
```

General state:
```
dp(level, constraints...)
```

---

## 2) Universal Steps

### Step 1️⃣ Identify the Level
Examples:
- index i
- step number
- item number

---

### Step 2️⃣ Identify Constraints
Only include values that change:
- remaining time
- remaining weight
- remaining moves
- remaining differences

---

### Step 3️⃣ Define the State

> dp(state) = answer for this state

Examples:
- dp[i]
- dp[i][w]
- dp[i][time][k]

---

### Step 4️⃣ Define Transitions

For each choice:
- check validity
- move to next state
- combine answers (sum / min / max)

---

### Step 5️⃣ Base Cases
Usually:
- reached end
- constraint exhausted

---

### Step 6️⃣ Memoization

Save results to avoid recomputation.

---

## 3) Example — Climbing Stairs

**Level:** step i  
**Choice:** jump 1 / 2 / 3  
**State:** dp[i]

```cpp
int dp[n+1];

int ways(int i){
    if(i == n) return 1;
    if(i > n) return 0;
    if(dp[i] != -1) return dp[i];
    return dp[i] = ways(i+1) + ways(i+2) + ways(i+3);
}
```

---

## 4) Example — 0/1 Knapsack

**Level:** item index i  
**Constraint:** remaining weight

State:
```
dp[i][W_left]
```

```cpp
int knapsack(int i, int W_left){
    if(i == n) return 0;
    if(dp[i][W_left] != -1) return dp[i][W_left];

    int ans = knapsack(i+1, W_left);
    if(W_left >= wt[i])
        ans = max(ans, knapsack(i+1, W_left-wt[i]) + val[i]);

    return dp[i][W_left] = ans;
}
```

---

## 5) Example — Brick Coloring

**Level:** brick index i  
**Constraint:** remaining differences k

State:
```
dp[i][k]
```

```cpp
int ways(int i, int k){
    if(i == n) return k == 0;
    if(dp[i][k] != -1) return dp[i][k];

    long long ans = 0;
    ans += (m-1) * ways(i+1, k-1);
    ans += ways(i+1, k);

    return dp[i][k] = ans % MOD;
}
```

---

## 6) Time Complexity Rule

> **Time = (#states) × (transitions per state)**

Examples:
- Knapsack → O(nW)
- Brick coloring → O(nk)
- Climbing stairs → O(n)

---

## 7) When to Use Form 1

✔ Linear decision sequence  
✔ Finite choices per level  
✔ Overlapping subproblems  
✔ Ask for count / min / max

---

## 8) When NOT to Use Form 1

✖ Full configuration matters  
✖ State space exponential  
✖ Need to generate all solutions

Examples:
- N Queens
- Sudoku

---

## 9) Common Pitfalls

- Forgetting constraints in state
- Using too many state variables
- Missing memoization
- Wrong base cases

---

## Final Takeaway 🔒

> **Form 1 DP = recursion + memoization over levels and constraints.**
