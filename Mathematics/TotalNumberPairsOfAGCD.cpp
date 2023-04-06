#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int f[1000005];              //All the different pairs till n which has a gcd as i

void code(){
    int n; cin>>n;
    for(int i=n/2+1;i<=n;i++)f[i] = 0;
    for(int i=n/2;i>=1;i--){
        int c = 0, k = n/i;
        for(int j=2;j*i<=n;j++)c+=f[j*i];
        f[i] = k*(k-1)/2-c;
    }
    for(int i=1;i<=n;i++)cout<<f[i]<<' ';cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}