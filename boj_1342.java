import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class boj_1342 {
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static int MAX=100000000;
    static int dx[]= {0,0,1,-1};
    static int dy[]= {1,-1,0,0};
    static int n,d;
    static int c[]=new int[26];
    static Set<String> s=new HashSet<>();
//    static ArrayList<Integer> tree[]=new ArrayList[100001];
    static ArrayList<Long> list=new ArrayList<>();
	public static void main(String[] args) throws IOException {
		String str=br.readLine();
		n=str.length();
		for(int i=0;i<n;i++) {
			c[str.charAt(i)-'a']++;
		}
		
		bw.write(Integer.toString(solve(0,-1,"")));
		bw.flush();
        bw.close();
        br.close();
	}
	static int solve(int depth,int prev,String str) {
		if(depth==n) {
			return 1;
		}
		int ret=0;
		for(int i=0;i<26;i++) {
			if(c[i]==0) continue;
			if(prev==i) continue;
			c[i]--;
			ret+=solve(depth+1,i,str+(char)(c[i]+'a'));
			c[i]++;
		}
		return ret;
	}
}