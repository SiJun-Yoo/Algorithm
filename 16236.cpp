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
int n;
int arr[20][20];
int chk[20][20];
int eat[20][20];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
struct shark {
	int x;
	int y;
	int size;
};
queue<shark> q;
int bfs() {
	int ret = 0;
	int cnt = 0;
	int cost = 2;
	while (1) {
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().size;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int mx = x + dx[i];
				int my = y + dy[i];
				if (mx < 0 || mx >= n || my < 0 || my >= n) continue;
				if (chk[mx][my]) continue;
				if (arr[mx][my] > z) continue;
				if (arr[mx][my] && arr[mx][my] < z) {
					chk[mx][my] = chk[x][y] + 1;
					eat[mx][my] = chk[x][y] + 1;
				}
				else if (arr[mx][my] == 0) {
					chk[mx][my] = chk[x][y] + 1;
					q.push({ mx,my,z });
				}
				else {
					chk[mx][my] = chk[x][y] + 1;
					q.push({ mx,my,z });
				}
			}
		}
		int flag = 1;
		int tmp = 100000000;
		int x = 0;
		int y = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (eat[i][j]) {
					if (tmp > eat[i][j]) {
						x = i;
						y = j;
						tmp = eat[i][j];
					}
					flag = 0;
				}
			}
		}
		if (flag) break;
		ret += tmp - 1;
		cnt++;
		if (cnt == cost) {
			cost++;
			cnt = 0;
		}
		memset(chk, 0, sizeof(chk));
		memset(eat, 0, sizeof(eat));
		chk[x][y] = 1;
		arr[x][y] = 0;
		q.push({ x,y,cost });
	}

	return ret;
}
void chck() {

}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				chk[i][j] = 1;
				arr[i][j] = 0;
				q.push({ i,j,2 });
			}
		}
	}
	cout << bfs();
	return 0;
}