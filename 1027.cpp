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
const ll MOD = 1000000007;
const int IDX = 200001;
const ll MAX = 2000000001;
const int MIN = -987654321;
ll ccw(pll a, pll b, pll c) {
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	if (n <=3) {
		cout << n - 1;
		return 0;
	}
	int ans = 2;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (i - 1 == j) {
				cnt++;
				continue;
			}
			if (i + 1 == j) {
				cnt++;
				continue;
			}
			bool flag = true;
			if (i > j) {
				for (int k = j + 1; k <i; k++) {
					ll now = ccw({ i,v[i] }, { k,v[k] }, { j,v[j] });
					if (now >= 0) {
						flag = false;
						break;
					}
				}
			}
			else {
				for (int k = i + 1; k < j; k++) {
					ll now = ccw({ i,v[i] }, { k,v[k] }, { j,v[j] });
					if (now <= 0) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
