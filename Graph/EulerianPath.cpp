#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
/*Eulerian Path is a path in a graph which visits each and every edge exactly once. The starting and ending vertices can be different or same.

For Eulerian Path to exist:
    ->either,
    the outdegree and indegree of every nodes must be equal, in this case the starting and ending nodes will be same
    or,
    the outdegree and indegree of every node must be equal except two nodes where outdegree[node1]-indegree[node1]=1 and 
    indegree[node2]-outdegree[node2]=1, in this the starting point will be node1 and ending point will be node2
    ->All the vertices having positive indegree or outdegree must be connected

The code below finds an Eulerian path between node 1 and node n, if there no eulerian path exist then it returns 'impossible' otherwise
returns the path.

The logic of this code eulerian path has been explained on William Fiest Youtube channel
*/
const int N = 1e5+5;
vector<int> graph[N];
int n,m,indeg[N],outdeg[N];
vector<int> route;
vector<int> track(N);
bool check(){
    if(outdeg[1]-indeg[1]!=1 || indeg[n]-outdeg[n]!=1){
        return false;
    }
    for(int i=2;i<n;i++){
        if(outdeg[i]!=indeg[i])return false;
    }
    int vis[n+1]{};
    queue<int> q;
    q.push(1);vis[1] = 1;
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
        if(!vis[i] && (indeg[i]!=0||outdeg[i]!=0)){
            return false;
        }
    }
    return true;
}
void dfs(int node){
    for(;track[node]<graph[node].size();){
        dfs(graph[node][track[node]++]);
    }
    route.push_back(node);
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        indeg[v]++;outdeg[u]++;
    }
    if(!check()){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    dfs(1);
    reverse(route.begin(),route.end());
    for(auto i : route){
        cout<<i<<' ';
    }
    return 0;
}