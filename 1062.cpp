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
qii q;
int d[21];
int c[50][26];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	string str;
	int cnt = 0;
	char ch = 'a';
	while (cnt < 21) {
		if (ch == 'a' || ch == 'n' || ch == 't' || ch == 'i' || ch == 'c') {
			ch++;
			continue;
		}
		d[cnt++] = ch - 'a';
		ch++;
	}
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			ch = str[j];
			if (ch == 'a' || ch == 'n' || ch == 't' || ch == 'i' || ch == 'c') continue;
			c[i][ch - 'a']++;
		}
	}
	if (k < 5) {
		cout << 0;
		return 0;
	}
	vector<int> v(21, 0);
	for (int i = 21 - (k - 5); i < 21; i++) {
		v[i] = 1;
	}
	int ans = 0;
	do {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			bool flag = true;
			for (int j = 0; j < 21; j++) {
				if (v[j] == 0 && c[i][d[j]]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cnt++;
			}
		}
		ans = max(ans, cnt);
	} while (next_permutation(begin(v), end(v)));
	cout << ans;
	return 0;
}