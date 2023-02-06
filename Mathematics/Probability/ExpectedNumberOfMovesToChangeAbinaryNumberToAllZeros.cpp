/*The program is about expected number of moves required to change a binary number to another for ex:- 0011010 to 0110101,
In one move we can select an index and flip the bit at that position (0->1 or 1->0) 

We can clearly see that positions where bits differ should be flipped odd number of times and other positions should be flipped even
number of times

So basically we have to find f[i,n] where i is the number of positions where bits differ and n is the total number of positions

now let's make a equation:

    f[i,n] = (i/n) (1+f[i-1,n]) + ((n-i)/n) (1+f[i+1,n])

    explanation of equation:- if i positions differ currently then there is i/n probability we would select one of those positoins(this takes one step) and flip the bit there which will leave us with more f[i-1,n] expected moves.
    But if we select a position where bits are same then we'd flip that bit to make it different, this takes one step, and leaves us with
    f[i+1,n] more expected moves to be performed.

    after rearranging we get f[i+1] = ( n*(f[i]-1)-i*f[i-1])/(n-i);

    which is equavalent to f[i] = (n * (f[i-1] - 1) - (i - 1) * f[i-2]) / (n - i + 1);

    So, to find the any value of f[i] we must know f[0] and f[1], we know f[0] = 0, but for f[1] we use markov's theorem which gets us
    f[1] = 2^n - 1;   ---------------> but remember this

*/

#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

const int mod = 998244353;

int exp(int a, int n){
    int ans = 1;
    while(n>0){
        if(n&1)ans = (ans*a)%mod;
        a = (a*a)%mod;
        n>>=1;
    }
    return ans;
}
int mod_inv(int a){
    return exp(a,mod-2);
}
int compute(int n, int d){
    int f[d+1];
    f[0] = 0; f[1] = (exp(2,n)-1)%mod;;
    for(int i=2;i<=d;i++){
        int num = (n*((f[i-1]-1+mod)%mod)%mod-((i-1)*f[i-2])%mod+mod)%mod;
        int den = mod_inv(n-i+1);
        f[i] = (num*den)%mod;
    }
    return f[d];
}
void code(){
    int n; cin>>n;
    string s,t; cin>>s>>t;
    int diff = 0;
    for(int i=0;i<n;i++) if(s[i]!=t[i])diff++;
    cout<<compute(n,diff)<<endl;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}