#include<bits/stdc++.h>
#define MOD 1000000007ll
#define MAX 200000000
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
int n, m;
int a[50][50];
int chk[13];
vector<pii> c;
vector<pii> h;
int ans = MAX;
void solve(int idx, int depth) {
	if (depth == m) {
		int cSize = c.size();
		int hSize = h.size();
		int ret = 0;
		for (int i = 0; i < hSize; i++) {
			int k = MAX;
			for (int j = 0; j < cSize; j++) {
				if (chk[j]) k = min(k, abs(c[j].first - h[i].first) + abs(c[j].second - h[i].second));
			}
			ret += k;
		}
		ans = min(ans, ret);
		return;
	}
	if (idx == c.size()) return;
	chk[idx]++;
	solve(idx + 1, depth + 1);
	chk[idx]--;
	solve(idx + 1, depth);
	return;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				h.push_back({ i,j });
			}
			if (a[i][j] == 2) {
				c.push_back({ i,j });
			}
		}
	}
	solve(0, 0);
	cout << ans;
	return 0;
}