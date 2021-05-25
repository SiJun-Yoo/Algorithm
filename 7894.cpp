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
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int now;
		cin >> now;
		double ans = 0;
		for (int j = 1; j <= now; j++) {
			ans += log10(j);
		}
		cout << (int)ans + 1 << '\n';
	}
	return 0;
}

