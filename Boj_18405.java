import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Boj_18405 {
    private static final int MAX = 123456789;
    private static final int MOD = 1000000007;
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int dx[] = {0, 0, 1, -1};
    public static int dy[] = {1, -1, 0, 0};
    public static int n, m, k;

    public static int map[][] = new int[201][201];
    public static Queue<Node> q[] = new LinkedList[1001];
    public static boolean visit[][] = new boolean[201][201];
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for(int i=1;i<=m;i++) q[i] = new LinkedList<>();
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] != 0){
                    q[map[i][j]].add(new Node(i,j));
                }
            }
        }
        st = new StringTokenizer(br.readLine());
        int s= Integer.parseInt(st.nextToken());
        int x= Integer.parseInt(st.nextToken());
        int y= Integer.parseInt(st.nextToken());
        for(int i=0;i<s;i++){
            bfs();
        }
        
        bw.write(map[x-1][y-1]+"");
        bw.flush();
    }
    static void bfs(){
        for(int i=1;i<=m;i++){
            int size = q[i].size();
            while(size-->0){
                Node node = q[i].poll();
                int x = node.x;
                int y = node.y;
                for(int j=0;j<4;j++){
                    int mx = x+dx[j];
                    int my = y+dy[j];
                    if(mx<0||my<0||mx>=n||my>=n) continue;
                    if(map[mx][my]!=0) continue;
                    if(visit[mx][my]) continue;
                    visit[mx][my] = true;
                    map[mx][my] = i;
                    q[i].add(new Node(mx,my));
                }
            }
        }
    }
    static class Node{
        int x;
        int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

}

