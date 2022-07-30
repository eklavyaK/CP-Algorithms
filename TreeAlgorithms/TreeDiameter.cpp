#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;

vector<vector<int>> tree;
vector<int> mx,par,dmtr;
int diameter(int node){
    vector<int> v;
    for(auto i:tree[node]){
        if(i==par[node])continue;
        par[i] = node;
        mx[node]=max(diameter(i)+1,mx[node]);
        v.push_back(mx[i]+1);
    }
    sort(v.begin(),v.end());
    if(v.size()>=2){
        dmtr[node]+=v.back();
        v.pop_back();
        dmtr[node]+=v.back();
    }
    else if(v.size())dmtr[node]=v.back();
    return mx[node];
}
int main(){
    int n; cin>>n;
    mx.clear();
    par.clear();
    tree.clear();
    dmtr.clear();
    mx.resize(n+1);
    par.resize(n+1);
    dmtr.resize(n+1);
    tree.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    diameter(1);
    cout<<*max_element(dmtr.begin(),dmtr.end())<<endl;
}