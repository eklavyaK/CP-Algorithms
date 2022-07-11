#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
string longestPalindromicSubstring(string s){
    int n = s.size();
    map<int,int> m;
    for(int i=0;i<n;i++){
        int l = i, r = i,cnt=1;
        while(l-1>=0 && r+1<n && s[l-1]==s[r+1]){
            r++;l--;cnt+=2;
        }
        if(!m.count(cnt))m[cnt]=l;
    }
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1])continue;
        int l = i, r = i+1, cnt = 2;
        while(l-1>=0 && r+1<n && s[l-1]==s[r+1]){
            r++;l--;cnt+=2;
        }
        if(!m.count(cnt))m[cnt]=l;
    }
    auto [len,pos]=*m.rbegin();
    return s.substr(pos,len);
}
int main(){
    while(true){
        string s; cin>>s;
        cout<<longestPalindromicSubstring(s)<<endl;
    }
    return 0;
}