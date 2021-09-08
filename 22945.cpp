#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef queue<int> qi;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, k;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int l = 0;
	int r = n - 1;
	int ans = 0;
	while (l <= r) {
		int val = min(v[l], v[r]);
		int cnt = r - l - 1;
		ans = max(ans, val * cnt);
		if (v[l] > v[r]) {
			r--;
		}
		else {
			l++;
		}
	}
	cout << ans;
	return 0;
}