import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

public class Boj_17140 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	public static int n, m, k,nCnt,mCnt;
	public static int a[][] = new int[101][101];
	public static int num[] = new int[101];
	public static int nIdx[] = new int[101];
	public static int mIdx[] = new int[101];

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		for(int i=1;i<=3;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=1;j<=3;j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		nCnt =3;
		mCnt =3;
		int cnt =0;
		while(true) {
			if(cnt>100) {
				cnt=-1;
				break;
			}
			if(a[n][m] == k) {
				break;
			}
			if(nCnt>=mCnt) {
				nSort();
			}else {
				mSort();
			}
			cnt++;
		}
		bw.write(Integer.toString(cnt));
		bw.flush();
	}

	public static void nSort() {
		for(int i=1;i<=nCnt;i++) {
			List<Node> list = new ArrayList<>();
			for(int j=1;j<=mCnt;j++) {
				num[a[i][j]]++;
			}
			for(int j=1;j<=100;j++) {
				if(num[j]==0) continue;
				list.add(new Node(j,num[j]));
				num[j] = 0;
			}
			Collections.sort(list);
			int numCnt = 1;
			for(int j=0;j<list.size()&&numCnt<=100;j++) {
				int val = list.get(j).val;
				int cnt = list.get(j).cnt;
				a[i][numCnt++] = val;
				if(numCnt>100) break;
				a[i][numCnt++] = cnt;
			}
			nIdx[i] = numCnt;
		}
		for(int i=1;i<=nCnt;i++) {
			mCnt = Math.max(mCnt, nIdx[i]);
		}
		for(int i=1;i<=nCnt;i++) {
			for(int j=nIdx[i];j<=mCnt;j++) {
				a[i][j] =0;
			}
		}
	}
	public static void mSort() {
		for(int i=1;i<=mCnt;i++) {
			List<Node> list = new ArrayList<>();
			for(int j=1;j<=nCnt;j++) {
				num[a[j][i]]++;
			}
			for(int j=1;j<=100;j++) {
				if(num[j]==0) continue;
				list.add(new Node(j,num[j]));
				num[j] = 0;
			}
			Collections.sort(list);
			int numCnt = 1;
			for(int j=0;j<list.size()&&numCnt<=100;j++) {
				int val = list.get(j).val;
				int cnt = list.get(j).cnt;
				a[numCnt++][i] = val;
				if(numCnt>100) break;
				a[numCnt++][i] = cnt;
			}
			mIdx[i] = numCnt;
		}
		for(int i=1;i<=mCnt;i++) {
			nCnt = Math.max(nCnt, mIdx[i]);
		}
		for(int i=1;i<=mCnt;i++) {
			for(int j=mIdx[i];j<=nCnt;j++) {
				a[j][i] =0;
			}
		}
	}
}
class Node implements Comparable<Node>{
	int val;
	int cnt;
	public Node(int val, int cnt) {
		super();
		this.val = val;
		this.cnt = cnt;
	}
	@Override
	public int compareTo(Node o) {
		if(this.cnt == o.cnt) {
			return this.val-o.val;
		}
		return this.cnt-o.cnt;
	}
	
}

