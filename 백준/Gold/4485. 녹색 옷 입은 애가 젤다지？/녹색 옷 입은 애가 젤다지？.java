import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Data implements Comparable<Data>{
	
	int x;
	int y;
	int cost;
	
	
	public Data(int x, int y, int cost) {
		this.x = x;
		this.y = y;
		this.cost = cost;
	}


	@Override
	public int compareTo(Data o) {
		return this.cost - o.cost;
	}
	
	
	
}

class Main{
	
	static int N;
	static int[][] map;
	static int[][] minDist;
	static int[] dx = {0,1,0,-1};
	static int[] dy = {1,0,-1,0};
	static boolean[][] visited;
	static int TC = 1;
	
	static PriorityQueue<Data> pq = new PriorityQueue<Data>();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		while(true) {
			
			N = Integer.parseInt(br.readLine());
			
			if(N == 0) break;
			
			map = new int[N][N];
			minDist = new int[N][N]; // 최소 손실 루피를 구하기 위함.
			visited = new boolean[N][N];
			
			for(int i=0;i<N;i++) {
				
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					map[i][j] = Integer.parseInt(st.nextToken()); // 도둑루피 입력
					minDist[i][j] = 200000; 
				}
			} // 입력 완료
			
			
			minDist[0][0] = map[0][0]; // 시작점 [0][0]으로  
			
			pq.offer(new Data(0,0,map[0][0])); // 시작점 삽입 
			
			while(!pq.isEmpty()) {
				
				Data cur = pq.poll();
				
				if(visited[cur.x][cur.y]) continue;
				
				visited[cur.x][cur.y] = true;
				
				for(int d=0;d<4;d++) { // 4방향 
					int nx = cur.x + dx[d];
					int ny = cur.y + dy[d];
					
					if(nx>-1 && nx<N && ny>-1 && ny<N) { // 범위 내에 존재하면 
						if(minDist[nx][ny] > minDist[cur.x][cur.y] + map[nx][ny]) { // 다음 위치의 최소 손실이 현재 최소 손실 + 다음 손실보다 크면 
							minDist[nx][ny] = minDist[cur.x][cur.y] + map[nx][ny]; // 업데이트
							pq.offer(new Data(nx,ny,minDist[nx][ny])); // 우선순위 큐 삽입
						}
					}
				}
			}
			
			sb.append("Problem "+TC+": "+minDist[N-1][N-1]+"\n"); // [n-1][n-1] 위치의 최소 손실 sb 삽입 
			
			TC++;
		}
		
		bw.write(String.valueOf(sb));
		bw.flush();
		br.close();
		bw.close();
		
	}
}