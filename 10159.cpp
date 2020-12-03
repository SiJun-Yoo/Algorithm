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
int arr[101][101];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		arr[s][e] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] && arr[k][j]) arr[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (!arr[i][j] && !arr[j][i]) tmp++;
		}
		cout << tmp << '\n';
	}
	return 0;
}