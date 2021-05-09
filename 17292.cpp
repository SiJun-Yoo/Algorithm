g#include<bits/stdc++.h>
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
const ll MOD = 1000000007;
const ll MAX = 1000000000;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool cmp(string a, string b) {
	int n1 = a[0] - '0';
	char c1 = a[1];
	int n2 = a[2] - '0';
	char c2 = a[3];
	int n3 = b[0] - '0';
	char c3 = b[1];
	int n4 = b[2] - '0';
	char c4 = b[3];
	if ('a' <= a[0] && a[0] <= 'f') {
		n1 = 10 + (a[0] - 'a');
	}
	if ('a' <= a[2] && a[2] <= 'f') {
		n2 = 10 + (a[2] - 'a');
	}
	if ('a' <= b[0] && b[0] <= 'f') {
		n3 = 10 + (b[0] - 'a');
	}
	if ('a' <= b[2] && b[2] <= 'f') {
		n4 = 10 + (b[2] - 'a');
	}
	int flag1 = ((abs(n1 - n2) == 1 || (n1 == 15 && n2 == 1) || (n1 == 1 && n2 == 15)));
	int flag2 = ((abs(n3 - n4) == 1 || (n3 == 15 && n4 == 1) || (n3 == 1 && n4 == 15)));
	int flag3 = (n1 == n2);
	int flag4 = (n3 == n4);
	int flag5 = (c1 == c2);//색
	int flag6 = (c3 == c4);//색
	int flag7 = max(n1, n2);//큰큰
	int flag8 = max(n3, n4);//큰큰
	int flag9 = min(n1, n2);//작큰
	int flag10 = min(n3, n4);//작큰
	int flag11 = (n1 == max(n1, n2) ? c1 == 'b' : c2 == 'b');
	int flag12 = (n3 == max(n3, n4) ? c3 == 'b' : c4 == 'b');
	if (flag1 == flag2) {
		if (flag3 == flag4) {
			if (flag5 == flag6) {
				if (flag7 == flag8) {
					if (flag9 == flag10) {
						return flag11;
					}
					return flag9 > flag10;

				}
				return flag7 > flag8;
			}
			return flag5;
		}
		return flag3;
	}
	return flag1;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	string str;
	cin >> str;
	vector<string> v;
	string now = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ',') {
			v.push_back(now);
			now = "";
			continue;
		}
		now += str[i];
	}
	v.push_back(now);
	vector<string> k;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			k.push_back(v[i] + v[j]);
		}
	}
	sort(begin(k), end(k), cmp);
	for (int i = 0; i < k.size(); i++) {
		cout << k[i] << '\n';
	}
	return 0;
}
