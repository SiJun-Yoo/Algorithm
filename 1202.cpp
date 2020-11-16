#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
pii p[300000];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	vector<int> v(k);
	for (int i = 0; i < k; i++) {
		cin >> v[i];
	}
	sort(begin(v), end(v));
	sort(p, p + n);
	ll ans = 0;
	int idx = 0;
	for (int i = 0; i < k; i++) {
		while (idx<n&&v[i] >= p[idx].first) {
			pq.push(p[idx++].second);
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}	
	cout << ans;
}