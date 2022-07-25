/*
What is a mother vertex?
    It is a vertex from where you can reach to all the vertices in the graph.

In case of disconnected graph there is no mother vertex.
In case of connected undirected graph, all the vertices are mother vertices.
In case of Directed graph, there can be 0 or more mother vertices.
*/

//Program to find A MOTHER VERTEX

#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
vector<vector<int>> graph;
vector<int> done;
void dfs(int node){
    done[node] = 1;
    for(auto i : graph[node]){
        if(!done[i]){
            dfs(i);
        }
    }
}
int main(){
    int n,m; cin>>n>>m;
    graph.clear();
    graph.resize(n+1);
    done.clear();
    done.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
    }
    int mth;
    for(int i=1;i<=n;i++){
        if(!done[i]){
            mth = i;
            dfs(i);
        }
    }
    done.clear();
    done.resize(n+1);
    dfs(mth);
    for(int i=1;i<=n;i++){
        if(!done[i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<mth<<endl;
    return 0;
}