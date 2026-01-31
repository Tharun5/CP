# DP — Form 5 (Game DP / Win–Lose DP)

> **Goal:** Recognize and solve impartial turn-based games where both players play optimally, and the task is to decide whether the current player is in a **winning (W)** or **losing (L)** position.

This form is extremely common in:
- combinatorial games
- take-away / subtraction games
- interval removal games
- strategy problems in interviews

---

## 0) Core Philosophy

> **Game DP is about forcing the opponent into a losing position.**

A position is:
- **Winning (W)** → if there exists *at least one* move to a losing state
- **Losing (L)** → if *all* moves lead to winning states

This is the single most important invariant.

---

## 1) Game DP Mental Model

```
State S
  ↙   ↓   ↘
  A   B   C   (possible moves)
```

- If **any** child state is **L** → `S` is **W**
- If **all** child states are **W** → `S` is **L**

Think:
> “Can I force my opponent into a losing state?”

---

## 2) State Definition

Game DP state usually represents:
- number of stones / chips
- current configuration
- interval of remaining elements
- mask of remaining moves

General form:
```
dp(state) = true (Winning) or false (Losing)
```

---

## 3) Universal Steps to Solve Game DP

### Step 1️⃣ Define the state
What fully describes the current game position?

Examples:
- dp[x] → x stones remaining
- dp[l][r] → game on interval [l,r]
- dp[mask] → remaining moves encoded in mask

---

### Step 2️⃣ Define valid moves
From the current state, what moves are allowed?

Examples:
- subtract allowed numbers
- remove an element or segment
- split interval

---

### Step 3️⃣ Write the transition rule

Core rule (memorize this):

```
dp[state] = true
    if exists move → dp[next_state] == false

dp[state] = false
    if all moves → dp[next_state] == true
```

---

### Step 4️⃣ Define base cases
Usually:
- no moves possible → losing state

Examples:
- dp[0] = false
- empty interval → losing

---

### Step 5️⃣ Memoize or iterate
Game DP almost always has overlapping states.

---

## 4) Example 1 — Subtraction Game (Powers of Two)

### Problem
- You have `x` chips
- A move subtracts `2^m` chips (for any `m ≥ 0`)
- Player who cannot move loses

---

### State
```
dp[x] = is winning with x chips?
```

---

### Base Case
```
dp[0] = false   // no move → lose
```

---

### Transition
```cpp
dp[x] = true
    if ∃ y = 2^m ≤ x such that dp[x - y] == false
else
    dp[x] = false
```

---

### Code (Top-down)

```cpp
int dp[200001]; // -1 = unknown, 0 = lose, 1 = win

bool win(int x){
    if(x == 0) return false;
    if(dp[x] != -1) return dp[x];

    for(int p = 1; p <= x; p <<= 1){
        if(!win(x - p))
            return dp[x] = true;
    }
    return dp[x] = false;
}
```

---

### Complexity
- States = `O(x)`
- Moves per state = `O(log x)`
- Total = `O(x log x)`

---

## 5) Example 2 — Interval Game

Common variant:
- Players remove elements from either end
- Score or win depends on choices

### State
```
dp[l][r] = can current player win on interval [l,r]
```

### Transition
```cpp
dp[l][r] = 
    (dp[l+1][r] == false) OR
    (dp[l][r-1] == false)
```

If either move forces opponent into losing state → win.

---

## 6) Zero-Sum Nature (Very Important)

Game DP assumes:
- two players
- perfect play
- zero-sum outcome (one wins, one loses)

This allows local optimal decisions.

---

## 7) Sprague–Grundy Insight (Optional, Advanced)

For impartial games:
- each state has a **Grundy number**
- losing states → Grundy = 0
- winning states → Grundy > 0

But for interviews:
> **W/L DP is sufficient.**

---

## 8) Common Pitfalls

- ❌ Forgetting base losing states
- ❌ Thinking greedily instead of adversarially
- ❌ Not considering “all moves”
- ❌ Forgetting opponent also plays optimally

---

## 9) Interview Sound-bite

> “This is a game DP. I mark a state winning if there exists a move that forces the opponent into a losing state.”

---

## Final Takeaway 🔒

> **Game DP is about forcing outcomes, not optimizing values.**  
> If you can force your opponent to lose, the state is winning.

This mindset solves most impartial game problems.

