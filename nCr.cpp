#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
vector<vector<int>> ans;
vector<int> track;
vector<int> arr;
void Combinations(int start, int cnt , int r, int n){
    if(cnt == r){
        ans.push_back(track);
        return;
    }
    if(start == n)return;
    for(int i=start;i<n;i++){
        track.push_back(arr[i]);
        Combinations(i+1,cnt+1,r,n);
        //while(i+1<n && arr[i+1]==arr[i])i++;   //-----------> uncomment this to get all the distinct combinations (if array has duplicates) and vector arr must be sorted
        track.pop_back();
    }
}
vector<vector<int>> nCr(vector<int> all, int n,int r){
    ans.clear();track.clear();
    if(r>n)return ans;arr = all;
    sort(arr.begin(),arr.end());   //sorting gives lexicographic ordered ans of Combinations and  is necessary for distinct combinations
    Combinations(0,0,r,n);
    return ans;
}
int main(){
    int n,r; cin>>n>>r;
    vector<int> v;
    for(int i=0;i<n;i++){
        v.push_back(i+1);
    }
    nCr(v,n,r);
    for(auto i : ans) {
        for(auto c : i) cout<<c<<' ';
        cout<<endl;
    }
    return 0;
}