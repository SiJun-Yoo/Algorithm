import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;
public class boj_1194{
	static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int MAX=100000000;
	static int dx[]= {0,0,1,-1};
	static int dy[]= {1,-1,0,0};
	static int a[][]=new int[8][8];
	static int visit[][][]=new int[50][50][1<<6];
	static int b[][]=new int[8][8];
	static int n,m;
	static Queue<Node> q=new LinkedList<>();
	static char c[][]=new char[50][50];
	public static void main(String[] args) throws NumberFormatException, IOException {
		st=new StringTokenizer(br.readLine());
		n=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		List<Node> list=new ArrayList<>();
		for(int i=0;i<n;i++) {
			String input=br.readLine();
			for(int j=0;j<m;j++) {
				c[i][j]=input.charAt(j);
				if(c[i][j]=='0') {
					visit[i][j][0]=1;
					q.add(new Node(i,j,0));
				}else if(c[i][j]=='1') {
					list.add(new Node(i,j,0));
				}
			}
		}
		bfs();
		int ans=MAX;
		for(int j=0;j<list.size();j++) {
			int gx=list.get(j).x;
			int gy=list.get(j).y;
			for(int i=0;i<(1<<6);i++) {
				if(visit[gx][gy][i]!=0) {
					ans=Math.min(ans, visit[gx][gy][i]);
				}
			}
		}
		
		bw.write((ans==MAX?-1:ans-1)+"");
		bw.flush();
	}
	static void bfs() {
		while(!q.isEmpty()) {
			Node node=q.poll();
			int x=node.x;
			int y=node.y;
			int chk=node.chk;
			for(int i=0;i<4;i++) {
				int mx=x+dx[i];
				int my=y+dy[i];
				if(mx<0||my<0||mx>=n||my>=m) continue;
				if(c[mx][my]=='#') continue;
				if(visit[mx][my][chk]!=0) continue;
				if('A'<=c[mx][my]&&c[mx][my]<='F') {
					int now=c[mx][my]-'A';
					if((chk&(1<<now))==0) continue;
					visit[mx][my][chk]=visit[x][y][chk]+1;
					q.add(new Node(mx,my,chk));
				}else if('a'<=c[mx][my]&&c[mx][my]<='f') {
					int now=c[mx][my]-'a';
					visit[mx][my][chk|(1<<now)]=visit[x][y][chk]+1;
					q.add(new Node(mx,my,chk|(1<<now)));
				}else {
					visit[mx][my][chk]=visit[x][y][chk]+1;
					q.add(new Node(mx,my,chk));
				}
			}
		}
	}
}
class Node{
	int x,y,chk;
	public Node(int x, int y,int chk) {
		super();
		this.x = x;
		this.y = y;
		this.chk=chk;
	}
	
}
