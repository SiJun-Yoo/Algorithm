import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class Main {
    private static final int MAX = 123456789;
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;

    public static int n, m, k;
    public static List<Node> list[] = new LinkedList[2001];
  
    public static boolean sVisit[] = new boolean[2001];
    public static boolean gVisit[] = new boolean[2001];
    public static boolean hVisit[] = new boolean[2001];

    public static int sDist[] = new int[2001];
    public static int gDist[] = new int[2001];
    public static int hDist[] = new int[2001];
  
    public static PriorityQueue<Node> pq = new PriorityQueue<Node>();

    public static void main(String[] args) throws IOException, ExecutionException, InterruptedException {
        int T = Integer.parseInt(br.readLine());
        while(T-->0){
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int g = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());
            for(int i=1;i<=n;i++){
                list[i] = new LinkedList<>();
                sVisit[i] = false;
                gVisit[i] = false;
                hVisit[i] = false;
                sDist[i] = MAX;
                gDist[i] = MAX;
                hDist[i] = MAX;
            }
            for(int i=0;i<m;i++){
                st= new StringTokenizer(br.readLine());
                int start = Integer.parseInt(st.nextToken());
                int end = Integer.parseInt(st.nextToken());
                int cost = Integer.parseInt(st.nextToken());
                list[start].add(new Node(end,cost));
                list[end].add(new Node(start,cost));
            }
            solve(s,sDist,sVisit);
            solve(g,gDist,gVisit);
            solve(h,hDist,hVisit);
            List<Integer> ans = new LinkedList<>();
            int cost = Math.abs(gDist[s]-hDist[s]);
            for(int i=0;i<k;i++){
                int now = Integer.parseInt(br.readLine());
                if((sDist[now]==(hDist[now]+cost+gDist[s]))||(sDist[now]==(gDist[now]+cost+hDist[s]))){
                    ans.add(now);
                }
            }
            ans.stream().sorted().forEach((num)-> {
                try {
                    bw.write(num+" ");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            });
            bw.write("\n");
        }
        bw.flush();
    }
    public static void solve(int start, int[] dist,boolean[] visit){
        dist[start] = 0;
        pq.add(new Node(start,0));
        while(!pq.isEmpty()){
            Node node = pq.poll();
            int x = node.e;
            if(visit[x]) continue;
            visit[x] = true;
            int size = list[x].size();
            for(int i=0;i<size;i++){
                int next = list[x].get(i).e;
                int cost = list[x].get(i).cost;
                if(dist[next]>dist[x]+cost){
                    dist[next] = dist[x]+cost;
                    pq.add(new Node(next,dist[next]));
                }
            }
        }
    }
}
class Node implements Comparable<Node>{
    int e;
    int cost;

    public Node(int e, int cost) {
        this.e = e;
        this.cost = cost;
    }

    @Override
    public int compareTo(Node o) {
        return this.cost-o.cost;
    }
}
