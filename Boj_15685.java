import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

public class Boj_15685 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	public static int n;
	public static boolean chk[][] = new boolean[101][101];
	public static int dx[] = {0,-1,0,1};
	public static int dy[] = {1,0,-1,0};
	public static void main(String[] args) throws IOException {
		n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			int x,y,dir,g;
			st = new StringTokenizer(br.readLine());
			y = Integer.parseInt(st.nextToken());
			x = Integer.parseInt(st.nextToken());
			dir = Integer.parseInt(st.nextToken());
			g = Integer.parseInt(st.nextToken());
			makeDragon(x,y,dir,g);
		}
		
		bw.write(Integer.toString(getRectCnt()));
		bw.flush();
	}
	public static void makeDragon(int x, int y,int dir, int g) {
		chk[x][y] = true;
		x+=dx[dir];
		y+=dy[dir];
		chk[x][y] = true;
		if(g==0) {
			return;
		}
		List<Integer> list = new ArrayList<>();
		list.add(dir);
		int level = 1;
		while(level<=g) {
			for(int i=list.size()-1;i>=0;i--) {
				int nowDir = list.get(i);
				nowDir = (nowDir+1)%4;
				x+=dx[nowDir];
				y+=dy[nowDir];
				chk[x][y] = true;
				list.add(nowDir);
			}
			level++;
		}
	}
	public static int getRectCnt() {
		int ret =0;
		for(int i=0;i<100;i++) {
			for(int j=0;j<100;j++) {
				if(chk[i][j] && chk[i+1][j] && chk[i][j+1] && chk[i+1][j+1]) ret++;
			}
		}
		return ret;
	}
	
}
