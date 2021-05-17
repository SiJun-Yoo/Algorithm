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
const int MAX = 1000000000;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int dist[1001];
bool chk[1001];
bool b[1001];
vii v[1001];
int path[1001];
priority_queue<pii> pq;
pii p[5000];
int n, m;
void dijk(int s, int e) {
	while (!pq.empty()) {
		auto a = pq.top();
		int idx = a.second;
		pq.pop();
		if (chk[idx]) continue;
		chk[idx] = true;
		int size = v[idx].size();
		for (int i = 0; i < size; i++) {
			int next = v[idx][i].first;
			int cost = v[idx][i].second;
			if (s == idx && e == next) continue;
			if (e == idx && s == next) continue;
			if (dist[next] > dist[idx] + cost) {
				dist[next] = dist[idx] + cost;
				pq.push({ -dist[next],next });
			}

		}
	}
}
void solve(int now, int cost) {
	if (!cost) return;
	int size = v[now].size();
	for (int i = 0; i < size; i++) {
		int next = v[now][i].first;
		if (b[next])continue;
		if (cost - v[now][i].second == dist[next]) {
			path[now] = next;
			solve(next, cost - v[now][i].second);
		}
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int cost;
		cin >> p[i].first >> p[i].second >> cost;
		v[p[i].second].push_back({ p[i].first,cost });
		v[p[i].first].push_back({ p[i].second,cost });
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = MAX;
	}
	dist[1] = 0;
	pq.push({ 0,1 });
	dijk(-1, -1);
	b[n] = 1;
	solve(n, dist[n]);
	int k = dist[n];
	int ans = 0;
	int now = n;

	while (now != 1) {
		int s = now;
		int e = path[now];
		for (int i = 1; i <= n; i++) {
			dist[i] = MAX;
		}
		memset(chk, 0, sizeof(chk));
		dist[1] = 0;
		pq.push({ 0,1 });
		dijk(s, e);
		if (dist[n] == MAX) {
			cout << -1;
			return 0;
		}
		ans = max(ans, dist[n]);
		now = path[now];
	}
	cout << ans - k;
	return 0;
}
