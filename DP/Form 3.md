# DP — Form 3 (Multi‑Sequence / Two‑Pointer DP)

> **Goal:** Recognize and solve DP problems involving **two or more sequences** (strings/arrays), where decisions are made by advancing one or more indices together.

This form is most commonly seen in **string DP** and **sequence alignment** problems.

---

## 0) Core Philosophy

> **Form 3 DP compares multiple sequences simultaneously.**

At every state, you decide:
- do I advance in sequence A?
- do I advance in sequence B?
- or do I advance in both?

The DP state captures **positions in all sequences**.

---

## 1) Form 3 Mental Model

For two sequences:

```
A = [ _ i _ _ _ _ _ ]
B = [ _ j _ _ _ _ _ ]
```

General state:
```
dp(i, j) = answer using A[i..] and B[j..]
```

For three sequences:
```
dp(i, j, k)
```

Key idea:
> **State = positions in each sequence**

---

## 2) When Form 3 Applies (Recognition Cues)

Use Form 3 when:
- Two or more strings / arrays involved
- Order must be preserved (subsequence / substring)
- Matching or alignment is required
- Problems ask about “common”, “palindrome”, “edit”, “transform”

Keywords:
- LCS / LPS / Edit Distance
- Subsequence / Substring
- Palindrome
- Transformation

---

## 3) Universal Steps to Solve Form 3 DP

### Step 1️⃣ Define the DP state
Ask:
> What does dp(i, j) represent *exactly*?

Example:
- LCS → length of longest common subsequence from A[i..] and B[j..]

---

### Step 2️⃣ Define base cases
Common bases:
```
if i == len(A) or j == len(B): return 0
```

---

### Step 3️⃣ Write transitions
At state (i, j):

- If characters match:
  - take them and move both
- Else:
  - try skipping one side

---

### Step 4️⃣ Combine answers
Depending on problem:
- max
- min
- sum

---

### Step 5️⃣ Memoize / Tabulate
Time becomes:
```
O(len(A) × len(B))
```

---

## 4) Example 1 — Longest Common Subsequence (LCS)

### State
```
dp(i, j) = LCS length of A[i..] and B[j..]
```

### Transition
```cpp
if (A[i] == B[j])
    dp(i,j) = 1 + dp(i+1, j+1);
else
    dp(i,j) = max(dp(i+1, j), dp(i, j+1));
```

---

## 5) Example 2 — LCS of 3 Strings

### State
```
dp(i, j, k)
```

### Transition
```cpp
if (A[i] == B[j] && B[j] == C[k])
    dp = 1 + dp(i+1, j+1, k+1);
else
    dp = max(
        dp(i+1, j, k),
        dp(i, j+1, k),
        dp(i, j, k+1)
    );
```

### Insight
> **LCS(A,B,C) ≠ LCS(LCS(A,B), C)**  
Because LCS is not unique.

---

## 6) Example 3 — Longest Common Substring

### Difference from LCS
- Substring must be **contiguous**
- On mismatch → reset length to 0

### State
```
dp(i, j) = length of common substring starting at i, j
```

### Transition
```cpp
if (A[i] == B[j])
    dp(i,j) = 1 + dp(i+1, j+1);
else
    dp(i,j) = 0;
```

Global answer = max over all dp(i,j).

---

## 7) Example 4 — Make String Palindrome (Min Insertions)

### Observation
> Minimum insertions = length − LPS

And:
```
LPS(s) = LCS(s, reverse(s))
```

### State
```
dp(i, j) = LCS length of s[i..] and rev[j..]
```

Answer:
```
n − dp(0,0)
```

---

## 8) Time & Space Complexity Rule

For k sequences:
```
Time = O(N1 × N2 × ... × Nk)
Space = same
```
This grows fast — Form 3 is practical mainly for 2 sequences.

---

## 9) Common Pitfalls

- ❌ Forgetting base cases
- ❌ Mixing substring vs subsequence logic
- ❌ Using LCS logic for substring
- ❌ Trying to reduce 3‑sequence DP naively

---

## 10) Interview Sound‑bite

> “This is a two‑sequence DP. I define dp(i,j) as the best answer using suffixes of both strings and transition by matching or skipping characters.”

---

## Final Takeaway 🔒

> **Form 3 DP aligns multiple sequences by advancing indices together.**

If the problem involves:
- matching
- alignment
- palindrome
- edit operations

→ **Form 3 is the natural model.**

---

### Status: COMPLETE ✔️
Next: **Tree DP**, **DP Form 4 (Partition / Palindrome DP)**, or **DP Master Notes consolidation**
