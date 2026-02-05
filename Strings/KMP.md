# KMP (Knuth–Morris–Pratt) Algorithm — Notes

> **Goal:** Efficiently find a pattern inside a text in **O(N + M)** time by reusing previously matched prefix information instead of re-checking characters.

---

## 0) The Problem KMP Solves

Given:
- Text `S` of length `N`
- Pattern `P` of length `M`

Naive approach:
- Try matching `P` at every position in `S`
- Worst case: **O(N × M)**

KMP reduces this to **O(N + M)**.

---

## 1) Core Idea

> **On mismatch, don’t restart from scratch.  
Reuse what you already matched.**

If:
```
S[i-j ... i-1] == P[0 ... j-1]
```
and mismatch happens at `P[j]`,  
then a prefix of `P` is also a suffix of the matched part → jump there.

---

## 2) LPS Array (Prefix Function)

```
lps[i] = length of the longest proper prefix of P[0..i]
         which is also a suffix of P[0..i]
```

LPS tells **how much of the pattern we can reuse** after mismatch.

---

## 3) LPS Construction (Intuition)

Maintain:
- `st` = length of current matching prefix

Rules:
- Match → extend (`st++`)
- Mismatch → fallback (`st = lps[st-1]`)

---

## 4) LPS Construction Code

```cpp
void findLPS(const string& p, vector<int>& lps){
    int n = p.length();
    lps[0] = 0;

    int st = 0;
    for(int i = 1; i < n; i++){
        if(p[st] == p[i]){
            st++;
            lps[i] = st;
        }else{
            while(st > 0 && p[st] != p[i]){
                st = lps[st-1];
            }
            if(p[st] == p[i]){
                st++;
                lps[i] = st;
            }else{
                lps[i] = 0;
            }
        }
    }
}
```

---

## 5) KMP Search Algorithm

### Invariant
```
S[i-j ... i-1] == P[0 ... j-1]
```

### Search Logic
- Match → move both pointers
- Mismatch:
  - If `j > 0` → `j = lps[j-1]`
  - Else → `i++`

---

## 6) KMP Search Code

```cpp
bool findPattern(const string& s, const string& p){
    int n = s.length();
    int m = p.length();
    if(m == 0) return true;

    vector<int> lps(m);
    findLPS(p, lps);

    int i = 0, j = 0;
    while(i < n){
        if(s[i] == p[j]){
            i++;
            j++;
            if(j == m) return true;
        }else{
            if(j > 0) j = lps[j-1];
            else i++;
        }
    }
    return false;
}
```

---

## 7) Why KMP is O(N + M)

- Each character in `S` is processed once
- `j` never moves backwards more than `lps`
- Total work is linear

---

## 8) Relation to Automata & DP

- LPS is a compact automaton
- Automata DP uses the same fallback idea
- Prefix reuse is a DP on pattern itself

---

## 9) Common Pitfalls

- Using `lps[i-1]` instead of `lps[st-1]`
- Forgetting to update `st` after fallback match
- Restarting from pattern index 0
- Writing overly complex loops

---

## 10) When to Use KMP

- Substring search
- Avoid O(N×M)
- Pattern reuse required
- Prefix/suffix structure present

---

## 11) Interview Sound-bite

> “KMP avoids redundant comparisons by using prefix-suffix reuse, achieving linear-time pattern matching.”

---

## Refer

- [KMP Tushar Youtube](https://www.youtube.com/watch?v=GTJr8OvyEVQ)
- Problem: [LC 28](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

