#include<bits/stdc++.h>
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
const ll MOD = 1000;
const int MAX = 987654321;
int dist[500];
bool visited[500];
priority_queue<pii> pq;
void solve(vector<pii> v[]) {
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second;
		pq.pop();
		if (visited[x]) continue;
		visited[x] = true;
		int size = v[x].size();
		for (int i = 0; i < size; i++) {
			int e = v[x][i].first;
			int c = v[x][i].second;
			if (e == -1) continue;
			if (dist[e] > dist[x] + c) {
				dist[e] = dist[x] + c;
				pq.push({ -dist[e],e });
			}
		}
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	while (1) {
		int n, m;
		cin >> n >> m;
		if (!(n | m)) break;
		int s, e;
		cin >> s >> e;
		vector<pii> v[500];
		vector<pii> rv[500];
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
			rv[b].push_back({ a,c });
		}
		for (int i = 0; i < n; i++) {
			dist[i] = MAX;
		}
		dist[s] = 0;
		pq.push({ 0,s });
		memset(visited, 0, sizeof(visited));
		solve(v);
		queue<int> q;
		q.push(e);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			int size = rv[x].size();
			for (int i = 0; i < size; i++) {
				int now = rv[x][i].first;
				if (dist[x] == dist[now] + rv[x][i].second) {
					rv[x][i].first = -1;
					q.push(now);
				}
			}
		}
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) {
			dist[i] = MAX;
		}
		dist[e] = 0;
		pq.push({ 0,e });
		solve(rv);
		(dist[s] == MAX) ? cout << -1 : cout << dist[s];
		cout << '\n';
	}
	return 0;
}
