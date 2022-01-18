import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Solution {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	public static int n,m;
	public static void main(String[] args) throws Exception {
		int T = Integer.parseInt(br.readLine());
		int idx = 1;
		while(T-->0) {
			n = Integer.parseInt(br.readLine());
			int now = n;
			int chk = solve(now);
			int goal = (1<<10)-1;
			while(true) {
				if(chk==goal) break;
				now+=n;
				chk|=solve(now);
			}
			bw.write('#'+Integer.toString(idx++)+' '+Integer.toString(now)+'\n');
		}
		bw.flush();
	}
	public static int solve(int now) {
		int ret = 0;
		while(now>0) {
			int num = now%10;
			now/=10;
			ret|=1<<num;
		}
		return ret;
	}
}
