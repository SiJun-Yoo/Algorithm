#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
int r, c;
int a[1000][1000];
int chk[1000][1000];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool isSafe(int x, int y) { 
	if (0 <= x && x < r && 0 <= y && y < c) return 1;
	return 0;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> r >> c;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
	}
	int x, y;
	cin >> x >> y;
	vector<int> v(4);
	for (int i = 0; i < 4; i++) {
		cin >> v[i];
	}
	int idx = 0; //이동방향 결정
	int cnt = 0; //4방향 탐색 가능확인
	chk[x][y] = 1;
	while (1) {
		if (cnt == 4) break; //4방향을 탐색해도 변함이 없으면 이동불가로 판단
		if (idx == 4) idx = 0; //idx가 4면 다시 첫번째 방향으로 변경
		int nx = dx[v[idx] - 1] + x; //idx에 맞는 방향으로 이동
		int ny = dy[v[idx] - 1] + y; //idx에 맞는 방향으로 이동
		if (!isSafe(nx, ny)) { //범위안에 있는지 확인
			cnt++;
			idx++;
			continue;
		}
		if (chk[nx][ny]) { //방문했는지 확인
			cnt++;
			idx++;
			continue;
		}
		if (a[nx][ny] == 1) { //장애물인지 확인
			cnt++;
			idx++;
			continue;
		}
		chk[nx][ny] = 1; //이동가능이라 방문했음 표시
		x = nx; //이동
		y = ny; //이동
		cnt = 0; //cnt초기화
	}
	cout << x << ' ' << y; //최종위치 출력
}