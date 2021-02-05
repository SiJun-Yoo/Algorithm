#include<bits/stdc++.h>
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
const ll MOD = 1000;
const int MAX = 987654321;
const int MIN = -987654321;
int n, m;
int a[201];
int d[201][201];
int solve(int s, int e) {
	if (s == e) return d[s][e] = 0;
	if (d[s][e] != -1) return d[s][e];
	int& val = d[s][e];
	val = MAX;
	for (int i = s + 1; i <= e; i++) {
		val = min(val, solve(s, i - 1) + solve(i, e) + (a[s] != a[i]));
	}
	return val;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));

	cout << solve(1, n);
	return 0;
}
