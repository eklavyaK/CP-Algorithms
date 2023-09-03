#include<bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;


vector<int> convert(int n, int k){
	vector<int> res;
	while(n > 0){
		res.push_back(n % k);
		n /= k;
	}
	return res;   // res contains the digits of the new number system
}


void code(int TC){
	int n, k; cin >> n >> k;
	auto ans = convert(n, k);
	while(!ans.empty()) cout << ans.back(), ans.pop_back();
	cout << endl;
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	cout.precision(30);
	int TT = 1; cin >> TT;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}