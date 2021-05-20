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
typedef priority_queue<ll> pql;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
const int MOD = 1000000007;
const ll MAX = 1000000000000000ll;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
vector<pll> v[100001];
ll dist[100001];
priority_queue<pll> pq;
bool chk[100001];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	ll n, m, s, e, c;
	cin >> n >> m >> s >> e >> c;
	ll l = 1;
	ll r = 0;
	for (int i = 0; i < m; i++) {
		ll a, b, cost;
		cin >> a >> b >> cost;
		r = max(r, cost);
		v[a].push_back({ b,cost });
		v[b].push_back({ a,cost });
	}
	ll ans = -1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		for (int i = 1; i <= n; i++) {
			dist[i] = MAX;
		}
		memset(chk, 0, sizeof(chk));
		dist[s] = 0;
		pq.push({ 0,s });
		while (!pq.empty()) {
			ll x = pq.top().second;
			pq.pop();
			if (chk[x]) continue;
			chk[x] = true;
			int size = v[x].size();
			for (int i = 0; i < size; i++) {
				int next = v[x][i].first;
				ll cost = v[x][i].second;
				if (cost > mid) continue;
				if (dist[next] > dist[x] + cost) {
					dist[next] = dist[x] + cost;
					pq.push({ -dist[next],next });
				}
			}
		}
		if (dist[e] <= c) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
