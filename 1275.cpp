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
const ll MOD = 1000;
const int MAX = 100001;
ll tree[4 * MAX];
ll arr[MAX];
ll init(int node, int s, int e) {
	if (s == e) return tree[node] = arr[s];
	int mid = (s + e) / 2;
	return tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
}
ll query(int node, int l, int r, int s, int e) {
	if (l > e || r < s) return 0;
	if (s <= l && r <= e) return tree[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, s, e) + query(node * 2 + 1, mid + 1, r, s, e);
}
void update(int node, int x, ll val, int s, int e) {
	if (s == e) {
		tree[node] = val;
		return;
	}
	int mid = (s + e) / 2;
	if (x <= mid) update(node * 2, x, val, s, mid);
	else update(node * 2 + 1, x, val, mid + 1, e);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, 1, n);
	while (m--) {
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		cout << query(1, 1, n, min(x, y), max(x, y)) << '\n';
		update(1, a, b, 1, n);
	}
	return 0;
}
