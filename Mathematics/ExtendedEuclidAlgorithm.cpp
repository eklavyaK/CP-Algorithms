#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

/*
Extended euclid algorithm gives us not only gcd of (a,b) but also finds the way to represent gcd in terms of a and b

    ax + by = gcd(a,b)

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
    int a,b; cin>>a>>b;
    triples c = extendedEuclidean(a,b);
    cout<<c.g<<' '<<c.x<<' '<<c.y<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}