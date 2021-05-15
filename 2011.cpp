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
const int MAX = 100001;
int dp[5001] = { 0, };
int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	string str;
	cin >> str;
	int mod = 1000000;
	dp[0] = 1;
	for (int i = 1; i < str.length() + 1; i++) {
		int n = str[i - 1] - '0';
		if (1 <= n && n < 10) {
			dp[i] = (dp[i] + dp[i - 1]) % mod;
		}
		if (i == 1) continue;
		if ((str[i - 2] - '0') == 0) continue;
		int tmp = (str[i - 2] - '0') * 10 + (str[i - 1] - '0');
		if (10 <= tmp && tmp < 27) {
			dp[i] = (dp[i] + dp[i - 2]) % mod;
		}
	}
	cout << dp[str.length()];
	return 0;
}
