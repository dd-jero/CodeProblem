import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Monkey{
	int x;
	int y;
	int cnt;
	int reK;
	
	public Monkey(int x, int y, int cnt, int reK) {
		this.x = x;
		this.y = y;
		this.cnt =cnt;
		this.reK = reK;
	}
}
class Main{
	
	static int K,W,H,res;
	static int[][] map;
	static int[] hdx = {-2,-1,1,2,2,1,-1,-2};
	static int[] hdy = {-1,-2,-2,-1,1,2,2,1};
	static int[] mdx = {0,1,0,-1};
	static int[] mdy = {1,0,-1,0};
	static boolean[][][] visited;
	static Queue<Monkey> q;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		K = Integer.parseInt(br.readLine()); // 말의 이동 방법에서 K 횟수 가능
		
		st = new StringTokenizer(br.readLine());
		W = Integer.parseInt(st.nextToken()); // 가로
		H = Integer.parseInt(st.nextToken()); // 세로 
		
		map = new int[H][W];
		res = Integer.MAX_VALUE;
		visited = new boolean[K+1][H][W];
		
		for(int i=0;i<H;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<W;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		} // 입력 완료 
		
		bfs();
		
		res = res != Integer.MAX_VALUE ? res : -1;
		// 출력
		bw.write(String.valueOf(res));
		bw.flush();
		br.close();
		bw.close();
		
	}
	
	static void bfs() {
		q = new ArrayDeque<Monkey>();
		
		// 출발 위치
		q.offer(new Monkey(0,0,0,K));
		visited[K][0][0] = true;
		
		while(!q.isEmpty()) {
			
			Monkey cur = q.poll();
			
			if(cur.x == H-1 && cur.y == W-1) {
				res = cur.cnt;
				return;
			}
			
			if(cur.reK > 0) {
				moveHorse(cur);
				moveMonkey(cur);
			}else {
				moveMonkey(cur);
			}
		}
		
	}
	
	static void moveHorse(Monkey cur) {
		
		for(int d=0;d<8;d++) {
			
			int nx = cur.x + hdx[d];
			int ny = cur.y + hdy[d];
			
			if(nx>-1 && nx<H && ny>-1 && ny<W) {
				if(visited[cur.reK-1][nx][ny] || map[nx][ny] == 1)  continue; // 방문했고 벽이면 안됨
				q.offer(new Monkey(nx,ny,cur.cnt+1, cur.reK-1));
				visited[cur.reK-1][nx][ny] = true;
			}
		}
	}
	
	static void moveMonkey(Monkey cur) {
		for(int d=0;d<4;d++) {
			
			int nx = cur.x + mdx[d];
			int ny = cur.y + mdy[d];
			
			if(nx>-1 && nx<H && ny>-1 && ny<W) {
				if(visited[cur.reK][nx][ny] || map[nx][ny] == 1)  continue; // 방문했고 벽이면 안됨
				
				q.offer(new Monkey(nx,ny,cur.cnt+1,cur.reK));
				visited[cur.reK][nx][ny] = true;
			}
		}
	}
}