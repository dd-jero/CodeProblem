import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	
	static int N, total;
	static int X,Y;
	static boolean[][] check = new boolean[101][101];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			
			X = Integer.parseInt(st.nextToken());
			Y = Integer.parseInt(st.nextToken());
			
			for(int j=X;j<X+10;j++) {
				for(int k=Y;k<Y+10;k++) {
					if(check[j][k]) continue;
					check[j][k] = true;
					total++;
				}
			}
		}
		
		bw.write(String.valueOf(total));
		
		bw.flush();
		br.close();
		bw.close();
	}
}