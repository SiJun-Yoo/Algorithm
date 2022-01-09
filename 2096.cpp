#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<memory.h>
#include <queue>
#include<math.h>
#include<utility>
#include<stack>
#include<set>
using namespace std;
int arr[100001][3];
int dpMin[2][3];
int dpMax[2][3];
int N;
int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	dpMin[0][0] = dpMax[0][0] = arr[1][0];
	dpMin[0][1] = dpMax[0][1] = arr[1][1];
	dpMin[0][2] = dpMax[0][2] = arr[1][2];
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			dpMin[1][j] = 100000000;
			dpMax[1][j] = 0;
			for (int k = 0; k < 3; k++) {
				if (j == 0 && k == 2) continue;
				if (j == 2 && k == 0) continue;
				dpMin[1][j] = min(dpMin[1][j], dpMin[0][k] + arr[i][j]);
				dpMax[1][j] = max(dpMax[1][j], dpMax[0][k] + arr[i][j]);
			}
		}
		for (int k = 0; k < 3; k++) {
			dpMin[0][k] = dpMin[1][k];
			dpMax[0][k] = dpMax[1][k];
		}
	}
	int ansMax = 0;
	int ansMin = 100000000;
	for (int i = 0; i < 3; i++) {
		ansMax = max(dpMax[0][i], ansMax);
		ansMin = min(dpMin[0][i], ansMin);
	}
	cout << ansMax << ' ' << ansMin;
	return 0;
}
