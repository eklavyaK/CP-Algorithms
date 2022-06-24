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
const int N = 2e5+5, LOG = 32;
int par[N][LOG], vis[N], dep[N];
vector<vector<int>> node(N);
int cyclenumber[N], cnt = 1;
map<int,int> cyclesize;
void dfs(int u, int k){
    cyclenumber[u]=k-1;
    if(cyclenumber[par[u][0]]==0){
        dfs(par[u][0],k-1);
    }
    if(cyclenumber[par[u][0]]<0){
        cyclesize[cnt] = cyclenumber[par[u][0]]-cyclenumber[u];   //this will give (size of the cycle-1)
        cyclenumber[u] = cnt;         //when a cycle is found we assign the number to it
        dep[u]=0; cnt++;              //assigning a random node in the cycle at depth as 0 and processing whole cycle using that reference
    }
    else{
        cyclenumber[u] = cyclenumber[par[u][0]];  //if cyclenumber is already positive means the root cycle has already processed
        dep[u]=dep[par[u][0]]+1;
    }
}
int lca(int u, int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }
    int k = dep[u]-dep[v]; 
    for(int i=0;i<LOG;i++){
        if(k & (1<<i)){
            u = par[u][i];
        }
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

int main(){
    rapid_iostream;
    int n,q; cin>>n>>q; int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        par[i][0]=a[i];
    }
    for(int j=1;j<LOG;j++){
        for(int i=1;i<=n;i++){
            par[i][j]=par[par[i][j-1]][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        if(cyclenumber[i]==0){
            dfs(i,0);
        }
    }
    map<int,map<int,bool>> cycle;
    for(int i=1;i<=n;i++){           //getting the nodes that lie in a cycle along with their cycle number
        if(dep[i]==0){
            int k = i;
            int num = cyclenumber[k];
            cycle[num][k]=true;
            while(par[k][0]!=i){
                k = par[k][0];
                cycle[num][k]=true;
            }
        }
    }
    while(q--){
        int in,f; cin>>in>>f;
        if(cyclenumber[in]!=cyclenumber[f]) println(-1);
        else if(lca(in,f)==f)cout<<dep[in]-dep[f]<<endl;
        else if(cycle[cyclenumber[f]][f]){
            cout<<cyclesize[cyclenumber[f]]-dep[f]+dep[in]+1<<endl;
        }
        else println(-1);
    }
    return 0;
}