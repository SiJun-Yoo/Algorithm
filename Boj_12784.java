import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class Boj_12784 {
    private static final int MAX = 123456789;
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int dx[] = {0, 0, 1, -1};
    public static int dy[] = {1, -1, 0, 0};
    public static int n, m, k;
    public static List<Node> list[] = new LinkedList[1001];
    public static int d[] = new int[1001];
    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(br.readLine());
        while(T-->0){
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            for(int i=1;i<=n;i++){
                d[i] = MAX;
                list[i] = new LinkedList<>();
            }
            for(int i=0;i<m;i++){
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                int e = Integer.parseInt(st.nextToken());
                int cost = Integer.parseInt(st.nextToken());
                list[s].add(new Node(e,cost));
                list[e].add(new Node(s,cost));
            }
            if(n==1){
                bw.write("0\n");
                continue;
            }
            bw.write(solve(1,0)+"\n");
        }
        bw.flush();
    }
    public static int solve(int now,int parent){
        int ret =0;
        for(Node node:list[now]){
            if(node.e == parent) continue;
            int next = node.e;
            int cost = node.cost;
            d[next] = Math.min(cost,solve(next,now));
            ret+=d[next];
        }
        if(ret==0) return MAX;
        return ret;
    }
    static class Node{
        int e;
        int cost;

        public Node(int e, int cost) {
            this.e = e;
            this.cost = cost;
        }
    }
}

