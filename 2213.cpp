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
vector<int> v;
vector<int> tree[10001];
vector<int> ans;
int d[10001][2];
int visited[10001];
int solve(int now, int chk, int parent) {
	if (d[now][chk] != -1) return d[now][chk];
	int& val = d[now][chk];
	val = 0;
	int size = tree[now].size();
	if (chk) val = v[now];
	for (int i = 0; i < size; i++) {
		int next = tree[now][i];
		if (parent == next) continue;
		if (chk) {
			val += solve(next, 0, now);
		}
		else {
			int a = solve(next, 1, now);
			int b = solve(next, 0, now);
			val += max(a, b);
		}
	}
	return val;
}
void dfs(int now, int parent, int chk) {
	int size = tree[now].size();
	if (chk) ans.push_back(now);
	for (int i = 0; i < size; i++) {
		int next = tree[now][i];
		if (next == parent) continue;
		if (chk) {
			dfs(next, now, 0);
		}
		else {
			if (d[next][chk] > d[next][!chk]) {
				dfs(next, now, 0);
			}
			else {
				dfs(next, now, 1);
			}
		}
	}


}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	v = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int s, e;
		cin >> s >> e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}
	memset(d, -1, sizeof(d));
	int k = max(solve(1, 1, -1), solve(1, 0, -1));
	cout << k << '\n';
	dfs(1, -1, k == d[1][1]);
	sort(begin(ans), end(ans));
	for (int a : ans) {
		cout << a << " ";
	}
	return 0;
}
