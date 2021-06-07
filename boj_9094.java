import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main { 
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static int MAX=100000000;
	static int n,m,k;
	public static void main(String[] args) throws IOException {
		int t=Integer.parseInt(br.readLine());
		StringBuilder sb=new StringBuilder();
		while(t-->0){
			st=new StringTokenizer(br.readLine());
			n=Integer.parseInt(st.nextToken());
			m=Integer.parseInt(st.nextToken());
			int ans=0;
			for(int i=2;i<n;i++) {
				for(int j=1;j<i;j++) {
					if(((i*i)+(j*j)+m)%(i*j)==0) {
						ans++;
					}
				}
			}
			bw.write(ans+"\n");			
		}
		bw.flush();
	}
}



