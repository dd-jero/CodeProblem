import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

class Main{
	
	static int N,M,roomCnt,maxSize;
	static int[][] map;
	static boolean[][] visited;
	static int[][][] roomSize;
	static Queue<int[]> q;
	static int[] dx = {0,-1,0,1}; // 서 북 동 남
	static int[] dy = {-1,0,1,0};
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken()); // 열
		N = Integer.parseInt(st.nextToken()); // 행
		
		map = new int[N][M];
		visited = new boolean[N][M];
		roomSize = new int[N][M][2];
		roomCnt = 0;
		maxSize = Integer.MIN_VALUE;
		q = new ArrayDeque<int[]>();
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<M;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		} // 입력 완료 
		
		// 이 성에 있는 방의 개수, 가장 넓은 방의 넓이
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(!visited[i][j]) {
					roomCnt++;
					bfs(i,j);
					
				}
			}
		}
		sb.append(roomCnt+"\n"+maxSize+"\n");
		
		makeMax();
		
		sb.append(maxSize+"\n");
		
		bw.write(String.valueOf(sb));
		bw.flush();
		br.close();
		bw.close();
		
	}

	private static void makeMax() {
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<M;j++) {
//				System.out.print(roomSize[i][j][0]+ " ");
//			}
//			System.out.println();
//		}
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				
				for(int d=0;d<4;d++) {
					
					int nx = i + dx[d];
					int ny = j + dy[d];
					
					if(nx>-1 && nx<N && ny>-1 && ny<M) {
						
						if(roomSize[i][j][0] != roomSize[nx][ny][0]) { // 서로 다른 방일 때 
							
							int tmpSize = roomSize[i][j][1] + roomSize[nx][ny][1]; // 두 방 크기의 합 
							maxSize = maxSize < tmpSize ? tmpSize : maxSize;
						}
					}
				}
			}
		}
	}

	private static void bfs(int i, int j) {
		
		List<int[]> sameR = new ArrayList<int[]>(); // 같은 방의 좌표들 
		
		sameR.add(new int[] {i,j});
		q.offer(new int[] {i,j});
		visited[i][j] = true;
		int tmpSize = 1;
		
		while(!q.isEmpty()) {
			
			int[] cur = q.poll();
			int x = cur[0];
			int y = cur[1];
			
			for(int d=0;d<4;d++) {
				
				int nx = x + dx[d];
				int ny = y + dy[d];
				
				if(nx > -1 && nx < N && ny > -1 && ny < M) {
					if(visited[nx][ny]) continue;
					
					if((map[x][y] & (1 << d)) == 0) { // 현재 위치에서 다음 위치까지 이동가능할 때
						sameR.add(new int[]{nx,ny});
						q.offer(new int[] {nx,ny});
						visited[nx][ny] = true;
						tmpSize++;
					}
					
				}
				
			}
		}
		// 방 하나의 크기를 구했으면 
		
		// 해당 사이즈를 저장한 좌표에 저장 
		for(int[] pos : sameR) {
			roomSize[pos[0]][pos[1]][0] = roomCnt;
			roomSize[pos[0]][pos[1]][1] = tmpSize;
		}
		
		// 방 크기 비교 갱신 
		maxSize = tmpSize > maxSize ? tmpSize : maxSize;
		
	}
}