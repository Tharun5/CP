# Intervals Notes

---

## 0) Mental Model

Intervals are usually one of these:
- **Union / merge**: combine overlaps into disjoint blocks
- **Intersection**: overlap of two (or more) schedules
- **Max overlap / resources**: “minimum rooms”, “max simultaneous”, “capacity exceeded?”
- **Greedy selection**: “pick maximum non-overlapping”, “min removals”, “min arrows”
- **Gaps / free time**: “common free time”, “days without meetings”
- **K schedules**: multiple employees/resources → heap or sweep line

When stuck, ask:
1. Do I need **output intervals** (merged, intersection, free gaps) or just a **count** (rooms, removals, days)?
2. Is the input **already sorted**? (then two pointers / heap shines)
3. Is it **two lists** or **many lists**?
4. Are endpoints **inclusive** `[l, r]` or half-open `[l, r)`? (off-by-one rules!)

---

## 1) Core Patterns (with templates)

### A) Merge Intervals (Union)
**Use when:** “merge overlapping intervals”, “busy time union”, “compress schedule”.

**Key idea:** sort by start, keep a running `[curL, curR]`.

**Template**
```cpp
sort(intervals.begin(), intervals.end()); // by start then end
vector<vector<int>> ans;
for (auto &in : intervals) {
    if (ans.empty() || in[0] > ans.back()[1]) ans.push_back(in);
    else ans.back()[1] = max(ans.back()[1], in[1]);
}
```

**Solved**
- LC 56 Merge Intervals
- Used inside free-time problems

---

### B) Insert Interval
**Use when:** already merged/non-overlapping list + insert 1 interval.

**Template**
```cpp
vector<vector<int>> ans;
int i=0, n=intervals.size();
int L=newI[0], R=newI[1];

// 1) add all strictly before
while (i<n && intervals[i][1] < L) ans.push_back(intervals[i++]);

// 2) merge overlaps
while (i<n && intervals[i][0] <= R) {
    L = min(L, intervals[i][0]);
    R = max(R, intervals[i][1]);
    i++;
}
ans.push_back({L,R});

// 3) add rest
while (i<n) ans.push_back(intervals[i++]);
```

**Solved**
- LC 57 Insert Interval

---

### C) Two Lists → Intersection (Two Pointers)
**Use when:** two sorted lists, need overlap pieces.

**Rule:** intersection exists if `max(st1, st2) <= min(en1, en2)`.

**Template**
```cpp
int i=0, j=0;
while (i<n && j<m) {
    int L = max(A[i][0], B[j][0]);
    int R = min(A[i][1], B[j][1]);
    if (L <= R) ans.push_back({L,R});
    if (A[i][1] < B[j][1]) i++;
    else j++;
}
```

**Solved**
- LC 986 Interval List Intersections

---

### D) “Minimum Rooms / Max Overlap” (Meeting Rooms II)
Two standard ways:

#### D1) Min-Heap on end times
**Use when:** need **max simultaneous active intervals**; scheduling/resources.

**Template**
```cpp
sort(intervals.begin(), intervals.end(),
     [](auto &a, auto &b){ return a[0] < b[0]; });

priority_queue<int, vector<int>, greater<int>> pq; // end times
int ans = 0;

for (auto &in : intervals) {
    while (!pq.empty() && pq.top() <= in[0]) pq.pop(); // free rooms
    pq.push(in[1]);
    ans = max(ans, (int)pq.size());
}
```

#### D2) Sweep Line (difference array)
**Use when:** only need max overlap / capacity check (no room assignment).

Create events:
- `+1` at start
- `-1` at end (tie handling important)

**Half-open vs inclusive note**
- If intervals are **[start, end)**: do `+1 at start`, `-1 at end`
- If intervals are **[start, end]** (inclusive): do `-1 at end+1` (most robust)

**Template (inclusive endpoints)**
```cpp
vector<pair<int,int>> ev;
for (auto &in: intervals) {
    ev.push_back({in[0], +1});
    ev.push_back({in[1] + 1, -1});
}
sort(ev.begin(), ev.end());
int cur=0, best=0;
for (auto &e: ev) { cur += e.second; best = max(best, cur); }
```

