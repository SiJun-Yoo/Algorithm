#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef queue<pair<int, int>> qii;
typedef queue<pair<ll, ll>> qll;
typedef queue<int> qi;
int parent[1001];
int degree[1001];
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
bool Union(int x, int y) {
	int rx = find(x);
	int ry = find(y);
	if (rx == ry) return false;
	parent[rx] = ry;
	return true;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		parent[i] = i;
	}
	priority_queue<pair<ll, pii>> pq;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ c,{a,b} });
		degree[a]++;
		degree[b]++;
	}
	ll ans = 0;
	while (!pq.empty()) {
		ll cost = pq.top().first;
		int s = pq.top().second.first;
		int e = pq.top().second.second;
		pq.pop();
		if (Union(s, e)) {
			ans += cost;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (Union(1,i)) {
			cout << -1;
			return 0;
		}
	}
	cout << ans;
	return 0;
}