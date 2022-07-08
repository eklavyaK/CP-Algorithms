#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
//implementation of Knuth-Morris-Pratt algorithm
int KMP(string origin, string to_be_found){
    string s = origin, t = to_be_found;
    int n = t.size(); vector<int> arr(n);
    for(int i=1;i<n;i++){                    //prefix generation
        int k=arr[i-1];
        while(k>0&&t[i]!=t[k])k=arr[k-1];
        if(t[i]==t[k])k++;
        arr[i] = k;
    }
    int i = 0, j = 0, pos = -1;
    while(i<s.size()){
        if(s[i]==t[j])i++,j++;
        else if(j!=0)j=arr[j-1];
        else i++;
        if(j==n)return i-n;
    }
    return pos;
}
int main(){
    while(true){
        string s, t; cin>>s>>t;
        cout<<KMP(s,t)<<endl;
    }
    return 0;
}