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
int parent[200001];
int a[200001];
int n;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	memset(parent, -1, sizeof(parent));
	cin >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		k = max(k, a[i]);
	}
	for (int i = 1; i < n; i++) {
		if (a[i] == a[0]) continue;
		if (parent[a[i]] == -1) {
			parent[a[i]] = a[i - 1];
		}
	}
	cout << k + 1 << '\n';
	for (int i = 0; i <= k; i++) {
		cout << parent[i] << ' ';
	}
	return 0;
}