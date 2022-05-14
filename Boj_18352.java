import java.io.*;
import java.util.*;

public class Boj_18352 {
    private static final int MAX = 300001;
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n, m, k, x;
    public static List<Integer> graph[] = new ArrayList[MAX];
    public static int dist[] = new int[MAX];
    public static boolean chk[] = new boolean[MAX];
    public static Queue<Integer> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            graph[s].add(e);
        }
        q.add(x);
        chk[x] = true;
        bfs();
        boolean flag= false;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == k){
                bw.write(i+"\n");
                flag= true;
            }
        }
        if(!flag) bw.write("-1");
        bw.flush();
    }

    public static void bfs() {
        while (!q.isEmpty()) {
            int now = q.poll();
            int size = graph[now].size();
            for (int i = 0; i < size; i++) {
                int next = graph[now].get(i);
                if(chk[next]) continue;
                dist[next] = dist[now]+1;
                chk[next] = true;
                q.add(next);
            }
        }
    }
}

