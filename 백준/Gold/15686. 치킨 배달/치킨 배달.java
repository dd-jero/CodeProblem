import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Main{
	
	
	static int N,M,res;
	static int[][] map;
	static List<int[]> house, chicken;
	static boolean[] visited;
	static List<Integer> selChicken;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		map = new int[N+1][N+1];  // 전체
		house = new ArrayList<>(); // 집
		chicken = new ArrayList<>(); // 치킨 집
		selChicken = new ArrayList<>();
		
		res = Integer.MAX_VALUE;
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				
				if(map[i][j] == 1) house.add(new int[] {i,j});
				else if(map[i][j] == 2) chicken.add(new int[] {i,j});
			}
		} // 입력 완료 
		
		visited = new boolean[chicken.size()];
		dfs(0,0);
		
		bw.write(String.valueOf(res));
		bw.flush();
		br.close();
		bw.close();
		
	}
	
	static void dfs(int cnt, int start) { // 조합
		
		if(cnt == M) { // M개 골랐으면
			calDistance();
			return;
		}
		
		for(int i=start;i<chicken.size();i++) {
			if(visited[i]) continue;
			
			// 선택
			visited[i] = true;
			selChicken.add(i);
			
			// 재귀
			dfs(cnt+1,i+1);
			
			
			// 원복
			visited[i] = false;
			selChicken.remove(selChicken.size()-1);
		}
	}
	
	
	static void calDistance() {
		
		int tmp = 0;
		for(int i=0; i<house.size();i++) {
			int[] curHouse = house.get(i);
			int minDist = Integer.MAX_VALUE;
			
			for(int j=0;j<selChicken.size();j++) {
				int[] curChicken = chicken.get(selChicken.get(j));
				int dist = Math.abs(curChicken[0]-curHouse[0]) + Math.abs(curChicken[1]-curHouse[1]);
				minDist = minDist > dist ? dist : minDist;
			}
			
			tmp += minDist;
		}
		
		res = res > tmp ? tmp : res;
	}
}