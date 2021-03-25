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
const int IDX = 200001;
const int MAX = 10000000;
const int MIN = -987654321;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
string str[1001];
map<string, int> k;
vector<int> v[1001];
int chk[1001];
void dfs(int now) {
	for (auto it = v[now].begin(); it != v[now].end();) {
		int next = *it;
		if (--chk[next]) {
			it = v[now].erase(it);
		}
		else {
			it++;
		}
	}
	for (auto it = v[now].begin(); it != v[now].end(); it++) {
		dfs(*it);
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> str[i];
	}
	sort(begin(str) + 1, begin(str) + 1 + n);
	for (int i = 1; i <= n; i++) {
		k[str[i]] = i;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		int child = k[a];
		int root = k[b];
		chk[child]++;
		v[root].push_back(child);
	}
	int cnt = 0;
	vector<string> tmp;
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			tmp.push_back(str[i]);
		}
	}
	sort(begin(tmp), end(tmp));
	cout << tmp.size() << '\n';
	int size = tmp.size();
	for (int i = 0; i < size; i++) {
		cout << tmp[i] << ' ';
		dfs(k[tmp[i]]);
	}
	cout << '\n';
	for (int i = 1; i <= n; i++) {
		cout << str[i] << ' ' << v[i].size() << ' ';
		size = v[i].size();
		sort(begin(v[i]), end(v[i]));
		for (int j = 0; j < size; j++) {
			cout << str[v[i][j]] << ' ';
		}
		cout << '\n';
	}

	return 0;
}