import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Boj_16958 {
    private static final int MAX = 123456789;
    private static final int MOD = 1000000007;
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int dx[] = {0, 0, 1, -1};
    public static int dy[] = {1, -1, 0, 0};
    public static int cnt1[] = new int[26];
    public static int cnt2[] = new int[26];
    public static int n, m,k;
    public static int dist[][] = new int[1001][1001];
    public static boolean flag[] = new boolean[1001];
    public static List<Node> list = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k= Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            if(s==1) flag[i] = true;
            list.add(new Node(x,y));

        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sx = list.get(i).x;
                int sy = list.get(i).y;
                int ex = list.get(j).x;
                int ey = list.get(j).y;
                dist[i][j] = Math.abs(sx-ex)+Math.abs(sy-ey);
            }
        }
        m = Integer.parseInt(br.readLine());
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            bw.write(solve(s-1,e-1)+"\n");
        }
        bw.flush();
    }
    static int solve(int s,int e){
        if(flag[s] && flag[e]){
            return Math.min(dist[s][e],k);
        }

        int dist1 = getDist(s);
        int dist2 = getDist(e);
        return Math.min(dist[s][e],dist1+dist2+k);
    }

    static int getDist(int now){
        int min  =MAX;
        for(int i=0;i<n;i++){
            if(!flag[i]) continue;
            if(min>dist[now][i]){
                min = dist[now][i];
            }
        }
        return min;
    }
    static class Node {
        int x, y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
