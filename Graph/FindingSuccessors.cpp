#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
vector<int> successor((int)2e5+5,-1);
int find_successor(int x, int k){
    if(k==1){
        if(successor[x]==-1)return x;
        return successor[x];
    }
    return find_successor(find_successor(x,k/2),k/2+k%2);
}
int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        successor[u]=v;
    }
    cout<<find_successor(1,5);
    return 0;
}