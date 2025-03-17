# Grid DP

- Each cell (i,j) -> Can represent a state/Subproblem
- Key Idea: Compute the result for a given cell based on the previously computed results of neighboring cells.

Example:
To a Grid to find no. of ways to reach from top left to bottom right
State: 
Consider a cell (i,j) which a sub-problem, So it will be the no. of ways to reach from (i,j) to (m-1,n-1)
Transition:
It depends on the answers of its right and down. Thus it will be summation.


Basic Problems:
1. https://leetcode.com/problems/unique-paths/description/
2. https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/ (Tricky Handling) Variation of [https://leetcode.com/problems/maximum-product-subarray/description/](MaxProductSubarray) in a Grid.



References:
Priyansh DP Playlist
CodeStoryWithMIK
