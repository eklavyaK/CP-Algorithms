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
Elmonds-Karp algorithm is based on Ford Fulkerson technique. It's commplexity is O(M^2 * N) where M is the number of edges. Dinic's algorithm
implements Ford Fulkerson technique in O(N^2 * M) which is considered to be faster as number of nodes is generally less than number of edges 
in a graph. But if number of nodes are more Elmonds-Karp algorithm can be used. 

To understand the logic behind algorithm watch the algorithm explanation on William Fiset YT channel.
*/
/***************************************************MAIN PROGRAM*******************************************************/

const int N = 505;  //max nodes
const ll inf = 1e18;
int in[N][N],par[N];
map<int,map<int,int>> check;
vector<pair<int,ll>> graph[N];
int s,f,n,m; ll ans,res;  //n,m declared
bool bfs(){
    queue<pil> Q; 
    bool done[n+1]{};
    Q.push({s,inf});
    done[s]=1;par[s]=s;
    while(!Q.empty()){
        auto[node,flo]=Q.front();Q.pop();
        for(auto [u,cap] : graph[node]){
            if(!done[u] && cap>0){
                Q.push({u,min(cap,flo)});
                done[u]=1; par[u]=node;
                if(u==f){                  //shortest non-blocking flow path is found
                    res = min(cap,flo);
                    ans += res;
                    return true;
                }
            }
        }
    }
    return false;
}
void ElmondsKarp(int start, int final){
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
    while(bfs()){                        //repeatedly doing bfs and finding shortest non-saturated route to destination till no route exists.
        for(int v=f;v!=s;v=par[v]){
            int u = par[v];
            graph[u][in[u][v]].S-=res;
            graph[v][in[v][u]].S+=res;
        }
    }
    cout<<ans<<endl;
}
int main(){
    rapid_iostream;
    cin>>n>>m;
    ElmondsKarp(1,n);
    return 0;
}