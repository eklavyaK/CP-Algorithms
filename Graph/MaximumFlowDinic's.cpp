#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
#define F first
#define S second

/*
Dinic's algorithm is used to find the maximum flow from an node to another in O(N^2 * M) where N is the number of nodes. This is more faster
than Elmonds-Karp algorithm as generally nodes are less compared to edges.

While constructing the graph we also add a backward edge between adjacent nodes if not present already. These backward edges are used to 
return the extra flow pushed to the adjacent node in case of saturating flow is less than the pushed flow. This backward flow can be used for
a future flow which has not been processed. The concept of backward edges might be found confusing but these back edges are the ones that run
the game.

Dinic's algorithm solves the question in phases. In each phase a level graph is constructed with starting node having level 0 or minimum and
the graph is then transversed using bfs while increasing the level of adjacent nodes at each step and marking them visited till we reach final
vertex. Then a dfs algorithm is run from starting vertex to final vertex which finds the saturating flows in a path which is added to the
final answer. While backtracking we subtract the ans of the path from each forward flow and add it to the backward flow for future dfs
transversals.
*/

const int N = 505;
unsigned int pos[N];
int in[N][N],dis[N];
map<int,map<int,int>> check;
vector<pair<int,ll>> graph[N];
int s,f,n,m;ll ans;
bool bfs(){
    fill(dis,dis+n+1,N);
    bool done[n+1]{};
    queue<int> Q; Q.push(s);
    done[s] = 1; dis[s] = 0;
    while(!Q.empty()){
        int node = Q.front(); Q.pop();
        for(auto [to, cap] : graph[node]){
            if(!done[to] && cap>0){
                dis[to] = dis[node]+1;
                done[to]=1;Q.push(to);
            }
        }
        if(dis[node]>dis[f])break;         //breaking the bfs as we don't need the edges which have higher distances than current distance of 
                                            //of the final vertex
    }
    return done[f];
}
ll dfs(int node, ll flo){
    if(node==f)return flo;
    for(;pos[node]<graph[node].size();pos[node]++){
        auto [u,cap] = graph[node][pos[node]];
        if(dis[u]==dis[node]+1 && cap>0){
            ll c = dfs(u,min(flo,cap));
            if(!c) continue;
            graph[u][in[u][node]].S+=c;      //adding the saturating flow to the backward edge
            graph[node][pos[node]].S-=c;     //subtracting the saturating flow as it cannot be used again for future paths
            return c;
        }
    }
    return 0;
}
void Dinic(int start, int final){
    ans = 0;check.clear();
    s = start; f = final;
    for(int i=0;i<m;i++){
        int u, v; ll c; cin>>u>>v>>c;
        if(!check[u].count(v)){
            in[u][v]=graph[u].size();
            graph[u].push_back({v,c});
            in[v][u]=graph[v].size();
            graph[v].push_back({u,0});
            check[u][v]; check[v][u];
        }
        else{
            graph[u][in[u][v]].S+=c;
        }
    }
    while(bfs()){
        fill(pos,pos+n+1,0);
        for(;pos[s]<graph[s].size();pos[s]++){
            auto [u,cap] = graph[s][pos[s]];
            if(dis[u]==dis[s]+1 && cap>0){
                ll c = dfs(u,cap);
                if(!c) continue;
                graph[u][in[u][s]].S+=c;
                graph[s][pos[s]].S-=c;
                ans+=c;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(0);
    cin>>n>>m;
    Dinic(1,n);
    return 0;
}