import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Data{
	int x;
	int y;
	int cnt;
	int dir;
	int time;
	
	public Data(int x, int y, int cnt, int dir, int time) {
		this.x = x;
		this.y = y;
		this.cnt = cnt;
		this.dir = dir;
		this.time = time;
	}

	@Override
	public String toString() {
		return "Data [x=" + x + ", y=" + y + ", cnt=" + cnt + ", dir=" + dir + ", time=" + time + "]";
	}
}


class Solution{
	
	static int TC,N,M,K,res;
	static Data[][] cell;
	static int[] dx = {-1,1,0,0}; // 상하좌우 
	static int[] dy = {0,0,-1,1};
	static PriorityQueue<Data> que = new PriorityQueue<Data>((o1,o2)->  o2.cnt - o1.cnt); // 미생물 수에 따른 내림차순 
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		TC = Integer.parseInt(br.readLine());
		
		for(int t=1;t<=TC;t++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken()); // 셀 개수
			M = Integer.parseInt(st.nextToken()); // 격리 시간
			K = Integer.parseInt(st.nextToken()); // 미생물 군집 수 
			
			cell = new Data[N][N];
			res = 0;
			
			for(int i=0;i<K;i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken()); // 세로 위치
				int y = Integer.parseInt(st.nextToken()); // 가로 위치
				int cnt = Integer.parseInt(st.nextToken()); // 미생물 수
				int dir = Integer.parseInt(st.nextToken()) - 1; // 이동 방향 (방향 배열의 인덱스로 활용하기 위해 0,1,2,3)
				
				que.add(new Data(x,y,cnt,dir,0));
			} // 입력 완료 	
			
			bfs();
			sb.append("#"+t+" "+res+"\n");
		}
		System.out.println(sb);
		
	}
	
	static void bfs() {
		
		while(!que.isEmpty()) {	
			Data cur = que.poll();
			
			if(cur.time == M) { // 격리 시간에 도달하면
				res += cur.cnt; // 일단 현재 군집의 미생물 수 더하고
				
				while(!que.isEmpty()) { // 큐에 남아 있는 나머지 군집의 미생물 수 까지 더함. 
					res += que.poll().cnt;
				}
				
				return;
			}
				
			int nx = cur.x + dx[cur.dir]; // 현재 군집의 이동 방향 
			int ny = cur.y + dy[cur.dir];
			
			// 이동 시
			if(nx>-1 && nx<N && ny>-1 && ny<N) { // 범위 내에 있다면 
				
				if(nx == 0 || nx == N-1 || ny == 0 || ny == N-1) { // 가장 자리에 존재하면
					
					cur.cnt /= 2; // 미생물 수 절반 감소
					
					switch(cur.dir) { // 방향 전환 
					
					case 0:
						cur.dir = 1;
						break;
					case 1:
						cur.dir = 0;
						break;
					case 2:
						cur.dir = 3;
						break;
					case 3:
						cur.dir = 2;
						break;
					}
				}
				
				Data before = cell[nx][ny]; // 같은 위치에 이미 존재하는 군집
				
				if(before != null) { // 존재하면
					before.cnt += cur.cnt; // 현재 군집의 미생물 수를 더해줌
					// 이미 우선순위 큐에서 미생물 수에 따라 내림차순 정렬이 되어 있어서 이미 존재하게 된 군집이 더 많은 미생물 수를 가짐. 
					
				}else { // 존재하지 않으면 
					cell[nx][ny] = new Data(nx, ny, cur.cnt, cur.dir, cur.time+1); // 1 시간 증가한 현재 군집의 정보 저장
				}
			}
		} // 큐 비어있음. 
		
		// 1시간 후 셀에 있는 군집을 다시 큐에 삽입 
		for(int i=0;i<N;i++) { 
			for(int j=0;j<N;j++) {
				if(cell[i][j] != null) {
					que.add(cell[i][j]);
				}
			}
		}
		
		cell = new Data[N][N];  // 셀 초기화 후 다시 bfs
		bfs();
	}
}