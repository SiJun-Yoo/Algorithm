#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
int d[10001][10001];
int n;
 int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		memset(d, 0, sizeof(d));
		for (int _i = 0; _i < n; _i++) {
			int x, y;
			cin >> x >> y;
			for (int i = y; i <= y + 10; i++) {
				if (i > 10000) break;
				for (int j = x; j <= x + 10; j++) {
					if (j > 10000) break;
					d[i][j]++;
					ans = max(ans, d[i][j]);
				}
			}
		}
		cout << ans << '\n';
	}
}
