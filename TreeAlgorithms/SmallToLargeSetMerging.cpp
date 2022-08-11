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

/*This problem requires knowledge of small-to-large set merging. Simply recurse from the leaves of the tree, and at each node merge all sets of its children to the set of its largest child. The time complexity of this is amortized O(NlogN). Simple proof is as follows:

When you move an element from a set, the new set it belongs to will always have at least double the size of the previous set (since we always choose the largest one). Since the maximum size of any set is O(N), each node will only be moved a maximum of O(logN) times.*/

int main(){
    rapid_iostream;
    int n; cin>>n; int arr[n+1];
    vector<vector<int>>tree(n+1);
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    set<int> st[n+1];
    int par[n+1]{}, ans[n+1];
    function<void(int)> dfs = [&](int node){
        int mx = 0, in = 0;
        for(auto i : tree[node]){
            if(i==par[node])continue;
            par[i] = node; dfs(i);
            if(ans[i]>mx){
                mx = ans[i]; in = i;
            }
        }
        if(mx==0){
            st[node].insert(arr[node]);
            ans[node] = 1; return;
        }
        swap(st[node],st[in]);      //we take the chile node with largest set size as current node set and add the other children's set to it
        for(auto i : tree[node]){
            if(i==par[node]||i==in)continue;
            for(auto j : st[i])st[node].insert(j);
            st[i].clear();
        }
        st[node].insert(arr[node]);
        ans[node] = st[node].size();
    };
    dfs(1);
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    return 0;
}