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
struct graph {
    int x;
    int y;
    int z;
    int num;
};
int parent[100001];
bool cmp1(const graph& g1, const graph& g2) {
    return g1.x < g2.x;
}
bool cmp2(const graph& g1, const graph& g2) {
    return g1.y < g2.y;
}
bool cmp3(const graph& g1, const graph& g2) {
    return g1.z < g2.z;
}
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
bool Union(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return true;
    parent[rx] = ry;
    return false;
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<graph> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].x >> v[i].y >> v[i].z;
        v[i].num = i;
        parent[i] = i;
    }
    priority_queue<pair<ll, pii>> pq;
    sort(begin(v) + 1, end(v), cmp1);
    for (int i = 1; i < n; i++) {
        int x = abs(v[i].x - v[i + 1].x);
        int s = v[i].num;
        int e = v[i + 1].num;
        pq.push({ -x,{s ,e} });
    }
    sort(begin(v) + 1, end(v), cmp2);
    for (int i = 1; i < n; i++) {
        int x = abs(v[i].y - v[i + 1].y);
        int s = v[i].num;
        int e = v[i + 1].num;
        pq.push({ -x,{s ,e} });
    }
    sort(begin(v) + 1, end(v), cmp3);
    for (int i = 1; i < n; i++) {
        int x = abs(v[i].z - v[i + 1].z);
        int s = v[i].num;
        int e = v[i + 1].num;
        pq.push({ -x,{s ,e} });
    }
    ll ans = 0;
    while (!pq.empty()) {
        ll cost = -pq.top().first;
        int s = pq.top().second.first;
        int e = pq.top().second.second;
        pq.pop();
        if (Union(s, e)) continue;
        ans += cost;
    }
    cout << ans;
    return 0;
}