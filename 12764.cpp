#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef queue<pair<int, int>> qii;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
const int MAX = 1000000000;
const int MIN = -1000000000;
const int MOD = 1000000007;
pii p[100001];
int a[100001];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	pqi k;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].first >> p[i].second;
		k.push(-i);
	}
	sort(p + 1, p + 1 + n);
	priority_queue<pii> pq;
	int ans = 0;
	pq.push({ -p[1].second,-1 });
	a[1] = 1;
	k.pop();
	for (int i = 2; i <= n; i++) {
		int s = p[i].first;
		int e = p[i].second;
		while (!pq.empty() && s > -pq.top().first) {
			k.push(pq.top().second);
			pq.pop();
		}
		pq.push({ -e,k.top() });
		a[-k.top()]++;
		k.pop();
	}
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			ans++;
			continue;
		}
		break;
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			cout << a[i] << ' ';
			continue;
		}
		break;
	}
	return 0;
}