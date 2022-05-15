import java.io.*;

public class Boj_11637 {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int idx = 0;
            int maxVal = 0;
            int maxCount = 0;
            int sum = 0;

            for (int i = 1; i <= n; i++) {
                int now = Integer.parseInt(br.readLine());
                sum+=now;
                if(maxVal<now){
                    maxVal = now;
                    idx = i;
                    maxCount = 1;
                }else if(maxVal == now){
                    maxCount++;
                }
            }
            if(maxCount >=2){
                bw.write("no winner\n");
                continue;
            }
            if(maxVal<=sum/2){
                bw.write("minority winner ");
            }else{
                bw.write("majority winner ");
            }
            bw.write(idx+"\n");
        }
        bw.flush();
    }
}
