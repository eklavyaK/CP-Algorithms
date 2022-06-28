#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
/*
Warnsdorf's Rule is used to solve the Knight's Tour problem in most optimized way.

The idea behind Warnsdorf's Rule is that if knight is standing on a box and has to move to the next unvisited box, then the selection of 
next box is such that it's degree is minimum amongst all possible next boxes. The degree of a box is defined as number of possible moves can
be made from the box to an unvisited box.
*/
int cnt = 0;
vector<vector<int>> ans(8,vector<int>(8));
vector<vector<bool>> vis(8,vector<bool>(8));
vector<array<int,2>> L({{-1,-2},{-2,-1},{-1,2},{2,-1},{1,-2},{-2,1},{1,2},{2,1}});
bool check(int u, int v){
    return !(u<0||v<0||u>7||v>7||vis[u][v]);
}
int find_deg(int u, int v){
    int deg = 0;
    for(int i=0;i<8;i++){
        int nu=L[i][0]+u;
        int nv=L[i][1]+v;
        deg+=check(nu,nv);
    }
    return deg;
}
void KnightTour(int u, int v){
    vis[u][v] = 1;
    ans[u][v]=++cnt;
    vector<array<int,2>> next;
    for(int i=0;i<8;i++){
        int nu=L[i][0]+u;
        int nv=L[i][1]+v;
        if(check(nu,nv)){
            next.push_back({find_deg(nu,nv),i});
        }
    }
    sort(next.begin(),next.end());
    for(int i=0;i<next.size();i++){
        KnightTour(L[next[i][1]][0]+u,L[next[i][1]][1]+v);
    }
    if(cnt<64){
        vis[u][v] = 0;
        ans[u][v] = 0;
        --cnt;
    }
    else{
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<ans[i][j]<<' ';
            }
            cout<<endl;
        }
        exit(0);
    }
}
int main(){
    int u,v; cin>>u>>v; --v;--u;
    KnightTour(v,u);
    return 0;
}