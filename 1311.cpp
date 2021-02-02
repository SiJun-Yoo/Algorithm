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
const int MAX = 100001;
int a[20][20];
int d[20][1 << 20];
int n;
int solve(int now, int chk, int goal) {
	if (chk == goal) return 0;
	if (d[now][chk] != -1) return d[now][chk];
	int& val = d[now][chk];
	val = 0;
	for (int i = 0; i < n; i++) {
		if (chk & (1 << i)) continue;
		if (!val)val = solve(now + 1, chk | (1 << i), goal) + a[i][now];
		else val = min(val, solve(now + 1, chk | (1 << i), goal) + a[i][now]);
	}
	return val;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	memset(d, -1, sizeof(d));
	cout << solve(0, 0, (1 << n) - 1);
	return 0;
}
