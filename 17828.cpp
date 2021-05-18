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
const int MOD = 1000000007;
const int MAX = 1000000000;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
ll n, m;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	string ans = "";
	if (n > m) {
		cout << "!";
		return 0;
	}
	if (n * 26 < m) {
		cout << "!";
		return 0;
	}
	while ((n - 1) * 26 >= m) {
		ans.push_back('A');
		n--;
		m--;
	}
	if (m % 26 != 0) {
		ans.push_back((char)((m % 26) - 1 + 'A'));
		m -= m % 26;
	}
	for (int i = 0; i < m; i += 26) {
		ans.push_back('Z');
	}
	cout << ans;
	return 0;
}