**Solved**
- Meeting Rooms II (heap + sweep)
- Car Pooling (capacity via sweep)
- Count Days Without Meetings (can be greedy merge or sweep)

---

### E) Greedy “Pick max non-overlapping” / “Min removals”
This is the classic **sort by end time** family.

#### E1) Maximum number of non-overlapping intervals
Pick the interval that **finishes earliest**, then repeat.

#### E2) Minimum intervals to remove to eliminate overlaps
Equivalent to: `remove = n - maxNonOverlap`.

**Template**
```cpp
sort(intervals.begin(), intervals.end(),
     [](auto &a, auto &b){ return a[1] < b[1]; });

int keep = 0;
int lastEnd = INT_MIN;
for (auto &in: intervals) {
    if (in[0] >= lastEnd) { keep++; lastEnd = in[1]; }
}
return n - keep;
```

**Solved**
- LC 435 Non-overlapping Intervals (min removals)
- LC 452 Minimum Number of Arrows to Burst Balloons (same greedy)
  - treat each balloon as interval; arrow at chosen end hits all overlapping

---

### F) Remove Covered Intervals (sort trick)
**Key sorting:** increasing start, and for equal start **decreasing end**.  
Then an interval is covered iff `end <= maxEndSoFar`.

**Template**
```cpp
sort(intervals.begin(), intervals.end(),
     [](auto &a, auto &b){
         if (a[0] == b[0]) return a[1] > b[1];
         return a[0] < b[0];
     });

int maxEnd = -1;
int covered = 0;
for (auto &in: intervals) {
    if (in[1] <= maxEnd) covered++;
    else maxEnd = in[1];
}
return n - covered;
```

**Solved**
- LC 1288 Remove Covered Intervals

Why the tie rule matters:
- `[1,10]` should come before `[1,5]` so `[1,5]` is correctly counted as covered.

---

### G) “Free time / Gaps” pattern
**Use when:** find common free time across multiple busy schedules, or days without meetings.

Two approaches:

#### G1) Merge all busy intervals → output gaps
1) Flatten all busy intervals  
2) Sort by start  
3) Merge  
4) Gaps are between merged blocks (+ boundaries)

This is simplest when total intervals not huge.

#### G2) K-way merge with heap (optimized)
If each employee list is already sorted and non-overlapping:
- Push first interval of each employee into a min-heap by start
- Pop the earliest start, update merged busy segment on the fly
- Push that employee’s next interval
- Emit gaps whenever `nextStart > currentBusyEnd + 1` (for inclusive time)

Complexity: `O(M log N)` where `M=total intervals`, `N=employees`.

**Solved (Coding Ninjas)**
- “Common free intervals for all setters”

---

### H) “Attend max events” (Day sweep + min-end heap)
**Problem type:** each event is a window `[start, end]`, you can pick **one day** inside it, only one event per day → maximize count.

**Greedy invariant**
On each day, among all available events (`start <= day`), attend the one with **smallest end** (most urgent).

**Template**
```cpp
sort(events.begin(), events.end()); // by start
priority_queue<int, vector<int>, greater<int>> pq; // end times

int i=0, n=events.size();
int day = events[0][0];
int ans=0;

while (i<n || !pq.empty()) {
    if (pq.empty() && i<n) day = max(day, events[i][0]);

    while (i<n && events[i][0] <= day) pq.push(events[i++][1]);

    while (!pq.empty() && pq.top() < day) pq.pop(); // expired

    if (!pq.empty()) {
        pq.pop(); ans++; day++;
    }
}
```

**Solved**
- LC 1353 Maximum Number of Events That Can Be Attended

---

## 2) When to Use What (Decision Guide)

### If the task is **output merged busy times**
→ **Merge Intervals** (sort + union).

### If task is **intersection of two calendars**
→ **Two pointers** (LC 986 style).

### If task is **max simultaneous / min rooms / capacity**
- Need just max overlap count? → **Sweep line**
- Need assignment / “which room” behavior? → **Heap of end times**

