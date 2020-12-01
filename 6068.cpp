#define MAX 2000000000
#define MOD 1000000007
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef queue<pair<int, int>> qii;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
pii p[1000];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].second >> p[i].first;
	}
	sort(p, p + n);
	int l = 0, r = 1000000;
	bool flag = true;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int cnt = mid;
		bool chk = true;
		for (int i = 0; i < n; i++) {
			if (cnt + p[i].second > p[i].first) {
				chk = false;
				break;
			}
			cnt += p[i].second;
		}
		if (chk) {
			l = mid + 1;
			flag = false;
			ans = max(ans, mid);
		}
		else {
			r = mid - 1;
		}
	}
	if (flag) {
		cout << -1;
		return 0;
	}
	else {
		cout << ans;
	}

}