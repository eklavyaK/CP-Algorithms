#define PROGRAM int main(){rapid_iostream;int tc=1;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
#define MAIN void codeforce();
#define Y() cout<<"YES"<<endl
#define print(n) cout<<n<<' '
#define N() cout<<"NO"<<endl
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
#define endl '\n'
#define S second
#define F first
Compare(pii)
/***************************************************/ MAIN PROGRAM /*******************************************************/

string s,t; 
bool check(int l,int r,int st, int en){
    cout<<s.substr(st,en-st+1)<<' '<<t.substr(l,r-l+1)<<endl;
    if(r-l+1<=3)return true;
    map<char,int> ms, mtf,mte;
    for(int i=l;i<r;i++){
        mtf[t[i]]++;
        mte[t[r-(i-l)]]++;
        ms[s[(i-l)+st]]++;
        if(mtf==ms){
            return check(l,i,st,st+(i-l)) && check(i+1,r,st+(i-l)+1,en);
        }
        else if(mte==ms){
            return check(r-(i-l),r,st,st+(i-l)) && check(l,r-(i-l)-1,st+(i-l)+1,en);
        }
    }
    return false;
}
int isScramble(const string A, const string B) {
    s = A; t = B;
    cout<<s<<' '<<t<<endl;
    if(s.size()!=t.size())return 0;
    int n = s.size();
    map<char,int> ms,mt;
    int l = 0;
    for(int i=0;i<n;i++){
        ms[s[i]]++;
        mt[t[i]]++;
        if(ms==mt){
            if(!check(l,i,l,i))return 0;
            l = i+1;
        }
    }
    if(ms!=mt)return 0;
    return 1;
}
void codeforce(){
    cout<<isScramble("abbbcbaaccacaacc","acaaaccabcabcbcb")<<endl;
}