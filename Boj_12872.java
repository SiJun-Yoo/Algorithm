import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.System.in;
import static java.lang.System.out;

public class Boj12872 {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(out));
    public static StringTokenizer st;
    public static int dx[] = {0, 0, 1, -1};
    public static int dy[] = {1, -1, 0, 0};
    public static int n, m, k;
    public static long MOD = 1000000007;
    public static int MAX = 987654321;
    public static long d[][] = new long[101][101];

    public static void main(String[] args) throws IOException {
        int input[] = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt)
                .toArray();
        n = input[0];
        m = input[1];
        k = input[2];
        memset();
        bw.write(Long.toString(solve(0, 0)));
        bw.flush();
    }

    public static void memset() {
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                d[i][j] = -1;
            }
        }
    }

    public static long solve(int idx, int cnt) {
        if (idx == k) {
            if (n == cnt) {
                return 1;
            }
            return 0;
        }
        if (d[idx][cnt] != -1) return d[idx][cnt];
        d[idx][cnt] = 0;
        if (n > cnt) {
            d[idx][cnt] += solve(idx + 1, cnt + 1) * (n-cnt);
            d[idx][cnt] %= MOD;
        }

        if (cnt > m) {
            d[idx][cnt] += solve(idx + 1, cnt) * (cnt - m);
            d[idx][cnt] %= MOD;
        }
        return d[idx][cnt];
    }
}

