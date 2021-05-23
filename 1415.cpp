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
typedef priority_queue<ll> pql;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
const ll MOD = 1000000007;
const ll MAX = 1000000000;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
ll d[500001];
ll cnt[10001];
int prime[500001];
int chk[10001];
int n, m;
void primeNum() {
	for (int i = 2; i <= 500000; i++) {
		if (prime[i]) continue;
		for (int j = i * 2; j <= 500000; j += i) {
			prime[j] = true;
		}
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	vi v(n);
	primeNum();
	cnt[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		cnt[v[i]]++;
	}
	d[0] = 1;
	for (int i = 0; i < n; i++) {
		int now = v[i];
		if (now == 0) continue;
		if (chk[now]) continue;
		chk[now] = 1;
		for (int j = 500000; j >= 0; j--) {
			for (int k = 1; k <= cnt[now]; k++) {
				if (j - now * k < 0) break;
				d[j] += d[j - k * now];
			}			
		}
	}
	ll ans = 0;
	for (int i = 2; i <= 500000; i++) {
		if(!prime[i]) ans += d[i];
	}
	cout << ans * cnt[0];
	return 0;
}
