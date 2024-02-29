import java.beans.beancontext.BeanContextServiceProviderBeanInfo;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

class CCTV{
	int x;
	int y;
	int num;
	
	public CCTV(int x, int y, int num) {
		this.x = x;
		this.y = y;
		this.num = num;
	}
}

class Main{
	
	static int N,M,res,minTmp;
	static int[][] map;
	static List<CCTV> cList;
	static int[] dxy = {1,-1};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		res = Integer.MAX_VALUE; // 최소값을 구하기 위해 
		map = new int[N][M];
		cList = new ArrayList<CCTV>();
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<M;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] > 0 && map[i][j] < 6) { 
					cList.add(new CCTV(i,j, map[i][j])); // CCTV 위치 입력 
				}
			}
		}// 입력 완료
		
		dfs(0);
		
		bw.write(String.valueOf(res));
		bw.flush();
		br.close();
		bw.close();
		
	}
	
	static void dfs(int idx) {
		
		if(idx == cList.size()) { //모든 CCTV 다 돌았으면
			
			minTmp = cntZero();
			res = res > minTmp ? minTmp : res;
			return;
			
		}
		
		CCTV cur = cList.get(idx);
		int x = cur.x;
		int y = cur.y;
		
		if(cur.num == 1) { // 1번 CCTV면
			
			checkRight(x, y, -1); // 해당 방향 감시 
			dfs(idx+1);
			checkRight(x, y, 1); // 원복 
			
			checkDown(x, y, -1); // 해당 방향 감시
			dfs(idx+1);
			checkDown(x, y, 1); // 원복 
			
			checkLeft(x, y, -1); // 해당 방향 감시 
			dfs(idx+1);
			checkLeft(x, y, 1); // 원복 
			
			
			checkUp(x, y, -1); // 해당 방향 감시
			
			dfs(idx+1);
			checkUp(x, y, 1); // 원복 
			
			
		}else if(cur.num == 2) {
			
			checkRight(x, y, -1); // 해당 방향 감시 
			checkLeft(x, y, -1); 
			
			dfs(idx+1);
			checkRight(x, y, 1); // 원복 
			checkLeft(x, y, 1); // 원복 
			
			
			checkUp(x, y, -1); // 해당 방향 감시 
			checkDown(x, y, -1); // 해당 방향 감시 
			
			dfs(idx+1);
			checkUp(x, y, 1); // 원복
			checkDown(x, y, 1); // 원복
			
			
		}else if(cur.num == 3) {
			
			checkRight(x, y, -1); // 해당 방향 감시
			checkUp(x, y, -1); // 해당 방향 감시 
			
			dfs(idx+1);
			checkRight(x, y, 1); // 원복 
			checkUp(x, y, 1); // 원복
			
			
			checkRight(x, y, -1); // 해당 방향 감시
			checkDown(x, y, -1); // 해당 방향 감시 
			
			dfs(idx+1);
			checkRight(x, y, 1); // 원복 
			checkDown(x, y, 1); // 원복
			
			
			checkLeft(x, y, -1); // 해당 방향 감시
			checkDown(x, y, -1); // 해당 방향 감시 
			
			dfs(idx+1);
			checkLeft(x, y, 1); // 원복 
			checkDown(x, y, 1); // 원복
			
			
			checkLeft(x, y, -1); // 해당 방향 감시
			checkUp(x, y, -1); // 해당 방향 감시 
			
			dfs(idx+1);
			checkLeft(x, y, 1); // 원복 
			checkUp(x, y, 1); // 원복
			
			
		}else if(cur.num == 4) {
			
			checkLeft(x, y, -1); 
			checkRight(x, y, -1); // 해당 방향 감시
			checkUp(x, y, -1); // 해당 방향 감시 
			
			dfs(idx+1);
			checkLeft(x, y, 1); // 원복 
			checkRight(x, y, 1); // 원복 
			checkUp(x, y, 1); // 원복
			
			checkUp(x, y, -1); 
			checkRight(x, y, -1); // 해당 방향 감시
			checkDown(x, y, -1); // 해당 방향 감시 
			
			dfs(idx+1);
			checkUp(x, y, 1); // 원복 
			checkRight(x, y, 1); // 원복 
			checkDown(x, y, 1); // 원복
			
			checkLeft(x, y, -1); 
			checkRight(x, y, -1); // 해당 방향 감시
			checkDown(x, y, -1); // 해당 방향 감시 
			
			dfs(idx+1);
			checkLeft(x, y, 1); // 원복 
			checkRight(x, y, 1); // 원복 
			checkDown(x, y, 1); // 원복
			
			checkUp(x, y, -1); 
			checkLeft(x, y, -1); // 해당 방향 감시
			checkDown(x, y, -1); // 해당 방향 감시 
			
			dfs(idx+1);
			checkUp(x, y, 1); // 원복 
			checkLeft(x, y, 1); // 원복 
			checkDown(x, y, 1); // 원복
			
			
		}else if(cur.num == 5) {
			
			checkLeft(x, y, -1); 
			checkRight(x, y, -1); // 해당 방향 감시
			checkUp(x, y, -1); // 해당 방향 감시 
			checkDown(x, y, -1); // 해당 방향 감시 
			
			dfs(idx+1);
			checkLeft(x, y, 1); // 원복 
			checkRight(x, y, 1); // 원복 
			checkUp(x, y, 1); // 원복
			checkDown(x, y, 1); // 원복
			
		}
		
	}
	static void checkRight(int x, int y, int num) {
		
		int ny = y;
		while(true) {
			
			ny += dxy[0]; // 오른쪽 방향으로 
			
			if(region(x,ny) || map[x][ny] == 6) return; // 범위를 넘어 가거나 벽이면 종료 
			if(map[x][ny] > 0 && map[x][ny] < 6) continue; // cctv 존재하면 
			if(map[x][ny] <= 0) {
				map[x][ny] += num; // 감시 가능 체크 
			}
		}
	}
	static void checkLeft(int x, int y, int num) {
	
		int ny = y;
		while(true) {
			
			ny += dxy[1]; // 왼쪽 방향으로 
			
			if(region(x,ny) || map[x][ny] == 6) return; // 범위를 넘어 가거나 벽이면 종료 
			if(map[x][ny] > 0 && map[x][ny] < 6) continue;
			
			if(map[x][ny] <= 0) {
				map[x][ny] += num; // 감시 가능 체크 
			}
		}
	}
	static void checkDown(int x, int y, int num) {
		
		int nx = x;
		while(true) {
			
			nx += dxy[0]; // 아래 방향으로 
			
			if(region(nx,y) || map[nx][y] == 6) return; // 범위를 넘어 가거나 벽이면 종료 
			if(map[nx][y] > 0 && map[nx][y] < 6) continue;
			
			if(map[nx][y] <= 0) {
				map[nx][y] += num; // 감시 가능 체크 
			}
		}	
	}
	static void checkUp(int x, int y, int num) {
		
		int nx = x;
		while(true) {
			
			nx += dxy[1]; // 위 방향으로 
			
			if(region(nx,y) || map[nx][y] == 6) return; // 범위를 넘어 가거나 벽이면 종료 
			if(map[nx][y] > 0 && map[nx][y] < 6) continue;
			
			if(map[nx][y] <= 0) {
				map[nx][y] += num; // 감시 가능 체크 
			}
		}
	}
	
	static int cntZero() {
		int cnt = 0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(map[i][j] == 0) {
					cnt++;
				}
			}
		}
		
		return cnt;
	}
	
	static boolean region(int x, int y) {
		if(x<0 || x>=N || y<0 || y>=M) {
			return true;
		}
		
		return false;
	}
}

