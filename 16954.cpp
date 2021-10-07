#include<bits/stdc++.h>
using namespace std;
char c[8][8];
bool chk[8][8][9];
int n;
struct Node {
	int x;
	int y;
	int cnt;
};
queue<Node> q;
int dx[9] = { 0,0,0,1,-1,1,1,-1,-1 };
int dy[9] = { 0,1,-1,0,0,-1,1,1,-1 };
bool bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();
		if (x == 7 && y == 7) return true;
		for (int i = 0; i < 8; i++) {
			int mx = x + dx[i];
			int my = y + dy[i];
			int k = min(cnt + 1, 8);
			if (mx < 0 || my < 0 || mx >= 8 || my >= 8) continue;
			if (chk[mx][my][k]) continue;
			if (mx + cnt < 8 && c[mx + cnt][my] == '#') continue;
			if (mx + k < 8 && c[mx + k][my] == '#') continue;
			chk[mx][my][k] = true;
			q.push({ mx,my,k });
		}
	}
	return false;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			cin >> c[i][j];
		}
	}
	q.push({ 0,0,0 });
	chk[0][0][0] = 1;
	cout << bfs();
	return 0;
}

