#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
const int inf = 1e9+5;
int main(){                       //Implementation of floyd warshall algorithm
    int n,m; cin>>n>>m;
    vector<vector<int>> dist(n+1,vector<int>(n+1,inf)); //distance matrix
    for(int i=0;i<=n;i++){
        dist[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=min(dist[u][v],w);
        dist[v][u]=min(dist[v][u],w);
    }
    for(int k=0;k<n;k++){        //Basically distance between each pair of nodes are checked with every other node to relax the 
        for(int j=0;j<n;j++){       //distance between the nodes if possible
            for(int i=0;i<n;i++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cout<<dist[i][j]<<' ';
        cout<<endl;
    }

    return 0;
}