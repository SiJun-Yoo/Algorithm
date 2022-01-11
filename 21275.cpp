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
const ll MOD = 1000000007;
const int IDX = 200001;
const int MAX = 10000000;
const int MIN = -987654321;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	int len1 = a.length();
	int len2 = b.length();
	int idx1 = 0, idx2 = 0;
	for (int i = 0; i < len1; i++) {
		int now = a[i];
		if ('0' <= now && now <= '9') {
			now -= '0';
		}
		else {
			now -= 'a';
			now += 10;
		}
		idx1 = max(idx1, now);
	}
	for (int i = 0; i < len2; i++) {
		int now = b[i];
		if ('0' <= now && now <= '9') {
			now -= '0';
		}
		else {
			now -= 'a';
			now += 10;
		}
		idx2 = max(idx2, now);
	}
	vector<pair<ll,pll>> v;
	for (int i = idx1+1; i <= 36; i++) {
		for (int j = idx2+1; j <= 36; j++) {
			if (i == j) continue;
			ll num1 = 0;
			ll num2 = 0;
			ll t = 1;
			for (int k = len1-1; k >=0; k--) {
				int now = a[k];
				if ('0' <= now && now <= '9') {
					now -= '0';
				}
				else {
					now -= 'a';
					now += 10;
				}
				now *= t;
				num1 += now;
				t *= i;
			}
			t = 1;
			for (int k = len2 - 1; k >= 0; k--) {
				int now = b[k];
				if ('0' <= now && now <= '9') {
					now -= '0';
				}
				else {
					now -= 'a';
					now += 10;
				}
				now *= t;
				num2 += now;
				t *= j;
			}
			if (num1 == num2) {
				v.push_back({ num1,{i,j} });
			}
		}
	}
	if (v.size() == 0) cout << "Impossible";
	else if (v.size() > 1) cout << "Multiple";
	else cout << v[0].first << ' ' << v[0].second.first << ' ' << v[0].second.second;
	return 0;
}
