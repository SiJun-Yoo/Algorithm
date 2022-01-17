#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<string>
#include<memory.h>
using namespace std;
typedef long long ll;
queue<int> q;
vector<int> v[501];
int dist[501];
int indegree[501];
int time[501];
void topol() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int size = v[x].size();
		for (int i = 0; i < size; i++) {
			int y = v[x][i];
			indegree[y]--;
			time[y] = max(time[y], dist[y] + time[x]);
			if (indegree[y]) continue;
			q.push(y);
		}
	}
}
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a,b;
		cin >> a;
		dist[i] = a;
		while (true) {
			cin >> b;
			if (b == -1) break;
			v[b].push_back(i);
			indegree[i]++;
		}		
	}
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			time[i] = dist[i];
		}
	}
	topol();
	for (int i = 1; i <= N; i++) {
		cout << time[i] << '\n';
	}
}