### If task is **pick max compatible intervals / minimize removals**
→ **Sort by end** greedy.

### If task is **covered intervals**
→ Sort by (start asc, end desc) + track maxEnd.

### If task is **common free time across many people**
- Lists already sorted? → **Heap k-way merge**
- Not sorted / huge flatten? → Flatten + merge (still fine if M manageable)

### If task is **choose one day inside each window to maximize count**
→ **Day sweep + min-end heap** (LC 1353 family)

---

## 3) Sweep Line: What it is & why it works

“**Sweep line**” means: imagine a vertical line moving left→right across time.  
At every event boundary (start/end), the set of active intervals changes.

We encode that change as:
- `+1` when an interval becomes active
- `-1` when it stops being active

Then prefix-summing in sorted time order gives the active count at each segment.

**Why the name?**
- In computational geometry, a line “sweeps” a plane to process intersections.
- In intervals, we sweep time similarly.

**Reference article**
- https://dilipkumar.medium.com/sweep-line-algorithm-e1db4796d638

**Tie-breaking**
- Half-open `[l, r)`: end happens at `r`, start at `l` → safe as-is
- Inclusive `[l, r]`: represent end as `r+1` for correctness (recommended)

---

## 4) Greedy Proof Cheats (fast interview reasoning)

### “Sort by end” proof sketch (435/452)
- If you want maximum non-overlapping intervals, always pick the interval with the earliest finish.
- Exchange argument: if an optimal solution picked a later-ending interval first, swap it with earlier-ending one → leaves at least as much room for remaining intervals.

### “Min-end heap” proof sketch (Meeting rooms / max events)
- If multiple choices exist now, pick the one that ends sooner; it’s the most constrained.
- Postponing early-ending items risks losing them forever; postponing late-ending items is safe.

### “Covered intervals” sorting trick proof sketch
- Sorting by start asc ensures any potential cover comes earlier.
- For equal starts, sorting end desc ensures the bigger one comes first so the smaller is detected as covered.

---

## 5) Problems You Covered (Quick Index)

### Merge / Insert / Union
- LC 56 Merge Intervals
- LC 57 Insert Interval

### Meeting rooms / overlaps / capacity
- LC 252 Meeting Rooms I (overlap check after sort)
- LC 253 Meeting Rooms II (heap or sweep line)
- LC 1094 Car Pooling (sweep line capacity)
- LC 3169 Count Days Without Meetings (merge or sweep)

### Greedy by end
- LC 435 Non-overlapping Intervals (min removals)
- LC 452 Min Arrows to Burst Balloons
- LC 1288 Remove Covered Intervals (special sort)

### Intersection / two pointers
- LC 986 Interval List Intersections

### Gaps / free time
- Coding Ninjas “Problem Setters Free Intervals” (k-way merge / sweep)

### Day window scheduling
- LC 1353 Max Events Attended (day sweep + min-end heap)

### Further standard Problems
 - https://github.com/Chanda-Abdul/Several-Coding-Patterns-for-Solving-Data-Structures-and-Algorithms-Problems-during-Interviews/blob/main/%E2%9C%85%20%20Pattern%2004%20:%20Merge%20Intervals.md
---

## 6) Common Pitfalls Checklist

- ✅ Clarify inclusive vs half-open:
  - CN free-time uses **inclusive integers**; often need `end+1` trick
- ✅ For sweep line, handle tie properly (end before start if needed)
- ✅ Avoid `O(n^2)` unless constraints allow
- ✅ For heap scheduling: always pop expired intervals before selecting
- ✅ For “free time”, define boundaries (0..1e8) and whether endpoints are allowed

---

## 7) Tiny Pattern Recognition Prompts

If prompt says…
- “merge/insert/covered” → sorting + one pass
- “minimum rooms/resources” → max overlap
- “capacity exceeded” → sweep line
- “pick maximum number” → greedy by earliest end
- “free time common” → union busy then invert → gaps
- “two calendars intersection” → two pointers
- “choose a day inside window” → day sweep + min-end heap

