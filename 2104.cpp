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
const int MAX = 10000000;
const int MIN = -987654321;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
ll tree[4 * 100001];
ll d[100001];
ll a[100001];
int n;
void init(int node, int s, int e) {
	if (s == e) {
		tree[node] = s;
		return;
	}
	int mid = (s + e) / 2;
	init(node * 2, s, mid);
	init(node * 2 + 1, mid + 1, e);
	if (a[tree[node * 2]] < a[tree[node * 2 + 1]]) {
		tree[node] = tree[node * 2];
	}
	else {
		tree[node] = tree[node * 2 + 1];
	}
}
ll query(int node, int l, int r, int s, int e) {
	if (e < l || r < s) return n + 1;
	if (s <= l && r <= e) return tree[node];
	int mid = (l + r) / 2;
	int aa = query(node * 2, l, mid, s, e);
	int bb = query(node * 2 + 1, mid + 1, r, s, e);
	if (a[aa] < a[bb]) {
		return aa;
	}
	else {
		return bb;
	}
}
ll solve(int s, int e) {
	if (e < s) return 0;
	if (s == e) return a[s] * a[s];
	ll now = query(1, 1, n, s, e);
	return max(a[now] * (d[e] - d[s - 1]), max(solve(s, now - 1), solve(now + 1, e)));
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = d[i - 1] + a[i];
	}
	init(1, 1, n);
	a[n + 1] = MAX;
	cout << solve(1, n);
	return 0;
}
