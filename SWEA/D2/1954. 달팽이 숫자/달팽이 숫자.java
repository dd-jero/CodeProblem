import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution {
	
	static int[][] dxy = {{0,1},{1,0},{0,-1},{-1,0}};
	static int[][] map;
	static boolean[][] visited;
	public static void main(String[] args) throws IOException {
//		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		
//		int TC = sc.nextInt();
		int TC = Integer.parseInt(br.readLine().trim());
		
		for(int t=1;t<=TC;t++) {
//			int N = sc.nextInt();
			int N = Integer.parseInt(br.readLine().trim());
			
			map = new int[N][N];
			visited = new boolean[N][N];
			int curX = 0;
			int curY = 0;
			
			int d = 0; // 방향
			
			for(int i=1;i<=N*N;i++) { // 배열의 크기만큼 루프
				
				map[curX][curY] =  i; // 현재 위치에 저장
				visited[curX][curY] = true; // 방문
				
				 // 우, 아래, 좌, 위 방향으로
				int nx = curX + dxy[d][0]; 
				int ny = curY + dxy[d][1];
				
				if(nx>=N || nx<0 || ny>=N || ny<0 || visited[nx][ny]) d = (d+1)%4; // 0,1,2,3 반복
				
				
				// 현재 위치 업데이트
				curX = curX + dxy[d][0];
				curY = curY + dxy[d][1];
				
			}
			
			bw.write("#"+t+"\n");
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					
					bw.write(map[i][j]+ " ");
				}
				bw.write("\n");
			}
		}
		bw.flush();
		
		bw.close();
		br.close();
	}
		
}