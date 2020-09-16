#define MAX 100000000
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
struct road {
    int s;
    int e;
    int cost;
};
vector<road> v;
int dist[10001];
bool cmp(const road& r1, const road& r2) {
    if (r1.s < r2.s) return true;
    else if (r1.s == r2.s && r1.e < r2.e) return true;
    else if (r1.s == r2.s && r1.e == r2.e && r1.cost < r2.cost) return true;
    else return false;
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        v.push_back({ s,e,cost });
    }
    sort(begin(v), end(v), cmp);
    for (int i = 0; i <= d; i++) {
        dist[i] = i;
        for (int j = 0; j < n; j++) {
            int start = v[j].s;
            int end = v[j].e;
            int cost = v[j].cost;
            if (i > end) {
                dist[i] = min(dist[i], dist[end] + i - end);
            }
            else if (i == end) {
                dist[i] = min(dist[i], dist[start] + cost);
            }
        }
    }
    cout << dist[d];
    return 0;
}