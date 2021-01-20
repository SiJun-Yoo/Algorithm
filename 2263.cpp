#include<bits/stdc++.h>
#define MOD 1000000007ll
#define MAX 200000000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef queue<int> qi;
typedef queue<pair<int, int>> qii;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
pii p[100001];
int in[100001];
int post[1000001];
int d[100001];
void solve(int inS, int inE, int postS, int postE) {
	if (inS > inE || postS > postE) return;
	cout << post[postE] << ' ';
	int inRoot = d[post[postE]];
	int cnt = inRoot - inS - 1;
	solve(inS, inRoot - 1, postS, postS + cnt);
	solve(inRoot + 1, inE, postS + cnt + 1, postE - 1);
	return;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> in[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> post[i];
	}
	for (int i = 1; i <= n; i++) {
		d[in[i]] = i;
	}
	solve(1, n, 1, n);
	return 0;
}