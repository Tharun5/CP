//Refer:https://unacademy.com/class/graph-theory-lecture-2/4GHKRNKV
// Time: O(mlogn) m-edges, logn from set (BFS takes O(n+m) so dijkstras takes O(nlogn+mlogn) as edges > no. of nodes we take as mlogn)


// Using Set
vector<pair<int,int>> grp[10001];
int dist[10001];
const int INF = 1e9;

void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        grp[u].push_back({w,v});
        grp[v].push_back({w,u});
    }

    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }

    set<pair<int,int>> s;//{dist,node}
    s.insert({0,1});
    dist[1]=0;

    while(!s.empty()){
        int dis=s.begin()->first;
        int ver=s.begin()->second;
        s.erase(s.begin());
        for(auto chld: grp[ver]){
            int newdis = dis+chld.first;
            int newver = chld.second;
            if(newdis < dist[newver]){
                s.erase({dist[newver],newver});
                dist[newver]=newdis;
                s.insert({newdis,newver});
            }
        }
    }

    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";
}



// Using Priority Queue

void solve(){
    int n, m;
    cin>>n>>m;

    g.resize(n+1);
    dis.resize(n+1, 1e18);

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b, c});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});
    dis[1] = 0;

    while(!pq.empty()){
        int cur = pq.top().second;
        int curwt = pq.top().first;
        pq.pop();

        if(curwt > dis[cur]) continue;

        for(auto ch: g[cur]){
            int edg = ch.first;
            long long edwt = ch.second;

            if(dis[edg] > dis[cur] + edwt){
                dis[edg] = dis[cur] + edwt;
                pq.push({dis[edg], edg});
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }

}



/*
+ When I am visiting a node from set in algo for sure there will not be any less dist apart from what it has.
+ Means if node is processed from set, there is no shortest path for this node apart from what dist it has
+ Bcoz, if it is available then that will be visited first

+ Why Dijkstra's Algo wont work for neg weights
   -2
0 -----1

Here it goes inf loop, as we dont maintain visited array in algo
every time the dis will be less than previous as these are neg values.

*/
