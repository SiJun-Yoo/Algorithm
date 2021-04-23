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
typedef vector<int> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
const ll MOD = 1000000007;
int n, m;
ll d[11][100002];
ll sum[100001];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		d[1][i] = 1;
	}
	sum[1] = m;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] += sum[i - 1];
			d[i][j] %= MOD;
			for (int k = j * 2; k <= m; k += j) {
				d[i][j] -= d[i - 1][k];
				d[i][j] %= MOD;
			}
			sum[i] += d[i][j];
			sum[i] %= MOD;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		ans += d[n][i];
		ans %= MOD;
	}
	cout << ans;
	return 0;
}