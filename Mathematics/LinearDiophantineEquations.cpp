#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;


/*
Linear diophantine equations are of form:

a1*x1 + a2*x2 + a3*x3 + .... + an*xn = C

a1, a2, a3, ...., an are all constants or known coeffiecients
x1, x2, x3, ...., xn are all known variables in degree one, that's name is linear

The theorem:
    Solution of this equation will exist only when C is divisible by gcd(a1, a2, a3, ...., an) i.e. C % gcd(a1, a2, a3, ...., an) = 0

For two variable case we can easily determine a solution using extended euclidean theorem:

    Ax + By = C
    
    First check if solution is possible or not,
    If solution is possible then proceed forward,
    Now let's find the solution of the this equation using extended euclidean

    let's rewrite the equation as AXg + BYg = G          (G is the gcd of (A,B))

    we can now easily determine Xg and Yg using extended euclidean,
    Now just simply multiply the equation with C/G in order to make the right side as C
    We get the final equation as:

    AXg*(C/G) + BYg*(C/G) = C

    x = Xg * (C/G)
    y = Yg * (C/G)
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

void code(int TC){
    
    int a, b, c; cin>>a>>b>>c;
    if(a==0 || b==0){
        cout<<"NOT VALID"<<endl;
        return;
    }
    int g = gcd(a,b);
    if(c%g!=0){
        cout<<"NO SOLUTION"<<endl;
    }
    else{
        int r = c/g;
        triples ans = extendedEuclidean(a,b);
        cout<<r*ans.x<<" "<<r*ans.y<<endl;
    }

}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}