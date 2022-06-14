#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
void swapp(int&a,int&b){int t=a;a=b;b=t;}
#define println(n) cout<<n<<'\n'
#define Y() cout<<"YES"<<endl
#define N() cout<<"NO"<<endl
#define print(n) cout<<n<<' '
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



int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> edge(n+1);
    vector<int> cnt(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        edge[u].push_back(v);
        cnt[v]++;
    }
    vector<int> ans;         //vector to contain the answer after sorting
    queue<int> q;int in = 0;
    for(int i=1;i<=n;i++){
        if(cnt[i]==0){
            q.push(i);
            ans.push_back(i);
        }
    }
    while(!q.empty()){
        int k = q.front(); q.pop();
        for(auto i : edge[k]){
            cnt[i]--;
            if(cnt[i]==0){
                ans.push_back(i);
                q.push(i);
            }
        }
    }
    if(ans.size()<n)print("IMPOSSIBLE");
    else for(auto i : ans) cout<<i<<' ';
    return 0;
}