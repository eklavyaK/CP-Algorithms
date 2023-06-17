#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

/*
x mod m1 = a1 mod m1
x mod m2 = a2 mod m2
x mod m3 = a3 mod m3
.
.
.
x mod mn = an mod mn

if all ai and mi are known then we can uniquely determine x mod lcm(m1,m2,m3)

if m1, m2, m3 ... mn are pair-wise coprime, then x (one of the solutions) can be determined by:

--------->     x = (X1*M1*a1 + X2*M2*a2 + X3*M3*a3 + .... + Xn*Mn*an) mod M

where,
Mi = prod(mj) , j=/=i    (meaning: product of all the mj except mi)
Xi = 1/Mi mod mi         (meaning: modulo multiplicative inverse of Mi with mi)
M = Mi * mi              (basically product of all mi or more formally LCM of all mi)

Note: 
for modular inverse to exist gcd(mi,Mi) must be 1, i.e. coprime numbers, for ex: mi = 4, and Mi = 2, modular inverse will not exist
We can always show Mi and mi are always coprime, because all other mj do not have a prime factor in common as they are coprime with mi
and Mi is multiplication of them so Mi will also not have a common prime factor with mi
*/

struct triples{
    int g, x, y;
};
triples extendedEuclidean(int a, int b){
    triples ans;
    if(!b){
        ans.x = 1;
        ans.y = 0;
        ans.g = a;
        return ans;
    }
    triples curr = extendedEuclidean(b,a%b);
    ans.x = curr.y;
    ans.y = curr.x - curr.y*(a/b);
    ans.g = curr.g;
    return ans;
}
int MI(int A, int M){
    if(gcd(A,M)!=1){
        cout<<"DOESN'T EXIST"<<endl;
        return -1;
    }
    int X = extendedEuclidean(A,M).x;
    return (X%M+M)%M;
}

int CRT(vector<int> m, vector<int> a){
    if(m.size()==1) return a[0]%m[0];
    int n = m.size(), ans = 0;
    vector<int> M(n), X(n);
    int forward[n], backward[n];
    forward[0] = m[0], backward[n-1] = m[n-1];
    for(int i=1;i<n;i++) forward[i] = forward[i-1]*m[i];
    for(int i=n-2;i>=0;i--) backward[i] = backward[i+1]*m[i];
    for(int i=0;i<n;i++){
        if(i==0) M[i] = backward[1];
        else if(i==n-1) M[i] = forward[n-2];
        else M[i] = forward[i-1]*backward[i+1];
        X[i] = MI(M[i],m[i]);
        int mod = M[i]*m[i];
        ans = (ans + M[i]*X[i]%mod*a[i])%mod;
    }
    return ans;
}

void code(int TC){
    vector<int> a({1, 1, 3});
    vector<int> m({5, 7, 11});
    cout<<CRT(m,a)<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}