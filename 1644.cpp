#include <iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#include<vector>
#include<memory.h>
using namespace std;
typedef long long ll;
const int MAX = 10000000;
bool prime[4000001];
vector<int> v;
void primeNum() {
    for (int i = 2; i <= 4000000; i++) {
        if (prime[i]) continue;
        v.push_back(i);
        for (int j = i * 2; j <= 4000000; j+=i) {
            prime[j] = true;
        }
    }
}
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    primeNum();
    int size = v.size();
    int l = 0,r=0;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < size; i++) {
        sum += v[i];
        if (sum >= N) {
            while (sum >= N) {
                if (sum == N) {
                    ans++;
                }
                sum -= v[l++];
            }
        }
        r++;
    }
    cout << ans;
    return 0;
}
