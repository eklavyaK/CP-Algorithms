#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;

//Time complexity per number is O(k*log(n)), for numbers upto 1e6, k=5 was found sufficient
ll power(ll x, ll y, ll p){
    ll res = 1;
    x = x%p;
    while(y>0){
        if(y&1)res = (res*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return res;
}
bool MillerRabin(ll d, ll n){
    ll a = 2+rand()%(n-4);
    ll x = power(a,d,n);
    if(x==1 || x==n-1)return true;
    while(d!=n-1){
        x=(x*x)%n; d*=2;
        if(x==1)return false;
        if (x==n-1)return true;
    }
    return false;
}
bool isPrime(ll n, ll k){
    if(n<=1 || n==4)return false;
    if(n<=3)return true;
    ll d = n-1;
    while(d%2==0)d/=2;
    for(int i=0; i<k;i++){
         if(!MillerRabin(d,n))return false;
    }
    return true;
}
int main(){
    vector<int> now;
    for(int i=1;i<=1e6;i++){
        if(isPrime(i,10))now.push_back(i);
    }
    cout<<now.size()<<endl;
    return 0;
}