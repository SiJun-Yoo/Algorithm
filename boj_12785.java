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
	static long d[][]=new long[201][201];
	public static void main(String[] args) throws IOException {
		st=new StringTokenizer(br.readLine());
		m=Integer.parseInt(st.nextToken());
		n=Integer.parseInt(st.nextToken());
		int x,y;
		st=new StringTokenizer(br.readLine());
		y=Integer.parseInt(st.nextToken());
		x=Integer.parseInt(st.nextToken());
		for(int i=1;i<=n;i++) {
			d[i][1]=1;
		}
		for(int i=1;i<=m;i++) {
			d[1][i]=1;
		}
		for(int i=2;i<=x;i++) {
			for(int j=2;j<=y;j++) {
				d[i][j]=d[i-1][j]+d[i][j-1];
				d[i][j]%=MOD;
			}
		}
		for(int i=1;i<=n;i++) {
			if(d[i][y]==0)d[i][y]=1;
		}
		for(int i=1;i<=m;i++) {
			if(d[x][i]==0)d[x][i]=1;
		}
		for(int i=x+1;i<=n;i++) {
			for(int j=y+1;j<=m;j++) {
				d[i][j]=d[i-1][j]+d[i][j-1];
				d[i][j]%=MOD;
			}
		}
		if(x==n&&y==m) bw.write(Long.toString(d[n][m]));
		else bw.write(Long.toString(d[x][y]*d[n][m]%MOD));
		bw.flush();
	}
	
}



