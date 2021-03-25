import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
public class boj_2473 {
	static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static long MAX=10000000000000l;
	static int n,m;
	static ArrayList<Long> list=new ArrayList<>();
	public static void main(String[] args) throws Exception{
		n=Integer.parseInt(br.readLine());
		st=new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			long now=Long.parseLong(st.nextToken());
			list.add(now);
		}
		Collections.sort(list);
		long ans=MAX;
		long ansX=0,ansY=0,ansZ=0;
		for(int i=0;i<n;i++) {
			int l=i+1;
			int r=n-1;
			while(l<r) {
				long x=list.get(i);
				long y=list.get(l);
				long z=list.get(r);
				long now=x+y+z;
				if(now>0) {
					r--;
					if(ans>now) {
						ans=now;
						ansX=x;
						ansY=y;
						ansZ=z;
					}
				}else if(now<0) {
					l++;
					if(ans>-now) {
						ans=-now;
						ansX=x;
						ansY=y;
						ansZ=z;
					}
				}else {
					bw.write(Long.toString(x)+" "+Long.toString(y)+" "+Long.toString(z));
					bw.flush();
					return;
				}
			}
		}
		bw.write(Long.toString(ansX)+" "+Long.toString(ansY)+" "+Long.toString(ansZ));
		bw.flush();
		bw.close();
		br.close();
	}
}


