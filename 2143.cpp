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
map<ll, ll> m1;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    int n;
    cin >> n;
    vector<int> v1(n);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    int m;
    cin >> m;
    vector<int> v2(m);
    for (int i = 0; i < m; i++) {
        cin >> v2[i];
    }
    for (int i = 0; i < n; i++) {
        ll now = 0;
        for (int j = i; j < n; j++) {
            now += v1[j];
            m1[now]++;
        }
    }
    vector<ll> tmp;
    for (int i = 0; i < m; i++) {
        ll now = 0;
        for (int j = i; j < m; j++) {
            now += v2[j];
            tmp.push_back(now);
        }
    }
    int size = tmp.size();
    ll ans = 0;
    for (int i = 0; i < size; i++) {
        if (m1[t - tmp[i]]) {
            ans += m1[t - tmp[i]];
        }
    }
    cout << ans;
    return 0;
}