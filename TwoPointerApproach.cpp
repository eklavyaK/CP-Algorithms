#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
//two pointer approach to find sum of pair of two numbers equal to or close to a given value in linear time complexity
int closestsum(vector<int> &arr, int value){
    sort(arr.begin(),arr.end());
    int l = 0, r = arr.size()-1;
    int ans = INT_MAX;
    while(l<r){
        int sum = arr[l]+arr[r];
        ans = min(ans,abs(sum-value));
        if(value>sum) l++;                //if we do r--, the sum will become more smaller
        else if(value<sum)r--;            //if we do l++, the sum will become more larger
        else return 0;
    }
    return ans;
}
int main(){
    
    int n,val; cin>>n>>val;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<closestsum(v,val)<<endl;

    return 0;
}