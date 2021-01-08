import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;


public class น้มุ14677 {
	static int d[][][]=new int[1500][1500][3];
	static char c[]= {'B','L','D'};
	static long MOD=1000000007;
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		String input=br.readLine();
		int n=Integer.parseInt(input);
		input=br.readLine();
		int ans=0;
		for(int i=0;i<n*3;i++) {
			for(int j=0;j<n*3;j++) {
				for(int k=0;k<3;k++) {
					d[i][j][k]=-1;
				}				
			}
		}
		bw.write(Integer.toString(solve(0,3*n-1,0,input)));
		bw.flush();
		bw.close();
		br.close();
	}
	static int solve(int s,int e,int k,String str) 
	{
		if(s>e) return 0;
		if(d[s][e][k]!=-1) return d[s][e][k];
		d[s][e][k]=0;
		if(str.charAt(s)==c[k]) d[s][e][k]=Math.max(d[s][e][k], solve(s+1,e,k==2?0:k+1,str)+1);
		if(str.charAt(e)==c[k]) d[s][e][k]=Math.max(d[s][e][k], solve(s,e-1,k==2?0:k+1,str)+1);
		return d[s][e][k];
	}
}

