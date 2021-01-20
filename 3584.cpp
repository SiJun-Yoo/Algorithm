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
int parent[10001];
int cnt[10001];
int chk[10001];
void dfs(int vtx, int root) {
	if (chk[vtx]) {
		cout << vtx << '\n';
		return;
	}
	chk[vtx]++;
	if (vtx == root) {
		return;
	}
	dfs(parent[vtx], root);
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		memset(chk, 0, sizeof(chk));
		memset(cnt, 0, sizeof(cnt));
		memset(parent, 0, sizeof(parent));
		int n;
		cin >> n;
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			parent[b] = a;
			cnt[b]++;
		}
		int root = 0;
		for (int i = 1; i <= n; i++) {
			if (!cnt[i]) {
				root = i;
				break;
			}
		}
		int a, b;
		cin >> a >> b;
		if (a == root || b == root) {
			cout << root << '\n';
		}
		else {
			dfs(a, root);
			dfs(b, root);
		}

	}
	return 0;
}
