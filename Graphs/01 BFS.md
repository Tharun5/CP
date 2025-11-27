# 01 BFS

### References-
https://medium.com/codestories/a-visual-guide-to-0-1-bfs-6f71b64d9a98 <br>
https://codeforces.com/blog/entry/22276
<br>

### Intro:
Given an undirected graph where every edge has a weight as either 0 or 1. 
The task is to find the shortest path from the source vertex to all other vertices in the graph.
In (V+E) Time

### Idea:
- The idea is to adapt BFS to efficiently handle graphs with binary weights (0 or 1) by using a deque instead of a queue.
- When we encounter an edge with weight 0, we add its destination to the front of the deque because it doesn't increase the distance.
- When we encounter an edge with weight 1, we add its destination to the back of the deque because it increases the distance by one unit.

<br>   

```cadence
void 01BFS(int sur){
    vector<int> dis(n, 1e9);

    deque<int> dq;
    dq.push_back(sur);
    dis[sur] = 0;

    while(!dq.empty()){
        int cur = dq.front();
        dq.pop_front();

        for(auto ch: g[cur]){
            int edg = ch.first;
            int wt = ch.second;

            if(dis[edg] > dis[cur] + wt){
                dis[edg] = dis[cur]+ wt;
                if(wt == 0){
                    dq.push_front(edg);
                }else{
                    dq.push_back(edg);
                }
            }
            
        }
    }
    cout<<dis[n-1];
}
```

### Problems:
- https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/
- https://leetcode.com/problems/find-a-safe-walk-through-a-grid/
