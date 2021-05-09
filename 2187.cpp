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
int d[1000];
pii p[1000];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, a, b;
	cin >> n >> a >> b;
	vector<pair<int, pii>> v;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second >> d[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int minX = min(p[i].first, p[j].first);
			int minY = min(p[i].second, p[j].second);
			int maxX = max(p[i].first, p[j].first);
			int maxY = max(p[i].second, p[j].second);
			if (maxX - minX + 1 > a) continue;
			if (maxY - minY + 1 > b) continue;
			ans = max(ans, (max(d[i], d[j]) - min(d[i], d[j])));
		}
	}
	cout << ans;
	return 0;
}
