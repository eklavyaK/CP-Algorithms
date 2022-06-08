#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
//The basic idea behind Prim's algorithm is that among all the edges that connect a node to the tree, the one with lowest weight should be used to connect it with the tree
ll primsMST(int src, vector<vector<array<int,2>>> edge){
    ll cost = 0;
    int inf = 1e9+5;
    int n=edge.size();
    vector<int> dist(n);
    vector<int> parent(n);
    for(int i=0;i<=n;i++){
        dist[i]=inf;
    }
    dist[src]=0;
    parent[src]=src;
    vector<int> visited(n);
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