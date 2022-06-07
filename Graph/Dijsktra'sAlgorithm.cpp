#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
int inf = 1e9+5;                  //dijsktra's algorithm works for positive weights only
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<array<int,2>>> edge(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[u].push_back({v,w});
        edge[v].push_back({u,w});             //comment out this line in case of directed graph
    }
    int start; cin>>start;
    vector<int> dist(n+1,inf);
    dist[start]=0;
    set<pair<int,int>> s;
    s.insert({0,start});
    while(!s.empty()){
        auto [x,y] = *s.begin();              //taking the node with minimum distance from source then trying to reduce the distance of 
        s.erase({x,y});                       //all other nodes connected to it using it's distance                  
        for(auto [a,b] : edge[y]){
            if(dist[a]>x+b){
                s.erase({dist[a],a});
                dist[a]=x+b;
                s.insert({dist[a],a});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[i]<inf){
            cout<<dist[i]<<' ';
        }
        else cout<<-1<<' ';
    }
    return 0;
}