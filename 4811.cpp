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
ll d[31][31];
ll solve(int x, int y) {
	if (x > y) return 0;
	if (x == 0) return d[x][y] = 1;
	if (d[x][y] != -1) return d[x][y];
	ll& val = d[x][y];
	val = solve(x - 1, y) + solve(x, y - 1);
	return val;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t = 1000;
	memset(d, -1, sizeof(d));
	d[1][1] = 1;
	d[2][2] = 2;
	d[3][3] = 5;
	d[4][4] = 14;
	while (t--) {
		int n;
		cin >> n;
		if (!n) break;
		cout << solve(n, n) << '\n';
	}
	return 0;
}
