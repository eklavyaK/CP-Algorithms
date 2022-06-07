void swapp(int&a,int&b){int t=a;a=b;b=t;}
#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
const int N = 2e5;
int parent[N+1];
int szn[N+1];
void make(int n){
    for(int i=0;i<=n;i++){
        parent[i]=i;szn[i]=1;        //Inverse Ackermann function approach
    }
}
int parent_set(int x){
    if(x==parent[x])return x;        //path compression approach
    return parent[x]=parent_set(parent[x]);
}
void merge_sets(int u, int v){
    u = parent_set(u);v = parent_set(v);
    if(u!=v){
        if(szn[u]<szn[v])swapp(u,v);
        parent[v]=u; szn[u]+=szn[v];
    }
}
int main(){
    int n,m; cin>>n>>m;
    vector<array<int,3>> edge;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        edge.push_back({w,u,v});
    }
    sort(edge.begin(),edge.end());
    make(n);ll cost = 0;
    for(int i=0;i<m;i++){
        if(parent_set(edge[i][1])!=parent_set(edge[i][2])){
            merge_sets(edge[i][1],edge[i][2]);
            cost+=edge[i][0];
        }
    }
    cout<<cost;
    return 0;
}