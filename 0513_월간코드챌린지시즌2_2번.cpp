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
typedef priority_queue<ll> pql;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
using namespace std;

vector<long long> solution(vector<long long> num) {
    vector<long long> ans;
    int size = num.size();
    for (int i = 0; i < size; i++) {
        long long now = num[i];
        long long cnt = 0;
        long long tmp = 0;
        priority_queue<ll> pq;
        for (int i = 0; i < 63; i++) {
            tmp = (now ^ (1ll << i));
            pq.push(-tmp);
        }
        for (int i = 0; i < 63; i++) {
            for (int j = i + 1; j < 63; j++) {
                tmp = (now ^ (1ll << i));
                tmp = (tmp ^ (1ll << j));
                pq.push(-tmp);
            }
        }
        ll b = num[i];
        while (!pq.empty()) {
            ll k = -pq.top();
            pq.pop();
            if (k <= b) continue;
            ans.push_back(k);
            break;
        }
    }
    return ans;
}
