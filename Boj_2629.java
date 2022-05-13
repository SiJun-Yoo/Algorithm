import java.io.*;
import java.util.*;

public class Boj_2629 {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n,m;
    public static int a[] = new int[31];
    public static boolean d[][] = new boolean[31][15001];

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        st= new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) {
            a[i] =  Integer.parseInt(st.nextToken());
        }
        solve(0,0);
        m =Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<m;i++){
            int now = Integer.parseInt(st.nextToken());
            if(now>15000) bw.write('N');
            else if(d[n][now]) bw.write('Y');
            else bw.write('N');
            bw.write(' ');
        }
        bw.flush();
    }

    public static void solve(int l,int r){
        if(l>n) return;
        if(d[l][r]) return;
        d[l][r] = true;
        solve(l+1,r);
        solve(l+1,r+a[l]);
        solve(l+1,Math.abs(r-a[l]));
    }
}
