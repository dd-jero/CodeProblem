import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Solution{
	
	static int TC;
	static int N,M,R,C,L,res;
	static int[][] map;
	static boolean[][] visited;
	static Queue<int[]> q;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		TC = Integer.parseInt(br.readLine()); // 테케
		
		for(int t=1;t<=TC;t++) {
			
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken()); // 지도 세로
			M = Integer.parseInt(st.nextToken()); // 지도 가로
			R = Integer.parseInt(st.nextToken()); // 맨홀 세로
			C = Integer.parseInt(st.nextToken()); // 맨홀 가로
			L = Integer.parseInt(st.nextToken())-1; // 탈출 후 소요 시간 
			
			map = new int[N][M]; // 지하 지도 
			visited = new boolean[N][M]; // 방문 체크
					
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<M;j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			} // 입력 완료 
			
			bfs(); 
			
			res = 0; 
			
			// 방문 체크 개수 확인
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) {
					if(visited[i][j]) {
						res++;
					}
				}
			}
			
			
			sb.append("#"+t+" "+res+"\n");
			
		}
		
		// 출력
		bw.write(String.valueOf(sb));
		bw.flush();
		br.close();
		bw.close();
	}
	
	static void bfs() {
		
		q = new ArrayDeque<int[]>();
		q.offer(new int[] {R,C}); // 맨홀 뚜껑 위치 시작
		visited[R][C] = true; // 체크
		
		while(L>0) {
			
			L--; 
			
			int qSize = q.size(); // 현재 큐에 들어 있는 요소만 활용 = 1시간
			
			for(int i=0;i<qSize;i++) {
				
				int[] cur = q.poll(); // 현재 위치
				
				int x = cur[0];
				int y = cur[1];
				
				switch(map[x][y]) { // 현재 터널 구조물 타입에 따라
					case 1: // 상하좌우
						checkLeft(x,y);
						checkRight(x,y);
						checkUp(x,y);
						checkDown(x,y);
						break;
					case 2: // 상하
						checkUp(x,y);
						checkDown(x,y);
						break;
					case 3: // 좌우
						checkLeft(x,y);
						checkRight(x,y);
						break;
					case 4: // 우상
						checkRight(x,y);
						checkUp(x,y);
						break;
					case 5: // 우하
						checkRight(x,y);
						checkDown(x,y);
						break;
					case 6: // 좌하
						checkLeft(x,y);
						checkDown(x,y);
						break;
					case 7: // 좌상
						checkLeft(x,y);
						checkUp(x,y);
						break;
				}
			}
			
			
		}
		
	}
	
	static void checkLeft(int x, int y) {
		
		if(checkRegion(x,y-1)) {
			// 좌측 구조물은 우측으로 연결되는 터널이어야
			if((map[x][y-1] == 1 || map[x][y-1] == 3 || map[x][y-1] == 4 || map[x][y-1] == 5)) {
				
				if(visited[x][y-1]) return;
				
				q.offer(new int[] {x,y-1});
				visited[x][y-1] = true;
			}
		}
		
		
	}
	
	static void checkRight(int x, int y) {
		
		if(checkRegion(x,y+1)) {
			// 우측 구조물은 좌측으로 연결되는 터널이어야
			if((map[x][y+1] == 1 || map[x][y+1] == 3 || map[x][y+1] == 6 || map[x][y+1] == 7)) {
				
				if(visited[x][y+1]) return;
				
				q.offer(new int[] {x,y+1});
				visited[x][y+1] = true;
			}
		}
	}
	
	static void checkUp(int x, int y) {
		
		if(checkRegion(x-1,y)) {
			// 위의 구조물은 아래로 연결되는 터널이어야
			if((map[x-1][y] == 1 || map[x-1][y] == 2 || map[x-1][y] == 5 || map[x-1][y] == 6)) {
				
				if(visited[x-1][y]) return;
				
				q.offer(new int[] {x - 1,y});
				visited[x-1][y] = true;
			}
		}
	}
	
	static void checkDown(int x, int y) {
		
		if(checkRegion(x+1,y)) {
			// 아래의 구조물은 위로 연결되는 터널이어야
			if(map[x+1][y] == 1 || map[x+1][y] == 2 || map[x+1][y] == 4 || map[x+1][y] == 7) {
				
				if(visited[x+1][y]) return;
				
				q.offer(new int[] {x+1,y});
				visited[x+1][y] = true;
			}
		}
	}
	
	static boolean checkRegion(int x, int y) { // 지도 범위 내 존재 확인
		return (x>-1 && x<N && y>-1 && y<M);
	}
}