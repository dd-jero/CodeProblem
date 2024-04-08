import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Solution{
	
	static int T,N,M,R,C,L,res;
	static int[][] map;
	static boolean[][] visited;
	static Queue<int[]> q;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		T = Integer.parseInt(br.readLine());
		
		for(int t=1;t<=T;t++) {
			
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken()); // 세로 크기
			M = Integer.parseInt(st.nextToken()); // 가로 크기
			R = Integer.parseInt(st.nextToken()); // 맨홀 뚜껑이 위치한 세로 위치
			C = Integer.parseInt(st.nextToken()); // 맨홀 뚜껑이 위치한 가로 위치
			L = Integer.parseInt(st.nextToken()); // 탈출 후 소요된 시간
			
			q = new ArrayDeque<int[]>();
			visited = new boolean[N][M];
			map = new int[N][M];
			
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				
				for(int j=0;j<M;j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			} // 입력 완료
			res = 1;
			bfs();
			sb.append("#"+t+" "+res+"\n");
		}
		
		bw.write(String.valueOf(sb));
		bw.flush();
		br.close();
		bw.close();
	}

	private static void bfs() {
		q.offer(new int[] {R,C});
		visited[R][C] = true;
		
		for(int t=1;t<L;t++) {
			// 한 시간 이동
			int qSize = q.size();
			for(int i=0; i<qSize;i++) {
				int[] cur = q.poll();
				int x = cur[0];
				int y = cur[1];
				
				// 각 터널 구조물에 따라 
				if(map[x][y] == 1) {
					checkLeft(x,y);
					checkRight(x,y);
					checkUp(x,y);
					checkDown(x,y);
				}else if(map[x][y] == 2) {
					checkUp(x,y);
					checkDown(x,y);
				}else if(map[x][y] == 3) {
					checkLeft(x,y);
					checkRight(x,y);
				}else if(map[x][y] == 4) {
					checkRight(x,y);
					checkUp(x,y);
				}else if(map[x][y] == 5) {
					checkRight(x,y);
					checkDown(x,y);
				}else if(map[x][y] == 6) {
					checkLeft(x,y);
					checkDown(x,y);
				}else if(map[x][y] == 7) {
					checkLeft(x,y);
					checkUp(x,y);
				}
			}
		}
		
	}
	
	private static void checkLeft(int x, int y) {
		if(checkRegion(x,y-1)) {
			if(map[x][y-1] == 1 || map[x][y-1] == 3 || map[x][y-1] == 4 || map[x][y-1] == 5) {
				if(!visited[x][y-1]) {
					q.offer(new int[] {x,y-1});
					visited[x][y-1] = true;
					res++;
				}
			}
		}
	}
	
	private static void checkRight(int x, int y) {
		if(checkRegion(x,y+1)) {
			if(map[x][y+1] == 1 || map[x][y+1] == 3 || map[x][y+1] == 6 || map[x][y+1] == 7) {
				if(!visited[x][y+1]) {
					q.offer(new int[] {x,y+1});
					visited[x][y+1] = true;
					res++;
				}
			}
		}
	}
	
	private static void checkUp(int x, int y) {
		if(checkRegion(x-1,y)) {
			if(map[x-1][y] == 1 || map[x-1][y] == 2 || map[x-1][y] == 5 || map[x-1][y] == 6) {
				if(!visited[x-1][y]) {
					q.offer(new int[] {x-1,y});
					visited[x-1][y] = true;
					res++;
				}
			}
		}
	}
	
	private static void checkDown(int x, int y) {
		if(checkRegion(x+1,y)) {
			if(map[x+1][y] == 1 || map[x+1][y] == 2 || map[x+1][y] == 4 || map[x+1][y] == 7) {
				if(!visited[x+1][y]) {
					q.offer(new int[] {x+1,y});
					visited[x+1][y] = true;
					res++;
				}
			}
		}
	}
	
	private static boolean checkRegion(int x, int y) {
		return (x>-1 && x<N && y>-1 && y<M);
	}
}