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
int dist[10001];
bool visit[10001];
struct network {
    int e;
    int cost;
};
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, d, c;
        cin >> n >> d >> c;
        vector<network> v[10001];
        for (int i = 0; i < d; i++) {
            int s, e, cost;
            cin >> s >> e >> cost;
            v[e].push_back({ s,cost });
        }
        for (int i = 1; i <= n; i++) {
            visit[i] = false;
            dist[i] = MAX;
        }
        dist[c] = 0;
        priority_queue<pii> pq;
        pq.push({ 0,c });
        dist[c] = 0;
        while (!pq.empty()) {
            int cost = -pq.top().first;
            int s = pq.top().second;
            pq.pop();
            if (visit[s]) continue;
            visit[s] = true;
            int size = v[s].size();
            for (int i = 0; i < size; i++) {
                int e = v[s][i].e;
                int time = v[s][i].cost;
                if (visit[e])continue;
                if (dist[e] > cost + time) {
                    dist[e] = cost + time;
                    pq.push({ -dist[e],e });
                }
            }
        }
        int cnt = n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == MAX) cnt--;
            if (dist[i] != MAX) ans = max(ans, dist[i]);
        }
        cout << cnt << ' ' << ans << '\n';
    }
    return 0;
}