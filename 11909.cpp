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
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };
int arr[2223][2223];
int d[2223][2223];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			d[i][j] = MAX;
		}
	}
	d[1][1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < 2; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (x <= 0 || y <= 0 || x > n || y > n) continue;
				if (arr[i][j] > arr[x][y]) d[x][y] = min(d[i][j], d[x][y]);
				else d[x][y] = min(d[x][y], d[i][j] + (arr[x][y] - arr[i][j] + 1));
			}
		}
	}
	cout << d[n][n];
	return 0;
}