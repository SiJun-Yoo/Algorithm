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
const ll MAX = 100000000000ll;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool chk[100001];
ll dist[100001];
int n, m, k;
vector<pll> v[100001];
priority_queue<pll> pq;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i <= n; i++) {
		dist[i] = MAX;
	}
	for (int i = 0; i < m; i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		v[e].push_back({ s,cost });
	}
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		v[0].push_back({ x,0 });
	}
	dist[0] = 0;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		auto a = pq.top();
		pq.pop();
		int x = a.second;
		if (chk[x]) continue;
		chk[x] = true;
		int size = v[x].size();
		for (int i = 0; i < size; i++) {
			int next = v[x][i].first;
			ll cost = v[x][i].second;
			if (dist[next] > dist[x] + cost) {
				dist[next] = dist[x] + cost;
				pq.push({ -dist[next],next });
			}
		}
	}
	ll ans = 0;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < dist[i]) {
			ans = dist[i];
			idx = i;
		}
	}
	cout << idx << '\n' << ans;
	return 0;
}
