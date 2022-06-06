#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
const int inf = 1e9;
//bellman ford algorithm is used to calculate the minimum distance from a node to another node
int main(){
    int n, m; cin>>n>>m;       //n is the count of nodes m is the count of edges
    vector<array<int,3>> edge;
    for(int i=0;i<m;i++){
        int u,v,w;                     //w is the weight of the edge connecting node from u to v
        cin>>u>>v>>w;
        edge.push_back({u,v,w});       //directed graph algorithm works also for undirected graph
    }
    int start; cin>>start;
    vector<int> dist(n,inf);
    dist[start]=0;                     //the distances are being calculated from node 0
    for(int i=0;i<n-1;i++){            //if we run the loop for more than m-1 times and values change is seen even after that
        bool detect = true;
        for(auto j : edge){            //then it implies that there is a negative edge cycle in the graph
            if(dist[j[1]]>dist[j[0]]+j[2])
                detect = false;
            dist[j[1]]=min(dist[j[1]],dist[j[0]]+j[2]);
        }
        if(detect)break;
    }
    for(auto i : dist){
        cout<<i<<' ';
    }
    return 0;
}