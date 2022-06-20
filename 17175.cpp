#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
ll fib[51];
ll MAX = 1000000007;
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i <= n; i++) {
		fib[i] = (1 + fib[i - 1] + fib[i - 2]) % MAX;
	}
	cout << fib[n];
}
