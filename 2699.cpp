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
typedef vector<pii> vii;
typedef vector<pll> vll;
struct P {
	int x, y, p, q;
};
int ccw(P a, P b, P c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}
bool cmp(P a, P b) {
	if (a.p * b.q != 1ll * a.q * b.p) return a.q * b.p > 1ll * a.p * b.q;
	if (a.y == b.y) return a.x < b.x;
	return a.y > b.y;
}
P p[100000];
deque<int> st;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			p[i] = { x,y,1,0 };
		}
		sort(p, p + n, cmp);
		for (int i = 1; i < n; i++) {
			p[i].p = p[i].x - p[0].x;
			p[i].q = p[i].y - p[0].y;
		}
		sort(p, p + n, cmp);
		st.push_front(0);
		st.push_front(1);
		int next = 2;
		while (next < n) {
			while (st.size() >= 2) {
				int first, second;
				second = st.front();
				st.pop_front();
				first = st.front();
				if (ccw(p[first], p[second], p[next]) < 0) {
					st.push_front(second);
					break;
				}
			}
			st.push_front(next++);
		}
		cout << st.size() << '\n';
		while (!st.empty()) {
			int now = st.back();
			st.pop_back();
			cout << p[now].x << ' ' << p[now].y << '\n';
		}
	}

	return 0;
}