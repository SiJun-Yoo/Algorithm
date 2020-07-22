#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<memory.h>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
int inDegree[1001];
vector<int> v[1001];
int arr[1001];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		int now;
		cin >> now;
		for (int j = 1; j < k; j++) {
			int a;
			cin >> a;
			v[now].push_back(a);
			inDegree[a]++;
			now = a;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			cout << 0;
			return 0;
		}
		int x = q.front();
		ans.push_back(x);
		q.pop();
		int size = v[x].size();
		for (int j = 0; j < size; j++) {
			int y = v[x][j];
			if (--inDegree[y] == 0) {
				q.push(y);
			}
		}
	}
	for (int k : ans) {
		cout << k << '\n';
	}
}
