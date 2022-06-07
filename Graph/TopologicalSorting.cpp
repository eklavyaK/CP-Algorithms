#include<bits/stdc++.h>
using namespace std;


int main(){                       //topological order exists for DAGs - Directed Acyclic Graphs
    int n,m; cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<int> indegree(n);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    for(auto i : indegree) cout<<i<<' ';cout<<endl;
    vector<int> ans(n);           //vector to contain topological order
    int cnt = 0;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
            ans[cnt++]=i;
        }
    }
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for(auto i : adj[k]){
            indegree[i]--;
            if(indegree[i]==0){
                ans[cnt++]=i;
            }
            q.push(i);
        }
    }
    for(auto i : ans) cout<<i<<' ';
}