# Monotonic Stack & Queue — Master Notes

---

## 0) Core Philosophy

> **We don’t memorize patterns.  
> We extract invariants and dominance rules.**

Before choosing a stack, ask:
- What is **fixed**?
- What **varies**?
- When does a decision become **final**?
- When does an element become **useless forever**?

Monotonic structures exist to answer these questions efficiently.

---

## 1) What is a Monotonic Stack?

A stack that maintains elements in **monotonic order** (increasing or decreasing).

But the key is **WHY**:

> Once an element is dominated by a better candidate, it will never be useful again → safe to pop.

---

## 2) Two Big Families (Very Important)

### 🔹 Family A — *Waiting for an Answer*
Pop = “I just found your answer.”

Use when each element is waiting to be resolved by a future element.

**Examples**
- Next Greater Element
- Daily Temperatures
- Stock Span
- Buildings With Ocean View
- Maximum Width Ramp

**Invariant**
Stack holds **unresolved candidates** in monotonic order.

**Generic Template**
```cpp
stack<int> st; // indices
for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] < arr[i]) {
        ans[st.top()] = i - st.top(); // or arr[i]
        st.pop();
    }
    st.push(i);
}
```

---

### 🔹 Family B — *Pop Defines a Range / Contribution*
Pop = “Your influence range is now finalized.”

Use when each element contributes to **many subarrays / rectangles / ranges**.

**Examples**
- Largest Rectangle in Histogram
- Maximal Rectangle
- Sum of Subarray Minimums
- Sum of Subarray Ranges

**Invariant**
When an element is popped:
- Right boundary = current index
- Left boundary = new stack top after pop

Contribution:
```
L = idx - leftBoundary
R = rightBoundary - idx
```

---

## 3) Dominance Principle (Why Pop is Safe)

If `i < j` and `A[j]` dominates `A[i]` (greater or smaller as needed):
- `i` will never be a better answer than `j` for any future position
- `i` can be safely removed

This single idea explains:
- popping in stacks
- greedy by end-time
- removing dominated intervals
- skyline-like problems

---

## 4) Strict vs Non-Strict Comparisons (Duplicates Handling)

Duplicates must be **owned by exactly one index** to avoid double counting.

### General Rule
- One side: strict (`<` or `>`)
- Other side: non-strict (`<=` or `>=`)

### Common Choices
| Problem | Pop Condition |
|------|-------------|
| Subarray Minimums | `cur < top` |
| Subarray Maximums | `cur > top` |
| Histogram | `cur < top` |
| Ramp | build `<`, resolve `<=` |

---

## 5) Indices vs Values

**Always store indices**, not values:
- width = distance between indices
- boundaries matter
- duplicates handled correctly

---

## 6) Sentinel Trick (Must Know)

Add a fake element at the end to flush stack:

- Histogram: append height `0`
- Forces all remaining bars to be popped and finalized

```cpp
for (int i = 0; i <= n; i++) {
    int cur = (i == n ? 0 : h[i]);
    ...
}
```

---

## 7) Grid → 1D Reduction (Powerful Invariant)

> **2D rectangle problems often reduce to 1D histograms.**

### Example: Maximal Rectangle
```
2D matrix of 1s
↓
Fix each row as base
↓
Build histogram heights
↓
Solve Largest Rectangle per row
```

This explains why DP fails for rectangles (2 degrees of freedom).

---

## 8) Greedy + Monotonic Stack (Strings / Numbers)

### Safe Deletion Invariant
You can pop a character/digit if:
1. It improves lexicographic order
2. You can still include it later

**Used in**
- Remove K Digits (402)
- Remove Duplicate Letters (316)
- Lexicographically Smallest Subsequence variants

---

## 9) Monotonic Queue (Deque)

Used when:
- Sliding window max/min
- Window size fixed
- Need O(1) window updates

**Example**
- Sliding Window Maximum (239)

**Invariant**
Deque stores indices in decreasing order of value.

---

## 10) Tool Hierarchy (Avoid Overengineering)

Before using a stack, ask:

1️⃣ Only need best-so-far? → single variable  
2️⃣ Many unresolved candidates? → monotonic stack  
3️⃣ Range finalized on pop? → monotonic stack (Family B)  
4️⃣ Fixed window max/min? → monotonic queue  

---

## 11) Problems Covered (Checklist)

### Family A
- 739 Daily Temperatures
- 901 Stock Span
- 503 Next Greater Element II
- 962 Maximum Width Ramp
- Buildings With Ocean View

### Family B
- 84 Largest Rectangle in Histogram
- 85 Maximal Rectangle
- 907 Sum of Subarray Minimums
- 2104 Sum of Subarray Ranges

### Greedy + Stack
- 402 Remove K Digits
- 316 Remove Duplicate Letters
- 3816 Lexicographically Smallest String After Deleting Duplicates

### Queue
- 239 Sliding Window Maximum

---

## 12) Common Pitfalls Checklist

- ❌ Forgetting duplicate handling (`<` vs `<=`)
- ❌ Storing values instead of indices
- ❌ Missing sentinel flush
- ❌ Using stack when a single variable suffices
- ❌ Not reasoning about when answers become final

---

## 13) Interview Sound-Bite (Use This)

> “I maintain a monotonic structure so that when an element is dominated, it can never contribute to a better solution. Popping finalizes its answer or contribution.”

---

## Final Takeaway 🔒

> **Monotonic stack problems are not about stacks.  
They are about dominance, finality, and deferred decisions.**

If you understand that, you can solve any variant.

Refer:
https://dilipkumar.medium.com/monotonic-stack-fdd3e3a5b251
https://leetcode.com/discuss/post/3773642/mastering-monotonic-stack-unlocking-effi-6h94/

---
