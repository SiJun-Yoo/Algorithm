import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	static int a[][]=new int[20][20];
	static int dx[]= {-1,0,1,1};
	static int dy[]= {1,1,1,0};
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		String input;
		StringTokenizer st;
		for(int i=1;i<=19;i++) {
			input=br.readLine();
			st=new StringTokenizer(input);
			for(int j=1;j<=19;j++) {
				a[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		for(int i=1;i<=19;i++) {
			for(int j=1;j<=19;j++) {
				if(a[i][j]==0) continue;
				for(int k=0;k<4;k++) {
					int x=i;
					int y=j;					
					for(int l=0;l<4;l++) {
						x+=dx[k];
						y+=dy[k];
						if(x<1||y<1||x>19||y>19) break;
						if(a[i][j]!=a[x][y]) break;
						if(l!=3) continue;
						x+=dx[k];
						y+=dy[k];
						if(x<1||y<1||x>19||y>19) {
							x-=dx[k];
							y-=dy[k];
						}else {
							if(a[i][j]==a[x][y]) {
								break;
							}
							x-=dx[k];
							y-=dy[k];
						}
						x-=dx[k]*5;
						y-=dy[k]*5;
						if(!(x<1||y<1||x>19||y>19)&&a[i][j]==a[x][y]) {
							break;
						}
						bw.write(Integer.toString(a[i][j])+"\n"+Integer.toString(i)+" "+Integer.toString(j));
						bw.flush();
						return;
					}
				}
			}
		}
		bw.write("0");
		bw.flush();
		bw.close();
		br.close();
	}
	
}