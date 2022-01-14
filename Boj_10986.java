import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Boj_10986 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	public static long d[] = new long[1001];
	public static int arr[] = new int[1000001];

	public static void main(String[] args) throws NumberFormatException, IOException {
		String input[] = br.readLine().split(" ");
		int n = Integer.parseInt(input[0]);
		int m = Integer.parseInt(input[1]);
		input = br.readLine().split(" ");
		long ans = 0;
		for (int i = 1; i <= n; i++) {
			int now = Integer.parseInt(input[i - 1]);
			arr[i] = (now + arr[i - 1]) % m;
			d[arr[i]]++;
		}
		ans = d[0];
		for (int i = 0; i < m; i++) {
			ans +=  (d[i] * (d[i] - 1) / 2);
		}
		bw.write(Long.toString(ans));
		bw.flush();
	}

}
