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
int n;
int d[1001];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	d[1] = 1;
	d[2] = 2;
	d[3] = 1;
	d[4] = 2;
	for (int i = 5; i <= n; i++) {
		int a = d[i - 1];
		int b = d[i - 3];
		int c = d[i - 4];
		if ((a % 2) || (b % 2) || (c % 2)) {
			d[i] = 2;
		}
		else d[i] = 1;
	}
	if ((d[n] & 1)) cout << "CY";
	else cout << "SK";
	return 0;
}
