# Recursion & Backtracking — Notes

> Goal: Instantly recognize recursion / backtracking problems, model them correctly using **Level–Choice–Check–Move**, and decide when to convert recursion into DP.

---

## 0) Core Philosophy

> **First generate all possibilities conceptually.  
Then ask: do subproblems repeat?  
If yes → DP.  
If no → Backtracking.**

Recursion is the *foundation*.  
Backtracking and DP are *specializations* of recursion.

---

## 1) Universal Recursion Framework (MEMORIZE THIS)

Every recursion / backtracking problem can be described using (LCCM Framework):

### 🔹 Level
What decision index are we fixing now?

Examples:
- index `i` in array
- row number in chessboard
- position in string
- item number in knapsack

---

### 🔹 Choice
What options do we have at this level?

Examples:
- jump 1 / 2 / 3
- place queen in column `j`
- take / not take an item
- add '(' or ')'

---

### 🔹 Check (Constraint)
Is this choice valid?

Examples:
- bounds check (`i + jump <= n`)
- column / diagonal safety
- remaining capacity / time
- balance of parentheses

---

### 🔹 Move
Apply the choice and recurse to the next level.

---

## 2) Example 1 — Climbing Stairs (Recursion → DP)

### Problem
From step `1` reach step `n` using jumps `{1,2,3}`. Count number of ways.

### Mapping
- **Level**: current step `i`
- **Choice**: jump `1,2,3`
- **Check**: `i + jump <= n`
- **Move**: recurse to `i + jump`

### Recursion
```cpp
int ways(int i){
    if(i == n) return 1;
    if(i > n) return 0;
    return ways(i+1) + ways(i+2) + ways(i+3);
}
```

### Observation → DP
- Same `i` reached many times
- Overlapping subproblems

### DP Invariant
> `dp[i]` = number of ways to reach `n` from step `i`

This reduces:
```
O(3^n) → O(n)
```

---

## 3) Example 2 — N Queens (Pure Backtracking)

### Problem
Place `N` queens so no two attack each other. Count configurations.

### Key Insight
- Only **one queen per row**
- So **Level = row**, not cell `(i,j)`

### Mapping
- **Level**: row `i`
- **Choice**: column `j`
- **Check**: no conflict with previous queens
- **Move**: place queen and go to row `i+1`

### Simple Representation
Store `queens[row] = col`

### Diagonal Check Invariant
Two queens `(r1,c1)` and `(r2,c2)` attack diagonally iff:
```
abs(r1 - r2) == abs(c1 - c2)
```

### Code
```cpp
int queens[8];
const int n = 8;

bool check(int row, int col){
    for(int i = 0; i < row; i++){
        if(queens[i] == col || abs(i - row) == abs(queens[i] - col))
            return false;
    }
    return true;
}

int ways(int row){
    if(row == n) return 1;
    int ans = 0;
    for(int col = 0; col < n; col++){
        if(check(row, col)){
            queens[row] = col;
            ans += ways(row + 1);
            queens[row] = -1;
        }
    }
    return ans;
}
```

### Why this is NOT DP
- State depends on **entire configuration**
- State space is exponential
- No clean overlapping subproblems

---

## 4) Enhanced Constraints (Queen + Knight)

Simply extend the **check**:

```cpp
bool check(int row, int col){
    for(int i = 0; i < row; i++){
        int prow = i;
        int pcol = queens[i];
        if(pcol == col) return false;
        if(abs(prow-row) == abs(pcol-col)) return false;
        if(abs(prow-row) + abs(pcol-col) == 3) return false; // knight
    }
    return true;
}
```

This demonstrates:
> **Backtracking adapts easily to added constraints.**

---

## 5) Example 3 — Knapsack-like Problem (Recursion → DP)

### Problem
Each item has `(time, skill)`.  
Total time ≤ `X`, total items ≤ `K`.  
Maximize skill.

### Mapping
- **Level**: item index `i`
- **Choice**: take / not take
- **Check**: `time + Ti <= X` and `count < K`
- **Move**: recurse to `i+1`

### DP State
```
dp[i][time][count]
```

### DP Invariant
> Best skill achievable considering items `[i…n)` with given time and slots left.

This is classic **0/1 Knapsack DP**.

---

## 6) Backtracking vs DP — Decision Rule (VERY IMPORTANT)

### Use Backtracking when:
- You must **generate / count configurations**
- State depends on **entire path**
- No meaningful overlapping subproblems

Examples:
- N Queens
- Sudoku
- Permutations
- Balanced parentheses

---

### Use DP when:
- You need **count / max / min / feasibility**
- State can be summarized compactly
- Subproblems repeat

Examples:
- Climbing stairs
- Knapsack
- LIS
- Grid paths

---

## 7) Example — Generate Balanced Parentheses

### Mapping
- **Level**: current length
- **Choice**: '(' or ')'
- **Check**:
  - open > 0
  - close > open
- **Move**: recurse

### Code
```cpp
void gen(int open, int close, string cur){
    if(open == 0 && close == 0){
        ans.push_back(cur);
        return;
    }
    if(open > 0)
        gen(open-1, close, cur + "(");
    if(close > open)
        gen(open, close-1, cur + ")");
}
```

### Invariant
> Never allow invalid prefix (more ')' than '(').

---

## 8) Key Invariants to Remember

### 🔑 Backtracking Invariant
> “I am building the solution incrementally; once I move deeper, earlier choices remain fixed until I backtrack.”

---

### 🔑 DP Invariant
> “The future outcome depends only on the current state variables, not on the full history.”

---

## 9) Common Pitfalls

- ❌ Using DP where state is exponential
- ❌ Forgetting to undo changes (backtracking)
- ❌ Overcomplicating constraints (diagonal checks are simple)
- ❌ Not defining level clearly

---

## 10) Interview Sound-Bite

> “I first model the problem with recursion using level–choice–check–move.  
If subproblems repeat, I memoize and convert it to DP.”

---

## Final Takeaway 🔒

> **Recursion is the root.  
Backtracking explores.  
DP optimizes.**

Master the modeling first — optimizations follow naturally.
