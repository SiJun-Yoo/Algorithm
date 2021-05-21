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
const int MOD = 1000000007;
const int MAX = 1000000000;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		ll m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			ll now;
			cin >> now;
			v[i] |= (1ll << now);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		ll m;
		cin >> m;
		ll now = 0;
		ll input = 0;
		for (int i = 0; i < m; i++) {
			cin >> input;
			now |= (1ll << input);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if ((v[i] & now) == v[i]) {
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}