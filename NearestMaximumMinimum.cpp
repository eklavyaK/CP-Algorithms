#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
int NearestMaximumMinimum(vector<int> &v) {
    int n = v.size();
    vector<int> lnm(n,-1), rnm(n,-1);      //vectors that contain the left_nearest_maximum and right_nearest_maximum, if not present then -1
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        while(!st.empty()){
            if(st.top().first>v[i]){        
                lnm[i] = st.top().second;
                break;
            }
            st.pop();                     //removing all the smaller values because for all the future elements current element will be nearer
        }
        st.push({v[i],i});
    }
    while(!st.empty())st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty()){
            if(st.top().first>v[i]){
                rnm[i] = st.top().second;
                break;
            }
            st.pop();                     //removing all the larger values because for all the future elements current element will be nearer
        }
        st.push({v[i],i});
    }
}
int main(){
    

    return 0;
}