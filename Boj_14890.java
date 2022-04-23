import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Boj_14890 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	public static int ans = 0;
	public static int n, m;
	public static int a[][] = new int[100][100];
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		//가로
		boolean chk[][] = new boolean[n][n];
		for(int i=0;i<n;i++) {
			int prev = a[i][0];
			boolean flag = true;
			for(int j=1;j<n;j++) {
				int now = a[i][j];
				if(now==prev)continue;
				if(prev-now==1) {
					//현재칸부터 m-1칸 순방향 경사로
					//범위체크
					if(j+m-1>=n) {
						flag= false;
						break;
					}
					//높이차이가 1로 일정한지 확인	
					boolean highFlag = true;
					for(int k=0;k<m;k++) {
						if(chk[i][j+k]) {
							highFlag=false;
							break;
						}
						if(now != a[i][j+k]) {
							highFlag = false;
							break;
						}
					}
					if(highFlag) {
						for(int k=0;k<m;k++) {
							chk[i][j+k]=true;
						}
						j+=m-1;
						prev = now;
						continue;
					}
					flag = false;
					break;
				}else if(now-prev == 1) {
					//이전칸부터 m-1전 역방향 경사로
					//범위체크
					if(j-m<0) {
						flag= false;
						break;
					}
					//높이차이가 1로 일정한지 확인	
					boolean highFlag = true;
					for(int k=1;k<=m;k++) {
						if(chk[i][j-k]) {
							highFlag=false;
							break;
						}
						if(prev != a[i][j-k]) {
							highFlag = false;
							break;
						}
					}
					if(highFlag) {
						for(int k=1;k<=m;k++) {
							chk[i][j-k]=true;
						}
						prev = now;
						continue;
					}
					flag = false;
					break;
				}else {
					//차이가 1보다크면 안됨
					flag= false;
					break;
				}
			}
			if(flag) {
				ans++;
			}
		}
		//세로
		chk= new boolean[n][n];
		for(int i=0;i<n;i++) {
			int prev = a[0][i];
			boolean flag = true;
			for(int j=1;j<n;j++) {
				int now = a[j][i];
				if(now==prev)continue;
				if(prev-now==1) {
					//현재칸부터 m-1칸 순방향 경사로
					//범위체크
					if(j+m-1>=n) {
						flag= false;
						break;
					}
					//높이차이가 1로 일정한지 확인	
					boolean highFlag = true;
					for(int k=0;k<m;k++) {
						if(chk[j+k][i]) {
							highFlag=false;
							break;
						}
						if(now != a[j+k][i]) {
							highFlag = false;
							break;
						}
					}
					if(highFlag) {
						for(int k=0;k<m;k++) {
							chk[j+k][i]=true;
						}
						j+=m-1;
						prev = now;
						continue;
					}
					flag = false;
					break;
				}else if(now-prev == 1) {
					//이전칸부터 m-1전 역방향 경사로
					//범위체크
					if(j-m<0) {
						flag= false;
						break;
					}
					//높이차이가 1로 일정한지 확인	
					boolean highFlag = true;
					for(int k=1;k<=m;k++) {
						if(chk[j-k][i]) {
							highFlag=false;
							break;
						}
						if(prev != a[j-k][i]) {
							highFlag = false;
							break;
						}
					}
					if(highFlag) {
						for(int k=1;k<=m;k++) {
							chk[j-k][i]=true;
						}
						prev = now;
						continue;
					}
					flag = false;
					break;
				}else {
					//차이가 1보다크면 안됨
					flag= false;
					break;
				}
			}
			if(flag) {
				ans++;
			}
		}
		bw.write(Integer.toString(ans));
		bw.flush();
	}
}
