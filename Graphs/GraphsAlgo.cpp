// Graph Algo's

/*

Refer: https://leetcode.com/discuss/post/3365918/graphs-all-algorithms-theroy-and-impleme-ktp5/
Graphs | All Algorithms | Theroy And Implementation

*/

vector<int> adj_list[N];
bool visited[N];
int dist[N];

// DFS
void dfs(int cur){
	visited[cur]=true;
	for(int edj:adj_list[cur]){
		if(visited[edj]) continue;
		dfs(edj);
	}
}

//--------------------------------------------------------------------------

// Checks Bipartite Graph using dfs
int col[100];
// Returns true if Bipartite
bool dfs(int cur,int color){
    visited[cur]=true;
    col[cur]=color;
    for(int edj:adj_list[cur]){
        if(visited[edj]){
            if(col[edj]==color) return false;
        }else{
            if(!dfs(edj,!color)){
                return false;
            }
        }
    }
    return true;
}
//--------------------------------------------------------------------------

// BFS
void bfs(int source){
    queue<int> q;
    q.push(source);
    dist[source]=0;
    visited[source]=true;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int edj:adj_list[cur]){
            if(!visited[edj]){
                q.push(edj);
                visited[edj]=true;
                dist[edj]=dist[cur]+1;
            }
        }
    }
}
/*
BFS Time Complexity: O(V + E)
1️⃣ Understanding the BFS Code Structure

while (!q.empty()) {           // Runs O(V) times (once per node)
    int node = q.front();
    q.pop();
    
    for (int neighbor : adj[node]) {  // Iterates over neighbors (edges)
        if (!visited[neighbor]) {
            q.push(neighbor);
            visited[neighbor] = true;
        }
    }
}

2️⃣ Why BFS is NOT O(V * E)?
The outer loop (while) runs O(V) times (each node dequeued once).
The inner loop (for neighbors) does NOT iterate over all E edges for every node.
Instead, across all nodes, we iterate only once per edge → O(E) total.

3️⃣ Proof: Summing Up the Work
Each edge appears once per endpoint in the adjacency list.
The total number of inner loop iterations across all nodes is O(2E).
Since we also perform enqueue & dequeue for V nodes, we add O(V).
Thus it is addition.

4️⃣ Final Complexity Derivation
Processing nodes (enqueue/dequeue) → O(V)
Processing edges (adjacency list traversal) → O(E)
Total = O(V) + O(E) = O(V + E) ✅
*/

//--------------------------------------------------------------------------

// Grid DFS
int grid[1005][1005];
bool vis[1005][1005];
int n;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool valid(int r,int c){
    if(r<1 || r>n || c<1 || c>n) return false;
    if(vis[r][c]) return false;
    if(grid[r][c]==1) return false;
    return true;
}

void dfs(int r,int c){
    vis[r][c]=true;
    for(int i=0;i<4;i++){
        if(valid(r+dx[i],c+dy[i]))
            dfs(r+dx[i],c+dy[i]);
    }
}
//dfs(1,1)
//--------------------------------------------------------------------------

// Grid BFS
int grid[10005][10005];
int dist[10005][10005];
bool vis[10005][10005];
int n,m;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool valid(int i,int j){
    if(i<1 || j<1 || i>n || j>m) return false;
    if(vis[i][j])return false;
    return true;
}

void bfs(int i,int j){
    vis[i][j]=true;
    dist[i][j]=0;
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()){
        int t1=q.front().first;
        int t2=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int p1=t1+dx[k];
            int p2=t2+dy[k];
            if(valid(p1,p2)){
                vis[p1][p2]=true;
                dist[p1][p2]=dist[t1][t2]+1;
                q.push({p1,p2});
            }
        }

    }
}



//---------------------------------------------------------------------------------------------

//MultiSoucre BFS
/* Same Like grid BFS but if we want to BFS on various soucres in grid, 
   Take a root and assume like root has all edges as soucres to which we want BFS.
   So push all soucres in queue and do One BFS for whole
   Then node dist-1 will be their distance
   
   Refer(first 30 mins): https://unacademy.com/class/graph-theory-lecture-2/4GHKRNKV
   
*/

//---------------------------------------------------------------------------------------------

// Find Bridges in Graph
vector<int> g[1005];
bool vis[1005];
int in[1005],low[1005];
int timer;

void dfs(int cur,int par){
    vis[cur]=true;
    in[cur]=low[cur]=timer;
    timer++;
    for(auto chld:g[cur]){
        if(vis[chld] && chld==par)continue;
        else if(vis[chld]){
            low[cur]=min(low[cur],in[chld]);
        }else{
            dfs(chld,cur);
            if(in[cur]<low[chld]){
                cout<<cur<<"--"<<chld<<" is Bridge"<<endl;
            }
            low[cur]=min(low[cur],low[chld]);
        }
    }
}

//--------------------------------------------------------------------------

// Articulation Points
vector<int> g[1000005];
bool vis[1000005];
int in[1000005],low[1000005];
int timer;
set<int> s; // As cnt will take single articulation point morethan once

void dfs(int cur,int par){
    vis[cur]=true;
    in[cur]=low[cur]=timer;
    timer++;
    int children=0;
    for(auto chld:g[cur]){
        if(chld==par) continue;
        else if(vis[chld]){
            low[cur]=min(low[cur],in[chld]);
        }else{
            dfs(chld,cur);
            if(in[cur]<=low[chld] && par!=-1){
                s.insert(cur);
            }
            children++;
            low[cur]=min(low[cur],low[chld]);
        }
    }
    if(par==-1 && children>1)s.insert(cur);;
}

//-----------------------------------------------------------------------------------

// Topological Sort (Kahn's Algorithm)
vector<int> g[1000005];
int in[1000005];
vector<int> ans;

void topsort(int n){
    queue<int> q;  //For sort order of vertices Use Priority Queue
    for(int i=1;i<=n;i++)
        if(in[i]==0){
            q.push(i);
        }
    while(!q.empty()){
        int cur=q.front();
        ans.pb(cur);
        q.pop();
        for(auto x:g[cur]){
            in[x]--;
            if(in[x]==0){
                q.push(x);
            }
        }
    }
}

void solve(){
    int n,edg;
    cin>>n>>edg;
    for(int i=0;i<edg;i++){
        int u,v;cin>>u>>v;
        g[u].pb(v);
        in[v]++;
    }
    topsort(n);
    if(ans.size()!=n)cout<<"Cant Perfom Topological Sort";
    else for(auto x:ans)cout<<x<<" ";
}
//----------------------------------------------------------------------------------


/* 
Refer: 
DFS tree of a graph-Applications: https://codeforces.com/blog/entry/68138

*/

