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
char c[10][10];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (c[i][j] == '1') {
                for (int k = 0; k <= i; k++) {
                    for (int l = 0; l <= j; l++) {
                        if (c[k][l] == '1')c[k][l] = '0';
                        else c[k][l] = '1';
                    }
                }
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}