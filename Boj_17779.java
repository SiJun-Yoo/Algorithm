import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

public class Boj_17779 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	public static int ans = 1000000;
	public static int n;
	public static int a[][] = new int[21][21];
	public static int b[][] = new int[21][21];
	public static int dx[] = { 0, -1, 0, 1 };
	public static int dy[] = { 1, 0, -1, 0 };

	public static void main(String[] args) throws IOException {
		n = Integer.parseInt(br.readLine());
		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= n; j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				for (int d1 = 1; d1 <= n; d1++) {
					for (int d2 = 1; d2 <= n; d2++) {
						if (!isSafe(x, y, d1, d2))
							continue;
						ans = Math.min(ans, solve(x, y, d1, d2));
					}
				}
			}
		}

		
		bw.write(Integer.toString(ans));
		bw.flush();
	}
	public static void print() {
		for(int i= 1;i<=n;i++) {
			for(int j =1;j<=n;j++)
				System.out.print(b[i][j]+" ");
			System.out.println();
		}
		System.out.println();
	}
	public static boolean isSafe(int x, int y, int d1, int d2) {
		return x + d1 + d2 <= n && 1 <= y - d1 && y + d2 <= n;
	}

	public static int getMinMaxSub() {
		int min = 10000000;
		int max = 0;
		int sum[] = new int[6];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				sum[b[i][j]] += a[i][j];
			}
		}
		for(int i= 1;i<=5;i++) {
			min = Math.min(min, sum[i]);
			max = Math.max(max, sum[i]);
		}
		return max - min;
	}

	public static int solve(int _x, int _y, int d1, int d2) {
		int x[] = new int[6];
		int y[] = new int[6];
		x[1] = _x;
		y[1] = _y;

		x[2] = _x + d2;
		y[2] = _y + d2;

		x[3] = _x + d1;
		y[3] = _y - d1;

		x[4] = _x + d1 + d2;
		y[4] = _y - d1 + d2;
		//5섹터
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				b[i][j] = 5;
			}
		}
		// 1섹터
		for (int i = 1; i < x[3]; i++) {
			for (int j = 1; j <= y[1]; j++) {
				if (i + j == x[1] + y[1])
					break;
				b[i][j] = 1;
			}
		}

		// 2섹터
		boolean flag = false; 
		int k = x[1]+y[1];
		for (int i = 1; i <=x[2]; i++) {
			if(i == x[1]) {
				flag= true;
			}
			for (int j = n; j > y[1]; j--) {
				if (flag && k == i+j) {
					break;
				}					
				b[i][j] = 2;
			}
			if(flag) k+=2;
		}
		
		//3섹터
		flag= false;
		k = x[4]+y[4];
		for(int i=n;i>=x[3];i--) {
			if(i == x[4]) {
				flag = true;
			}
			for(int j=1;j<y[4];j++) {
				if(flag && k == i+j) {
					break;
				}
				b[i][j] = 3;
			}
			if(flag) k-=2;
		}
		//4섹터
		for(int i=n;i>x[2];i--) {
			for(int j=n;j>=y[4];j--) {
				if(i+j == x[4]+y[4]) {
					break;
				}
				b[i][j] =4;
			}
		}
		return getMinMaxSub();
	}
}
