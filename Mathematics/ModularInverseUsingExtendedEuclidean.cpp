#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

/*
What is modular inverse?

modular inverse of a Integer A w.r.t a Integer M is a Integer which when multiplied with A gives remainder as 1 when divided with M

more formally: A*X % M = 1, 

for modular inverse to exist gcd(A,M) must be 1, i.e. coprime numbers, for ex: M = 4, and A = 2, modular inverse will not exist

now let's find modular inverse of A w.r.t M:

    let's write a diophantine equation,
    ----> A*x+M*y = 1
    we know gcd(A,M) = 1, so we can easily determine x and y using extended euclidean

    taking modulo with M on both sides we get,
    A*x % M = 1
    
    so we can conclude x is a modular inverse of A
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
int modularInverse(int A, int M){
    if(gcd(A,M)!=1){
        cout<<"DOESN'T EXIST"<<endl;
        return -1;
    }
    int X = extendedEuclidean(A,M).x;
    return (X%M+M)%M;
}


void code(int TC){
    int A, M; cin>>A>>M;
    cout<<modularInverse(A,M)<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}