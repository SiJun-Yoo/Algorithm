#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int ans = 0;
    for (int i = left; i <= right; i++) {
        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) cnt++;
        }
        if (cnt & 1) ans -= i;
        else ans += i;
    }
    return ans;
}
1¹ø