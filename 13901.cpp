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
	int idx = 0; //�̵����� ����
	int cnt = 0; //4���� Ž�� ����Ȯ��
	chk[x][y] = 1;
	while (1) {
		if (cnt == 4) break; //4������ Ž���ص� ������ ������ �̵��Ұ��� �Ǵ�
		if (idx == 4) idx = 0; //idx�� 4�� �ٽ� ù��° �������� ����
		int nx = dx[v[idx] - 1] + x; //idx�� �´� �������� �̵�
		int ny = dy[v[idx] - 1] + y; //idx�� �´� �������� �̵�
		if (!isSafe(nx, ny)) { //�����ȿ� �ִ��� Ȯ��
			cnt++;
			idx++;
			continue;
		}
		if (chk[nx][ny]) { //�湮�ߴ��� Ȯ��
			cnt++;
			idx++;
			continue;
		}
		if (a[nx][ny] == 1) { //��ֹ����� Ȯ��
			cnt++;
			idx++;
			continue;
		}
		chk[nx][ny] = 1; //�̵������̶� �湮���� ǥ��
		x = nx; //�̵�
		y = ny; //�̵�
		cnt = 0; //cnt�ʱ�ȭ
	}
	cout << x << ' ' << y; //������ġ ���
}