# 🧠 Sliding Window Minimum — From Brute Force ➜ Multiset ➜ Monotonic Deque (O(N))

## 📘 Problem Statement

Given an array `arr[]` of size `N` and a window size `K`, find the **minimum element** in every window of size `K`.

---

## 🪜 Approaches Overview

| # | Approach | Data Structure | Time Complexity | Space | Remarks |
|---|-----------|----------------|----------------|--------|----------|
| 1️⃣ | Brute Force | None | O(N × K) | O(1) | Very slow |
| 2️⃣ | Multiset | Balanced BST | O(N log K) | O(K) | Easier to code |
| 3️⃣ | Monotonic Deque | Deque | **O(N)** | O(K) | 🚀 Optimal solution |

---

## **1️⃣ Brute Force Approach**

### 🔹 Idea

For every window of size `K`, iterate over all elements inside the window and find the minimum.

### ⏱️ Complexity

- **Time:** O(N × K)  
- **Space:** O(1)

### 💻 Code (C++)

```cpp
vector<int> slidingWindowMin_Brute(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> res;

    for (int i = 0; i <= n - k; ++i) {
        int mn = INT_MAX;
        for (int j = i; j < i + k; ++j) {
            mn = min(mn, arr[j]);
        }
        res.push_back(mn);
    }

    return res;
}
```

### 🧩 Example

```
arr = [4, 2, 12, 3, 5], k = 3
Windows:
[4,2,12] → min = 2  
[2,12,3] → min = 2  
[12,3,5] → min = 3  
Result = [2, 2, 3]
```

---

## **2️⃣ Multiset / Balanced BST Approach**

### 🔹 Idea

Maintain a **multiset** (which stores elements in sorted order):
- Insert new element of the window  
- Remove the outgoing (i - k + 1)-th element  
- The minimum is always the **first element** in the set (`*begin()`)

### ⏱️ Complexity

- **Time:** O(N log K)  
- **Space:** O(K)

### 💻 Code (C++)

```cpp
vector<int> slidingWindowMin_Multiset(vector<int>& arr, int k) {
    multiset<int> window;
    vector<int> res;

    for (int i = 0; i < arr.size(); ++i) {
        window.insert(arr[i]);

        if (i >= k - 1) {
            res.push_back(*window.begin()); // minimum element
            window.erase(window.find(arr[i - k + 1])); // remove outgoing
        }
    }

    return res;
}
```

### ✅ Pros
- Simple and reliable.
- Easy to extend for both min and max.

### ❌ Cons
- Not optimal for very large N (O(N log K)).

---

## **3️⃣ Monotonic Deque Approach — O(N)** 🚀

### 🔹 Intuition

We use a **deque (double-ended queue)** to maintain indices of potential minimum elements for the current window.

We ensure that the deque:
- Stores indices in **increasing order of their values**.
- The **front** of the deque always holds the **smallest element** of the current window.
- Remove elements from the back that are **greater than or equal** to the current element (they can never be minimums again).

### 🔹 Steps

For each index `i`:
1. **Pop from front** if element is **out of the current window** (index < i - k + 1).  
2. **Pop from back** while `arr[dq.back()] >= arr[i]` to maintain increasing order.  
3. **Push current index** `i` into deque.  
4. Once we reach at least `k` elements (`i >= k - 1`), the **front** holds the index of the window’s minimum.

### ⏱️ Complexity

- **Time:** O(N) (each element is inserted and removed at most once)  
- **Space:** O(K)

---

### 💻 Code (C++)

```cpp
vector<int> slidingWindowMin_Deque(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> res;
    int n = arr.size();

    for (int i = 0; i < n; ++i) {
        // 1️⃣ Remove out-of-window elements
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // 2️⃣ Remove elements from back that are greater than current
        while (!dq.empty() && arr[dq.back()] >= arr[i])
            dq.pop_back();

        // 3️⃣ Add current element index
        dq.push_back(i);

        // 4️⃣ Record minimum for current window
        if (i >= k - 1)
            res.push_back(arr[dq.front()]);
    }

    return res;
}
```

---

### 🧩 Example Walkthrough

```
arr = [4, 2, 12, 3, 5], k = 3
Step-by-step deque status:

i=0 → dq = [4]
i=1 → pop_back(4) → dq = [2]
i=2 → dq = [2,12] → window [4,2,12] → min=2
i=3 → remove out-of-window(4) → dq=[2,12] → pop_back(12), arr[2]>arr[3] → dq=[3] → window [2,12,3] → min=2
i=4 → dq=[3,4] → window [12,3,5] → min=3
Result: [2,2,3]
```

---

## 🧩 Comparison Summary

| Approach | Time Complexity | Space | Ease | When to Use |
|-----------|----------------|--------|------|--------------|
| Brute Force | O(N × K) | O(1) | Very Easy | For small inputs |
| Multiset | O(N log K) | O(K) | Moderate | If simplicity preferred |
| **Monotonic Deque** | **O(N)** | O(K) | Harder initially | **Always use in production/interviews** |

---

## 🧠 Related Problems

| Problem | Platform | Concept |
|----------|-----------|----------|
| [Sliding Window Maximum (LeetCode 239)](https://leetcode.com/problems/sliding-window-maximum/) | LeetCode | Same concept with decreasing deque |
| [Sliding Window Median (LeetCode 480)](https://leetcode.com/problems/sliding-window-median/) | LeetCode | Use multiset or heaps |
| [Longest Continuous Subarray With Absolute Diff ≤ Limit (LeetCode 1438)](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/) | LeetCode | Uses 2 deques for min & max |

---

## 🧩 Real-Life Analogy

Imagine tracking the **cheapest stock price** in the last 5 days.  
You maintain a small list of recent prices but automatically discard:
- Old prices outside the window.
- Prices that are higher than a newer, smaller one.

That’s exactly what the **monotonic deque** does — it keeps only the *useful candidates* for the current window.

---

## 🏁 Takeaway

✅ Brute Force — Understand first for clarity  
✅ Multiset — Good for concept building  
✅ **Monotonic Deque — Optimal and Elegant**

When solving any **“K window min/max”** type question — immediately think **deque**!

file_path
