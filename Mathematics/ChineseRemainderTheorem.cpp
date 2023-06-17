#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

/*
x ≡ a1 (mod m1)
x ≡ a2 (mod m2)
x ≡ a3 (mod m3)                // The equal sign actually means congruence which represented by three lines ≡
.
.
.
x ≡ an (mod mn)

Note: Here we're dealing with non coprime mi's

first of all reduce all the a1's to their minimal state i.e. ai = ai mod mi

now let's analyse the expressions one by one
first let's determine the x satisfying expression 1 and 2

    x mod m1 = a1 => x = a1 + b1*m1
    similarly x = a2 + b2*m2
    so, a2 + b2*m2 = a1 + b1*m1
    => m1*b1 + m2*(-b2) = a2 - a1
    for solution to exist in above equation we know extended euclidean algo, i.e. (a2-a1) % gcd(m1,m2) = 0
    if condition is true then we proceed further otherwise system will not have any solution
    we know how to determine b1 and b2 using extended euclidean:
        if(a1>a2) swap(a2-a1), swap(m1,m2)
        now, we get gcd of m1 and m2 = g
        let r = (a2-a1)/g
        solutions for b1 = Xg*r, b2 = -Yg*r,    (Xg and Yg are found using extended euclidean for gcd)

    after we write x = a1 + b1*m1
    after that we obtain lcm(n1,n2) and replace the first two equations as:
    x ≡ [((a1+(b1 % lcm)*m1 % lcm) % lcm)]   (mod lcm)

hence one by one we reduce the equations and we can determine whether the solution exists or not simultaneously we get a value of x

note: while doing multiplication of (b1 % lcm)*m1 % lcm there can be overflow as m1 is already an lcm for next operations which can be of order 1e18, to handle that this situation we can apply a theorem:
    c*a mod c*b = c*(a mod b)
    we know lcm = m1*m2/g
    we replace (b1 % lcm)*m1 % lcm = b1*m1 mod lcm => (Xg*r*m1 mod m1*m2/g) => m1*(Xg*r mod m2/g)
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
int merge(int a, int n, int b, int m, int lc){
    if(b<a) swap(a,b),swap(n,m);
    triples curr = extendedEuclidean(n,m);
    if((b-a) % curr.g != 0) return -1;
    int r = (b-a)/curr.g;
    int ans = (a + (curr.x*r % (m/curr.g))*n % lc) % lc;
    return (ans + lc) % lc;
}
int CRT(vector<int> a, vector<int> m){    // vectors of remainders (a) when x is divided by values (m)
    int n = a.size();
    if(n==0) return -1;
    for(int i=0;i<n;i++){
        if(m[i]==0) return -1;
        a[i] = a[i]%m[i];
    }
    int r = a[0], lc = m[0];
    for(int i=1;i<n;i++){
        int lcm = lc*m[i]/gcd(lc,m[i]);
        r = merge(r,lc,a[i],m[i],lcm);
        if(r==-1) return -1;
        lc = lcm;
    }
    return r;
}
void code(int TC){
    int a,n,b,m; cin>>a>>n>>b>>m;
    vector<int> aa({a,b});
    vector<int> md({n,m});
    int ans = CRT(aa,md);
    if(ans==-1) cout<<"no solution"<<endl;
    else cout<<ans<<" "<<n*m/gcd(n,m)<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin>>TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}