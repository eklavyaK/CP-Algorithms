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
/***************************************************MAIN PROGRAM*******************************************************/

const int N = 505;  //max nodes
unsigned int pos[N];
int in[N][N],dis[N];
map<int,map<int,int>> check;
vector<pair<int,ll>> graph[N];
int s,f,n,m;ll ans;  //n,m declared
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
    ans = 0;check.clear();
    s = start; f = final;
    for(int i=0;i<m;i++){
        int u, v; cin>>u>>v;
        if(!check[u].count(v)){
            in[u][v]=graph[u].size();
            graph[u].push_back({v,1});
            in[v][u]=graph[v].size();
            graph[v].push_back({u,1});
            check[u][v]; check[v][u];
        }
        else{
            graph[u][in[u][v]].S+=1;
        }
    }
    while(bfs()){
        fill(pos,pos+n+1,0);
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
    cout<<ans<<endl;           //maximum flow and minimum cut

    bool vis[n+1]{};
    function<void(int)> dfsmincut = [&](int node){
    	vis[node]=true;                          //checking edges which can be visited from s
    	for(auto [u,cap] : graph[node]){
    		if(!vis[u] && cap>0)
    			dfsmincut(u);
    	}
    };
    dfsmincut(s);
    set<pii> st;            //cut edges are the ones which are adjacent to visited edges(from s) but has cap = 0
    for(auto vec : graph){
    	for(auto [node,cap] : vec){
    		if(vis[node]){
    			for(auto [u,_] : graph[node]){
    				if(!vis[u]){
    					st.insert({node,u});
    				}
    			}
    		}
    	}
    }
    for(auto [a,b] : st)cout<<a<<' '<<b<<endl;  //edges to be removed
}

int main(){
    rapid_iostream;
    cin>>n>>m;
    Dinic(1,n);
    return 0;
}