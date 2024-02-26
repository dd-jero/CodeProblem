import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

class Solution{
	
	static int TC, N, K, res, cnt;
	static int[][] map, tmp;
	static boolean[][] visited;
	static int[] dx = {0,1,0,-1};
	static int[] dy = {1,0,-1,0};
	static List<int[]> maxList;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		TC = Integer.parseInt(br.readLine());
		
		for(int t=1;t<=TC;t++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			
			map = new int[N][N];
			tmp = new int[N][N];
			maxList = new ArrayList<int[]>();
			int maxtmp = 0;
			res = 0;
			
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					tmp[i][j] = map[i][j];
					
					if(maxtmp < map[i][j]) maxtmp = map[i][j]; // 가장 높은 봉우리값 찾기 위함.
				}
			} // 입력 완료 
			
			for(int i=0;i<N;i++) { 
				for(int j=0;j<N;j++) {
					if(map[i][j] == maxtmp) maxList.add(new int[] {i,j}); // 가장 높은 봉우리의 위치 삽입 
				}
			}
			
			for(int k=1; k<=K;k++) { // 1 ~ K 만큼 깎기
				
				for(int i=0;i<N;i++) {
					for(int j=0;j<N;j++) {
						
						map[i][j] -= k; // 해당 위치 깎기 
						
						for(int c=0;c<maxList.size();c++) { // 높은 봉우리 개수 만큼 
							
							visited = new boolean[N][N];
							cnt = 0; 
							dfs(maxList.get(c), 1);
							
							res = res < cnt ? cnt : res;
						}
						
						map[i][j] = tmp[i][j]; // 원상복구
						
					}
				}
			}
			
			bw.write(String.valueOf("#"+t+" "+res+"\n"));
			bw.flush();
		}
		
		br.close();
		bw.close();
	}
	
	static void dfs(int[] idx, int tmp) {
		
		int x = idx[0];
		int y = idx[1];
		visited[x][y] = true;
		
		cnt = cnt < tmp ? tmp : cnt; // 큰 cnt 갱신 
		
		for(int d=0;d<4;d++) {
			
			int nx = x + dx[d];
			int ny = y + dy[d];
			
			if(nx>-1 && nx<N && ny>-1 && ny<N) {
				if(map[x][y] > map[nx][ny] && !visited[nx][ny]) { // 현재 값보다 작고 방문하지 않았으면
					dfs(new int[] {nx,ny}, tmp+1);
					visited[nx][ny] = false; // 원상복구 
				}
			}
		}
		
	}
}