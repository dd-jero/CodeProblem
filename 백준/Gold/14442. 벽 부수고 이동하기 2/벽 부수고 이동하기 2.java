import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Pos{
	int x;
	int y;
	int cnt;
	int k;
	
	public Pos(int x, int y, int cnt,int k) {
		this.x = x;
		this.y = y;
		this.cnt = cnt;
		this.k = k;
	}
}

class Main{
	
	static int N,M,K,res;
	static int[][] map;
	static boolean[][][] visited;
	static Queue<Pos> q;
	static int[] dx = {0,1,0,-1};
	static int[] dy = {1,0,-1,0};
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken()); // 세로
		M = Integer.parseInt(st.nextToken()); // 가로
		K = Integer.parseInt(st.nextToken()); // 벽을 부술 수 있는 횟수 
		
		map = new int[N][M];
		visited = new boolean[K+1][N][M]; // 벽을 부순 횟수에 따라서 방문 체크 위함 
		res = Integer.MAX_VALUE;
		
		for(int i=0;i<N;i++) {
			String tmp = br.readLine();
			for(int j=0;j<M;j++) {
				map[i][j] = tmp.charAt(j)-'0';
			}
		} // 입력 완료 
		
		bfs();
		
		res = res != Integer.MAX_VALUE ? res : -1; // 도착 할 수 없을 때 
		
		bw.write(String.valueOf(res));
		bw.flush();
		br.close();
		bw.close();
		
	}
	
	static void bfs() {
		
		q = new ArrayDeque<Pos>();
		
		// 시작 위치 
		q.offer(new Pos(0,0,1,K));
		visited[K][0][0] = true;
		
		while(!q.isEmpty()) {
			
			Pos cur = q.poll(); // 현재 
			
			if(cur.x == N-1 && cur.y == M-1) { // 도착하면 
				res = cur.cnt;
				return;
			}
			
			for(int d=0;d<4;d++) {
				
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				
				if(nx>-1 && nx<N && ny>-1 && ny<M) { // 범위 내에 존재 시 
					
					if(map[nx][ny] == 1) { // 벽이면
						if(cur.k > 0 && !visited[cur.k-1][nx][ny]) { // 벽을 부술 수 있고, 동일 한 경우가 없었을 때 
							
							q.offer(new Pos(nx,ny,cur.cnt+1,cur.k-1)); // 벽 부술 수 있는 횟 수 1 감소 
							visited[cur.k-1][nx][ny] = true;
						}
					}
					else { // 벽이아니면
						if(!visited[cur.k][nx][ny]) { // 해당 경우가 없었을 때
							q.offer(new Pos(nx,ny,cur.cnt+1,cur.k)); // 벽 부술 수 있는 횟수 그대로 
							visited[cur.k][nx][ny] = true;
						}
						
					}
					
					
				}
			}
			
		}
		
	}
}