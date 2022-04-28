import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Boj_16235 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	public static int ans = 0;
	public static int n, m, k;
	public static int map[][] = new int[11][11]; // 영양분 정보
	public static int a[][] = new int[11][11]; // 추가되는 영양분
	public static List<Integer> b[][] = new ArrayList[11][11]; // 나무
	public static int dx[] = {-1,-1,-1,0,0,1,1,1};
	public static int dy[] = {-1,0,1,-1,1,-1,0,1};

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		for(int i=1;i<=n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=1;j<=n;j++) {
				map[i][j] = 5;
				a[i][j] = Integer.parseInt(st.nextToken());
				b[i][j] = new ArrayList<>();
			}
		}
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			b[x][y].add(z);
		}
		for(int i=0;i<k;i++) {
			springAndSummer();
			fall();
			winter();
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				ans+=b[i][j].size();
			}
		}
		bw.write(Integer.toString(ans));
		bw.flush();
	}

	public static void springAndSummer() {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(b[i][j].size() == 0) continue;
				int idx =0;
				Collections.sort(b[i][j]);
				int size = b[i][j].size();
				while(idx<size) {
					int now = b[i][j].get(idx);
					if(now<=map[i][j]) {
						map[i][j]-=now;
						b[i][j].set(idx, now+1);
						idx++;
					}else { 
						for(int _idx = idx;_idx<size;_idx++) {
							map[i][j]+=b[i][j].get(idx)/2;
							b[i][j].remove(idx);
						}
						break;
					}
				}
			}
		}
	}

	public static void fall() {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(b[i][j].size() == 0 ) continue;
				for(int now:b[i][j]) {
					if(now%5!=0) continue;
					for(int idx = 0;idx<8;idx++) {
						int x = i+dx[idx];
						int y = j+dy[idx];
						if(x<1||y<1||x>n||y>n) continue;
						b[x][y].add(1);
					}
				}
				
			}
		}
	}

	public static void winter() {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				map[i][j] += a[i][j];
			}
		}
	}
	
}
