#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;

//SCC (strongly connected components) is the collection of nodes in a directed graph such that it is possible to go from a node to another node in that component

const int N = 2e5+5;
int vis[N],ans[N],n,m,cnt=1;           //ans variable stores the component number to which the node belongs
vector<vector<int>> graph(N);
vector<vector<int>> revgraph(N);       //transpose of the directed graph
stack<int> comps;                      //stack is compulsory data structure to get SCCs
void dfs(int node){
    vis[node]=1;
    for(auto i : graph[node]){
        if(!vis[i]) dfs(i);
    }
    comps.push(node);
}
void revdfs(int node){
    vis[node]=0; ans[node] = cnt;
    for(auto i : revgraph[node]){
        if(vis[i]) revdfs(i);
    }
}
void SCC(){
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    while(!comps.empty()){        //stack is compulsory because we have to process the node which is first SCC otherwise if we start from middle or the end there is possibility that we will process the SCCs before it thereby joining the these SCCs which will be wrong. If we process the first SCC and go to the second SCC then we can't come back to the first SCC as it has already been processed and all its nodes will be marked vis[i] = 0
        int c = comps.top();
        comps.pop();
        if(!vis[c])continue;
        revdfs(c); cnt++;
    }
}
int main(){
    cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        revgraph[v].push_back(u);
    }
    SCC(); cout<<cnt-1<<endl;
    for(int i=1;i<=n;i++)
    cout<<ans[i]<<' ';cout<<endl;
    return 0;
}