//Refer:https://unacademy.com/class/graph-theory-lecture-2/4GHKRNKV
// Time: O(mlogn) m-edges, logn from set (BFS takes O(n+m) so dijkstras takes O(nlogn+mlogn) as edges > no. of nodes we take as mlogn)

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



/*
+ Why Dijkstra's Algo wont work for neg weights
   -2
0 -----1

Here it goes inf loop, as we dont maintain visited array in algo
every time the dis will be less than previous as these are neg values.

*/
