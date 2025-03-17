# Grid DP

- Each cell (i,j) -> Can represent a state/Subproblem
- Key Idea: Compute the result for a given cell based on the previously computed results of neighboring cells.

Example:
To a Grid to find no. of ways to reach from top left to bottom right
State: 
Consider a cell (i,j) which a sub-problem, So it will be the no. of ways to reach from (i,j) to (m-1,n-1)
Transition:
It depends on the answers of its right and down. Thus it will be summation.

Note:
+ In grid problems to understand somtimes why DP wont work (When we can go to all neighboring cells in all directions)
- DP only works with a DAG, here we have a graph with cycles.
- Like it only works if we have dependency on two directions like right and bottom.
- If you see dependency on four directions then we might not memoize the solution as the optimal answer can be found only after calculating all the nodes. But this has cyclic dependency.



Basic Problems:
1. https://leetcode.com/problems/unique-paths/description/
2. https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/ (Tricky Handling) Variation of [MaxProductSubarray](https://leetcode.com/problems/maximum-product-subarray/description/) with Grid.



References:
Priyansh DP Playlist
CodeStoryWithMIK
