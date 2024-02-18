import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

class Main{
	
	static int N,a,b,M;
	static int[][] adjacency;
	static int[] visited;
	static Queue<Integer> que = new ArrayDeque<Integer>();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		N = Integer.parseInt(br.readLine());
		adjacency = new int[N+1][N+1];
		visited = new int[N+1];
		
		st = new StringTokenizer(br.readLine());
		a = Integer.parseInt(st.nextToken()); 
		b = Integer.parseInt(st.nextToken());
		
		M = Integer.parseInt(br.readLine());
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			adjacency[x][y] = 1;
			adjacency[y][x] = 1;
		}
		
		que.add(a); // a로 시작 
		bfs();
		
		System.out.println(visited[b] == 0? -1 : visited[b]);
	}
	
	static void bfs() {
		
		while(!que.isEmpty()) {
			
			int cur = que.poll();
			
			if(cur == b) break; // b와 같으면 종료 
			
			for(int i=1;i<N+1;i++) {
				
				if(adjacency[cur][i] == 1 && visited[i] == 0) { // i와 관계가 있고 방문한 적이 없으면
					que.add(i);
					visited[i] = visited[cur] + 1; // 이전 관계에 1 더하여 현재 관계에 저장 
					
				}
			}
		}
	}
}