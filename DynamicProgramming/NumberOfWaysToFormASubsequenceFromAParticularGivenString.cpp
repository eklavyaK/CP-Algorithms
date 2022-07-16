#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
int numDistinct(string t, string s) {
    if(s.size()==0)return 0;
    int n = s.size(), m = t.size();
    vector<vector<int>> form(n+1,vector<int>(m+1,0));
    int cnt = 0;
    for(int i=0;i<m;i++){
        if(s[0]==t[i])cnt++;
        form[1][i+1] = cnt;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            form[i][j] = form[i-1][j-1]*(s[i-1]==t[j-1])+form[i][j-1];
        }
    }
    return form[n][m];
}
int main(){
    string s, t; cin>>s>>t; //length of the strings must be order of thousands only
    cout<<numDistinct(s,t)<<endl;
    return 0;
}