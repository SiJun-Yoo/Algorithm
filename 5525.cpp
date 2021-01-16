#include<bits/stdc++.h>
#define MOD 1000000007ll
#define MAX 2000000000ll
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
ll a[1 << 21];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	int cnt = 0;
	int flag = 0;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (flag) {
			if (str[i] == 'O') {
				flag = 0;
				cnt++;
			}
			else {
				flag = 1;
				cnt = 1;
			}
		}
		else {
			if (str[i] == 'I') {
				cnt++;
				flag = 1;
			}
			else {
				flag = 0;
				cnt = 0;
			}
		}
		if (cnt == n * 2 + 1) {
			cnt -= 2;
			ans++;
		}
	}
	cout << ans;
	return 0;
}