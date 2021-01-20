#include<bits/stdc++.h>
#define MOD 1000000007ll
#define MAX 200000000
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
bool chk[1002];
int dist[1002];
vector<pii> v[1002];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int num;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num;
			if (!num) continue;
			v[i].push_back({ j,num });
			v[j].push_back({ i,num });
		}
	}
	int p, q;
	cin >> p >> q;
	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;
		v[0].push_back({ a,-b });
	}
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back({ n + 1,-b });
	}
	for (int i = 0; i <= n + 1; i++) {
		dist[i] = MAX;
	}
	dist[0] = 0;
	priority_queue<pii> pq;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second;
		pq.pop();
		if (chk[x]) continue;
		chk[x] = true;
		int size = v[x].size();
		for (int i = 0; i < size; i++) {
			int e = v[x][i].first;
			int c = v[x][i].second;
			if (dist[e] > dist[x] + c) {
				dist[e] = dist[x] + c;
				pq.push({ -dist[e],e });
			}
		}
	}
	cout << -dist[n + 1];

	return 0;
}