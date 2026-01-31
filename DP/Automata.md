# DP — (Automata)

> **Goal:** Cover advanced DP patterns that extend Forms 1–5:
> - Automata-based DP for forbidden substrings / subsequences
> - DP with state machines

---

## 0) Core Philosophy

> **When DP state transitions are regular, monotonic, or pattern-driven,  
we can optimize DP using data structures or automata.**

---

## 1) Automata DP — Forbidden Subsequence

### Problem
Count strings that do NOT contain a forbidden subsequence.

### State
```
dp[pos][matched_len]
```

If `matched_len == pattern_length` → invalid.

### Complexity
```
O(N × pattern_length)
```

---

## 2) Automata DP — Forbidden Substring

### Why harder?
Overlapping prefixes require fallback transitions.

Example:
```
pattern = "0100"
string  = "010100"
```

Matching `"010"` then seeing `'1'` doesn’t reset to 0.

---

## 3) Automata Construction

Each state = how much of pattern matched.

Example transitions for `"0100"`:

```
0: '0'→1, '1'→0
1: '0'→1, '1'→2
2: '0'→3, '1'→0
3: '0'→4(invalid), '1'→2
```

State 4 = forbidden.

---

## 4) Automata DP Template

```cpp
dp[pos][state] = sum over all choices:
    dp[pos+1][automaton[state][choice]]
```

---

## 5) Remove Subsequence ("hard")

### State
```
dp[i][matched_len]
```

### Choices
- delete char (pay cost)
- keep char and advance automaton

This is **Form 1 DP + automata state**.

---

## 6) When to Use This Form

- Forbidden patterns
- String constraints
- DP needs more structure
- Optimizing naive DP

---

## 7) Common Pitfalls

- ❌ Ignoring overlapping prefix matches
- ❌ Confusing substring vs subsequence
- ❌ Overcomplicating state

---

## Final Takeaway 🔒

> **Advanced DP = Basic DP + structure (binary search / automata).**

---

### Status: COMPLETE ✔️
DP FORMS 1–6 DONE 🎉
