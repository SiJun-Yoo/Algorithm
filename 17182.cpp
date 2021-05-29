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
int n, m;
int a[10][10];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > a[i][k] + a[k][j]) {
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}
	vector<int> v(n);
	for (int i = 0; i < n; i++) v[i] = i;
	int ans = MAX;
	int size = v.size();
	do {
		if (v[0] != m) continue;
		int now = 0;
		for (int i = 1; i < size; i++) {
			now += a[v[i - 1]][v[i]];
		}
		ans = min(ans, now);
	} while (next_permutation(begin(v), end(v)));
	cout << ans;
	return 0;
}

