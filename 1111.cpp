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
int n;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (n == 1) {
		cout << "A";
		return 0;
	}
	if (n == 2) {
		if (v[0] == v[1]) {
			cout << v[0];
			return 0;
		}
		cout << "A";
		return 0;
	}
	int a = 0, b = 0;
	if (v[0] != v[1]) {
		a = (v[2] - v[1]) / (v[1] - v[0]);
	}
	b = v[1] - (v[0] * a);
	for (int i = 2; i < v.size(); i++) {
		int now = v[i-1] * a + b;
		if (now != v[i]) {
			cout << "B";
			return 0;
		}
	}
	cout << v[v.size() - 1] * a + b;
	return 0;
}

