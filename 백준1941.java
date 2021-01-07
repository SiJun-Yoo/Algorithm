import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;


public class น้มุ1941 {
	static int dx[]= {0,0,1,-1};
	static int dy[]= {1,-1,0,0};
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		String str[]=new String[5];
		for(int i=0;i<5;i++) {
			str[i]=br.readLine();
		}
		int ans=0;
		for(int i=0;i<25;i++) {
			boolean k[][]=new boolean[5][5];
			boolean visit[]=new boolean[25];
			int x=i/5;
			int y=i%5;
			visit[i]=true;
			k[x][y]=true;
			if(str[x].charAt(y)=='S') ans+=dfs(i,1,0,k,visit,str);
			else ans+=dfs(i,0,1,k,visit,str);
		}
		bw.write(Integer.toString(ans));
		bw.flush();
		bw.close();
		br.close();
	}
	static boolean check(boolean k[][],boolean visit[]) {
		Queue<Integer> q=new LinkedList<Integer>();
		boolean c[]=new boolean[25];
		for(int i=0;i<25;i++) {
			if(visit[i]) {
				q.offer(i);
				c[i]=true;
				break;
			}
		}
		int cnt=1;
		while(!q.isEmpty()) {
			int i=q.peek();
			q.poll();
			int x=i/5;
			int y=i%5;
			for(int j=0;j<4;j++) {
				int mx=x+dx[j];
				int my=y+dy[j];
				if(0<=mx&&mx<5&&0<=my&&my<5) {
					if(k[mx][my]&&!c[mx*5+my]) {
						c[mx*5+my]=true;
						cnt++;
						q.offer(mx*5+my);
					}
				}
			}
		}
		if(cnt==7) return true;
		return false;
	}
	static int dfs(int n,int a,int b,boolean k[][],boolean visit[],String str[]) {
		if(a+b==7) {
			if(check(k,visit)) {
				return 1;
			}
			return 0;
		}
		int ret=0;
		for(int i=n+1;i<25;i++) {
			int x=i/5;
			int y=i%5;
			if(str[x].charAt(y)=='S') {
				k[x][y]=true;
				visit[i]=true;
				ret+=dfs(i,a+1,b,k,visit,str);
				k[x][y]=false;
				visit[i]=false;
			}else {
				if(b>=3) continue;
				k[x][y]=true;
				visit[i]=true;
				ret+=dfs(i,a,b+1,k,visit,str);
				k[x][y]=false;
				visit[i]=false;
			}
		}
		return ret;
	}

}

