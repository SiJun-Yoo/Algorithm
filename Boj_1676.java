import java.io.*;

public class Boj_1676 {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        bw.write(solve(n)+"");
        bw.flush();
    }
    public static int solve(int n){
        if(n<4) return 0;
        return solve(n/5)+n/5;
    }
}

