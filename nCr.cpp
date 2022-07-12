#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
vector<vector<int>> ans;
vector<int> track;
vector<int> arr;     //actual array of n elements
void Combinations(int start, int cnt , int r, int n){
    if(cnt == r){
        ans.push_back(track);
        return;
    }
    if(start == n)return;
    for(int i=start;i<n;i++){
        track.push_back(arr[i]);
        Combinations(i+1,cnt+1,r,n);
        track.pop_back();
    }
}
vector<vector<int>> nCr(int n,int r){
    ans.clear();track.clear();
    if(r>n)return ans;
    Combinations(0,0,r,n);
    return ans;
}
int main(){
    int n,r; cin>>n>>r;
    for(int i=0;i<n;i++){
        arr.push_back(i+1);
    }
    nCr(n,r);
    for(auto i : ans) {
        for(auto c : i) cout<<c<<' ';
        cout<<endl;
    }
    return 0;
}