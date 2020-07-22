#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<memory.h>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
int inDegree[101];
int arr[101][101];
int ans[101];
int chk[101];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n>>m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
		inDegree[b]++;
		chk[a]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0)	q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		for (int j = 1; j <= n; j++) {
			if (arr[x][j]) {
				if (ans[x] == 0) ans[x] = 1;
				ans[j] += arr[x][j] * ans[x];
				if (--inDegree[j]==0) {
					q.push(j);
				}
			}			
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			cout << i << ' ' << ans[i]<<'\n';
		}
	}
}
