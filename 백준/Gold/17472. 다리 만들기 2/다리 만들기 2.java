import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

class Main{
	
	static int N,M,num,res,cnt, parent[];
	static int[][] map;
	static boolean[][] visited;
	static Queue<int[]> q;
	static PriorityQueue<Bridge> pq;
	static int[] dx = {1,0,-1,0};
	static int[] dy = {0,1,0,-1};
	
	static class Bridge implements Comparable<Bridge>{
		 int from; // 출발 섬
		 int to; // 도착 섬 
		 int len;  // 다리 길이 
		 
		public Bridge(int from, int to, int len) {
			this.from = from;
			this.to = to;
			this.len = len;
		}

		@Override
		public String toString() {
			return "Edge [from=" + from + ", to=" + to + ", len=" + len + "]";
		}

		@Override
		public int compareTo(Bridge o) {
			return this.len - o.len; // 다리 길이 오름차순 
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		map = new int[N][M];
		visited = new boolean[N][M];
		q = new ArrayDeque<int[]>(); 
		pq = new PriorityQueue<Bridge>(); 
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<M;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		} // 입력 완료
		
		num = 1;
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(map[i][j] == 1 && !visited[i][j]) { // 땅이고 방문하지 않았으면
					divIsland(i,j); // dfs 한번
					num++; // 끝나면 섬 숫자 증가 
				}
			}
		}
		
//		for(int[] b:q) {
//			System.out.println(Arrays.toString(b));
//		}
//		for(int i=0;i<N;i++) {
//			System.out.println(Arrays.toString(map[i]));
//		}
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(map[i][j] != 0) { // 섬이면 
					makeBridge(i,j);
				}
			}
		}
		
//		for(Bridge b:pq) {
//			System.out.println(b);
//		}
		make();
		cnt = 1;
		
		while(!pq.isEmpty()) {
			Bridge cur = pq.poll();
			union(cur.from, cur.to, cur.len);
			
		}
		
		if(cnt == num-1) {
			System.out.println(res);
		}else {
			System.out.println(-1);
		}
		
	}

	// 섬 구분 하기
	private static void divIsland(int i, int j) {
		
		q.offer(new int[] {i,j}); // 다리를 만들기 위해 섬 위치 삽입 
		visited[i][j] = true; // 방문 체크
		map[i][j] = num; // 섬 숫자 기록
		
		for(int d=0;d<4;d++) {
			
			int nx = i + dx[d];
			int ny = j + dy[d];
			
			if(nx>-1 && nx<N && ny>-1 && ny<M) {
				if(visited[nx][ny]) continue;
			
				if(map[nx][ny] == 1) { // 땅이면
					divIsland(nx,ny); // 재귀 
				}
			}
		}
		
	}
	
	// 각 섬의 다리 연결
	private static void makeBridge(int x, int y) {
			
		int sNum = map[x][y];
		
		for(int d=0;d<4;d++) {
			
			int nx = x;
			int ny = y;
			int curLen = 0; // 방항 바뀔 때마다 다리 길이 초기
			
			while(true) { // 한 방향으로 쭉
				
				nx += dx[d];
				ny += dy[d];
				
				if(nx<0 || nx>=N || ny<0 || ny>=M ) break; // 범위 넘어가면 루프 종료 종료
				if(map[nx][ny] == sNum) break; // 같은 섬이면 루프 종료
				
				if(map[nx][ny] == 0) { // 다음 위치가 바다면
					curLen++; // 다리 길이 증가
				}else  { //  다른 섬에 도착하면 
					
					if(curLen > 1) { //다리 길이 2이상일 때
						pq.offer(new Bridge(sNum, map[nx][ny], curLen)); // from, to, 다리 길이
					} 
					
					break; // 종료
				}
					
			}
			
		}
		
	}
	
	// 각 섬끼리의 최소 경로로 연결 (크루스칼 활용)
	private static void union(int from, int to, int len) {
		
		int a = find(from); // 출발 섬의 부모
		int b = find(to); // 도착 섬의 부모
		
		if(a==b) return; // 이미 같은 트리에 속함
		
		parent[b] = a; // 도착 섬의 부모를 출발 섬의 부모로 저장
		res += len;
		cnt++;
	}

	private static int find(int a) { // a가 속한 트리의 부모찾기
		if(a == parent[a]) return a; // 자신의 대표자가 자신이 루트
		return parent[a] = find(parent[a]); // 자신의 부모를 자신이 속한 트리의 대표자로 바꾸어 리턴 (경로 압축 활용)
	}
	

	private static void make() { // 부모 배열 생성 및 초기화 
		
		parent = new int[num];
		for(int i=1;i<num;i++) { // 각 섬의 부모를 자신으로 초기화
			parent[i] = i;
		}
		
	}
}