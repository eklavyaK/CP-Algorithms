#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
/*********************************************TARJAN'S ALGORITHM***********************************************/
const int N = 2e5+5;
vector<vector<int>> graph(N);
int vis[N], proc[N], mn[N], n, m, id = 0, cnt = 1;
vector<int> ans[N];
bool inStack[N];
stack<int> comps;
void dfs(int node){
    vis[node] = 1;
    comps.push(node);
    inStack[node]=true;
    proc[node]=mn[node]=++id;
    for(auto i : graph[node]){
        if(!vis[i]) dfs(i);
        if(inStack[i]) mn[node] = min(mn[i],mn[node]);
    }
    if(mn[node]!=proc[node])return;
    while(true){
        int c = comps.top();
        mn[c] = proc[node];
        inStack[c] = false;
        comps.pop();
        ans[cnt].push_back(c);
        if(c==node)break;
    }
    cnt++;
}
void SCC(){
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i);
    }
}
int main(){
    cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
    }
    SCC();
    for(int i=1;i<=n;i++){
        if(!ans[i].size())break;
        for(auto nodes : ans[i])
        cout<<nodes<<' ';cout<<endl;
    }
    return 0;
}