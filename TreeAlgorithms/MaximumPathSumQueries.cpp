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
const int N = 1e5+5, LOG = 21;
int par[N][LOG], n, done[N], dist[N], mx[N][LOG];
vector<pair<int,int>> graph[N];
void dfs(int node){
    done[node] = 1;
    for(auto [u,edge] : graph[node]){
        if(!done[u]){
            dist[u] = dist[node]+1;
            par[u][0] = node; mx[u][0] = edge;
            dfs(u);
        }
    }
}
void computemax(){
    for(int i=1;i<LOG;i++){
        for(int j=2;j<=n;j++){
            mx[j][i] = max(mx[j][i-1],mx[par[j][i-1]][i-1]);
        }
    }
}
int getmax(int u, int v){
    int k = dist[u]-dist[v], ret = 0;
    if(k==0)return k;
    for(int i=0;i<LOG;i++){
        if((1<<i)&k){
            ret = max(ret,mx[u][i]);
            u = par[u][i];
        }
    }
    return ret;
}
int getlca(int u, int v){
    if(dist[u]<dist[v])swap(u,v);
    int k = dist[u]-dist[v];
    for(int i=0;i<LOG;i++){
        if((1<<i)&k)u = par[u][i];
    }
    if(u==v)return u;
    for(int i=LOG-1;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
vector<int> solve(const vector<vector<int>> &A, const vector<vector<int>> &B){
    n = A.size()+1;
    for(int i=1;i<=n;i++){
        graph[i].clear();
    }
    for(int i=0;i<n-1;i++){
        graph[A[i][0]].push_back({A[i][1],A[i][2]});
        graph[A[i][1]].push_back({A[i][0],A[i][2]});
    }
    fill(done,done+n+1,0); 
    fill(dist,dist+n+1,0);
    fill(par[1],par[1]+LOG,1);
    dist[1] = 0; dfs(1);
    for(int i=1;i<LOG;i++){
        for(int j=2;j<=n;j++){
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    computemax();
    for(int i=1;i<=n;i++){
        for(int j=0;j<LOG;j++){
            cout<<mx[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<int> ans;
    int m = B.size();
    for(int j=0;j<m;j++){
        int k = getlca(B[j][0],B[j][1]);
        cout<<k<<' ';
        ans.push_back(max(getmax(B[j][0],k),getmax(B[j][1],k)));
    }
    cout<<endl;
    for(auto i : ans) cout<<i<<" ";cout<<endl;
    return ans;
}

int main(){
    rapid_iostream;
    solve({{8, 2, 23282},
  {6, 3, 16828},
  {5, 2, 9962},
  {3, 1, 492},
  {4, 2, 2996},
  {7, 2, 11943},
  {2, 1, 4828}},{{1,3},{8,4},{2,4}});
    return 0;
}