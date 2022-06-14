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
#define S second
#define F first
Compare(pii)
/***************************************************MAIN PROGRAM*******************************************************/


const ll inf = 2e14;
int main(){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> edge(n+1);
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        edge[u].push_back({v,w});
    }
    int parent[n+1];
    parent[1]=1;int c=1;
    vector<ll> dist(n+1,inf);
    dist[1]=0;bool detect = true;
    for(int i=0;i<n;i++){
        detect = true;
        for(int j=1;j<=n;j++){
            for(auto [node,w] : edge[j]){
                if(dist[node]>dist[j]+w){
                    dist[node]=dist[j]+w;  //*Note the distance of a node in negative cycle or nodes after a negative changes(reduced in this case)
                    parent[node]=j;
                    detect = false;
                    c=node;
                }
            }
        }
    }
    if (detect){
        N();
    } 
    else{
        Y();
        for (int i=0;i<n;++i)c = parent[c]; //Since the distance of the node 'c' has changed so we can assume that this node is either in negative cycle or comes after it. So to make sure that the node we get to a node in a negative cycle we do n-1 trackbacks because there are only n nodes. After n-1 trackbacks we'd certainly end up in a negative cycle. Also we can never go backtrack after first negative cycle because we'd end up falling in a loop in the negative cycle because every node in the negative cycle has it's parent in negative cycle itself
        vector<int> cycle;
        for (int v=c;;v=parent[v]) {
            cycle.push_back(v);
            if (v==c && cycle.size()>1)break;
        }
        reverse(cycle.begin(),cycle.end());
        for(int v : cycle)
            cout <<v <<' ';
        cout<<endl;
    }
    return 0;
}