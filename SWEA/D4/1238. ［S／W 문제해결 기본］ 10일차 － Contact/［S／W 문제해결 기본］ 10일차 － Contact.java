import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

class Solution{
	
	static int N,start,from,to;
	static ArrayList<Integer>[] adjList;
	static Queue<Integer> q;
	static int[] visited;
	static int res;
	static StringBuilder sb;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		sb = new StringBuilder();
		
		for(int t=1;t<=10;t++) {
			
			sb.append("#"+t+" ");
			
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken()); // 데이터의 개수
			start = Integer.parseInt(st.nextToken()); // 시작 숫자 
			
			// 초기화 
			q = new ArrayDeque<Integer>();
			adjList = new ArrayList[101]; // 1 ~ 100
			visited = new int[101];
			
			// 인접 리스트 활용 
			for(int i=0;i<=100;i++) {
				adjList[i] = new ArrayList<Integer>();
			}
			
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<N/2;i++) { // 데이터는 from,to 짝이어서 N/2번 돌면 됨
				from = Integer.parseInt(st.nextToken());
				to = Integer.parseInt(st.nextToken());
				adjList[from].add(to);
			}
			bfs();
			find_max();
		}
		bw.write(String.valueOf(sb));
		bw.flush();
		br.close();
		bw.close();
		
	}
	static void bfs() { // 인접 리스트를 활용해서 BFS
		q.add(start);
		visited[start] = 1;
		
		while(!q.isEmpty()) {
			
			int curNum = q.poll();
			
			for(int next : adjList[curNum]) { // 현재 숫자와 인접한 노드 확인 
				if(visited[next] == 0) { // 방문하지 않았으면 
					q.add(next);
					visited[next] = visited[curNum] + 1; // 이전 노드 + 1을 저장 => 최대값이 마지막에 전화한 사람들
				}
			}
		}
	}
	
	static void find_max() {
		
		int maxCnt = 0; // 마지막 전화 
		res = 0;
		for(int i=0; i<101;i++) {
			maxCnt = maxCnt < visited[i] ? visited[i] : maxCnt;
		} // 제일 마지막에 연락 깊이 확인
		
		for(int i=0; i<101;i++) {
			if(visited[i] == maxCnt) { // 마지막 전화를 받은 숫자 간의 최대 값 구하기 
				res = i > res ? i : res;
			}
		} 
		
		sb.append(res+"\n");
	}
}