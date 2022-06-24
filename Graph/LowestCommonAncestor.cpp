#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;

const int N = 2e5+5, LOG = 32;
int par[N][LOG], vis[N], dep[N];
vector<vector<int>> node(N);

void dfs(int u){
    for(auto i : node[u]){ //in case of tree dfs and bfs both work perfectly while finding depth or parent but in case of graph we prefer bfs
        dep[i] = dep[u]+1;
        par[i][0] = u;
        for(int j=1;j<LOG;j++){
            par[i][j]=par[par[i][j-1]][j-1];
        }
        dfs(i);
    }
}
int lca(int u, int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }
    int k = dep[u]-dep[v]; 
    for(int i=0;i<LOG;i++){               //bringing u and v at the same level
        if(k & (1<<i)){
            u = par[u][i];
        }
    }
    if(u==v)return u;
    for(int i=LOG-1;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int m; cin>>m;                  //number of children of i
        for(int j=0;j<m;j++){
            int k; cin>>k;              //children of i
            node[i].push_back(k);
        }
    }
    vis[0]=1;
    dfs(0);
    int q; cin>>q;
    while(q--){
        int u,v; cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
    return 0;
}