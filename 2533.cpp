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
const ll MOD = 1000;
const int MAX = 987654321;
vector<int> v[1000001];
int d[1000001][2];
int n;
int dfs(int now, int parent, int chk) {
	int& val = d[now][chk];
	if (val != -1) return val;
	val = chk;
	int size = v[now].size();
	for (int i = 0; i < size; i++) {
		int next = v[now][i];
		if (next == parent) continue;
		if (chk) val += min(dfs(next, now, 1), dfs(next, now, 0));
		else val += dfs(next, now, 1);
	}
	return val;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(d, -1, sizeof(d));
	cout << min(dfs(1, -1, 1), dfs(1, -1, 0));
	return 0;
}
