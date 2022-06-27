#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
/*Eulerian Circuit is a path which starts at a node and goes through each and every edge 'exactly' once and terminates at the starting node.
Eulerian Circuit will exist only if degree of every node is even and all the vertices are connected in the same component.

Eulerian Path is bit different from Eulerian circuit. Eulerian Path is a path connecting two vertices (not necessarily same) where path goes
through each and every edge exactly once.

Below is the code to find a eulerian circuit in the given graph, or declare it's 'impossible to find'
*/
const int N = 1e5+5;
vector<int> graph[N];
unsigned int n,m, cnt[N], track[N];
map<int,bool> edge[N];
vector<int> route;
bool check(){
    for(int i=1;i<=n;i++)
    if(cnt[i]%2)return false;
    int vis[n+1]{};
    queue<int> bfs;
    bfs.push(1);vis[1]=1;
    while(!bfs.empty()){
        int node = bfs.front(); bfs.pop();
        for(auto i : graph[node]){
            if(vis[i])continue;
            vis[i]=1;bfs.push(i);
        }
    }
    for(int i=1;i<=n;i++)
    if(!vis[i]&&cnt[i]!=0)return false;
    return true;
}
void dfs(int node){
    for(;track[node]<graph[node].size();){
        if(edge[node][graph[node][track[node]]]){
            edge[node][graph[node][track[node]]]=false;
            edge[graph[node][track[node]]][node]=false;
            dfs(graph[node][track[node]]);
        }
        else track[node]++;
    }
    route.push_back(node);
}
int main(){
    cin>>n>>m;
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v;
        cnt[u]++; cnt[v]++;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edge[u][v]=true;
        edge[v][u]=true;
    }
    if(!check()){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    dfs(1);
    reverse(route.begin(),route.end());
    for(auto i : route) cout<<i<<' ';
    return 0;
}