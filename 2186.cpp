#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int d[101][101][81];
string s[101];
int n, m, k;
string target;
int solve(int x, int y, int cnt) {
	if (d[x][y][cnt] != -1) return d[x][y][cnt];
	if (cnt == target.length()) return 1;
	int& val = d[x][y][cnt];
	val = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= k; j++) {
			int mx = x + dx[i] * j;
			int my = y + dy[i] * j;
			if (mx < 0 || my < 0 || mx >= n || my >= m) continue;
			if (s[mx][my] != target[cnt]) continue;
			val += solve(mx, my, cnt + 1);
		}		
	}
	return val;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	memset(d, -1, sizeof(d));
	cin >> target;
	char start = target[0];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] != start) continue;
			ans += solve(i, j, 1);
		}
	}
	cout << ans;
}
