import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Boj_14503 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	public static int ans = 0;
	public static int n, m;
	public static int a[][] = new int[50][50];
	public static boolean chk[][] = new boolean[50][50];
	public static int dx[] = {-1,0,1,0};
	public static int dy[] = {0,1,0,-1};
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int dir = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		while(true) {
			if(!chk[x][y]) {
				ans++; //현재위치를 청소한다.
				chk[x][y] = true;
			}
			
			boolean flag = false;
			for(int i=0;i<4;i++) {
				dir--;
				if(dir==-1) dir = 3;
				int mx = x+dx[dir];
				int my = y+dy[dir];
				if(a[mx][my]==0 && !chk[mx][my]) {
					x=mx;
					y=my;
					flag = true;
					break; //현재 위치의 바로 왼쪽에 아직 청소하지 않은 빈 공간이 존재한다면, 왼쪽 방향으로 회전한 다음 한 칸을 전진하고 1번으로 돌아간다.
				}
			}
			if(flag) {
				continue;
			}
			int nextDir = (dir+2)%4;
			int mx = x+dx[nextDir];
			int my = y+dy[nextDir];
			if(a[mx][my]==1) {
				break;
			}
			x=mx;
			y=my;
		}
		bw.write(Integer.toString(ans));
		bw.flush();
	}
}
