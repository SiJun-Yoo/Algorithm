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
int n, m, k;
vector<pii> v[10001];
int d[10001];
priority_queue<int> pq;
int dfs(int now, int parent) {
	int size = v[now].size();
	for (int i = 0; i < size; i++) {
		int k = 0;
		int next = v[now][i].first;
		int nextCost = v[now][i].second;
		if (next == parent) continue;
		d[now] = max(d[now], dfs(next, now) + nextCost);
	}
	return d[now];
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int s, e, cost;
	int root = 0;
	while (true) {
		if (cin.eof()) break;
		cin >> s;
		if (cin.eof()) break;
		cin >> e;
		if (cin.eof()) break;
		cin >> cost;
		if (!root) root = s;
		v[s].push_back({ e,cost });
		v[e].push_back({ s,cost });
	}
	dfs(root, 0);
	int ans = 0;
	if (v[root].size() <= 1) {
		ans = d[root];
	}
	else {
		for (int i = 0; i < v[root].size(); i++) {
			pq.push(d[v[root][i].first] + v[root][i].second);
		}
		ans += pq.top();
		pq.pop();
		ans += pq.top();
	}
	cout << ans;
	return 0;
}