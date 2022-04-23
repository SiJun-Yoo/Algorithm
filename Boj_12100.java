import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Boj_12100 {
  public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  public static StringTokenizer st;
  public static int ans = 0;
  public static int blockCnt = 0;
  public static int n;
  public static int map[][] = new int[20][20];
  public static int dx[] = {0, 0, 1, -1};// 오른쪽,왼쪽,아래,위
  public static int dy[] = {1, -1, 0, 0};


  public static void main(String[] args) throws IOException {
    n = Integer.parseInt(br.readLine());
    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < n; j++) {
        map[i][j] = Integer.parseInt(st.nextToken());
        if (map[i][j] != 0)
          blockCnt++;
      }
    }
    if (n == 1) {
      bw.write(Integer.toString(map[0][0]));
      bw.flush();
      return;
    }
    solve(0, map);
    bw.write(Integer.toString(ans));
    bw.flush();
  }

  public static void solve(int now, int state[][]) {
    if (now == 5) {
      setMaxResult(state);
      return;
    }
    for (int i = 0; i < 4; i++) {
      int nowMap[][] = copy(state);
      move(i, nowMap, new boolean[n][n]);
      solve(now + 1, nowMap);
    }

  }

  public static void setMaxResult(int[][] a) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        ans = Math.max(ans, a[i][j]);
      }
  }

  public static void move(int idx, int k[][], boolean chk[][]) {
    if (idx == 0) {// 오른쪽
      for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= 0; j--) {
          int x = i;
          int y = j;
          while (true) {
            if (y == n - 1) {
              break;
            }
            int mx = x + dx[idx];
            int my = y + dy[idx];
            if (k[mx][my] == 0) {
              k[mx][my] = k[x][y];
              k[x][y] = 0;
              chk[mx][my] = chk[x][y];
            } else if (!chk[mx][my] && !chk[x][y] && k[mx][my] == k[x][y]) {
              k[mx][my] += k[x][y];
              chk[mx][my] = true;
              chk[x][y] = false;
              k[x][y] = 0;
            } else {
              break;
            }
            x = mx;
            y = my;
          }
        }
      }
    } else if (idx == 1) {// 왼쪽
      for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
          int x = i;
          int y = j;
          while (true) {
            if (y == 0) {
              break;
            }
            int mx = x + dx[idx];
            int my = y + dy[idx];
            if (k[mx][my] == 0) {
              k[mx][my] = k[x][y];
              k[x][y] = 0;
              chk[mx][my] = chk[x][y];
            } else if (!chk[mx][my] && !chk[x][y] && k[mx][my] == k[x][y]) {
              k[mx][my] += k[x][y];
              k[x][y] = 0;
              chk[mx][my] = true;
              chk[x][y] = false;
            } else {
              break;
            }
            x = mx;
            y = my;
          }
        }
      }
    } else if (idx == 2) {// 아래
      for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
          int x = i;
          int y = j;
          while (true) {
            if (x == n - 1) {
              break;
            }
            int mx = x + dx[idx];
            int my = y + dy[idx];
            if (k[mx][my] == 0) {
              k[mx][my] = k[x][y];
              k[x][y] = 0;
              chk[mx][my] = chk[x][y];
            } else if (!chk[mx][my] && !chk[x][y] && k[mx][my] == k[x][y]) {
              k[mx][my] += k[x][y];
              k[x][y] = 0;
              chk[mx][my] = true;
              chk[x][y] = false;
            } else {
              break;
            }
            x = mx;
            y = my;
          }
        }
      }
    } else {// 위
      for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
          int x = i;
          int y = j;
          while (true) {
            if (x == 0) {
              break;
            }
            int mx = x + dx[idx];
            int my = y + dy[idx];
            if (k[mx][my] == 0) {
              k[mx][my] = k[x][y];
              chk[mx][my] = chk[x][y];
              k[x][y] = 0;
            } else if (!chk[mx][my] && !chk[x][y] && k[mx][my] == k[x][y]) {
              k[mx][my] += k[x][y];
              k[x][y] = 0;
              chk[mx][my] = true;
              chk[x][y] = false;
            } else {
              break;
            }
            x = mx;
            y = my;
          }
        }
      }
    }
  }

  public static int[][] copy(int k[][]) {
    int ret[][] = new int[n][n];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        ret[i][j] = k[i][j];
    return ret;
  }
}
