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
typedef vector<pii> vii;
typedef vector<pll> vll;
const ll MOD = 1000000007;
const int MAX = 10000000;
const int MIN = -987654321;
const int IDX = 200001;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans;
int d[1000001];
vector<int> kmp(string str, string ptr) {
	vector<int> v;
	int n = str.length();
	int m = ptr.length();
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && str[i] != ptr[j]) j = d[j - 1];
		if (str[i] == ptr[j]) {
			if (j == m - 1) {
				ans++;
				v.push_back(i - ptr.length() + 2);
				j = d[j];
			}
			else {
				j++;
			}
		}
	}
	return v;
}
void getPi(string ptr) {
	int m = ptr.length();
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && ptr[i] != ptr[j]) j = d[j - 1];
		if (ptr[i] == ptr[j]) d[i] = ++j;
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	getPi(s2);
	vector<int> v = kmp(s1, s2);
	cout << ans << '\n';
	for (int a : v) {
		cout << a << ' ';
	}
	return 0;
}
