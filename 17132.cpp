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
const ll MOD = 1000000007;
const ll MAX = 1000000000;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int dist[500][500];
bool chk[500][500];
char c[500][500];
qii q;
int parent[100001];
ll cnt[100001];
priority_queue<pair<ll, pii>> pq;
int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
ll Union(int x, int y, ll cost) {
	x = find(x);
	y = find(y);
	ll ret = 0;
	if (x == y) {
		cnt[x] += cnt[y];
		ret += (cost) * (cnt[x] - 1);
		return ret;
	}
	parent[y] = x;
	ret += cnt[x] * cnt[y] * cost;
	cnt[x] += cnt[y];
	return ret;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		pq.push({ cost,{s,e} });
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		cnt[i] = 1;
	}
	ll ans = 0;
	while (!pq.empty()) {
		auto a = pq.top();
		pq.pop();
		ll cost = a.first;
		int s = a.second.first;
		int e = a.second.second;
		ans += Union(s, e, cost);
	}
	cout << ans;
	return 0;
}
