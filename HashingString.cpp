#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

/*
For string hashing we use polynomial hash function also called rolling hash, where we have a base P and a modulo M.

h[s] = [ (s[0]-'a'+1)*P^1 + (s[1]-'a'+1)*P^2 + (s[2]-'a'+1)*P^3 .... + (s[n-1]-'a'+1)*P^n  ] % M

generally P is taken as 31 in case of lower case latin characters, for combination of lower and uppercase latin letters P is taken as 53

the probability of collision is 1/M. So bigger the modulo better the hashing, if we use two modulo then collision probability decreases further to 1/(M1*M2).

The major advantage of rolling over other hash functions is that we can compute the hash of any substring on log(M) time, if we know the hash value of the all prefixes of the string

h[s(l,r)] = (h[r] - h[l-1]) * P^(-l)
*/

const int P = 31, M = 1e9+7;
int exp(int a, int n){
    int res = 1;
    while(n>0){
        if(n&1) res = (res*a) % M;
        a = (a*a) % M; n>>=1;
    }
    return res;
}
int hashvalue(string s){
    int n = s.size(), hash = 0;
    for(int i=1;i<=n;i++){
        hash = (hash + (s[i-1]-'a'+1) * exp(P,i)) % M;
    }
    return hash;
}

void code(int TC){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        cout<<hashvalue(s)<<endl;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}