import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Boj_16946 {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int dx[] = {0, 0, 1, -1};
    public static int dy[] = {1, -1, 0, 0};
    public static int n, m;
    public static int a[][] = new int[1001][1001];
    public static int cnt[] = new int[1000001];
    public static int d[][] = new int[1001][1001];
    public static boolean chk[] = new boolean[100001];
    public static Queue<Node> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                a[i][j] = str.charAt(j) - '0';
            }
        }
        int idx = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) continue;
                if (d[i][j] != 0) continue;
                q.add(new Node(i, j));
                d[i][j] = idx;
                cnt[idx++] = 1;
                bfs();
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(a[i][j]==0){
                    bw.write("0");
                    continue;
                }
                int sum = 1;
                for (int k = 0; k < 4; k++) {
                    int mx = i + dx[k];
                    int my = j + dy[k];
                    if (mx < 0 || my < 0 || mx >= n || my >= m) continue;
                    if(chk[d[mx][my]]) continue;
                    chk[d[mx][my]] = true;
                    sum+=cnt[d[mx][my]];
                }
                for(int k=0;k<4;k++){
                    int mx = i + dx[k];
                    int my = j + dy[k];
                    if (mx < 0 || my < 0 || mx >= n || my >= m) continue;
                    chk[d[mx][my]] = false;
                }
                bw.write(Integer.toString(sum%10));
            }
            bw.write("\n");
        }
        bw.flush();
    }

    public static void bfs() {
        while (!q.isEmpty()) {
            Node node = q.poll();
            int x = node.x;
            int y = node.y;
            int idx = d[x][y];
            for (int i = 0; i < 4; i++) {
                int mx = x + dx[i];
                int my = y + dy[i];
                if (mx < 0 || my < 0 || mx >= n || my >= m) continue;
                if (a[mx][my] != 0) continue;
                if (d[mx][my] != 0) continue;
                d[mx][my] = idx;
                cnt[idx]++;
                q.add(new Node(mx, my));
            }
        }
    }

    static class Node {
        int x, y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}

