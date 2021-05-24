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
int a[100001];
pair<pii, int> p[100001];
pii k[100001];
bool cmp(pair<pii, int> x, pair<pii, int> y) {
	if (x.first.first == y.first.first) return x.first.second < y.first.second;
	return x.first.first < y.first.first;
}
int find(int x) {
	if (a[x] == x) return x;
	return a[x] = find(a[x]);
}
void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	a[x] = y;
	k[y].first = min(k[y].first, k[x].first);
	k[y].second = max(k[y].second, k[x].second);
	return;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		a[i] = i;
		int x, y, z;
		cin >> x >> y >> z;
		k[i].first = x;
		k[i].second = y;
		p[i] = { {x,y},i };
	}
	sort(p + 1, p + 1 + n, cmp);
	for (int i = 2; i <= n; i++) {
		int x = find(p[i - 1].second);
		if (k[x].second < p[i].first.first) continue;
		Union(x, p[i].second);
	}
	while (q--) {
		int s, e;
		cin >> s >> e;
		if (find(s) == find(e)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}

