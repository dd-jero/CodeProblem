import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Main{
	
	static int R,C,res;
	static char[][] map;
	static Queue<int[]> waterQ, gosumQ;
	static boolean[][] visitedG;
	static int[] dx = {0,1,0,-1};
	static int[] dy = {1,0,-1,0};
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		map = new char[R][C];
		visitedG = new boolean[R][C];
		waterQ = new ArrayDeque<>(); // 현재 물의 경계
		gosumQ = new ArrayDeque<>(); // 고슴도치 이동
		
		for(int i=0;i<R;i++) {
			String tmp = br.readLine();
			for(int j=0;j<C;j++) {
				map[i][j] = tmp.charAt(j);
				
				if(map[i][j] == 'S') {
					gosumQ.offer(new int[] {i,j,0});
				}else if(map[i][j] == '*') {
					waterQ.offer(new int[] {i,j});
				}
 			}
		} // 입력 완료 
		
		// 물 먼저 채우고 이동 
		for(int i=0;i<R*C;i++) {
			fill();
			move();
			
			if(res != 0) break;
		}
		
		
		if(res == 0) System.out.println("KAKTUS"); 
		else System.out.println(res);
		
	}

	private static void move() {
		int size = gosumQ.size();
		for(int i=0;i<size;i++) {
			
			int[] cur = gosumQ.poll();
			int x = cur[0];
			int y = cur[1];
			int curT = cur[2];
			
			if(map[x][y] == 'D') {// 종료 조건
				res = curT;
				return;
			}		
			
			// 물(+바뀐 구역), 돌을 제외하고 고슴도치 이동 위치 확인
			for(int d=0;d<4;d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				
				if(nx>-1 && nx<R && ny>-1 && ny<C) {
					if(visitedG[nx][ny]) continue;
					
					if(map[nx][ny] != 'X' && map[nx][ny] != '*') {
						gosumQ.offer(new int[] {nx,ny,curT+1});
						visitedG[nx][ny] = true;
					}
				}
			}
			
		}
		
	}

	private static void fill() {
		int size = waterQ.size();
		
		for(int i=0;i<size;i++) {
			int[] cur = waterQ.poll();
			
			for(int d=0;d<4;d++) {
				int nx = cur[0] + dx[d];
				int ny = cur[1] + dy[d];
				
				if(nx>-1 && nx<R && ny>-1 && ny<C) {
					if(map[nx][ny] != 'X' && map[nx][ny] != 'D' && map[nx][ny] != '*') {
						map[nx][ny] = '*';
						waterQ.offer(new int[] {nx,ny});
					}
				}
			}
			
		}
		
	}
}