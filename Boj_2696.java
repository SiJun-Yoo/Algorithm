import java.io.*;
import java.util.*;

public class Boj_2696 {
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
            PriorityQueue<Integer> minPq = new PriorityQueue<>(Collections.reverseOrder());
            PriorityQueue<Integer> maxPq = new PriorityQueue<>();
            List<Integer> list = new ArrayList<>();
            boolean flag = false;
            int mid = 0;
            int size = (n-1)/10+1;
            int cnt = 1;
            for(int i=0;i<size;i++){
                st = new StringTokenizer(br.readLine());
                while(st.hasMoreTokens()){
                    int now = Integer.parseInt(st.nextToken());
                    if(!flag){
                        mid = now;
                        flag= true;
                    }
                    else if(minPq.size()== maxPq.size()){
                        if(now>=mid){
                            maxPq.add(now);
                        }else{
                            minPq.add(now);
                        }
                    }else if(minPq.size()< maxPq.size()){
                        if(now<mid){
                            minPq.add(now);
                        }else{
                            maxPq.add(now);
                            minPq.add(mid);
                            mid = maxPq.poll();

                        }
                    }else{
                        if(now>=mid){
                            maxPq.add(now);
                        }else{
                            minPq.add(now);
                            maxPq.add(mid);
                            mid = minPq.poll();
                        }
                    }
                    if(cnt++%2==1){
                        list.add(mid);
                    }
                }
            }
            bw.write(list.size()+"\n");
            for(int a:list) bw.write(a+" ");
            bw.write("\n");
        }
        bw.flush();
    }

}
