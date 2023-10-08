#include<bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;


vector<int> kmp(string a, string b){
	int n = a.size(), m = b.size(), cur = -1;
    // T stores the index till which current suffix is matched to prefix for ex: ababefababg => T [-1, -1, 0, 1, -1, -1, 0, 1, 2, 3, -1], we can see that at 3rd index, indices 2 and 3 match to prefix, similarly at index 9, four characters match with prefix. So basically T is called largest prefix suffix (LPS) array which stores the index where largest prefix ends such that this prefix can be matched to current suffix.
	vector<int> T(m, -1), ans; 
	for(int i = 1; i < m; i++){
		if(b[i] == b[cur + 1]) T[i] = cur += 1;   // cur is the largest prefix index till now which has been matched, if cur + 1 is also matched then we just give T[i] an increased value, otherwise we'll move 'cur' to a smaller prefix index which again matches with current suffix and again check b[i] with it's next character until match is found of cur becomes -1, in that case we'll start with next index and cur = -1
		else if(cur != -1) cur = T[cur], i--;
	}
	cur = -1;
	for(int i = 0; i < n; i++){
		if(cur + 1 > a.size()) break;   // this condition in case if length of b is 0
		if(a[i] == b[cur + 1]){
			cur += 1;
			if(cur == m - 1) cur = T[cur], ans.push_back(i - m + 1); // if match is found we put the index in the ans, and again move cur to a smaller index
		}
		else if(cur != -1) cur = T[cur], i--;
	}

    // key to note in kmp algorithm we constantly increasing the value of i and value of cur is quickly reduced to the next best index where is match is being found or to -1, this makes the complexity of the algorithm to be of order O(n + m);
	return ans;
}


void code(int TC){
	string s, t; cin >> s >> t;
	auto v = kmp(s, t);
	cout << v.size() << endl;
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	cout.precision(30);
	int TT = 1;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}