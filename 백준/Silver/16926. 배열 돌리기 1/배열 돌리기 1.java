import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	
	static int[] dx = {0,1,0,-1};
	static int[] dy = {1,0,-1,0};
	
	static int[][] arr;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb;
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());
		
		arr = new int[N][M];
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<M;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		} // 입력 완료 
		
		// 0,0 / 1,1 / 2,2 /... 를 기준으로
		int num = Math.min(N, M) / 2;
		
		for(int r=0;r<R;r++) { // 회전 횟 수 만큼 
			for(int i=0;i<num;i++) {
				int x = i;
				int y = i;
				
				int tmp = arr[x][y]; // 처음 덮어 씌워지는 값이므로 따로 저장해둠.
				
				int d = 0;
				
				while(d<4) { // 한 줄씩 계속 옮기기 위함.
					int nx = x + dx[d];
					int ny = y + dy[d];
					
					if(i-1<nx&&nx<N-i&&i-1<ny&&ny<M-i) { // 범위 조건 중요
						arr[x][y] = arr[nx][ny]; // 옮겨지는 값을 현재 위치로 저장
						x = nx;
						y = ny;
					}else { // 범위 내에 들어오지 못하면
						d++; // 다음 방향					
					}
				}
				
				arr[i+1][i] = tmp; // 마지막 바꾸는 요소는 이미 바뀌어 있는 값이어서 이전에 저장한 값 불러옴
			}
		}
		
		sb = new StringBuilder();
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				sb.append(arr[i][j]).append(" ");
			}
			sb.append("\n");
		}
	
		bw.write(String.valueOf(sb));
		bw.flush();
		
		br.close();
		bw.close();
		
	}
}