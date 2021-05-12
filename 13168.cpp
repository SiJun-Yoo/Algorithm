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
typedef priority_queue<ll> pql;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
const ll MOD = 1000000007;
const int MAX = 100000000;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m, k, t;
map<string, int> m1;
string b[201];
double dist1[101][101];
double dist2[101][101];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string now;
		cin >> now;
		m1[now] = i;
	}
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> b[i];
	}
	cin >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist1[i][j] = MAX;
			dist2[i][j] = MAX;
		}
		dist1[i][i] = 0;
		dist2[i][i] = 0;
	}
	for (int i = 1; i <= t; i++) {
		string str1, str2, str3;
		double num;
		cin >> str1 >> str2 >> str3 >> num;
		int s = m1[str2];
		int e = m1[str3];
		dist1[e][s] = dist1[s][e] = min(dist1[s][e], num);
		if (str1 == "S-Train" || str1 == "V-Train") { num /= 2.0; }
		else if (str1 == "Mugunghwa" || str1 == "ITX-Saemaeul" || str1 == "ITX-Cheongchun") { num = 0; }
		dist2[e][s] = dist2[s][e] = min(dist2[s][e], num);
	}

	for (int l = 1; l <= n; l++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist1[i][j] > dist1[i][l] + dist1[l][j]) {
					dist1[i][j] = dist1[i][l] + dist1[l][j];//내일로 안쓴거
				}
				if (dist2[i][j] > dist2[i][l] + dist2[l][j]) {
					dist2[i][j] = dist2[i][l] + dist2[l][j];
				}
			}
		}
	}
	double ans1 = 0;
	double ans2 = m;
	for (int i = 2; i <= k; i++) {
		int s = m1[b[i - 1]];
		int e = m1[b[i]];
		ans1 += dist1[s][e];
		ans2 += dist2[s][e];
	}
	int s = m1[b[k]];
	int e = m1[b[1]];
	ans1 += dist1[s][e];
	ans2 += dist2[s][e];
	cout << (ans2 < ans1 ? "Yes" : "No");
	return 0;
}

