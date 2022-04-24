import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Boj_15684 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	public static int ans = 0;
	public static int n, m,h;
	public static boolean chk[][] = new boolean[12][32];
	public static boolean flag;
	public static void main(String[] args) throws IOException {
		st= new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		for(int i=0;i<h;i++) {
			st= new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());
			int idx = Integer.parseInt(st.nextToken());
			chk[idx][k] = true;
		}
		for(int i=0;i<=3;i++) {
			solve(1,0,i);
			if(flag) {
				bw.write(Integer.toString(i));
				bw.flush();
				return;
			}
		}
		
		bw.write("-1");
		bw.flush();
	}
	public static void solve(int idx,int cnt,int ladderCnt) {
		if(flag) {
			return;
		}
		if(move()) {
			flag= true;
			ans=cnt;
			return;
		}
		if(cnt==ladderCnt) return;
		for(int i=idx;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(!chk[i][j] && !chk[i-1][j] && !chk[i+1][j]) { //현재 왼쪽 오른쪽 다 사다리가 없으면 
					chk[i][j] = true;
					solve(i,cnt+1,ladderCnt);
					chk[i][j] = false;
				}
			}
		}
		
	}
	public static boolean move() {
		for(int i=1;i<=n;i++) {
			int now = i;
			for(int j=1;j<=m;j++) {
				if(chk[now][j]) now++; //오른쪽으로 턴
				else if(chk[now-1][j]) now--; //왼쪽으로 턴
			}
			if(now==i) continue;
			return false;
		}
		return true;
	}
}
