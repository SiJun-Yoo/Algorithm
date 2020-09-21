#define MAX 100000000000
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
    int e;
    int cost;
    graph(int e, int cost) :e(e), cost(cost) {

    }
};
vector<graph> v[10001];
ll dist[10001][21];
bool visit[10001][21];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        v[s].push_back({ e,cost });
        v[e].push_back({ s,cost });
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dist[i][j] = MAX;
        }
    }
    priority_queue<pair<pair<ll, int>, int>> pq;
    dist[1][0] = 0;
    pq.push({ {0,0},1 });
    while (!pq.empty()) {
        int x = pq.top().second;
        int cnt = pq.top().first.second;
        pq.pop();
        if (visit[x][cnt]) continue;
        visit[x][cnt] = true;
        int size = v[x].size();
        for (int i = 0; i < size; i++) {
            int vtx = v[x][i].e;
            int c = v[x][i].cost;
            if (dist[vtx][cnt] > dist[x][cnt] + c) {
                dist[vtx][cnt] = dist[x][cnt] + c;
                pq.push({ {-dist[vtx][cnt],cnt}, vtx });
            }
            if (cnt + 1 <= k && dist[vtx][cnt + 1] > dist[x][cnt]) {
                dist[vtx][cnt + 1] = dist[x][cnt];
                pq.push({ {-dist[vtx][cnt + 1],cnt + 1}, vtx });
            }
        }
    }
    ll ans = MAX;
    for (int i = 0; i <= k; i++) {
        if (visit[n][i])       ans = min(ans, dist[n][i]);
    }
    cout << ans;
    return 0;
}