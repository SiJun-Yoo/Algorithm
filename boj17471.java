import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static ArrayList<ArrayList<Integer>> list=new ArrayList<ArrayList<Integer>>(); 
	static boolean visit[]=new boolean[11];
	static boolean pick[]=new boolean[11];
	static int score[]=new int[11];
	static Queue<Integer> q=new LinkedList<>();
	static int dx[]= {0,0,1,-1};
	static int dy[]= {1,-1,0,0};
	static int n,m;
	static int ans=1000000000;
	public static void main(String[] args) throws IOException{
		n=Integer.parseInt(br.readLine());
		st=new StringTokenizer(br.readLine());
		list.add(new ArrayList<Integer>());
		for(int i=1;i<=n;i++) {
			score[i]=Integer.parseInt(st.nextToken());
			list.add(new ArrayList<Integer>());
		}
		for(int i=1;i<=n;i++) {
			st=new StringTokenizer(br.readLine());
			m=Integer.parseInt(st.nextToken());
			for(int j=0;j<m;j++){
				list.get(i).add(Integer.parseInt(st.nextToken()));
			}
		}
		for(int i=1;i<=n/2;i++) {
			chk(1,0,i);
		}
		bw.write(Integer.toString(ans==1000000000?-1:ans));
		bw.flush();
		bw.close();
		br.close();
	}
	static void chk(int idx,int depth,int max) {
		if(depth==max) {
			Arrays.fill(visit, false);
			for(int i=1;i<=n;i++) {
				if(pick[i]) {
					visit[i]=true;
					q.add(i);
					bfs();
					break;
				}
			}
			for(int i=1;i<=n;i++) {
				if(!pick[i]) {
					visit[i]=true;
					q.add(i);
					bfs();
					break;
				}
			}
			boolean flag=true;
			for(int i=1;i<=n;i++) {
				if(!visit[i]) flag=false;
			}
			if(flag) {
				int now=0;
				for(int i=1;i<=n;i++) {
					if(pick[i]) now+=score[i];
					else now-=score[i];
				}
				ans=Math.min(ans, Math.abs(now));
			}
			return;
		}
		if(idx>n) return;
		pick[idx]=true;
		chk(idx+1,depth+1,max);
		pick[idx]=false;
		chk(idx+1,depth,max);
	}
	static void bfs() {
		while(!q.isEmpty()) {
			int x=q.peek();
			q.poll();
			int size=list.get(x).size();
			for(int i=0;i<size;i++) {
				int next=list.get(x).get(i);
				if(visit[next]) continue;
				if(pick[next]!=pick[x]) continue;
				q.add(next);
				visit[next]=true;
			}
		}
	}
}



