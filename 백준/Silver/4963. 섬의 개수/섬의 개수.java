import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int W,H,res;
	static int[][] map;
	static int[] dx = {-1,-1,-1,0,1,1,1,0}; // 8방향 
	static int[] dy = {-1,0,1,1,1,0,-1,-1};
	static boolean[][] visited;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		
		while(true) {
			st = new StringTokenizer(br.readLine());
			W = Integer.parseInt(st.nextToken());
			H = Integer.parseInt(st.nextToken());
			
			
			if(W == 0 && H == 0) break;
			
			res = 0;
			map = new int[H][W];
			visited = new boolean[H][W];
			
			for(int i=0;i<H;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<W;j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			} // 입력 완료
			
			for(int i=0;i<H;i++) {
				for(int j=0;j<W;j++) {
					if(map[i][j] == 1 && !visited[i][j]) { // 해당 값이 1이고 방문하지 않았으면 
						res += 1;
						dfs(i,j);
					}
					
				}
			} 
			
			sb.append(res+"\n");
		}
		
		System.out.print(sb);
		
	}
	
	static void dfs(int x, int y) {
		
		visited[x][y] = true; // 방문 체크 
		
		for(int d=0;d<8;d++) { // 8방향 확인 
			
			int nx = x + dx[d];
			int ny = y + dy[d];
			
			if(nx>-1 && nx<H && ny>-1 && ny<W) { // 범위 내에 존재하고
				if(map[nx][ny] == 1 && !visited[nx][ny]) { // 1이면서 방문하지 않았다면
					dfs(nx,ny); // 재귀 
				}
			}
			
		}
		
	}
}
