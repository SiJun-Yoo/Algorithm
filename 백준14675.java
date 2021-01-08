import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


public class น้มุ14675 {
	static long MOD=1000000007;
	static int k[]=new int[100001];
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		String input=br.readLine();
		int n=Integer.parseInt(input);
		for(int i=0;i<n-1;i++) {
			input=br.readLine();
			StringTokenizer st=new StringTokenizer(input);
			int a=Integer.parseInt(st.nextToken());
			int b=Integer.parseInt(st.nextToken());
			k[a]++;
			k[b]++;
		}
		input=br.readLine();
		int q=Integer.parseInt(input);
		for(int i=0;i<q;i++) {
			input=br.readLine();
			StringTokenizer st=new StringTokenizer(input);
			int a=Integer.parseInt(st.nextToken());
			int b=Integer.parseInt(st.nextToken());
			if(a==1) {
				if(k[b]==1) bw.write("no\n");
				else bw.write("yes\n");
			}else {
				bw.write("yes\n");
			}
		}
		bw.flush();
		bw.close();
		br.close();
	}
	
}

