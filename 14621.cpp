#define MAX 100000000
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<memory.h>
#include<map>
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
int parent[1001];
int sex[1001];
struct graph;
vector<graph> v[1001];
struct graph {
    int end;
    int cost;
};
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
bool Union(int x,int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return true;
    parent[rx] = ry;
    return false;
}
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        parent[i] = i;
        if (c == 'M') {
            sex[i] = 1;
        }
        else {
            sex[i] = 2;
        }
    }
    priority_queue<pair<int,pii>> pq;
    for (int i = 0; i < m; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        v[s].push_back({ e,cost });
        v[e].push_back({ s,cost });
        pq.push({ -cost,{s,e} });
    }
    int ans = 0;
    int cnt = 0;
    while (!pq.empty()) {
        auto k = pq.top();
        pq.pop();
        int start = k.second.first;
        int end = k.second.second;
        int cost = -k.first;
        if (sex[start] == sex[end]) continue;
        if (Union(start, end)) continue;
        ans += cost;
        cnt++;
    }
    if (cnt != n-1) cout << -1;
    else cout << ans;
}