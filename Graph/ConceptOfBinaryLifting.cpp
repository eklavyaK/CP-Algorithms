#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;

//Finding kth ancesstor using binary lifting, here every node has only one ancestor

int main(){
    int n,q; cin>>n>>q;
    int ancestor[n+1][30];
    for(int i=1;i<=n;i++){
        cin>>ancestor[i][0];
    }
    for(int i=1;i<30;i++){
        for(int j=1;j<=n;j++){
            ancestor[j][i]=ancestor[ancestor[j][i-1]][i-1];
        }
    }
    while(q--){
        int x,k;cin>>x>>k;
        for(int i=0;i<30;i++){
            if((1<<i)&k){
                x = ancestor[x][i];
            }
        }
        cout<<x<<endl;
    }
    return 0;
}