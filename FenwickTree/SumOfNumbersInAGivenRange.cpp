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

int n;
const int N = 2e5+5;
vector<ll> bit(N);
void update(int idx, int val){
    while(idx<=n){
        bit[idx]+=val;
        idx += (idx & (-idx));
    }
}
ll query(int idx){
    ll ans = 0;
    while(idx>0){
        ans+=bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}
int main(){
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i]);
    }
    int q;cin>>q;
    while(q--){
        int type; cin>>type;
        if(type==1){
            int l,r; cin>>l>>r;                  //in case of 0 based indexing do l++, r++;
            ll result = query(r) - query(l-1);   
            cout<<result<<endl;              
        }
        else if(type==2){
            int in, val; cin>>in>>val;
            update(in, -a[in]);
            update(in, val);
            a[in]=val;
        }
    }
    return 0;
}