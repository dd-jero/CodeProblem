import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;

class Main{
	
	static char[][] map;
	static int res;
	static int[] selected;
	static int[] dx = {0,1,0,-1};
	static int[] dy = {1,0,-1,0};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		map = new char[5][5];
		selected = new int[7];
		
		for(int i=0;i<5;i++) {
			map[i] = br.readLine().toCharArray();
			
		} // 입력 완료
		
		comb(0,0,0);
		
		bw.write(String.valueOf(res));
		bw.flush();
		
		br.close();
		bw.close();
		
	}
	
	static void comb(int cnt, int cntY, int start) {
		
		if(cntY >= 4) return; // 임도현파가 4명 이상이면 가지치기
		
		if(cnt == 7) { // 7명이면
			
			bfs();
			return;
		}
		
		for(int i=start;i<25;i++) { // 25명에 대해서 조합 
			
			selected[cnt] = i;
			if(map[i/5][i%5] == 'Y') { // 해당 학생이 임도연 파면 
				comb(cnt+1,cntY+1,i+1);
			}else {
				comb(cnt+1,cntY,i+1);
			}
			
		}
	}
	
	static void bfs() {
		
		
		Queue<int[]> q = new ArrayDeque<int[]>();
		boolean[] visited = new boolean[7];
		
		q.offer(new int[] {selected[0]/5, selected[0]%5});
		visited[0] = true;
		int tmp = 1;
		
		while(!q.isEmpty()) {
			
			int[] cur = q.poll();
			
			for(int d=0;d<4;d++) {
				
				int nx = cur[0] + dx[d];
				int ny = cur[1] + dy[d];
				
				if(nx>-1 && nx<5 && ny>-1 && ny<5) {
					int nxIdx = nx*5 + ny; // selected 배열에서의 인덱스 
					
					for(int i=0;i<7;i++) {
						
						if(!visited[i] && selected[i] == nxIdx) {
							
							q.offer(new int[] {nx,ny});
							visited[i] = true;
							tmp++;
						}
					}
					
				}
				
			}
			
		}
		
		if(tmp == 7) res++;
	}
}