import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st; 
	static int dx[]= {1,0,-1,0};
	static int dy[]= {0,-1,0,1};
	static int a[][]=new int[52][52];
	static int n,r;
	static int x,y;
	public static void main(String[] args) throws IOException{
		int T=Integer.parseInt(br.readLine());
		for(int t=0;t<T;t++) {
			st=new StringTokenizer(br.readLine());
			n=Integer.parseInt(st.nextToken());
			r=Integer.parseInt(st.nextToken());
			memset();
			for(int i=0;i<r;i++) {
				st=new StringTokenizer(br.readLine());
				x=Integer.parseInt(st.nextToken());
				y=Integer.parseInt(st.nextToken());
				a[x][y]=1;
			}
			st=new StringTokenizer(br.readLine());
			x=Integer.parseInt(st.nextToken());
			y=Integer.parseInt(st.nextToken());
			a[x][y]=2;
			int dir=0;
			if(x==0) dir=0;
			else if(y==n+1) dir=1;
			else if(x==n+1) dir=2;			
			else if(y==0) dir=3;
			int mx=x;
			int my=y;
			
			while(true) {
				if(a[mx][my]==1) {
					if(dir==3) dir=0;
					else dir++;
				}
				mx+=dx[dir];
				my+=dy[dir];

				x=mx;
				y=my;
				if(x==0||y==0||x==n+1||y==n+1) break;
			}
			bw.write(Integer.toString(x)+" "+Integer.toString(y)+"\n");
		}		
		
		bw.flush();
		bw.close();
		br.close();
	}
	static void memset() {
		for(int i=0;i<=n+1;i++) {
			for(int j=0;j<=n+1;j++) {
				a[i][j]=0;
			}
		}
	}
}
