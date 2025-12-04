# Disjoint Set (Union-Find Algorithm)

### References-
Youtube CodeStoryWithMIK: [Concepts and Problems](https://www.youtube.com/watch?v=iH3XVIVzl7M&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=19&pp=iAQB)
<br>
### Intro:
- Two sets are called disjoint sets if they don’t have any element in common. The disjoint set data structure is used to store such sets.

It supports following operations:
1. Merging two disjoint sets to a single set using **Union** operation.
2. Finding representative of a disjoint set using **Find** operation.
3. Check if two elements belong to same set or not. We mainly find representative of both and check if same.
<br>   

```cadence
class DisjointSet{
        vector<int> parent;
        vector<int> rank;
        vector<int> size;
        
        public:
            DisjointSet(int n){
                rank.resize(n+1, 0);
                size.resize(n+1, 1);
                parent.resize(n+1);
                for(int i=0;i<=n;i++){
                    parent[i]=i;
                }
            }
            
            int find(int u){
                if(parent[u]==u) 
                    return u;
                
                return parent[u]=find(parent[u]);
            }

            // Rank here represents - Height of tree, Graph
            void unionByRank(int u, int v){
                int parent_u = find(u);
                int parent_v = find(v);
                
                // Means they are in same set
                if(parent_u==parent_v) return;
                
                if(rank[parent_u] > rank[parent_v]){
                    parent[parent_v] = parent_u;
                }else if(rank[parent_u] < rank[parent_v]){
                    parent[parent_u] = parent_v;
                }else{
                    parent[parent_v] = parent_u;
                    rank[parent_u]++;
                }
            }
            
            void unionBySize(int u, int v){
                int parent_u = find(u);
                int parent_v = find(v);
                
                if(parent_u == parent_v) return;
                
                if(size[parent_u] > size[parent_v]){
                    parent[parent_v] = parent_u;
                    size[parent_u] += size[parent_v];
                }else{
                    parent[parent_u] = parent_v;
                    size[parent_v] += size[parent_u];
                }
            }
    };
```

<br>

## Time Complexity:
- For Find, Path compression O(n) -> O(logn)
- For Union ->  O(α(N)) which is Inverse Ackermann's Function
- Which is almost logn or constant.
