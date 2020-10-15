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
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef queue<pair<int, int>> qii;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
int d[32][100001];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        v[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        reverse(begin(v) + s, begin(v) + e + 1);
    }
    for (int i = 1; i <= n; i++) {
        d[0][i] = v[i];
    }
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = d[i - 1][d[i - 1][j]];
        }
    }
    int cnt = (1 << 30);
    int tmp = 30;
    int now = 0;
    while (k) {
        if (cnt > k) {
            cnt /= 2;
            tmp--;
            continue;
        }
        for (int i = 1; i <= n; i++) {
            a[i] = d[tmp][a[i]];
        }
        k -= cnt;
        tmp--;
        cnt /= 2;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}