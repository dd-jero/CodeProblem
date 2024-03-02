import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Swan{
	int x;
	int y;
	
	public Swan(int x, int y) {
		this.x = x;
		this.y = y;
	}
}
class Main{
	
	static int R,C, res;
	static char[][] map;
	static Swan[] swans;
	static Queue<int[]> waterQ, mainQ;
	static boolean[][] visited;
	static int[] dx = {0,1,0,-1};
	static int[] dy = {1,0,-1,0};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		map = new char[R][C];
		swans = new Swan[2]; // 두 백조의 위치 저장 
		waterQ = new ArrayDeque<int[]>(); // 물의 위치 저장 (얼음 녹이기 위함)
		mainQ = new ArrayDeque<int[]>(); // 백조가 움직임 
		visited = new boolean[R][C];
		
		for(int i=0;i<R;i++) {
			map[i] = br.readLine().toCharArray();
			
			for(int j=0;j<C;j++) {
				if(map[i][j] == 'L') {
					if(swans[0] == null) swans[0] = new Swan(i,j);
					else swans[1] = new Swan(i,j);
				}
				if(map[i][j] != 'X') waterQ.offer(new int[] {i,j});
			}
		} // 입력 완료 
		
		res = 0;
		mainQ.offer(new int[] {swans[0].x, swans[0].y});
		visited[swans[0].x][swans[0].y] = true;
		
		while(true) {
			
			boolean check = moveSwan();
			
			if(check) {
				break;
			}
			
			meltIce();
			res++;
		}
		
		
		bw.write(String.valueOf(res));
		bw.flush();
		br.close();
		bw.close();
	}
	
	static boolean moveSwan() { // 현재 물인 위치에서 백조 이동
		
		Queue<int[]>nextQ = new ArrayDeque<int[]>(); // 다음날 이동 시 사용할 큐 
		
		while(!mainQ.isEmpty()) {
			
			int[] cur = mainQ.poll();
			
			if(cur[0] == swans[1].x && cur[1] == swans[1].y) { // 다른 백조랑 만나면 
				return true;
			}
			
			for(int d=0;d<4;d++) {
				
				int nx = cur[0] + dx[d];
				int ny = cur[1] + dy[d];
				
				if(nx<0 || nx>=R || ny<0 || ny>=C) continue;
				if(visited[nx][ny]) continue;
				
				visited[nx][ny] = true;
				if(map[nx][ny] == 'X') { // 현재 이동 구역은 물이어서 다음날 녹는 얼음 => 다음날 이동 가능!
					nextQ.offer(new int[] {nx,ny}); // 다음 날 이동할 위치로 저장 
					continue;
				}
				// 물이면 
				mainQ.offer(new int[] {nx,ny}); 
				
				
			}
		} // 오늘 이동할 수 있는 구역 모두 이동 했으면
		
		mainQ = nextQ; // 다음날 이동할 구역으로 큐 교체
		return false; // 아직 다른 백조와 만나지 못함.
	}
	static void meltIce() {
		
        int size = waterQ.size();
        
        while (size>0) {
            int[] cur = waterQ.poll();
            int x = cur[0];
            int y = cur[1];
 
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || nx>=R || ny<0 || ny>=C) continue;
                
                if(map[nx][ny] == 'X' || map[nx][ny] == 'L') { // 물과 인접한 지역이므로
           		 	map[nx][ny] = '.'; // 녹는다.
                    waterQ.offer(new int[] {nx,ny});
                }
            }
            
            size--;
        }
    }
}