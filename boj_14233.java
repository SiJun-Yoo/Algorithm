import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class boj_14233 {
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static int MAX=100000000;
    static int dx[]= {0,0,1,-1};
    static int dy[]= {1,-1,0,0};
    static int n,s,d;
    static int dist[]=new int[100001]; 
//    static ArrayList<Integer> tree[]=new ArrayList[100001];
    static ArrayList<Long> list=new ArrayList<>();
	public static void main(String[] args) throws IOException {
		n=Integer.parseInt(br.readLine());
		st=new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			list.add(Long.parseLong(st.nextToken()));
		}
		Collections.sort(list);
		long l=1;
		long r=1000000000;
		long ans=0;
		while(l<=r) {
			long mid=(l+r)/2;
			long cnt=mid;
			boolean flag=true;
			for(int i=0;i<n;i++) {
				if(cnt>list.get(i)) {
					flag=false;
					break;
				}
				cnt+=mid;
			}
			if(flag) {
				ans=mid;
				l=mid+1;
			}else {
				r=mid-1;
			}
			
		}
		bw.write(Long.toString(ans));
        bw.flush();
        bw.close();
        br.close();
	}

}