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
const int IDX = 44001;
const ll MAX = 2000000001;
const int MIN = -987654321;
ll a[IDX];
void primeNum() {
	for (ll i = 2; i < IDX; i++) {
		if (a[i]) continue;
		for (ll j = i; j < IDX; j += i) {
			if (j % (i * i) == 0) a[j] -= MAX;
			else a[j]++;
		}
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	ll k;
	cin >> k;
	primeNum();
	vector<ll> v;
	for (int i = 2; i <= 44000; i++) {
		if (a[i] > 0) v.push_back((a[i] % 2 ? 1 : -1) * (i * i));
	}
	ll now = k;
	ll tmp = 0;
	while (k != tmp) {
		tmp = 0;
		for (ll b : v) {
			tmp += now / b;
		}
		tmp = now - tmp;
		now += k - tmp;
	}
	cout << now;
	return 0;
}
