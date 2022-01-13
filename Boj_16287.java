import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Boj_16287 {
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static long MOD=1000000000;
    static int dx[]= {0,0,1,-1};
    static int dy[]= {1,-1,0,0};
    static int n,m;
    static int a[]=new int[5000];
    static boolean d[]=new boolean[800001];
	public static void main(String[] args) throws IOException {
		st=new StringTokenizer(br.readLine());
		n=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		st=new StringTokenizer(br.readLine());
		for(int i=0;i<m;i++) {
			a[i]=Integer.parseInt(st.nextToken());
		}
		for(int i=0;i<m;i++) {
			for(int j=i+1;j<m;j++) {
				int now=a[i]+a[j];
				if(now>n) continue;
				if(d[n-a[i]-a[j]]) {
					bw.write("YES");
					bw.flush();
					return;
				}
			}
			for(int j=0;j<i;j++) {
				int now=a[i]+a[j];
				if(now>n) continue;
				d[a[i]+a[j]]=true;
			}
			
		}
		bw.write("NO");
        bw.flush();
        bw.close();
        br.close();
	}
}
