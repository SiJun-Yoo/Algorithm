#include<bits/stdc++.h>
#include<unordered_set>
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
const ll MOD = 1000000000;
const int IDX = 200001;
const int MAX = 10000000;
const int MIN = -987654321;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
pii p[100001];
int n, m;
priority_queue<pair<int, pii>> pq;
int parent[100001];
ll cnt[100001];
int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[x] = y;
	cnt[y] += cnt[x];
	return;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	ll sum = 0;
	for (int i = 0; i < m; i++) {
		ll x, y, cost;
		cin >> x >> y >> cost;
		sum += cost;
		pq.push({ cost,{x,y} });
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		cnt[i] = 1;
	}
	ll ans = 0;
	while (!pq.empty()) {
		auto a = pq.top();
		pq.pop();
		int cost = a.first;
		int x = a.second.first;
		int y = a.second.second;
		int rx = find(x);
		int ry = find(y);
		if (rx != ry) {
			ans += ((cnt[rx] * cnt[ry]) % MOD * sum) % MOD;
			Union(x, y);
			ans %= MOD;
		}
		sum -= cost;
	}
	cout << ans;
	return 0;
}