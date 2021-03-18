#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef queue<pair<int, int>> qii;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
const int MAX = 1000000000;
pii d[501][501];
pii a[501];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j].first = MAX;
		}
		d[i][i].first = 0;
	}
	for (int i = 0; i < m; i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		d[s][e].second = max(a[s].first, a[e].first);
		d[e][s].second = max(a[s].first, a[e].first);
		d[s][e].first = cost + d[s][e].second;
		d[e][s].first = cost + d[e][s].second;
	}
	sort(a + 1, a + n + 1);
	for (int t = 1; t <= n; t++) {
		int k = a[t].second;
		int cost = a[t].first;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int now = max(cost, max(d[i][k].second, d[k][j].second));
				int score = now - (d[i][k].second + d[k][j].second);
				if (d[i][k].first + d[k][j].first + score < d[i][j].first) {
					d[i][j].first = d[i][k].first + d[k][j].first + score;
					d[i][j].second = now;
				}
			}
		}
	}
	while (q--) {
		int s, e;
		cin >> s >> e;
		cout << (d[s][e].first >= MAX ? -1 : d[s][e].first) << '\n';
	}
}



