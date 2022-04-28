import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Boj_17143 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	public static int ans = 0;
	public static int n, m, k;
	public static Map<Integer, Shark> map = new HashMap<>(); // 나무
	public static int a[][] = new int[101][101];
	public static int dx[] = { 0, -1, 1, 0, 0 };
	public static int dy[] = { 0, 0, 0, 1, -1 };

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		for (int i = 1; i <= k; i++) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			Shark shark = new Shark(r, c, s, d, z);
			map.put(i, shark);
			a[r][c] = i;
		}
		for (int i = 1; i <= m; i++) {
			// 2. 상어잡기
			for (int j = 1; j <= n; j++) {
				if (a[j][i] != 0) {
					ans  += map.get(a[j][i]).size;
					map.remove(a[j][i]);
					a[j][i] = 0;
					break;
				}
			}
			move();
		}
		bw.write(Integer.toString(ans));
		bw.flush();
	}

	private static void move() {
		for (int i = 1; i <= k; i++) {
			if (!map.containsKey(i))
				continue;
			Shark shark = map.get(i);
			int x = shark.x;
			int y = shark.y;
			int speed = shark.speed;
			int dir = shark.dir;
			int cnt = speed;
			int mx = x;
			int my = y;
			while (cnt > 0) {
				mx += dx[dir];
				my += dy[dir];
				if (mx < 1 | my < 1 | mx > n | my > m) {
					mx-=dx[dir];
					my-=dy[dir];
					if (dir % 2 == 1)
						dir += 1;
					else
						dir -= 1;
					mx += dx[dir];
					my += dy[dir];
				}
				cnt--;
			}
			shark.x = mx;
			shark.y = my;
			shark.dir = dir;
			a[x][y] =0;
		}
		kill();
	}
	public static void kill() {
		for(int i=1;i<=k;i++) {
			Shark shark = map.get(i);
			if(shark == null) continue;
			int x = shark.x;
			int y= shark.y;
			if (a[x][y] == 0) {
				a[x][y] = i;
				
			} else {
				Shark bShark = map.get(a[x][y]); //먼저 들어온거
				Shark aShark = map.get(i); //이번에 들어갈거
				if(aShark.size>bShark.size) {
					map.remove(a[x][y]);
					a[x][y] = i;
					
				}else {
					map.remove(i);
				}
			}
		}
	}
}

class Shark {
	int x, y;
	int speed;
	int dir;
	int size;

	public Shark(int x, int y, int speed, int dir, int size) {
		super();
		this.x = x;
		this.y = y;
		this.speed = speed;
		this.dir = dir;
		this.size = size;
	}

}
