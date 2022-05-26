
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 추석트래픽 {
    private static final int MAX = 123456789;
    private static final int MOD = 1000000007;
    private static final long SECOND = 1000;
    private static final long MINUTE = 60*SECOND;
    private static final long HOUR = 60*MINUTE;

    public static StringTokenizer st;
    public static int dx[] = {0, 0, 1, -1};
    public static int dy[] = {1, -1, 0, 0};
    public static int n, m, k;

    public int solution(String[] lines) {
        int ans = 0;
        List<Node> list = new ArrayList<>();
        for (String str : lines) {
            st = new StringTokenizer(str);
            st.nextToken();
            String response = st.nextToken();
            long hour = Long.parseLong(response.substring(0,2))*HOUR;
            long minute = Long.parseLong(response.substring(3,5))*MINUTE;
            long second = Long.parseLong(response.substring(6,8))*SECOND;
            long ms = Long.parseLong(response.substring(9,12));
            long end = hour+minute+second+ms;

            String request[] = st.nextToken().split("\\.");
            if(request.length==1){
                long reqSecond = Long.parseLong(request[0].substring(0,request[0].length()-1))*SECOND;
                long start = end-reqSecond+1;
                list.add(new Node(start,end));
            }else{
                long reqSecond = Long.parseLong(request[0])*SECOND;
                long reqMs = Long.parseLong(request[1].substring(0,request[1].length()-1));
                long start = end-(reqSecond+reqMs)+1;
                list.add(new Node(start,end));
            }
        }
        int size =list.size();
        for(int i=0;i<size;i++){
            long start = list.get(i).start;
            long end = list.get(i).end;
            int cnt = 1;
            for(int j=i+1;j<size;j++){
                if(list.get(j).start<start+SECOND || list.get(j).start<end+SECOND){
                    cnt++;
                }
            }
            ans=Math.max(ans,cnt);
        }
        return ans;
    }
    static class Node{
        long start;
        long end;

        public Node(long start, long end) {
            this.start = start;
            this.end = end;
        }
    }
    
}


