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
vector<int> graph[N],ans[N];
map<int,bool> edge[N];
int n,m,cnt[N],godfs[N];
set<int> st;
bool check(){
    for(int i=1;i<=n;i++){
        if(cnt[i]&1){
            return false;
        }
    }
    int vis[n+1]{};
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int node = q.front();q.pop();
        for(auto i : graph[node]){
            if(!vis[i]) {
                q.push(i);
                vis[i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i] && cnt[i]!=0){
            return false;
        }
    }
    return true;
}
vector<int> route;
void construct(int node){
    route.push_back(node);
    for(int i=1;i<ans[node].size();i++){
        if(ans[node][i]==node){
            route.push_back(node);
            continue;
        }
        construct(ans[node][i]);
        ans[ans[node][i]].clear();
    }
}
bool track = false;
void dfs(int node,int k){
    cnt[node]-=2;
    if(!godfs[node])
    st.insert(node);
    ans[k].push_back(node);
    if(cnt[node]<0){
        track = true;
        return;
    }
    for(auto [i,t] : edge[node]){
        edge[i].erase(node);
        edge[node].erase(i);
        dfs(i,k);
        if(track)return;
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        edge[u][v]=true;
        edge[v][u]=true;
        cnt[u]++;cnt[v]++;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if(!check()){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    st.insert(1);
    while(!st.empty()){
        int k = *st.begin();
        st.erase(k);
        godfs[k] = 1;
        if(cnt[k]>0){
            dfs(k,k);
        }
    }
    construct(1);
    for(auto i : route) cout<<i<<' ';
    return 0;
}