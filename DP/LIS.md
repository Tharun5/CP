# DP — (Optimized LIS)

> **Goal:** Cover advanced DP patterns that extend Forms 1–5:
> - Optimized LIS (O(N log N))
> - Counting LIS

---

## 0) Core Philosophy

> **When DP state transitions are regular, monotonic, or pattern-driven,  
we can optimize DP using data structures or automata.**

---

## 1) Optimized LIS — O(N log N)

### Observation
Track the **minimum possible tail value** for LIS of each length.

### Invariant
```
tail[k] = smallest ending value of an increasing subsequence of length k+1
```

`tail` is always sorted.

### Code
```cpp
vector<int> tail;
for(int x : nums){
    auto it = lower_bound(tail.begin(), tail.end(), x);
    if(it == tail.end()) tail.push_back(x);
    else *it = x;
}
return tail.size();
```

### Why it works
Smaller tail → more extension possibilities later.

---

## 2) Counting Number of LIS

### State
```
dp[i]  = length of LIS ending at i
cnt[i] = number of LIS ending at i
```

### Transition
```cpp
if(dp[j]+1 > dp[i]) {
    dp[i] = dp[j]+1;
    cnt[i] = cnt[j];
} else if(dp[j]+1 == dp[i]) {
    cnt[i] += cnt[j];
}
```

Final answer = sum of `cnt[i]` where `dp[i]` is maximum.

---

