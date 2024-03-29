import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Boj_14891 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	public static int ans = 0;
	public static int n, m;
	public static int a[][] = new int[4][8];
	public static int chk[] = new int[4];
	public static void main(String[] args) throws IOException {
		for(int i=0;i<4;i++) {
			String str = br.readLine();
			for(int j=0;j<8;j++) {
				a[i][j] = str.charAt(j)-'0';
			}
		}
		int k = Integer.parseInt(br.readLine());
		for(int i=0;i<k;i++) {
			chk = new int[4];
			st = new StringTokenizer(br.readLine());
			int idx = Integer.parseInt(st.nextToken());
			int dir = Integer.parseInt(st.nextToken());
			chk[--idx] = dir;
			for(int j=idx+1;j<4;j++) {
				if(chk[j-1]==0) break;
				if(a[j-1][2]!=a[j][6]) {
					chk[j] = chk[j-1]*-1;
					continue;
				}
				chk[j] = 0;
			}
			for(int j=idx-1;j>=0;j--) {
				if(chk[j+1]==0) break;
				if(a[j+1][6]!=a[j][2]) {
					chk[j] = chk[j+1]*-1;
					continue;
				}
				chk[j]=0;
			}
			move();
		}
		int score = 1;
		for(int i=0;i<4;i++) {
			ans+=score*a[i][0];
			score*=2;
		}
		bw.write(Integer.toString(ans));
		bw.flush();
	}
	public static void move() {
		for(int i=0;i<4;i++) {
			if(chk[i]==0) continue;
			if(chk[i] == 1) {
				int end = a[i][7];
				for(int j=7;j>0;j--) {
					a[i][j]=a[i][j-1];
				}
				a[i][0] = end;
			}else {
				int start = a[i][0];
				for(int j=0;j<7;j++) {
					a[i][j]=a[i][j+1];
				}
				a[i][7] = start;
			}
			
		}
	}
}
