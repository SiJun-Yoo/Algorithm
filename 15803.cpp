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
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int x[3], y[3];
	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}
	double x1 = x[0] - x[1];
	double x2 = x[0] - x[2];
	double y1 = y[0] - y[1];
	double y2 = y[0] - y[2];
	if (x1 == 0 || x2 == 0) {
		x1 == x2 ? cout << "WHERE IS MY CHICKEN?" : cout << "WINNER WINNER CHICKEN DINNER!";
	}
	else {
		y1 / x1 == y2 / x2 ? cout << "WHERE IS MY CHICKEN?" : cout << "WINNER WINNER CHICKEN DINNER!";
	}

	return 0;
}