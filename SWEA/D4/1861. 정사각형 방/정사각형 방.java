import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Data{
	int x;
	int y;
	public Data(int x, int y) {
		this.x = x;
		this.y = y; 
	}
	
}
class Solution{
	
	static int TC, N;
	static int[][] arr;
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,-1,0,1};
	static int[][] visited;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		TC = Integer.parseInt(br.readLine());
		
		for(int t=1;t<=TC;t++) {
			
			Queue<Data> q = new ArrayDeque<Data>();
			
			N = Integer.parseInt(br.readLine());
			arr = new int[N][N];
			visited = new int[N][N];
			
			int resVal = Integer.MAX_VALUE;
			int resCnt = 0;
			
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			} // 입력 완료
			
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					if(visited[i][j] != 0) continue; // 해당 위치 방문 했으면 무시
					
					q.add(new Data(i,j)); // 해당 위치 큐 삽입 
					visited[i][j] = 1; // 카운트 1
					
					while(!q.isEmpty()) { // 큐가 빌 때까지 
						Data cur = q.poll();
						
						int x = cur.x;
						int y = cur.y;
						
						for(int d=0;d<4;d++) { // 4방향 검사 
							
							int nx = x + dx[d];
							int ny = y + dy[d];
							
							if(-1<nx&&nx<N&&-1<ny&&ny<N) { // 범위 내에 위치할 때
								if(arr[x][y] - arr[nx][ny] == 1) { // 현재 위치 값이 다음 방향 값보다 1크면 
									q.add(new Data(nx,ny)); // 큐 삽입 
									visited[nx][ny] = visited[x][y] + 1; // 카운트 1 증가 
									
									if(visited[nx][ny] > resCnt) { // 이동 수가 더 크면
										// 이동 수와 현재 값 갱신 
										resCnt = visited[nx][ny]; 
										resVal = arr[nx][ny];
									}
									else if(visited[nx][ny] == resCnt) { // 이동 수가 같으면 
										resVal = (resVal > arr[nx][ny])?arr[nx][ny]:resVal;
									}
									
									break; // 숫자는 모든 방에 대해 서로 다르기 때문에 종료 
								}
							}
						}
					}
				}
			}
			
			sb.append("#").append(t+" ").append(resVal+" ").append(resCnt+"\n");
		}
		bw.write(String.valueOf(sb));
		
		bw.flush();
		br.close();
		bw.close();
		
	}
}