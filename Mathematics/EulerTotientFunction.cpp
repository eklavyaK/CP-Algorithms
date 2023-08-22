#include<bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;


/*
Euler totient function: 
	Phi(n) = number of positive integers strictly less than n, which are coprime with n, i.e. gcd(n, i) = 1

	Theorem:
		if n = p1 ^ r1 * p2 ^ r2 .... * pk ^ rk where p1, p2, ... pk are distinct primes,
		
		then Phi(n) = p1 ^ (r1 - 1) * (p1 - 1) * p2 ^ (r2 - 1) * (p2 - 1) ..... * pk ^ (rk - 1) * (pk - 1)
		alternatively, Phi(n) = n * (1 - 1 / p1) * (1 - 1 / p2) ..... * (1 - 1 / pk)

		for computation:

		Phi(n) = [n / (p1 * p2 .. * pk)] * (p1 - 1) * (p2 - 1) .... * (pk - 1);
*/

// Discussed problem: https://codeforces.com/problemset/problem/1717/E
const int N = 1e5 + 5, M = 1e9 + 7;
vector<int> spf(N), pfac, fac, prime;
void spfac(int n){
	for(int i = 0; i <= n; i++) spf[i] = i;
	for(int i = 2; i * i <= n; i++){
		if(spf[i] != i) continue;
		for(int c = i * i; c <= n; c += i) if(spf[c] == c) spf[c] = i;
	}
	for(int i = 2; i <= n; i++) if(spf[i] == i) prime.push_back(i);
}
void primefactor(int n){
	pfac.clear();
	while(n != 1) pfac.push_back(spf[n]), n /= spf[n];
}
void allfactors(int n){
	fac.clear();
	primefactor(n);
	fac.push_back(1);
	for(int i = 0; i < pfac.size(); i++){
		n = i;
		while(i + 1 < pfac.size() && pfac[i + 1] == pfac[i]) i += 1;
		int cur = pfac[i], en = fac.size();
		for(int j = 0; j <= (i - n); j++, cur *= pfac[i]){
			for(int l = 0; l < en; l++){
				fac.push_back(fac[l] * cur);
			}
		}
	}
}

vector<int> Phi(N);
void EulerTotient(int n){
	for(int i = 2; i <= n; i++) Phi[i] = i;
	for(int i = 2; i <= n; i++){
		primefactor(i);
		for(int j = 0; j < pfac.size(); j++){
			Phi[i] /= pfac[j];
			Phi[i] *= (pfac[j] - 1);
			while(j + 1 < pfac.size() && pfac[j + 1] == pfac[j]) j += 1;
		}
	}
}

int lcm(int a, int b){
	return a * b / gcd(a, b);
}

void code(int TC){
	int n; cin >> n;
	int ans = 0;
	for(int i = 1; i < n - 1; i++){
		int K = n - i;
		allfactors(K);
		for(auto j : fac) ans = (ans + lcm(i, j) * Phi[K / j]) % M;
	}
	cout << ans << endl;
}
 
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	cout.precision(30);
	spfac(N - 5);
	EulerTotient(N - 5);
	code(0);
	return 0;
}