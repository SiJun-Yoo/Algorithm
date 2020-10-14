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
pair<pii, int> p[300001];
bool cmp(pair<pii, int> a, pair<pii, int> b) {
    if (a.first.first < b.first.first) return true;
    else if (a.first.first == b.first.first) return a.first.second < b.first.second;
    return false;
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first.first >> p[i].first.second;
        p[i].second = i;
    }
    if (n == 1) {
        cout << "1\n1";
        return 0;
    }
    sort(p + 1, p + 1 + n, cmp);
    int ans = 1;
    int e = p[1].first.second;
    priority_queue<pii> pq;
    pq.push({ -e,p[1].second });
    for (int i = 2; i <= n; i++) {
        int nowS = p[i].first.first;
        int nowE = p[i].first.second;
        while (!pq.empty() && nowS > -pq.top().first) {
            pq.pop();
        }
        pq.push({ -nowE,p[i].second });
        int size = pq.size();
        ans = max(ans, size);
    }
    cout << ans << '\n';
    while (!pq.empty()) {
        pq.pop();
    }
    e = p[1].first.second;
    pq.push({ -e,p[1].second });
    for (int i = 2; i <= n; i++) {
        int nowS = p[i].first.first;
        int nowE = p[i].first.second;
        while (!pq.empty() && nowS > -pq.top().first) {
            pq.pop();
        }
        pq.push({ -nowE,p[i].second });
        if (ans == pq.size()) {
            while (!pq.empty()) {
                cout << pq.top().second << ' ';
                pq.pop();
            }
            return 0;
        }
    }
    return 0;
}