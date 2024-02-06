import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int N,M;
	static int[][] arr;
	static int[][] res;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N+1][N+1];
		res = new int[N+1][N+1];
		
		// 상, 좌 측에 0인 1차원 배열로 덮도록함.
		for(int i=1;i<N+1;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=1;j<N+1;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		} 
		
		res[1][1] = arr[1][1];
		
		for(int i=1;i<N+1;i++) { // 누적 합
			for(int j=1;j<N+1;j++) {
				res[i][j] = (res[i-1][j] + res[i][j-1] - res[i-1][j-1] + arr[i][j]);
			}
		}
		
		for(int i=0;i<M;i++) {
			String[] idx = br.readLine().split(" ");
			
			int x1 = Integer.parseInt(idx[0]);
			int y1 = Integer.parseInt(idx[1]);
			int x2 = Integer.parseInt(idx[2]);
			int y2 = Integer.parseInt(idx[3]);
			
			sb.append(res[x2][y2] - res[x2][y1-1] - res[x1-1][y2] + res[x1-1][y1-1]).append("\n"); // 누적합을 이용하여 해당 범위 합 계산
		}
		
		bw.write(String.valueOf(sb));
		bw.flush();
		
		br.close();
		bw.close();
	}
}