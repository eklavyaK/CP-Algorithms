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
 
const int N = 2e5+5;
vector<vector<int>> tree(N);
int now[N], dep[N], par[N], sz[N];
int Tree[N*4]; int arr[N], idx = 1;
int heavy[N], pos[N];
int upper[N], n, m;
void dfs(int node){
    int mx = 0;
    for(auto i : tree[node]){
        if(i==par[node])continue;
        par[i] = node;
        dep[i] = dep[node]+1;
        dfs(i); sz[node]+=sz[i];
        if(sz[i]>mx){
            heavy[node] = i;
            mx = sz[i];
        }
    }
    sz[node]++;
}
void HLD(int node){
    arr[idx] = now[node];
    pos[node] = idx++;
    if(!upper[node])upper[node] = node;
    if(heavy[node]){
        upper[heavy[node]] = upper[node];
        HLD(heavy[node]);
    }
    for(auto i : tree[node]){
        if(i!=par[node]&&i!=heavy[node])HLD(i);
    }
}
int lca(int u,int v){
    while(upper[u]!=upper[v]){
        if(dep[upper[u]]<dep[upper[v]])v = par[upper[v]];
        else u = par[upper[u]];
    }
    return dep[v]>dep[u]?u:v;
}
void SegmentTree(int node, int l, int r){
    if(l==r){
        Tree[node] = arr[l];
        return;
    }
    int mid = (l+r)>>1;
    SegmentTree(2*node,l,mid);
    SegmentTree(2*node+1,mid+1,r);
    Tree[node] = max(Tree[2*node],Tree[2*node+1]);
}
void update(int node, int l, int r, int index, int value){
    if(l==r){
        Tree[node] = value;
        return;
    }
    int mid = (l+r)>>1;
    if(index<=mid) update(2*node,l,mid,index,value);
    else update(2*node+1,mid+1,r,index,value);
    Tree[node] = max(Tree[2*node],Tree[2*node+1]);
}
int query(int node, int l, int r, int st, int en){
    if(r<st || l>en)return 0;
    if(st<=l && en>=r)return Tree[node];
    int mid = (l+r)>>1;
    return max(query(2*node,l,mid,st,en),query(2*node+1,mid+1,r,st,en));
}
int make_query(int u, int v){
    int mx = 0;
    while(upper[u]!=upper[v]){
        if(dep[upper[u]]<dep[upper[v]]){
            mx = max(mx,query(1,1,n,pos[upper[v]],pos[v]));
            v = par[upper[v]];
        }
        else{
            mx = max(mx,query(1,1,n,pos[upper[u]],pos[u]));
            u = par[upper[u]];
        }
    }
    if(dep[u]>dep[v])swap(u,v);
    return max(mx,query(1,1,n,pos[u],pos[v]));
}
int main(){
    rapid_iostream;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>now[i];
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1); HLD(1);
    SegmentTree(1,1,n);
    while(m--){
        int type; cin>>type;
        if(type==1){
            int s,x; cin>>s>>x;
            update(1,1,n,pos[s],x);
        }
        else{
            int a,b; cin>>a>>b;
            cout<<make_query(a,b)<<' ';
        }
    }
    return 0;
}