#define MAX 2000000000
#define MOD 1000000007
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
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int arr[401][401];
int d[401][401];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int s, e;
		cin >> s >> e;
		arr[s][e] = 1;
	}
	for (int l = 1; l <= n; l++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][l] && arr[l][j]) arr[i][j] = 1;
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int s, e;
		cin >> s >> e;
		if (arr[s][e]) cout << -1;
		else if (arr[e][s]) cout << 1;
		else cout << 0;
		cout << '\n';
	}
	return 0;
}