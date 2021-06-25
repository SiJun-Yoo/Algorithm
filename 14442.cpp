#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef queue<pair<int, int>> qii;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
const int MAX = 1000000000;
const int MIN = -1000000000;
const int MOD = 1000000007;
int n, m, k;
int c[1001][1001];
int d[1001][1001][11];
queue<pair<pii, int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		if (x == n && y == m) {
			return d[x][y][z];
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mx = x + dx[i];
			int my = y + dy[i];
			if (mx<1 || my<1 || mx>n || my>m) continue;
			if (c[mx][my]) {
				if (z == k) continue;
				if (d[mx][my][z + 1]) continue;
				q.push({ {mx,my},z + 1 });
				d[mx][my][z + 1] = d[x][y][z] + 1;
			}
			else {
				if (d[mx][my][z]) continue;
				q.push({ {mx,my},z });
				d[mx][my][z] = d[x][y][z] + 1;
			}
		}
	}
	return -1;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			c[i][j] = str[j - 1]-'0';
		}
	}
	q.push({ {1,1},0 });
	d[1][1][0] = 1;
	cout<<bfs();
	return 0;
}

