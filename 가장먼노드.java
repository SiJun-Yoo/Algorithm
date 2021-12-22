import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class 가장먼노드 {
	static Queue<Integer> q = new LinkedList<>();
	static List<Integer> list[] = new ArrayList[20001];
	static int dist[] = new int[20001];
	static boolean chk[] = new boolean[20001];

	public int solution(int n, int[][] edge) {
		int answer = 0;

		for (int i = 1; i <= n; i++) {
			list[i] = new ArrayList<>();
		}
		for (int i = 0; i < edge.length; i++) {
			int s = edge[i][0];
			int e = edge[i][1];
			list[s].add(e);
			list[e].add(s);
		}
		chk[1] = true;
		q.add(1);
		bfs();
		int maxLength = 0;
		for (int i = 2; i <= n; i++) {
			if (dist[i] > maxLength) {
				maxLength = dist[i];
				answer = 1;
			} else if (dist[i] == maxLength) {
				answer++;
			}
		}
		return answer;
	}

	public void bfs() {
		while (!q.isEmpty()) {
			int now = q.poll();
			int size = list[now].size();
			for (int i = 0; i < size; i++) {
				int next = list[now].get(i);
				if (chk[next])
					continue;
				chk[next] = true;
				dist[next] = dist[now] + 1;
				q.add(next);
			}
		}
	}

}
