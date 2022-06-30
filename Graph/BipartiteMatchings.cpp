#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
#define Y() cout<<"YES"<<endl
#define print(n) cout<<n<<' '
#define N() cout<<"NO"<<endl
#define pii pair<int,int>
#define mod1 1000000007ll
#define pli pair<ll,int>
#define pil pair<int,ll>
#define mod2 998244353ll
#include<bits/stdc++.h>
#define pll pair<ll,ll>
typedef long double ld;
typedef long long ll;
#define mp make_pair
using namespace std;
#define endl '\n'
#define S second
#define F first
Compare(pii)

/*
Bipartite Matchings can be solved using max flow algorithm.

We construct a directed graph with edge weight of every edge as 1.
We connect column 1 to column 2 as described in the input. 
Then we connect every element in column 1 to a source with a directed edge starting at the source and ending at the elements.
Then we connect every element in column 2 to a sink with a directed edge starting at the elements and ending in the sink.
Then we apply maximum flow algorithm on this newly constructed graph. The maximum flow found is the maximum number of bipartite matchings.
To find the these matchings we see which edges from column 1 to column 2 has been saturated(capacity 0) and these nodes have been matched.
*/

/***************************************************MAIN PROGRAM*******************************************************/
const int N = 1005;  //max nodes
unsigned int pos[N];
int in[N][N],dis[N];
int check[2][N];
vector<pii> res;
vector<int> track;
vector<pair<int,ll>> graph[N];
int s,f,n,m,k;ll ans;  //n,m declared
bool bfs(){
    bool done[N]{};
    fill(dis,dis+N,N);
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
        if(dis[node]>dis[f])break;
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
            graph[u][in[u][node]].S+=c;
            graph[node][pos[node]].S-=c;
            return c;
        }
    }
    return 0;
}
void Dinic(int start, int final){
    ans = 0;
    s = start; f = final;
    for(int i=0;i<k;i++){
        int u, v; cin>>u>>v;
        v = 500+v;
        in[u][v]=graph[u].size();
        graph[u].push_back({v,1});
        in[v][u]=graph[v].size();
        graph[v].push_back({u,0});
        if(!check[0][u]){
            check[0][u]=1;
            in[0][u]=graph[0].size();
            graph[0].push_back({u,1});
            in[u][0]=graph[u].size();
            graph[u].push_back({0,0});
        }
        if(!check[1][v]){
            check[1][v]=1;
            in[1001][v]=graph[1001].size();
            graph[1001].push_back({v,0});
            in[v][1001]=graph[v].size();
            graph[v].push_back({1001,1});
        }
    }
    while(bfs()){
        fill(pos,pos+N,0);
        for(;pos[s]<graph[s].size();pos[s]++){
            auto [u,cap] = graph[s][pos[s]];
            if(dis[u]==dis[s]+1 && cap>0){;
                ll c = dfs(u,cap);
                if(!c) continue;
                graph[u][in[u][s]].S+=c;
                graph[s][pos[s]].S-=c;
                ans+=c;
            }
        }
    }
    cout<<ans<<endl;

    //printing matchings
    for(auto [node,_] : graph[0]){
        for(auto [u,c] : graph[node]){
            if(u!=0 && c==0){
                cout<<node<<' '<<u-500<<endl;
            }
        }
    }
}

int main(){
    rapid_iostream;
    cin>>n>>m>>k;
    Dinic(0,1001);
    return 0;
}