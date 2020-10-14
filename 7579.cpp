#define MAX 2000000000
#define MOD 1000000007
#define _CRT_SECURE_NO_WARNINGS
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
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef queue<pair<int, int>> qii;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
ll d[101][10001];
ll solve(int idx, int now, int n, vector<pii>& v) {
    if (idx == 0) return 0;
    if (d[idx][now] != -1) return d[idx][now];
    ll& val = d[idx][now];
    val = 0;
    int cnt = v[idx].second;
    int cost = v[idx].first;
    val = solve(idx - 1, now, n, v);//idx선택 안하는 경우
    if (now >= cnt) val = max(val, solve(idx - 1, now - cnt, n, v) + cost); //idx선택하는 경우
    return val;
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pii> v(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i].second;
        sum += v[i].second;
    }
    sort(begin(v), end(v));
    memset(d, -1, sizeof(d));
    int cnt = 0;
    while (1) {
        if (solve(n, cnt, n, v) >= m) { //초기 비용 cnt
            cout << cnt;
            return 0;
        }
        cnt++;
    }
    return 0;
}