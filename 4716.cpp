#include<bits/stdc++.h>
#include<unordered_set>
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
const ll MOD = 1000000000;
const int IDX = 200001;
const int MAX = 10000000;
const int MIN = -987654321;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
pair<ll, pll> p[1000];
bool cmp(pair<ll, pll> a, pair<ll, pll> b) {
	ll c = abs(a.second.first - a.second.second);
	ll d = abs(b.second.first - b.second.second);
	return c > d;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	while (1) {
		ll n, a, b;
		cin >> n >> a >> b;
		if (n == 0 && a == 0 && b == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> p[i].first >> p[i].second.first >> p[i].second.second;
		}
		sort(p, p + n, cmp);
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if (p[i].second.first > p[i].second.second) {
				if (b >= p[i].first) {
					b -= p[i].first;
					ans += p[i].first * p[i].second.second;
				}
				else {
					ans += b * p[i].second.second;
					p[i].first -= b;
					b = 0;
					ans += p[i].first * p[i].second.first;
					a -= p[i].first;
				}
			}
			else {
				if (a >= p[i].first) {
					a -= p[i].first;
					ans += p[i].first * p[i].second.first;
				}
				else {
					ans += a * p[i].second.first;
					p[i].first -= a;
					a = 0;
					ans += p[i].first * p[i].second.second;
					b -= p[i].first;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}