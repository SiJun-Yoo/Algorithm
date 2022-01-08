#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef queue<pii> qii;
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
int n, m;
int a[101][71];
bool b[101][71];
qii q;
bool bfs() {
	bool flag = true;
	while (!q.empty()) {
		auto k = q.front();
		q.pop();
		int x = k.first;
		int y = k.second;
		for (int i = 0; i < 8; i++) {
			int mx = x + dx[i];
			int my = y + dy[i];
			if (mx <= 0 || my <= 0 || mx > n || my > m) continue;
			if (a[x][y] < a[mx][my]) flag = false;
			if (a[mx][my] != a[x][y]) continue;
			if (b[mx][my]) continue;
			b[mx][my] = true;
			q.push({ mx,my });
		}
	}
	return flag;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[i][j]) continue;
			b[i][j] = true;
			q.push({ i,j });
			if (bfs()) ans++;
		}
	}
	cout << ans;
	return 0;
}
