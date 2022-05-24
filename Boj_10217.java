import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class Boj_10217 {
    private static final int MAX = 123456789;
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int dx[] = {0, 0, 1, -1};
    public static int dy[] = {1, -1, 0, 0};
    public static int n, m, k;
    public static List<Node> list[] = new LinkedList[101];
    public static PriorityQueue<Node> pq = new PriorityQueue<Node>();
    public static int d[][] = new int[101][10001];
    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(br.readLine());
        while(T-->0){
            st= new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            for(int i=1;i<=n;i++){
                list[i] = new LinkedList<>();
                for(int j=0;j<=m;j++){
                    d[i][j] = MAX;
                }
            }
            for(int i=0;i<k;i++){
                st = new StringTokenizer(br.readLine());

                int s = Integer.parseInt(st.nextToken());
                int e = Integer.parseInt(st.nextToken());
                int cost = Integer.parseInt(st.nextToken());
                int dist = Integer.parseInt(st.nextToken());

                list[s].add(new Node(e,cost,dist));
            }

            pq.add(new Node(1,0,0));
            d[1][0] = 0;
            while(!pq.isEmpty()){
                Node node = pq.poll();
                int now = node.e;
                for(Node nextNode: list[now]){
                    int next = nextNode.e;
                    int cost = nextNode.cost+node.cost;
                    int dist = nextNode.dist;
                    if(cost>m) continue;
                    if(d[next][cost]>d[now][node.cost]+dist){
                        d[next][cost] = d[now][node.cost]+dist;
                        pq.add(new Node(next,cost,d[next][cost]));
                    }
                }
            }
            int ans = MAX;
            for(int i=0;i<=m;i++){
                if(d[n][i]!=MAX){
                    ans=Math.min(ans,d[n][i]);
                }
            }
            bw.write(((ans==MAX)?"Poor KCM":ans)+"\n");

        }
        bw.flush();
    }

}
class Node implements Comparable<Node>{
    int e;
    int cost;
    int dist;

    public Node(int e, int cost, int dist) {
        this.e = e;
        this.cost = cost;
        this.dist = dist;
    }

    @Override
    public int compareTo(Node o) {
        return this.dist-o.dist;
    }
}
