import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
	
	static int N,M,K,res;
	static int[][] map;
	static int[][][] visited;
	static int[] dx = {0,1,-1,0};
	static int[] dy = {1,0,0,-1};
	static Queue<Pos> q;
	
	static class Pos{
		int x;
		int y;
		int dist;
		int remainK; // 남은 벽 부수기 가능 수
		int time; // 현재 시간 
		
		public Pos(int x, int y, int dist, int remainK, int time) {
			this.x = x;
			this.y = y;
			this.dist = dist;
			this.remainK = remainK;
			this.time = time; // 1은 낮, -1은 밤 
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken()); // 행
		M = Integer.parseInt(st.nextToken()); // 열
		K = Integer.parseInt(st.nextToken()); // 부술 수 있는 최대 수
		
		map = new int[N][M];
		q = new ArrayDeque<Pos>();
		visited = new int[N][M][K+1];
		
		for(int i=0;i<N;i++) {
			String tmp = br.readLine();
			
			for(int j=0;j<M;j++) {
				map[i][j] = Character.getNumericValue(tmp.charAt(j));
			}
		} // 입력 완료 
		
		res = -1;
		bfs();
		
		bw.write(String.valueOf(res));
		bw.flush();
		br.close();
		bw.close();
	}

	private static void bfs() {
		q.offer(new Pos(0,0,1,K,1)); 
		visited[0][0][K] = 1;
		
		while(!q.isEmpty()) {
			
			Pos cur = q.poll();
			int x = cur.x;
			int y = cur.y;
			int dist = cur.dist;
			int remainK = cur.remainK;
			int time = cur.time;
			
			if(x == N-1 && y == M-1) {
				res = dist;
				return;
			}
			
			for(int d=0;d<4;d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				
				if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
				
				if(map[nx][ny] == 0) { // 다음 위치가 벽 아닐 때
					if(visited[nx][ny][remainK] == 0) { // 방문 안했으면
						visited[nx][ny][remainK] = dist+1;
						q.offer(new Pos(nx,ny,dist+1,remainK,-time));
					}else { // 방문 했으면
						
						if(visited[nx][ny][remainK] > dist+1) { // 현재 경로가 더 작으면
							visited[nx][ny][remainK] = dist+1;
							q.offer(new Pos(nx,ny,dist+1,remainK,-time));
						}
					}
				}else { // 다음 위치가 벽이면 
					if(time == 1 && remainK > 0) { // 낮이고 벽을 부술 수 있으면
						
						if(visited[nx][ny][remainK-1] == 0) { // 방문 안했으면
							visited[nx][ny][remainK-1] = dist+1;
							q.offer(new Pos(nx,ny,dist+1,remainK-1,-time));
						}else { // 방문 했으면
							
							if(visited[nx][ny][remainK-1] > dist+1) { // 현재 경로가 더 작으면
								visited[nx][ny][remainK-1] = dist+1;
								q.offer(new Pos(nx,ny,dist+1,remainK-1,-time));
							}
						}
					}else if(time == -1 && remainK>0) { // 밤이면 현재 위치에서 머물러야됨.
						q.offer(new Pos(x,y,dist+1,remainK,-time));
					}
				}
			}
		}
		
	}
}