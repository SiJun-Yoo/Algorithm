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
int n, m, a, b, k;
int map[501][501];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int visit[501][501];
qii q;
bool check(int x, int y) {
    for (int j = 0; j < a; j++) {
        for (int l = 0; l < b; l++) {
            if (map[x + j][y + l] == 1) {
                return false;
            }
        }
    }
    return true;
}
void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (map[x][y] == 3) {
            return;
        }
        for (int i = 0; i < 4; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if (0 >= mx || mx + a - 1 > n || 0 >= my || my + b - 1 > m) continue;
            if (visit[mx][my]) continue;
            if (check(mx, my)) {
                visit[mx][my] = visit[x][y] + 1;
                q.push({ mx,my });
            }
        }
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m >> a >> b >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }
    int s, e;
    cin >> s >> e;
    map[s][e] = 2; //시작
    visit[s][e] = 1;
    q.push({ s,e });
    cin >> s >> e;
    map[s][e] = 3; //목적지
    bfs();
    cout << visit[s][e] - 1;
    return 0;
}