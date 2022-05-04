import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class Main {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	public static int ans = 0;
	public static int n;
	public static int a[][] = new int[51][51];
	public static int parent[] = new int[51];
	public static PriorityQueue<Edge> pq = new PriorityQueue<>();
	public static void main(String[] args) throws IOException {
		n = Integer.parseInt(br.readLine());
		for (int i = 1; i <= n; i++) {
			String s = br.readLine();
			parent[i] = i;
			for (int j = 1; j <= n; j++) {
				char c = s.charAt(j-1);
				if(c=='0') continue;
				if ('a' <= c && c <= 'z') {
					a[i][j] = c - 'a' + 1;
				}
				if ('A' <= c && c <= 'Z') {
					a[i][j] = c - 'A' + 27;
				}
				pq.add(new Edge(i,j,a[i][j]));
			}
		}
		while(!pq.isEmpty()) {
			Edge edge = pq.poll();
			int x = edge.s;
			int y= edge.e;
			int cost = edge.cost;
			if(union(x,y)) {
				ans+=cost;
			}
		}
		boolean flag= true;
		for(int i=2;i<=n;i++) {
			if(!union(1,i)) {
				flag=false;
				break;
			}
		}
		if(flag) bw.write(Integer.toString(ans));
		else bw.write("-1");
		bw.flush();
	}

	public static int find(int x) {
		if (parent[x] == x)
			return x;
		return parent[x] = find(parent[x]);
	}

	public static boolean union(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)	return true;
		parent[x] = y;
		return false;
	}
}
class Edge implements Comparable<Edge>{
	int s,e;
	int cost;
	@Override
	public int compareTo(Edge o) {
		return this.cost-o.cost;
	}
	public Edge(int s, int e, int cost) {
		super();
		this.s = s;
		this.e = e;
		this.cost = cost;
	}

	
}
