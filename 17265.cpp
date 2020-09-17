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
char c[5][5];
qii q;
int n;
int a[5][5];
int b[5][5];
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };
void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 2; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if (mx < 0 || my < 0 || mx >= n || my >= n) continue;
            if ('0' <= c[x][y] && c[x][y] <= '9') {
                a[mx][my] = max(a[mx][my], a[x][y]);
                b[mx][my] = min(b[mx][my], b[x][y]);
                q.push({ mx,my });
            }
            else {
                char op = c[x][y];
                if (op == '+') {
                    int now = a[x][y] + (c[mx][my] - '0');
                    a[mx][my] = max(a[mx][my], now);
                    now = b[x][y] + (c[mx][my] - '0');
                    b[mx][my] = min(b[mx][my], now);
                }
                else if (op == '*') {
                    int now = a[x][y] * (c[mx][my] - '0');
                    a[mx][my] = max(a[mx][my], now);
                    now = b[x][y] * (c[mx][my] - '0');
                    b[mx][my] = min(b[mx][my], now);
                }
                else if (op == '-') {
                    int now = a[x][y] - (c[mx][my] - '0');
                    a[mx][my] = max(a[mx][my], now);
                    now = b[x][y] - (c[mx][my] - '0');
                    b[mx][my] = min(b[mx][my], now);
                }
                q.push({ mx,my });
            }
        }
    }

}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
            a[i][j] = -MAX;
            b[i][j] = MAX;
        }
    }
    a[0][0] = c[0][0] - '0';
    b[0][0] = c[0][0] - '0';
    q.push({ 0,0 });
    bfs();
    cout << a[n - 1][n - 1] << ' ' << b[n - 1][n - 1];
    return 0;
}