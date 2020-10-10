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
int d[16][(1 << 16)];
int a[16][16];
int solve(int now, int idx, int goal, int n) {
    if (idx == goal) {
        if (a[now][0])  return a[now][0];
        else return MAX;
    }
    if (d[now][idx] != -1) return d[now][idx];
    int& val = d[now][idx];
    val = MAX;
    for (int i = 0; i < n; i++) {
        if (idx & (1 << i)) continue;
        if (!a[now][i]) continue;
        val = min(val, solve(i, idx | (1 << i), goal, n) + a[now][i]);
    }
    return val;
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    cout << solve(0, 1, (1 << n) - 1, n);
    return 0;
}