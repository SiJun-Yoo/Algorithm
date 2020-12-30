#define MAX 2000000000
#define MOD 1000000007
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
string k;
ll solve(ll idx, ll now, ll tmp, ll flag) {
	if (k.length() == 1) {
		ll t = stol(k);
		if (t % 2 == 0 || t % 3 == 0 || t % 5 == 0 || t % 7 == 0) {
			return 1;
		}
		return 0;
	}
	if (idx == k.length() - 1) {
		ll t = now + flag * (tmp * 10 + k[idx] - '0');
		t = abs(t);
		if (t % 2 == 0 || t % 3 == 0 || t % 5 == 0 || t % 7 == 0) {
			return 1;
		}
		return 0;
	}
	ll val = 0;
	val += solve(idx + 1, now, (tmp * 10 + k[idx] - '0'), flag);//弊成 穿利
	val += solve(idx + 1, now + flag * (tmp * 10 + k[idx] - '0'), 0, 1);//+老锭 +持扁
	val += solve(idx + 1, now + flag * (tmp * 10 + k[idx] - '0'), 0, -1);//-持扁
	return val;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> k;
		cout << "Case #" << i << ": " << solve(0, 0, 0, 1) << '\n';
	}
	return 0;
}