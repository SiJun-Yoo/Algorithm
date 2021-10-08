#include<bits/stdc++.h>
using namespace std;
string str[2];
string k;
long long d[101][2][21];
int solve(int x, int y, int z) {
	if (z == k.length() + 1) return 1;
	if (x == str[0].length() + 1) return 0;
	if (d[x][y][z] != -1) return d[x][y][z];
	long long &val = d[x][y][z];
	val = 0;
	for (int i = x; i <= str[0].length(); i++) {
		if (z == 0) {
			if (str[0][i] == k[z]) {
				val += solve(i + 1, 0, 1);
			}
			if (str[1][i] == k[z]) {
				val += solve(i + 1, 1, 1);
			}
		}
		else {
			if (str[!y][i] == k[z]) {
				val += solve(i + 1, !y, z + 1);
			}
		}
	}
	return val;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> k;
	cin >> str[0] >> str[1];
	memset(d, -1, sizeof(d));
	cout << solve(0, 0, 0);
	return 0;
}

