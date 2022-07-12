#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
vector<int> arr;
void permutation(int l, int r){
    if(l==r){
        for(auto i : arr) cout<<i<<' ';
        cout<<endl; return;
    }
    for(int i=l;i<r;i++){
        swap(arr[l],arr[i]);
        permutation(l+1,r);
        swap(arr[l],arr[i]);
    }
}
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        arr.push_back(i+1);
    }
    permutation(0,n);
    return 0;
}