import java.io.*;
import java.util.*;

public class Boj2696BySort {
    private static final int MAX = 123456789;
    private static final int MOD = 1000000007;
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int dx[] = {0, 0, 1, -1};
    public static int dy[] = {1, -1, 0, 0};
    public static int n, m, k;

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(br.readLine());
        while(T-->0){
            int n = Integer.parseInt(br.readLine());
            List<Integer> list = new ArrayList<>();
            List<Integer> ans = new ArrayList<>();
            int size = (n-1)/10+1;
            int cnt = 1;
            for(int i=0;i<size;i++){
                st = new StringTokenizer(br.readLine());
                while(st.hasMoreTokens()) {
                    int now = Integer.parseInt(st.nextToken());
                    list.add(now);
                    Collections.sort(list);
                    if (cnt % 2 == 1) {
                        ans.add(list.get(cnt / 2));
                    }
                    cnt++;
                }
            }
            bw.write(ans.size()+"\n");
            for(int a:ans) bw.write(a+" ");
            bw.write("\n");
        }
        bw.flush();
    }

}
