import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

class Solution{
	
	static int TC,N;
	static int[][] map;
	static int[][] minDist;
	static final int INF = Integer.MAX_VALUE;
	static boolean[][] visited;
	static int[] dx = {0,-1,0,1};
	static int[] dy = {1,0,-1,0};
	static PriorityQueue<Pos> pq;
	
	static class Pos{
		int x;
		int y;
		int time;
		public Pos(int x, int y, int time) {
			this.x = x;
			this.y = y;
			this.time = time;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		
		TC = Integer.parseInt(br.readLine());
		
		for(int t=1;t<=TC;t++) {
			
			N = Integer.parseInt(br.readLine());
			map = new int[N][N];
			minDist = new int[N][N];
			
			// 초기화 
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					minDist[i][j] = INF;
				}
			}
			
			visited = new boolean[N][N];
			pq = new PriorityQueue<Pos>((o1,o2) -> o1.time - o2.time); // 복구 시간 오름차순 
			
			for(int i=0;i<N;i++) {
				String tmp = br.readLine();
				
				for(int j=0;j<N;j++) {
					map[i][j] = tmp.charAt(j)-'0';
				}
			} // 입력 완료
			
			dijkstra();
			/*
			 * for(int i=0;i<N;i++) { System.out.println(Arrays.toString(minDist[i])); }
			 */
			sb.append("#"+t+" "+minDist[N-1][N-1]+"\n");
		}
		
		bw.write(String.valueOf(sb));
		bw.flush();
		br.close();
		bw.close();
	}

	private static void dijkstra() {
		// 출발 지점 삽입 
		pq.offer(new Pos(0,0,0));
		minDist[0][0] = 0;
		visited[0][0] = true;
		
		while(!pq.isEmpty()) {
			
			Pos cur = pq.poll();
			int x = cur.x;
			int y = cur.y;
			
			// 도착 지점이면 리턴
			if(x == N-1 && y == N-1) return;
			
			// 이미 
			
			
			
			for(int d=0;d<4;d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				
				if(nx>-1 && nx<N && ny>-1 && ny<N) {

					if(visited[nx][ny]) continue;
					
					if(minDist[nx][ny] > minDist[x][y]  + map[nx][ny]) {
						
						minDist[nx][ny] = minDist[x][y] + map[nx][ny];
						pq.offer(new Pos(nx,ny,minDist[nx][ny]));
						visited[nx][ny] = true;
					}
					
				}
			}
		}
	}
}