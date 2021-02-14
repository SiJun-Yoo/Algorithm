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
const int IDX = 100001;
const ll MAX = 2000000001;
const int MIN = -987654321;
pii p[IDX];
bool cmp(pii a, pii b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		p[i].first = min(a, b);
		p[i].second = max(a, b);

	}
	sort(p, p + n, cmp);
	int d;
	cin >> d;
	pqi pq;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (pq.empty()) {
			if (p[i].first + d >= p[i].second) {
				pq.push(-p[i].first);
				ans = max(ans, 1);
			}
		}
		else {
			if (p[i].second - p[i].first > d) continue;
			while (!pq.empty() && -pq.top() + d < p[i].second) {
				pq.pop();
			}
			pq.push(-p[i].first);
			ans = max(ans, (int)pq.size());
		}
	}
	cout << ans;
	return 0;
}
