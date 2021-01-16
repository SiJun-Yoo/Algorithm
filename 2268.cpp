#include<bits/stdc++.h>
#define MOD 1000000007ll
#define MAX 2000000000ll
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
ll a[1 << 21];
void update(int x, int var, int node, int s, int e) {//segTree배열 x번째에 var라는 값으로 update를 하는데 현재 번호는 node이며 배열의 s~e번째 노드에 해당한다.
	if (s == e) {
		a[node] = var;
		return;
	}
	int mid = (s + e) / 2;
	if (x <= mid) update(x, var, 2 * node, s, mid); //왼쪽 자식은 2*node
	else update(x, var, 2 * node + 1, mid + 1, e); //오른쪽 자식은 2*node+1
	a[node] = a[2 * node] + a[2 * node + 1];
	return;
}
ll query(int l, int r, int node, int s, int e) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return a[node];
	int mid = (s + e) / 2;
	return query(l, r, 2 * node, s, mid) + query(l, r, 2 * node + 1, mid + 1, e);
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int k, b, c;
		cin >> k >> b >> c;
		if (!k) {

			cout << query(min(b, c), max(b, c), 1, 1, 1 << 20) << '\n';
		}
		else {
			update(b, c, 1, 1, 1 << 20);
		}
	}
	return 0;
}