#define MAX 1000000000
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<memory.h>
#include<stack>
#include<string>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef queue<pair<int, int>> qii;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
bool cmp(string a, string b) {
	string x = a;
	string y = b;
	int l1 = a.length();
	int l2 = b.length();
	if (l1 < l2) {
		int k = l2 / l1;
		int m = l2 % l1;
		for (int i = 0; i < k - 1; i++) {
			x += a;
		}
		for (int i = 0; i < m; i++) {
			x.push_back(a[i]);
		}
	}
	else if (l1 > l2) {
		int k = l1 / l2;
		int m = l1 % l2;
		for (int i = 0; i < k - 1; i++) {
			y += b;
		}
		for (int i = 0; i < m; i++) {
			y.push_back(b[i]);
		}
	}
	int len = x.length();
	return x > y;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> v; int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num) v.push_back(to_string(num));
	}
	if (v.size() == 0) {
		cout << 0;
		return 0;
	}
	sort(begin(v), end(v), cmp);
	int size = v.size();
	for (int i = 0; i < size; i++) {
		cout << v[i];
	}
	for (int i = 0; i < n - size; i++) {
		cout << 0;
	}
	return 0;
}