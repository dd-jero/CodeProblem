import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	
	static int N;
	static int[][] check;
	static int[] dx = {0,-1,0,1};
	static int[] dy = {1,0,-1,0};
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N= Integer.parseInt(br.readLine());
		check = new int[101][101];
		int total = 0;
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			int X = Integer.parseInt(st.nextToken());
			int Y = Integer.parseInt(st.nextToken());
			
			for(int j=X;j<X+10;j++) {
				for(int k=Y;k<Y+10;k++) {
					check[j][k] = 1;
				}
			}
		}
		
//		for(int i=0;i<101;i++) {
//			for(int j=0;j<101;j++) {
//				System.out.print(check[i][j]);
//			}
//			System.out.println();
//		}
		
		for(int i=0;i<=100;i++) {
			for(int j=0;j<=100;j++) {
				if(check[i][j]==0) {
					for(int d=0;d<4;d++) {
						int nx = i + dx[d];
						int ny = j + dy[d];
						if(-1<nx&&nx<101&&-1<ny&&ny<101) {
							if(check[nx][ny] == 1) {
								total++;
							}
						}
					}
				}
			}
		}
		
		System.out.println(total);
	}
}