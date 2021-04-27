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
typedef vector<int> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
const ll MOD = 1000000007;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int chk1[500001][21];
int chk2[500001][21];
queue<pii> q;
int n, a, b;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		int k = pow(2, cnt);
		int next1 = x + k;
		int next2 = x - k;
		if (next1 <= n && !chk1[next1][cnt + 1]) {
			q.push({ next1,cnt + 1 });
			chk1[next1][cnt + 1] = 1;
		}
		if (next2 >= 1 && !chk1[next2][cnt + 1]) {
			q.push({ next2,cnt + 1 });
			chk1[next2][cnt + 1] = 1;
		}
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> a >> b;
	q.push({ a,0 });
	chk1[a][0] = 1;
	bfs();
	chk2[b][0] = 1;
	q.push({ b,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (chk1[x][cnt] && chk2[x][cnt]) {
			cout << cnt;
			return 0;
		}
		int k = pow(2, cnt);
		int next1 = x + k;
		int next2 = x - k;
		if (next1 <= n && !chk2[next1][cnt + 1]) {
			q.push({ next1,cnt + 1 });
			chk2[next1][cnt + 1] = 1;
		}
		if (next2 >= 1 && !chk2[next2][cnt + 1]) {
			q.push({ next2,cnt + 1 });
			chk2[next2][cnt + 1] = 1;
		}
	}
	cout << -1;
	return 0;
}