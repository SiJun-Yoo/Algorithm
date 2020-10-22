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
int n, m;
string str[10];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int visit[10][10][10][10];
queue<pair<pii, pii>> q;
bool isSafe(int x, int y) {
    if (0 <= x && x < n && 0 <= y && y < m) return true;
    return false;
}
int bfs() {
    while (!q.empty()) {
        int x1 = q.front().first.first;
        int y1 = q.front().first.second;
        int x2 = q.front().second.first;
        int y2 = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int mx1 = x1;
            int my1 = y1;
            int mx2 = x2;
            int my2 = y2;
            while (isSafe(mx1 + dx[i], my1 + dy[i]) && str[mx1 + dx[i]][my1 + dy[i]] == '.') {
                mx1 += dx[i];
                my1 += dy[i];
            }
            while (isSafe(mx2 + dx[i], my2 + dy[i]) && str[mx2 + dx[i]][my2 + dy[i]] == '.') {
                mx2 += dx[i];
                my2 += dy[i];
            }
            if (isSafe(mx2 + dx[i], my2 + dy[i]) && str[mx2 + dx[i]][my2 + dy[i]] == 'O') {
                continue;
            }
            if (isSafe(mx1 + dx[i], my1 + dy[i]) && str[mx1 + dx[i]][my1 + dy[i]] == 'O') {
                return visit[x1][y1][x2][y2];
            }
            if (mx1 == mx2 && my1 == my2) {
                if (i == 1) {
                    if (y1 > y2) {
                        my1 -= dy[i];
                    }
                    else {
                        my2 -= dy[i];
                    }
                }
                else if (i == 2) {
                    if (x1 > x2) {
                        mx2 -= dx[i];
                    }
                    else {
                        mx1 -= dx[i];
                    }
                }
                else if (i == 3) {
                    if (x1 > x2) {
                        mx1 -= dx[i];
                    }
                    else {
                        mx2 -= dx[i];
                    }
                }
                else {
                    if (y1 > y2) {
                        my2 -= dy[i];
                    }
                    else {
                        my1 -= dy[i];
                    }
                }
            }
            if (visit[mx1][my1][mx2][my2]) continue;
            if (visit[x1][y1][x2][y2] >= 10) continue;
            visit[mx1][my1][mx2][my2] = visit[x1][y1][x2][y2] + 1;
            q.push({ {mx1,my1},{mx2,my2} });
        }
    }
    return -1;
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        for (int j = 0; j < m; j++) {
            if (str[i][j] == 'R') {
                x1 = i;
                y1 = j;
                str[i][j] = '.';
            }
            else if (str[i][j] == 'B') {
                x2 = i;
                y2 = j;
                str[i][j] = '.';
            }
        }
    }
    q.push({ {x1,y1},{x2,y2} });
    visit[x1][y1][x2][y2] = 1;
    cout << bfs();
    return 0;
}