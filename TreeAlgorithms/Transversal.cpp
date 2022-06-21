#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
vector<vector<int>> node(200005);
int parent[200005];
void dfs(int x, int p){
    cout<<x<<' ';
    for(auto i : node[x]){
        if(i!=p){
            dfs(i,x);
            parent[i]=x;
        }
    }
}
int main(){
    int n; cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        node[u].push_back(v);
    }
    dfs(1,0);
    parent[1]=1;
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<parent[i]<<' ';
    }
    return 0;
}