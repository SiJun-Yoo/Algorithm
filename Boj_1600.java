import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
public class Boj_1600 {
	static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static long MAX=10000000000000l;
	static int n,m,k;
	static int visit[][][]=new int[200][200][31];
	static int a[][]=new int[200][200];
	static int dx[]={1,-1,0,0};
	static int dy[]={0,0,-1,1};
	static int hx[]={1,1,-1,-1,2,2,-2,-2};
	static int hy[]={2,-2,2,-2,1,-1,-1,1};
	static Queue<Pos> q=new LinkedList<>();
	public static void main(String[] args) throws Exception{
		k=Integer.parseInt(br.readLine());
		st=new StringTokenizer(br.readLine());
		m=Integer.parseInt(st.nextToken());
		n=Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				a[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		visit[0][0][0]=1;
		q.add(new Pos(0,0,0));
		bw.write(Integer.toString(bfs()));
		bw.flush();
		bw.close();
		br.close();
	}
	static int bfs() {
		int ret=-1;
		while(!q.isEmpty()) {
			int x=q.peek().x;
			int y=q.peek().y;
			int cnt=q.peek().cnt;
			q.poll();
			if(x==n-1&&y==m-1) {
				return visit[x][y][cnt]-1;
			}
			if(cnt<k) {
				for(int i=0;i<8;i++) {
					int mx=hx[i]+x;
	                int my=hy[i]+y;
	                if(mx<0||my<0||mx>=n||my>=m) continue;
	                if(a[mx][my]==1) continue;
	                if(visit[mx][my][cnt+1]!=0) continue;
	                visit[mx][my][cnt+1]=visit[x][y][cnt]+1;
	                q.add(new Pos(mx,my,cnt+1));
				}
			}
			for(int i=0;i<4;i++) {
				int mx=dx[i]+x;
	            int my=dy[i]+y;
                if(mx<0||my<0||mx>=n||my>=m) continue;
                if(a[mx][my]==1) continue;
                if(visit[mx][my][cnt]!=0) continue;
                visit[mx][my][cnt]=visit[x][y][cnt]+1;
                q.add(new Pos(mx,my,cnt));
			}
		}
		return ret;
	}
}
class Pos{
	int x,y,cnt;

	public Pos(int x, int y, int cnt) {
		super();
		this.x = x;
		this.y = y;
		this.cnt = cnt;
	}
}
