#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

/*
Two trees can be said isomorphic (same) when one can be made exactly similar to another by some series of flips (reordering the child subtrees of a node) while being rooted at some node, examples at : https://codeforces.com/blog/entry/101010

We can hash a tree if it is rooted at some point. And all trees isomorphic trees to this tree will have the same value.

source: https://codeforces.com/blog/entry/113465

Idea:
    Every node will have a hash value which is equal to integer (which will denote the hash value of the subtree whose root is the node). The hash value of a node is calculated by storing the hash values of all its children in a vector and sorting the vector (this vector is called ChildInfo). If that vector is equal to a already stored vector, we'll assign the hash value corresponding to the vector as hash value of the node. Otherwise we'll assign a different hash value to the node, and store update the map of the vectors with the current vector and the corresponding hash value.

    If two node have same hash value means that both subtrees are isomorphic.

    Firstly leaves have no child so their ChildInfo = [], we map the vector [] with hash value 0,
    Now we go to the parent, if parent has two child the ChildInfo = [0,0], since [0,0] is not present in the map, we update the map with pair {[0,0],1}, and assign the hash value of the parent as 1. we do the similar process till we reach the root.

Complexity analysis:
    The sum of sizes of all the arrays in the map is n-1. In worst case all the nodes will have different hash values but the hash value of a node is pushed into the map only once (when computing the hash value of it's parent). So total time of search a vector in the map is logn, which gives total complexity as n * logn in worst case

This algorithm to hash a root tree runs in O(n logn) time

NOTE: Probability of collision using this technique is 0.

Sample problem: https://codeforces.com/contest/1800/problem/G
*/


void code(int TC){
    int n; cin>>n;

    vector<vector<int>> tree(n+1);

    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int par[n+1]{}, hash[n+1]{}, now = 1;

    map<vector<int>,int> is;    //map storing all possible vectors

    function<void(int)> dfs = [&](int node){
        vector<int> cur;
        for(auto i : tree[node]){
            if(i==par[node]) continue;
            par[i] = node;
            dfs(i);
            cur.push_back(hash[i]);
        }
        sort(cur.begin(),cur.end());
        if(!is.count(cur)) is[cur] = now++;   //if hash is not found we update the map
        hash[node] = is[cur];
    };
    dfs(1);

    for(int i=1;i<=n;i++) cout<<hash[i]<<' ';cout<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}