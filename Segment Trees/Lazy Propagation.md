# Lazy Propagation
Lazy propagation is an optimization technique used with segment trees to efficiently handle range updates. While a standard segment tree can perform point updates and range queries in O(log N) time, range updates without lazy propagation would require updating all affected nodes, leading to O(N) time complexity in the worst case for each range update.

**Lazy Array:**<br>
An additional array, often called a **"lazy array" or "lazy tree,"** is maintained alongside the segment tree. This array stores information about pending updates that have not yet been propagated down to the child nodes. Initially, all values in the lazy array are typically set to a "no-op" value (e.g., zero for sum updates).
<br>
``` cadence

```
