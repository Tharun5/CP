# DP — Form 4 (Interval / LR DP)

> **Goal:** Recognize and solve DP problems where the state is defined over a **subarray / interval [l, r]**, and decisions split or reduce this interval.

This form appears whenever:
- you cut / merge / destroy elements
- order matters
- the cost depends on the **whole segment length or contents**
- operations reduce an interval into smaller intervals

---

## 0) Core Philosophy

> **Instead of simulating operations forward, ask:  
“How did the LAST operation happen?”**

Interval DP works by **reasoning backward**:
- What was the last cut?
- What was the last merge?
- What was the last removal?

Once the last operation is fixed, the problem splits cleanly into independent subproblems.

---

## 1) Form 4 Mental Model

Problems look like:

```
[ l  _  _  _  _  _  r ]
```

General state:
```
dp(l, r) = best answer for subarray / segment [l, r]
```

Key idea:
> **dp(l, r) depends only on smaller intervals inside it.**

---

## 2) When Form 4 Applies (Recognition Cues)

Use Interval DP when:
- You repeatedly **cut / merge / delete** elements
- Cost depends on **segment length or segment sum**
- Final goal is to reduce interval to empty or one element
- Operations split interval into left & right parts

Keywords:
- cut
- merge
- destroy
- burst
- remove substring
- cost of segment

---

## 3) Universal Steps to Solve Interval DP

### Step 1️⃣ Define the interval state

Ask:
> What does dp(l, r) represent exactly?

Examples:
- min cost to cut rod between l and r
- min time to destroy substring l..r
- min cost to merge stones l..r

---

### Step 2️⃣ Define base cases

Usually:
```
if l >= r → 0 cost
or
if l + 1 == r → no operation needed
```

---

### Step 3️⃣ Decide how interval is reduced

Two common styles:

#### A) Split at some point `p`
```
dp(l, r) = min over p:
    cost(l,r) + dp(l,p) + dp(p,r)
```

#### B) Decide behavior of first element
```
dp(l, r) =
    remove l alone
    OR
    match l with some k (l < k ≤ r)
```

---

### Step 4️⃣ Enumerate transitions

Loop over all valid split points or matching positions.

---

### Step 5️⃣ Memoize or tabulate

States are O(N²), transitions often O(N) → O(N³) total.

---

## 4) Example 1 — Rod Cutting (LC 1547)

### Observation
Cutting cost depends on **current segment length**.
So order of cuts matters.

### State
```
dp(l, r) = minimum cost to cut between cuts[l] and cuts[r]
```

### Transition
```cpp
dp(l,r) = min over p in (l,r):
    (cuts[r] - cuts[l]) + dp(l,p) + dp(p,r)
```

### Complexity
```
States: O(N²)
Transitions: O(N)
Total: O(N³)
```

---

## 5) Example 2 — Destroy Colored Gemstones

### Observation
Think in terms of **what happens to the first element**.

### State
```
dp(l, r) = min seconds to destroy substring l..r
```

### Transitions
- Destroy arr[l] alone
- Destroy arr[l] with a matching arr[x]

```cpp
dp(l,r) = min(
    1 + dp(l+1, r),
    dp(l+1, x-1) + dp(x+1, r)   where arr[l] == arr[x]
)
```

### Key Insight
> Fixing the behavior of the **first element** is often easier than splitting arbitrarily.

---

## 6) Example 3 — Merge Elements / Mixtures Problem

### Observation
Instead of simulating merges forward, ask:
> **What was the last merge?**

Last merge splits `[l,r]` into:
```
[l..p] and [p+1..r]
```

### State
```
dp(l,r) = minimum cost to merge l..r into one
```

### Transition
```cpp
dp(l,r) = min over p:
    dp(l,p) + dp(p+1,r) + cost(left) * cost(right)
```

Where:
```
cost(l,r) = (prefix[r+1] - prefix[l]) % 100
```

This avoids simulating array changes.

---

## 7) Two Key Interval DP Patterns

### 🔹 Pattern A — Split-based DP
Used when:
- cost applies to whole segment
- final operation splits interval

Examples:
- Rod cutting
- Matrix chain multiplication
- Merge stones

---

### 🔹 Pattern B — First-element DP
Used when:
- removing elements
- matching pairs

Examples:
- Destroy palindromes
- Remove boxes
- Strange game DP problems

---

## 8) Complexity & Constraints

Interval DP is usually:
```
O(N³) time
O(N²) space
```

So N is typically ≤ 400–500.

If N is large:
- need optimization
- or different DP form

---

## 9) Common Pitfalls

- ❌ Thinking forward instead of backward
- ❌ Missing correct base cases
- ❌ Incorrect interval boundaries
- ❌ Forgetting to sort cuts (rod cutting)
- ❌ Simulating array merges explicitly

---

## 10) Interview Sound-bite

> “This is interval DP. I define dp(l,r) as the best answer for the segment [l,r] and consider all ways the last operation could have split this segment.”

---

## Final Takeaway 🔒

> **Form 4 DP works when operations split or reduce an interval.  
Reason about the LAST operation, not the first.**

If you think:
- cut
- merge
- destroy
- cost of segment

→ **Interval DP is the right model.**

