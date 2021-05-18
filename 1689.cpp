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
int n;
pqi pq;
pii p[1000000];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n);
	pq.push(-p[0].second);
	int ans = 1;
	for (int i = 1; i < n; i++) {
		int s = p[i].first;
		int e = p[i].second;
		while (!pq.empty()&&-pq.top() <= s) {
			pq.pop();
		}
		pq.push(-e);
		ans = max(ans, (int)pq.size());
	}
	cout << ans;
	return 0;
}
