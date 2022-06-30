#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;

//(0,1) knapsack problem (fraction of an item can be included)

//where you have a container of size x and there are n items, price of a item is c[i] and it's price is p[i].
//we have to fill the bag such as it's total cost is maximum.

int main(){
    int n,x; cin>>n>>x;
    int c[n],p[n];
    vector<pair<ld,int>> frac(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        frac[i]={(ld)p[i]/c[i],i};
    }
    ld ans = 0;
    sort(frac.begin(),frac.end(),greater{});
    for(int i=0;i<n;i++){
        auto [per,j]=frac[i];
        if(x-c[j]>0){
            ans+=p[j];
            x-=c[j];
        }
        else{
            ans+=x*per;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}