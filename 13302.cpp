#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  unsigned long long ull;
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
int d[101][101];//d[x][y]=x일에 쿠폰y개가 있을때 최소비용
int a[101];
int n, m;
int solve(int x, int y) {
	if (x == n + 1) return 0;
	if (d[x][y] != -1) return d[x][y];
	int& val = d[x][y];
	val = 0;
	if (a[x]) {
		val = solve(x + 1, y);
	}
	else {
		val = solve(x + 1, y) + 10000;
		val = min(val, solve(x + 3, y + 1) + 25000);
		val = min(val, solve(x + 5, y + 2) + 37000);
		if (y >= 3) {
			val = min(val, solve(x + 1, y - 3));
		}
	}
	return val;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		a[num]++;
	}
	memset(d, -1, sizeof(d));
	cout << solve(1, 0);
	return 0;
}