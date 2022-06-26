#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;

/*Two boolean satisfiability is problem where multiple pairs of conditions are given and atleast one of the conditions in the given pairs
must hold for the final answer to be true. It's in our hands to assign the values to all the conditions but value assigned to a condition in
a pair mustn't contradict in another pair

like for ex:-
    (~a or b) and (b or c) and (d and ~b) and (c and a) == x

    for final ans x to be true all the pairs must be true for which atleast one of the condition in the pair must hold, but we can assign 
    only  one value to the variables, values of variables can vary with pairs.

we bulid a directed graph such that if in a particular pair one of the condition doesn't hold then other must hold, so there is edge between 
'inverse of condition former' and 'latter'. With that said, each pair will contribute two edges to the directed graph.

While traversing the graph if there is a path from a variable to inverse of the variable then that path cannot be taken.
We form SCCs and sort them in topological order using Kosaraju's algorithm. Now if a SCC contains both variable and inverse of the variable
then ans to the problem x is false. If no such SCC exist then for value of a variable will be inverse or non-inverse depending on whose SCC
is present higher in topological ordering. Because if we take the one with lower topological ordering then there will path between the one
in lower order to one at higher order.
*/

const int N = 1e5+5;               //maximum number of nodes
vector<int> ans[2*N];
vector<vector<int>> graph(2*N);    //2 has been multiplied to include 'inclusion' and 'non-inclusion' of a node
vector<vector<int>> revgraph(2*N);
int vis[2*N],order[2*N],n,m,cnt=1;
stack<int> comps;
void dfs(int node){
    vis[node]=1;
    for(auto i : graph[node]){
        if(!vis[i]) dfs(i);
    }
    comps.push(node);
}
void revdfs(int node){
    vis[node]=0;
    ans[cnt].push_back(node);
    for(auto i : revgraph[node]){
        if(vis[i]) revdfs(i);
    }
}
void SCC(){
    for(int v=1;v<=n;v++){
        for(auto u : graph[v])
        revgraph[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    while(!comps.empty()){
        int c = comps.top();
        comps.pop();
        if(!vis[c])continue;
        revdfs(c); cnt++;
    }
}
void add_junction(bool cnfa, int a, bool cnfb, int b){
    if(cnfa){
        if(cnfb){
            graph[n+a].push_back(b);  //graph is formed in such a way that if one of the conditions is false then other must be true
            graph[n+b].push_back(a);  //so we join a edge from a vertex which is inverse of the to the second condition meaning that
        }                             //if inverse is true then second condition must hold for the final ans to be true
        else{
            graph[n+a].push_back(n+b);
            graph[b].push_back(a);
        }
    }
    else{
        if(cnfb){
            graph[a].push_back(b);
            graph[n+b].push_back(n+a);
        }
        else{
            graph[a].push_back(n+b);
            graph[b].push_back(n+a);
        }
    }
}
void solve_2SAT(int nodes, int junctions){
    n=nodes;
    while(junctions--){
        char ca,cb; int a,b;
        cin>>ca>>a>>cb>>b;
        bool cnfa = (ca=='-'?false:true);
        bool cnfb = (cb=='-'?false:true);
        add_junction(cnfa,a,cnfb,b);
        //cnfa, cnfb denotes whether a and b are included or not if cnfa is true means a is included same goes for cnfb
    }
    n = nodes*2;
    SCC();
    for(int i=1;i<=n;i++){
        for(auto u : ans[i]){
            order[u]=i;
        }
    }
    n/=2;
    char result[n+1];
    for(int i=1;i<=n;i++){
        if(order[n+i]==order[i]){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        else{
            result[i]=order[n+i]>order[i]?'-':'+';
        }
    }
    for(int i=1;i<=n;i++){
        cout<<result[i]<<' ';
    }
}
int main(){
    int nodes, junctions;
    cin>>junctions>>nodes;
    solve_2SAT(nodes,junctions);
    return 0;
}