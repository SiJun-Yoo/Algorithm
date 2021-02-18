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
const ll MOD = 1000000007;
const int IDX = 200001;
const int MAX = 10000000;
const int MIN = -987654321;
char a[102][102];
bool chk[102][102];
int w, h, k;
bool flag;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
qii q;
int bfs() {
	int ret = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mx = x + dx[i];
			int my = y + dy[i];
			if (mx<0 || my<0 || mx>w + 1 || my>h + 1) continue;
			if (chk[mx][my]) continue;
			if (a[mx][my] == '*') continue;
			if (a[mx][my] == '$') {
				ret++;
				chk[mx][my] = true;
				a[mx][my] = '.';
				q.push({ mx,my });
				flag = false;
			}
			else if (a[mx][my] == '.') {
				chk[mx][my] = true;
				q.push({ mx,my });
			}
			else if ('a' <= a[mx][my] && a[mx][my] <= 'z') {
				int now = a[mx][my] - 'a';
				k |= (1 << now);
				chk[mx][my] = true;
				a[mx][my] = '.';
				q.push({ mx,my });
				flag = false;
			}
			else {
				int now = 1 << (a[mx][my] - 'A');
				if (k & now) {
					chk[mx][my] = true;
					a[mx][my] = '.';
					q.push({ mx,my });
				}
			}
		}
	}
	return ret;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		k = 0;
		cin >> w >> h;
		for (int i = 0; i <= w + 1; i++) {
			a[i][0] = '.';
			a[i][h + 1] = '.';
		}
		for (int i = 0; i <= h + 1; i++) {
			a[0][i] = '.';
			a[w + 1][i] = '.';
		}
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				cin >> a[i][j];
			}
		}
		string str;
		cin >> str;
		int len = str.length();
		for (int i = 0; i < len; i++) {
			int now = str[i] - 'a';
			k |= (1 << now);
		}
		int ans = 0;
		while (true) {
			memset(chk, 0, sizeof(chk));
			flag = true;
			q.push({ 0, 0 });
			chk[0][0] = true;
			ans += bfs();
			if (flag) break;
		}
		cout << ans << '\n';
	}
	return 0;
}
