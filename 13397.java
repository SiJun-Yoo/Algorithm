import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
  public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  public static StringTokenizer st;
  public static int n, m;

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    List<Integer> list = new ArrayList<>();
    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < n; i++) {
      int now = Integer.parseInt(st.nextToken());
      list.add(now);
    }
    int l = 0, r = 10000;
    while (l <= r) {
      int mid = (l + r) / 2;
      int min = list.get(0);
      int max = list.get(0);
      int cnt = 1;
      for (int i = 1; i < n; i++) {
        int now = list.get(i);
        min = Math.min(min, now);
        max = Math.max(max, now);
        if ((max - min) > mid) {
          cnt++;
          min = now;
          max = now;
          continue;
        }
      }
      if (cnt > m) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    bw.write(Integer.toString(l));
    bw.flush();
  }
}
