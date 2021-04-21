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
typedef vector<int> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
const int MOD = 1000000007;
const ll MAX = (1ll << 62);
int a[8] = { 0,0,1,7,4,2,0,8 };
int b[10] = { 6,2,5,5,4,5,6,3,7,6 };
ll d[101] = { 0,0,1,7,4,2,0,8, };
void minSolve(int now) {
	if (!((now - 6) % 7)) {
		cout << 6;
		for (int i = 0; i < now / 7; i++) {
			cout << "8";
		}
		cout << " ";
		return;
	}
	cout << d[now] << ' ';
}
void maxSolve(int now) {
	if (now & 1) {
		cout << "7";
		for (int i = 0; i < (now - 3) / 2; i++) {
			cout << "1";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < now / 2; i++) {
			cout << "1";
		}
		cout << "\n";
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 8; i <= 100; i++) {
		ll next = MAX;
		for (int j = 2; j <= 7; j++) {
			if (i - j < 2) continue;
			if (i - j == 6) continue;
			next = min(next, d[i - j] * 10 + d[j]);
		}
		d[i] = next;
	}
	while (t--) {
		int now;
		cin >> now;
		minSolve(now);
		maxSolve(now);
	}
	return 0;
}