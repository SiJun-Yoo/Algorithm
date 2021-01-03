#define MAX 2000000000
#define MOD 1000000007
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
ll k[250];
ll d[50001];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i < 250; i++) {
		k[i] = i * i;
	}
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = MAX;
		for (int j = 0; j < 250; j++) {
			if (k[j] > i) break;
			d[i] = min(d[i], d[i - k[j]] + 1);
		}
	}
	cout << d[n];
	return 0;
}