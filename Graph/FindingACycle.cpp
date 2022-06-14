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
set<int> st;
int parent[100001];
int check[100001];
vector<vector<int>> edge(100001);
void display(int f,int node){
    vector<int> ans;
    ans.push_back(f);
    while(node!=f){
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(f);
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto i : ans) cout<<i<<' ';
}
void dfs(int node){
    st.insert(node);
    check[node]=1;
    for(auto i : edge[node]){
        if(check[i]){
            if(st.find(i)!=st.end()){
                display(i,node);exit(0);
            }
        }
        else if(!check[i]){
            parent[i]=node;
            dfs(i);
        }
    }
    st.erase(node);
}
int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        edge[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!check[i]){
            parent[i]=i;
            st.insert(i);
            dfs(i);
        }
    }
    print("IMPOSSIBLE");
    return 0;
}