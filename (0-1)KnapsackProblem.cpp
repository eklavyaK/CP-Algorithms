#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;

//0-1 knapsack problem (either the item is included or rejected, fraction of item cannot be included)

//where you have a container of size x and there are n items, price of a item is c[i] and it's price is p[i].
//we have to fill the bag such as it's total cost is maximum.

int main(){
    int n,x; cin>>n>>x;
    int c[n],p[n];
    ll dp[x+1]{};
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        if(c[i]>x)continue;
        for(int j=x;j>=c[i];j--){
            dp[j]=max(dp[j],dp[j-c[i]]+p[i]);
        }
    }
    cout<<*max_element(dp,dp+x+1);
    return 0;
}