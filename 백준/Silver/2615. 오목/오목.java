import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	
	static int[][] dxy = {{1,0},{1,1},{0,1},{-1,1}};
	
	public static void main(String[] args) throws Exception {
		
		// 콘솔로 입력 받기 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[][] board = new int[19][19];
		
		for(int i=0;i<19;i++) {
			
			// 해당 클래스를 이용해 " "기준으로 문자열 분리하기 
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			
			for(int j=0;j<19;j++){
				// 분리된 문자열을 정수로 변환하여 저장하기 
				board[i][j] = Integer.parseInt(st.nextToken());
			}
			
		}
		
		// 오목판 전체 탐색
		for(int y=0;y<19;y++) {
			for(int x=0;x<19;x++) {
				// 검은 돌 또는 흰 돌이면
				if(board[x][y] == 1 || board[x][y] == 2) {
					
					// 4방향 확인 
					for(int d=0;d<4;d++) { 
						int nx = x;
						int ny = y;
						int cnt = 1;
						
						// 같은 방향으로 같으면 계속해서 진행 
						while(true) {
							nx += dxy[d][0];
							ny += dxy[d][1];
							
							if((-1<nx&&nx<19)&&(-1<ny&&ny<19)) {
								if(board[x][y] == board[nx][ny]) {
									cnt++;
								}else {
									break;
								}
							}else {
								break;
							}
						}
						nx = x;
						ny = y;
						
						while(true) {
							nx -= dxy[d][0];
							ny -= dxy[d][1];
							
							if((-1<nx&&nx<19)&&(-1<ny&&ny<19)) {
								if(board[x][y] == board[nx][ny]) {
									cnt++;
								}else {
									break;
								}
							}else {
								break;
							}
						}
						
						
						if(cnt == 5) {
							System.out.println(board[x][y]);
							System.out.printf("%d %d\n",x+1,y+1);
							return;
						}
					}
				}
					
				
			}
		}
		System.out.println(0);
		

	}

}
