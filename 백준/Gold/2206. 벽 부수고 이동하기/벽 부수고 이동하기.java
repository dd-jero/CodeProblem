import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;


class Pos{
	
	int x;
	int y;
	int cnt;
	int reWall;

	
	public Pos(int x, int y, int cnt, int reWall) {
		this.x = x;
		this.y = y;
		this.cnt = cnt;
		this.reWall = reWall; // 0: 이미 벽을 한번 부숨, 1: 아직 부수지 않음 
	}

	@Override
	public String toString() {
		return "Pos [x=" + x + ", y=" + y + ", cnt=" + cnt + ", reWall=" + reWall + "]";
	}
	
}
class Main{
	
	static int N,M,res;
	static int[][] map;
	static boolean[][][] visited;
	static Queue<Pos> q;
	static int[] dx = {0,1,0,-1};
	static int[] dy = {1,0,-1,0};
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken()); // 세로
		M = Integer.parseInt(st.nextToken()); // 가로 
		
		res = Integer.MAX_VALUE;
		map = new int[N][M];
		visited = new boolean[2][N][M];
		
		for(int i=0;i<N;i++) {
			String tmp = br.readLine();
			for(int j=0;j<M;j++) {
				map[i][j] = tmp.charAt(j) - '0';
			}
		} // 입력완료
		
		bfs();
		
		res = res != Integer.MAX_VALUE ? res : -1;
		
		bw.write(String.valueOf(res));
		bw.flush();
		br.close();
		bw.close();
		
	}
	
	static void bfs() {
		q = new ArrayDeque<Pos>();
		q.offer(new Pos(0,0,1,1));
		visited[1][0][0] = true;
		
		while(!q.isEmpty()) {
			
			Pos cur = q.poll(); // 현재 
			
			if(cur.x == N-1 && cur.y == M-1) {
				res = cur.cnt;
				return;
			}
			
			for(int d=0;d<4;d++) {
				
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				
				if(nx>-1 && nx<N && ny>-1 && ny<M) {
					
					if(map[nx][ny] == 1) { // 다음 위치가 벽일 때
						if(!visited[0][nx][ny] && cur.reWall == 1) {
							q.offer(new Pos(nx,ny,cur.cnt+1,0)); // 벽을 제거
							visited[0][nx][ny] = true; 
						}
						
					}else if(map[nx][ny] == 0){ // 다음 위치가 벽이 아닐 때
						if(!visited[cur.reWall][nx][ny]) {
							q.offer(new Pos(nx,ny,cur.cnt+1,cur.reWall)); // reWall 그대로 
							visited[cur.reWall][nx][ny] = true;
						}
					}
				}
			}
			
		}
		
	}
}