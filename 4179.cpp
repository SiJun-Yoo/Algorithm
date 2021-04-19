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
typedef priority_queue<ll> pqll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
const ll MOD = 1000000000;
const int MAX = 1000000000;
const int MIN = -987654321;
const int IDX = 200001;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
string str[1000];
qii f;
qii q;
int chkF[1000][1000];
int chk[1000][1000];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		for (int j = 0; j < m; j++) {
			if (str[i][j] == 'J') {
				chk[i][j] = 1;
				q.push({ i,j });
			}
			if (str[i][j] == 'F') {
				chkF[i][j] = 1;
				f.push({ i,j });
			}
		}
	}
	int ans = MAX;
	while (!q.empty()) {
		int size1 = q.size();
		while (size1--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (chkF[x][y]) continue;
			for (int i = 0; i < 4; i++) {
				int mx = x + dx[i];
				int my = y + dy[i];
				if (mx == -1 || my == -1 || mx == n || my == m) {
					cout << chk[x][y];
					return 0;
				}
				if (str[mx][my] == '#') continue;
				if (chkF[mx][my]) continue;
				if (chk[mx][my]) continue;
				chk[mx][my] = chk[x][y] + 1;
				q.push({ mx,my });
			}
		}
		int size2 = f.size();
		while (size2--) {
			int x = f.front().first;
			int y = f.front().second;
			f.pop();
			for (int i = 0; i < 4; i++) {
				int mx = x + dx[i];
				int my = y + dy[i];
				if (mx < 0 || my < 0 || mx >= n || my >= m) continue;
				if (str[mx][my] == '#') continue;
				if (chkF[mx][my]) continue;
				chkF[mx][my] = chkF[x][y] + 1;
				f.push({ mx,my });
			}
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}