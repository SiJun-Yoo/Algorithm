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
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<ll, ll> m;
		pqll pq1, pq2;
		for (int i = 0; i < n; i++) {
			char c; ll a;
			cin >> c >> a;
			if (c == 'I') {
				pq1.push(-a);//弥家赛
				pq2.push(a);//弥措赛
				m[a]++;
			}
			else {
				if (a == -1) {//弥家赛 昏力
					while (!pq1.empty() && !m[-pq1.top()]) {
						pq1.pop();
					}
					if (!pq1.empty()) {
						m[-pq1.top()]--;
						pq1.pop();
					}
				}
				else {//弥措赛 昏力
					while (!pq2.empty() && !m[pq2.top()]) {
						pq2.pop();
					}
					if (!pq2.empty()) {
						m[pq2.top()]--;
						pq2.pop();
					}
				}
			}
			while (!pq1.empty() && !m[-pq1.top()]) {
				pq1.pop();
			}
			while (!pq2.empty() && !m[pq2.top()]) {
				pq2.pop();
			}
		}
		if (pq1.empty() || pq2.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << pq2.top() << ' ' << -pq1.top() << '\n';
		}
	}
	return 0;
}