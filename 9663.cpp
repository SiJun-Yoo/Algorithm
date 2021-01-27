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
int n;
bool col[14];
bool r[28];
bool l[28];
int solve(int cnt) {
	if (cnt == n) return 1;
	int ret = 0;
	int x = cnt;
	for (int y = 0; y < n; y++) {
		if (!col[y] && !r[x + y] && !l[(x - y) + (n - 1)]) {
			col[y] = true;
			r[x + y] = true;
			l[x - y + (n - 1)] = true;
			ret += solve(cnt + 1);
			col[y] = false;
			r[x + y] = false;
			l[(x - y) + (n - 1)] = false;
		}
	}
	return ret;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	cout << solve(0);
	return 0;
}
