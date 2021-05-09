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
const ll MOD = 1000000007;
const ll MAX = 1000000000;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int dist[500][500];
bool chk[500][500];
char c[500][500];
qii q;
int n, m;
void getDist() {
	while (!q.empty()) {
		auto a = q.front();
		q.pop();
		int x = a.first;
		int y = a.second;
		for (int i = 0; i < 4; i++) {
			int mx = x + dx[i];
			int my = y + dy[i];
			if (mx < 0 || my < 0 || mx >= n || my >= m) continue;
			if (dist[mx][my]) continue;
			dist[mx][my] = dist[x][y] + 1;
			q.push({ mx,my });
		}
	}
}
bool bfs(int cnt, int kx, int ky) {
	bool ret = false;
	while (!q.empty()) {
		auto a = q.front();
		q.pop();
		int x = a.first;
		int y = a.second;
		if (x == kx && y == ky) {
			ret = true;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int mx = x + dx[i];
			int my = y + dy[i];
			if (mx < 0 || my < 0 || mx >= n || my >= m) continue;
			if (chk[mx][my]) continue;
			if (dist[mx][my] - 1 < cnt) continue;
			chk[mx][my] = 1;
			q.push({ mx,my });
		}
	}
	while (!q.empty()) {
		q.pop();
	}
	return ret;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	int rx = 0, ry = 0;
	int kx = 0, ky = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			c[i][j] = str[j];
			if (c[i][j] == '+') {
				dist[i][j] = 1;
				q.push({ i,j });
			}
			if (c[i][j] == 'V') {
				rx = i;
				ry = j;
			}
			if (c[i][j] == 'J') {
				kx = i;
				ky = j;
			}
		}
	}
	getDist();
	int l = 0, r = 500;
	int ans = 0;
	while (l <= r) {
		memset(chk, 0, sizeof(chk));
		int mid = (l + r) / 2;
		q.push({ rx,ry });
		chk[rx][ry] = 1;
		if (dist[rx][ry] - 1 < mid) {
			r = mid - 1;
			continue;
		}
		if (dist[kx][ky] - 1 < mid) {
			r = mid - 1;
			continue;
		}
		if (bfs(mid, kx, ky)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
