#include<bits/stdc++.h>
#define MOD 1000000007ll
#define MAX 2000000000ll
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
ll arr[3002][3002];
ll d[3002][3002];
ll lrr[3003][3003];
ll rrr[3003][3003];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[b + 1501][a + 1501]++;
	}
	for (int i = 1; i <= 3001; i < i++) {
		for (int j = 1; j <= 3001; j++) {
			d[i][j] = arr[i][j] + rrr[i - 1][j - 1] + d[i - 1][j] + lrr[i - 1][j + 1];
			lrr[i][j] = lrr[i - 1][j + 1] + arr[i][j];
			rrr[i][j] = rrr[i - 1][j - 1] + arr[i][j];
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << d[b + 1501][a + 1501] << '\n';
	}
	return 0;
}