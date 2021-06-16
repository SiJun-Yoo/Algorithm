import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main { 
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static int MAX=100000000;
	static int n,m,k;
	static long MOD=987654321;
	static long d[]=new long[10001];
	public static void main(String[] args) throws IOException {
		st=new StringTokenizer(br.readLine());
		n=Integer.parseInt(st.nextToken());
		d[0]=1;
		d[2]=1;
		d[4]=2;
		for(int i=6;i<=n;i+=2) {
			for(int j=0;j<=i-2;j+=2) {
				d[i]+=d[j]*d[i-j-2];
				d[i]%=MOD;			
			}
		}
		bw.write(Long.toString(d[n]));
		bw.flush();
	}	
}

