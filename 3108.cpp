#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef queue<int> qi;
typedef queue<pair<int, int>> qii;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
const int MOD = 1000000007;
const int MAX = 1002002;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int a[2001][2001];
int n;
int chk[2001][2001];
qii q;
void bfs() {
	while (!q.empty()) {
		auto k = q.front();
		q.pop();
		int x = k.first;
		int y = k.second;
		for (int i = 0; i < 4; i++) {
			int mx = x + dx[i];
			int my = y + dy[i];
			if (mx < 0 || my < 0 || mx>2000 || my>2000) continue;
			if (!a[mx][my]) continue;
			if (chk[mx][my]) continue;
			q.push({ mx,my });
			chk[mx][my] = 1;
		}
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int sx, sy, ex, ey;
		cin >> sy >> sx >> ey >> ex;
		sx = (sx + 500) * 2;
		sy = (sy + 500) * 2;
		ex = (ex + 500) * 2;
		ey = (ey + 500) * 2;
		for (int j = sx; j <= ex; j++) {
			a[j][sy] = 1;
			a[j][ey] = 1;
		}
		for (int j = sy; j <= ey; j++) {
			a[sx][j] = 1;
			a[ex][j] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= 2000; j++) {
			if (chk[i][j]) continue;
			if (a[i][j]) {
				ans++;
				q.push({ i,j });
				chk[i][j] = 1;
				bfs();
			}
		}
	}
	if (chk[1000][1000]) ans--;
	cout << ans;
	return 0;
}
