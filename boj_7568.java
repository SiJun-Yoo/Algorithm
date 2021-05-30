import java.io.*;
import java.util.*;
public class Main {
	static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws Exception{
		int N=Integer.parseInt(br.readLine());
		int weight[]=new int[N];
		int height[]=new int[N];
		int count[]=new int[N];
		for(int i=0;i<N;i++) {
			String str=br.readLine();
			st=new StringTokenizer(str);
			weight[i]=Integer.parseInt(st.nextToken());
			height[i]=Integer.parseInt(st.nextToken());
		}
		for(int i=0;i<N;i++) {
			count[i]=1;
		}
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(i==j) continue;
				if(weight[i]<weight[j]&&height[i]<height[j]) {
					count[i]++;
				}
			}
		}
		for(int i=0;i<N;i++) {
			bw.write(Integer.toString(count[i])+" ");
		}
		bw.flush();
		bw.close();
		br.close();
	}
}
