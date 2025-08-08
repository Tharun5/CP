# 📘 GCD (Greatest Common Divisor) - Reference

---

## 🔢 Definition

The **Greatest Common Divisor (GCD)** of two integers \( a \) and \( b \), written as `gcd(a, b)`, is the **largest positive integer that divides both** without leaving a remainder.

 
$$\gcd(a, b) = \max \{k > 0 : (k \mid a) \text{ and } (k \mid b) \}$$ 


(here the symbol " 
$\mid$ " denotes divisibility, i.e. " 
$k \mid a$ " means " 
$k$  divides  
$a$ ")

---

## 🧮 Euclidean Algorithm

### Recursive
```cpp
int gcd(int a, int b) {
    if (b != 0) return gcd(b, a % b);
    return abs(a);  // ensures non-negative result
}
```

### Iterative
```cpp
int gcd(int a, int b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return abs(a);
}
```

### STL (C++17+)
```cpp
#include <numeric>
int g = std::gcd(a, b);
```

---

## ✅ GCD Properties (Very Useful)

- **Commutative**: `gcd(a, b) = gcd(b, a)`
- **With 0**:
  - `gcd(a, 0) = |a|`
  - `gcd(0, 0) = 0` (usually defined as 0)
- **Associative**: `gcd(a, gcd(b, c)) = gcd(gcd(a, b), c)`
- **Divisibility**: `gcd(a, b)` divides both `a` and `b`
- **Common Divisor Rule**: If `x` divides both `a` and `b`, then `x` divides `gcd(a, b)`
- **Bézout’s Identity**: If `gcd(a, b) = d`, then there exist integers `x` and `y` such that `a * x + b * y = d`
- **Multiplicative with Co-primes**: If `gcd(a, b) = 1`, then `gcd(a * c, b) = gcd(c, b)`
- **LCM Relation**: `gcd(a, b) * lcm(a, b) = |a * b|`

---

## 📚 Applications in Coding Problems

### 1. Reducing Fractions
```cpp
int g = gcd(a, b);
a /= g;
b /= g;
```

### 2. Prefix & Suffix GCD (Excluding One Element)
```cpp
vector<int> pref(n + 1, 0), suff(n + 2, 0);

for (int i = 1; i <= n; i++)
    pref[i] = gcd(pref[i - 1], a[i - 1]);

for (int i = n; i >= 1; i--)
    suff[i] = gcd(suff[i + 1], a[i - 1]);

int ans = 0;
for (int i = 1; i <= n; i++)
    ans = max(ans, gcd(pref[i - 1], suff[i + 1]));
```

### 3. GCD of Differences (Make All Equal)
```cpp
int g = 0;
for (int i = 1; i < n; i++)
    g = gcd(g, abs(a[i] - a[i - 1]));
```

### 4. Coprime Check
```cpp
if (gcd(a, b) == 1) {
    // a and b are coprime
}
```

### 5. LCM using GCD
```cpp
int lcm(int a, int b) {
    return abs(a / gcd(a, b) * b);
}
```

---

## 🛠 Edge Cases to Handle

| Case             | Behavior                   |
|------------------|----------------------------|
| `gcd(a, 0)`      | Returns `abs(a)`           |
| `gcd(0, 0)`      | Usually defined as `0`     |
| Negative inputs  | Use `abs()` to normalize   |
| Large inputs     | Efficient up to 1e18       |

---

## 🔁 GCD of N Numbers
```cpp
int g = a[0];
for (int i = 1; i < n; i++)
    g = gcd(g, a[i]);
```

---

## 🚀 Performance

- **Time Complexity**: `O(log min(a, b))`
- Efficient for 64-bit integers

---

## 💡 Contest Tips

- Use prefix/suffix GCD for subarray queries
- If GCD of array is 1 → can't reduce further
- If GCD of array is > 1 → all elements divisible by that
- Combine with binary search or greedy methods
- Think GCD when seeing: "make equal", "common divisor", "simplify", etc.

---

## 🔐 Safe Implementation Template

```cpp
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return abs(a); // ensure positive result
}
```

Or using STL:
```cpp
#include <numeric>
int g = std::gcd(a, b);
```

---

## 🏁 Summary

Use this reference when:
- Simplifying numbers
- Dealing with divisibility
- Optimizing number transformations
- Solving array GCD problems in contests
