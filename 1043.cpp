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
int parent[51];
int arr[51][51];
bool chk[51];
int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}
int Union(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x == y) return 1;
	parent[x] = y;
	return 0;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(k + 1);
	for (int i = 1; i <= k; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int a;
		cin >> a;
		for (int j = 1; j <= a; j++) {
			cin >> arr[i][j];
		}
		for (int j = 2; j <= a; j++) {
			Union(arr[i][j - 1], arr[i][j]);
		}
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= m; j++) {
			int idx = 1;
			while (arr[j][idx] != 0) {
				int x = find(arr[j][idx++]);
				int y = find(v[i]);
				if (x == y) {
					chk[j] = 1;
					break;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (!chk[i]) ans++;
	}
	cout << ans;
	return 0;
}
