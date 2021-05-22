#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef queue<int> qi;
typedef queue<pair<int, int>> qii;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
const int MOD = 1000000007;
const int MAX = 123456789;
int arr[1001];
int dp[1001];
int N;
int solve(int x) {
    if (x == N) {
        return 0;
    }
    if (x > N) {
        return MAX;
    }
    int& val = dp[x];
    if (val != 0) return val;
    val = MAX;
    for (int i = 1; i <= arr[x]; i++) {
        val = min(val, 1 + solve(x + i));
    }
    return val;
}
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int ans = solve(1);
    if (ans >= MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }

}