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
bool chk[301][301][2];
queue<pair<pii, int>> q;
int n, m, k, t;
int dx[8] = { 2,2,1,1,-2,-2,-1,-1 };
int dy[8] = { 1,-1,2,-2,1,-1,2,-2 };
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m >> k >> t;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		q.push({ {a,b},0 });
		chk[a][b][0] = 1;
	}
	vii v(k);
	for (int i = 0; i < k; i++) {
		cin >> v[i].first >> v[i].second;
	}
	int time = t;
	int z = 0;
	int cnt = 0;
	while (time--) {
		int size = q.size();
		if (cnt >= 160) {
			if ((cnt & 1) == (t & 1)) break;
		}
		while (size--) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int z = q.front().second;
			q.pop();
			chk[x][y][z % 2] = 0;
			for (int i = 0; i < 8; i++) {
				int mx = x + dx[i];
				int my = y + dy[i];
				if (0 >= mx || mx > n || 0 >= my || my > n) continue;
				if (chk[mx][my][!z]) continue;
				chk[mx][my][!z] = 1;
				q.push({ { mx,my},!z });
			}
		}
		cnt++;
	}
	for (pii a : v) {
		if (chk[a.first][a.second][t & 1]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}