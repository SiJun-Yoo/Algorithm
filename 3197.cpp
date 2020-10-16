#define MAX 2000000000
#define MOD 1000000007
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef queue<pair<int, int>> qii;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
string str[1500];
int parent[1500 * 1500 + 5];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int r, c;
queue<pii> q;
vector<int> v;
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
bool Union(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return false;
    parent[rx] = ry;
    return true;
}
void Set(int x, int y) {
    int now = x * c + y;
    for (int i = 0; i < 4; i++) {
        int mx = x + dx[i];
        int my = y + dy[i];
        if (mx < 0 || my < 0 || mx >= r || my >= c) {
            continue;
        }
        if (str[mx][my] == 'X') continue;
        int next = mx * c + my;
        Union(now, next);
    }
}
int bfs() {
    int ret = 0;
    while (!q.empty()) {
        int size = q.size();
        if (find(v[0]) == find(v[1])) break;
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            int now = x * c + y;
            q.pop();
            for (int j = 0; j < 4; j++) {
                int mx = x + dx[j];
                int my = y + dy[j];
                if (mx < 0 || my < 0 || mx >= r || my >= c) {
                    continue;
                }
                int next = mx * c + my;
                if (Union(now, next)) {
                    str[mx][my] = '.';
                    Set(mx, my);
                    q.push({ mx,my });
                }
            }
        }
        ret++;
    }
    return ret;
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> r >> c;
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        cin >> str[i];
        for (int j = 0; j < c; j++) {
            int now = i * c + j;
            parent[now] = now;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int now = i * c + j;
            if (str[i][j] == 'X') continue;
            if (str[i][j] == 'L') {
                v.push_back(now);
            }
            q.push({ i,j });
            Set(i, j);
        }
    }
    if (v.size() == 1) {
        cout << 0;
        return 0;
    }
    cout << bfs();
    return 0;
}