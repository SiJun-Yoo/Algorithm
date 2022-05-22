#include<iostream>
using namespace std;
int arr[301][301] = {};
int dp[301][301] = {};
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			cin >> arr[i][j];
			dp[i][j] += dp[i][j-1]+arr[i][j];
		}
	}
	int K,i,j,x,y;
	cin >> K;
	for (int h = 0; h < K; h++) {
		int ans = 0, ans2 = 0;
		cin >> i >> j >> x >> y;
		if (i == x && j == y) {
			cout << arr[i][j] << "\n";
		}
		else {
			for (int q = i; q < x + 1; q++) {
				ans += dp[q][y];
			}
			for (int q = i; q < x+1; q++) {
				ans2 += dp[q][j-1];
			}
			cout << ans-ans2<<"\n";
		}
	}
	return 0;
}
