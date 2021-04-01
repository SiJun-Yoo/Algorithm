import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class boj_12888 {
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static int MAX=100000000;
    static int dx[]= {0,0,1,-1};
    static int dy[]= {1,-1,0,0};
    static int n;
    static long d[]=new long[61];
    static Set<String> s=new HashSet<>();
//    static ArrayList<Integer> tree[]=new ArrayList[100001];
	public static void main(String[] args) throws IOException {
		n=Integer.parseInt(br.readLine());
		d[0]=1;
		d[1]=1;
		d[2]=3;
		if(n>2) {
			for(int i=3;i<=n;i++) {
				d[i]=1;
				for(int j=0;j<i-1;j++) {
					d[i]+=d[j]*2;
				}
			}
		}
		bw.write(Long.toString(d[n]));
		bw.flush();
        bw.close();
        br.close();
	}

}