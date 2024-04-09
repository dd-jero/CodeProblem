import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main{
	
	static int TC,N,M,res,moveCnt;
	static char[][] map;
	static boolean[][] visited;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,1,-1};
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		TC = 1;
		
		while(true) {
			
			try {
				st = new StringTokenizer(br.readLine());
				
				N = Integer.parseInt(st.nextToken());
				M = Integer.parseInt(st.nextToken());
				
				visited = new boolean[N][M];
				res = Integer.MAX_VALUE;
				map = new char[N][M];
				moveCnt = 0; // 빈 공간의 수 
				
				for(int i=0;i<N;i++) {
					String str2 = br.readLine();
					for(int j=0;j<M;j++) {
						map[i][j] = str2.charAt(j);
						
						if(map[i][j] == '.') moveCnt++;
					}
				}
				
				for(int i=0;i<N;i++) {
					for(int j=0;j<M;j++) {
						if(map[i][j] == '.') { // 해당 칸이 빈칸이면 
							visited[i][j] = true;
							// x,y,단계,이동한 빈칸 수
							dfs(i,j,0,1);
							
							visited[i][j] = false;
						}
					}
				}
				
				res = (res == Integer.MAX_VALUE) ? -1 : res;
				
				sb.append("Case "+TC+": "+res+"\n");
				TC++;
				
			} catch (Exception e) {
				bw.write(String.valueOf(sb));
				bw.flush();
				bw.close();
				br.close();
				break;
			}
		}
	}

	private static void dfs(int x, int y, int cnt, int moveSum) {
		
		// 종료 조건 : 모든 빈칸을 다 방문 했으면 
		if(moveSum == moveCnt) { 
			res = res > cnt ? cnt : res; 
			return;
		}
		
		for(int d=0;d<4;d++) { // 4 방향 
			
			int tmpSum = 0;
			int curX = x;
			int curY = y;
			int nx;
			int ny;
			
			while(true) { // 한 방향으로 계속 이동 시키기 위함
				
				nx = curX + dx[d];
				ny = curY + dy[d];
				
				// 보드 경계 외, 장애물, 이미 지나갔던 칸이면 루프문 종료 
				if(!checkRegion(nx,ny) || visited[nx][ny] || map[nx][ny] == '*') break;
				
				// 현재 위치 새로 갱신 
				curX = nx;
				curY = ny;
				visited[curX][curY] = true; // 방문 체크 
				tmpSum++;
			}
			
			// 움직이지 못하면 다음 방향 진행 (다음 단계로 X)
			if(curX == x && curY == y) continue;
			
			// 움직였으면 다음 단계로 넘어감 
			dfs(curX, curY, cnt+1, moveSum+tmpSum);
			
			// 원상 복구 : 해당 방향에서 움직인 만큼 
			for(int i=0;i<tmpSum;i++) {
				visited[curX][curY] = false;
				
				curX -= dx[d];
				curY -= dy[d];
			}
		}
		
	}

	private static boolean checkRegion(int x, int y) { // 경계 체크 
		return x>-1 && x<N && y>-1 && y<M;
	}
	
}