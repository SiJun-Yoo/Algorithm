#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef queue<pair<int, int>> qii;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
const int MAX = 1000000000;
const int MIN = -1000000000;
const int MOD = 1000000007;
pll p[100001];
int n, m;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	priority_queue<pair<pll, ll>> pq;
	priority_queue<ll> k;
	int now = 0;
	ll ans = 0;
	ll idx = 1;
	for (int i = 1; i <= m; i++) k.push(-i);
	for (int i = 1; i <= n; i++) {
		if (pq.size() < m) {
			pq.push({ {-(p[i].second + now),-k.top()},p[i].first });
			k.pop();
			continue;
		}
		while (!pq.empty() && (-pq.top().first.first <= now || pq.size() >= m)) {
			auto a = pq.top();
			pq.pop();
			ll x = -a.first.first;
			ll y = a.first.second;
			ll z = a.second;
			ans += (idx++) * z;
			now = x;
			k.push(-y);
		}
		pq.push({ {-(p[i].second + now),-k.top()},p[i].first });
		k.pop();
	}
	while (!pq.empty()) {
		auto a = pq.top();
		pq.pop();
		ll x = -a.first.first;
		ll y = a.first.second;
		ll z = a.second;
		ans += (idx++) * z;
	}
	cout << ans;
	return 0;
}

