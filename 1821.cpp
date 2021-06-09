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
int n,m;
int d[11][11];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	d[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i][j] = d[i-1][j - 1] + d[i-1][j];
		}
	}
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	do {
		int now = 0;
		for (int i = 0; i < n; i++) {
			now += d[n][i + 1] * v[i];
		}
		if (now == m) {
			break;
		}
	} while (next_permutation(begin(v), end(v)));
	for (int a : v) {
		cout << a << ' ';
	}
	return 0;
}

