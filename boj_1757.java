import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main { 
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static int MAX=100000000;
	static int n,m,k;
	static long MOD=1000007;
	static int d[][]=new int[10001][501];
	static int a[]=new int[10001];
	public static void main(String[] args) throws IOException {
		st=new StringTokenizer(br.readLine());
		n=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		for(int i=1;i<=n;i++) {
			a[i]=Integer.parseInt(br.readLine());
		}
		memset(n,m);
		bw.write(Integer.toString(solve(1,0)));
		bw.flush();
	}
	public static int solve(int x,int y) {
		if(x+y==n+1) return 0;
		if(x+y>n+1) return -MAX;
		if(d[x][y]!=-1) return d[x][y];
		d[x][y]=0;
		if(y<m) {
			if(y>0) {
				d[x][y]=Math.max(d[x][y], solve(x+1,y+1)+a[x]);
				d[x][y]=Math.max(d[x][y], solve(x+y,0));
			}else if(y==0) {
				d[x][y]=Math.max(d[x][y], solve(x+1,y+1)+a[x]);
				d[x][y]=Math.max(d[x][y], solve(x+1,0));
			}
		}else if(y==m)d[x][y]=Math.max(d[x][y], solve(x+y,0));
		return d[x][y];
	}
	public static void memset(int x,int y) {
		for(int i=0;i<=x;i++) {
			for(int j=0;j<=y;j++) {
				d[i][j]=-1;
			}
		}
	}
	
}



