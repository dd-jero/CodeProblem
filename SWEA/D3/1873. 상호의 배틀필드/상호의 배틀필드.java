import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Solution{
	
	static int T;
	static int H,W,N;
	static char[][] map;
	static char[] cmd;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	static int curX,curY;
	static int curDir;
	static StringBuilder sb;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		sb = new StringBuilder();
		
		T = Integer.parseInt(br.readLine());
		
		for(int t=1;t<=T;t++) {
			
			st = new StringTokenizer(br.readLine());
			H = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			
			map = new char[H][W];
			
			for(int i=0;i<H;i++) {
				map[i] = br.readLine().toCharArray();
			} // 맵 입력
			
			N = Integer.parseInt(br.readLine());
			cmd =  br.readLine().toCharArray(); // 동작 입력 
			
			loop:for(int i=0;i<H;i++) {
				for(int j=0;j<W;j++) {
					if(map[i][j]=='^'||map[i][j]=='v'||map[i][j]=='<'||map[i][j]=='>') { // 전차 시작 위치 
						
						// 초기 탱크 위치와 바라보는 방향 저장 
						curX = i;
						curY = j;
						if(map[i][j]=='^')curDir=0;
						else if(map[i][j]=='v')curDir=1;
						else if(map[i][j]=='<')curDir=2;
						else if(map[i][j]=='>')curDir=3;
						break loop; 
					}
				}
			}
			
			for(char c:cmd) { // 동작 진행 
				
				
				int nx =0;
				int ny =0;
				if(c == 'U') { // 전차가 바라보는 방향을 위쪽으로 바꾸고, 한 칸 위의 칸이 평지라면 위 그 칸으로 이동한다.
					curDir = 0;
					map[curX][curY] = '^';
					nx = curX + dx[curDir];
					ny = curY + dy[curDir];
					
					if(checkgo(nx, ny)) {
						map[curX][curY] = '.';
						map[nx][ny] = '^';
						curX = nx;
						curY = ny;
					}
				}else if(c == 'D') { // 전차가 바라보는 방향을 아래쪽으로 바꾸고, 한 칸 아래의 칸이 평지라면 그 칸으로 이동한다.
					curDir = 1;
					map[curX][curY] = 'v';
					nx = curX + dx[curDir];
					ny = curY + dy[curDir];
					
					if(checkgo(nx, ny)) {
						map[curX][curY] = '.';
						map[nx][ny] = 'v';
						curX = nx;
						curY = ny;
					}
				}else if(c == 'L') { //  전차가 바라보는 방향을 왼쪽으로 바꾸고, 한 칸 왼쪽의 칸이 평지라면 그 칸으로 이동한다.
					curDir = 2;
					map[curX][curY] = '<';
					nx = curX + dx[curDir];
					ny = curY + dy[curDir];
					
					if(checkgo(nx, ny)) {
						map[curX][curY] = '.';
						map[nx][ny] = '<';
						curX = nx;
						curY = ny;
					}
				}else if(c == 'R') { //  전차가 바라보는 방향을 오른쪽으로 바꾸고, 한 칸 오른쪽의 칸이 평지라면 그 칸으로 이동한다.
					curDir = 3;
					map[curX][curY] = '>';
					nx = curX + dx[curDir];
					ny = curY + dy[curDir];
					
					if(checkgo(curX, curY+1)) {
						map[curX][curY] = '.';
						map[nx][ny] = '>';
						curX = nx;
						curY = ny;
					}
				}else if(c == 'S') { //  전차가 현재 바라보고 있는 방향으로 포탄을 발사한다.
					
					nx = curX + dx[curDir];
					ny = curY + dy[curDir];
					shoot(nx,ny,curDir);
				}
				
			}
			
			sb.append("#"+t+" ");
			for(int i=0;i<H;i++) {
				for(int j=0;j<W;j++) {
					
					sb.append(map[i][j]);
				}
				sb.append("\n");
			}
			
		}
		
		System.out.println(sb);
	}
	
	
	static boolean checkgo(int x, int y) { // 이동 가능 확인 
		if(x>-1 && x < H && y>-1 && y < W && map[x][y] == '.') {
			return true; // 이동가능
		}
		
		return false;
	}
	
	static void shoot(int x, int y, int dir) { // 포탄 발사 
		
		while(x>-1 && x < H && y> -1 && y < W) { // 범위 내에서 존재할 때 
			if(map[x][y] =='#') break; // 강철 벽 또는 물이면 
			else if(map[x][y] == '*') { // 벽돌 벽이면 평지로 
				map[x][y] = '.';
				break;
			}
			else if(map[x][y] == '.' || map[x][y] == '-' ) { // 평지면  
				x += dx[dir]; // 해당 방향으로 나아가 범위 내에서 벽  파괴 가능  
				y += dy[dir];
				
			}
			
		}
		
	}
}