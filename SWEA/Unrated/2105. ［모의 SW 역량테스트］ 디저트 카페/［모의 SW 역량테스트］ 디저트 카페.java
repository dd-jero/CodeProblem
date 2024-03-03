import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Solution{
	
	static int TC,N,res, start[];
	static int[][] map;
	static boolean[] sameD;
	static boolean[][] visited;
	static int[] dx = {-1, 1, 1, -1}; // 우상, 우하, 좌하, 좌상 
	static int[] dy = {1, 1, -1, -1};
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		TC = Integer.parseInt(br.readLine());
		
		for(int t=1;t<=TC;t++) {
			
			N = Integer.parseInt(br.readLine()); // 길이
			
			map = new int[N][N];
			start = new int[2];
			res = 0;
			
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			} // 입력 완료
			
			for(int i=1;i<N-1;i++) { // 위 행과 아래 행이 있어야함
				for(int j=0;j<N-2;j++) { // 오른쪽으로 두 개 열이 존재해야 
					sameD = new boolean[101]; // 매 확인 마다 초기화 
					visited = new boolean[N][N]; // 다시 돌아가는 것을 방지하기 위해 
					start[0] = i;
					start[1] = j;
					dfs(i,j,1,0);
				}
			}
			
			res = res != 0 ? res : -1;
			sb.append("#"+t+" "+res+"\n");
		}
		
		bw.write(String.valueOf(sb));
		bw.flush();
		
		br.close();
		bw.close();
	}
	
	static void dfs(int x, int y, int cnt, int dir) {
		
		visited[x][y] = true;
		sameD[map[x][y]] = true;
		
		for(int d=dir;d<4;d++) { // 이전 방향과 같거나 다음 방향으로 넘어가야됨 
			int nx = x + dx[d];
			int ny = y + dy[d];
			
			if(nx>-1 && nx<N && ny>-1 && ny<N) {
				
				if(nx == start[0] && ny == start[1] && cnt > 2) { // 시작점은 이미 방문 처리 되어서 이 부분에서 확인 
					res = cnt > res ? cnt : res;
					return;
				}
				
				if(!sameD[map[nx][ny]] && !visited[nx][ny]) {  // 해당 디저트 안먹고 다시 돌아가는 게 아니면 
					
					dfs(nx,ny,cnt+1,d);
					
					// 원복
					sameD[map[nx][ny]] = false;
					visited[nx][ny] = false;
				}
			}
		}
	}
}