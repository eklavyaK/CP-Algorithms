#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
//The basic idea behind Prim's algorithm is that among all the edges that connect a node to the tree, the one with lowest weight should be used to connect it with the tree
ll primsMST(int src, vector<vector<array<int,2>>> edge){
    ll cost = 0;
    int inf = 1e9+5;
    int n=edge.size();
    vector<int> dist(n+1,inf);
    vector<int> parent(n+1);
    dist[src]=0;
    parent[src]=src;
    vector<int> visited(n+1);
    set<array<int,2>> s;
    s.insert({0,src});
    while(!s.empty()){
        auto node = *s.begin();
        s.erase(node);
        cost+=node[0];
        visited[node[1]]=1;
        //cout<<node[1]<<' '<<parent[node[1]]<<' '<<node[0]<<endl;
        for(auto i : edge[node[1]]){
            if(visited[i[0]]){
                continue;
            }
            if(dist[i[0]]>i[1]){
                s.erase({dist[i[0]],i[0]});
                s.insert({i[1],i[0]});
                dist[i[0]]=i[1];
                parent[i[0]]=node[1];
            }
        }
    }
    return cost;
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<array<int,2>>> edge(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[u].push_back({v,w});
        edge[v].push_back({u,w});
    }
    cout<<primsMST(0, edge)<<endl;
    return 0;
}
/*******************************************SIMPLIFIED VERSION*************************************/
// const int N = 1e5+5, inf = 1e9+5;
// vector<vector<pair<int,int>>> node(N);

// int main(){
//     rapid_iostream;
//     int n,m; cin>>n>>m;
//     while(m--){
//         int u,v,c; cin>>u>>v>>c;
//         node[u].push_back({v,c});
//         node[v].push_back({u,c});
//     }
//     vector<int> cost(n+1,inf);
//     ll ans = 0; 
//     cost[1]=0;
//     bool check[n+1]{};
//     set<pair<int,int>> st;
//     st.insert({0,1});
//     while(!st.empty()){
//         auto [c,u] = *st.begin();
//         ans += c; check[u]=true;
//         for(auto [nod,cos] : node[u]){
//             if(!check[nod]){
//                 if(cost[nod]>cos){
//                     st.erase({cost[nod],nod});
//                     cost[nod] = cos;
//                     st.insert({cost[nod],nod});
//                 }
//             }
//         }
//         st.erase({c,u});
//     }

//     for(int i=1;i<=n;i++){
//         if(cost[i]==inf){
//             print("IMPOSSIBLE");
//             return 0;
//         }
//     }
//     cout<<ans;
//     return 0;
// }