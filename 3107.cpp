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
const ll MOD = 1000000007;
const int MAX = 1000000000;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	string str;
	cin >> str;
	string ans = "0000:0000:0000:0000:0000:0000:0000:0000";
	int idx = ans.length() - 1;
	for (int i = str.length() - 1; i >= 0; i--, idx--) {
		if (str[i] == ':') {
			if (str[i - 1] == ':') {
				if (i - 1 == 0) break;
				int cnt = 0;
				for (int j = 0; j < i; j++) {
					if (str[j] == ':') cnt++;
				}
				idx = 5 * cnt;
			}
			else {
				while (idx >= 0 && ans[idx] != ':') {
					idx--;
				}
			}
		}
		else {
			ans[idx] = str[i];
		}
	}
	cout << ans;
	return 0;
}
