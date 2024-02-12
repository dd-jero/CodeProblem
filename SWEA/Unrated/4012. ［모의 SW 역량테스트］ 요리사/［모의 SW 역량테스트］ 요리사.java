import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Solution{
	
	static int TC,N,res;
	static int[][] arr;
	static boolean[] visited;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		TC = Integer.parseInt(br.readLine());
		
		for(int t=1;t<=TC;t++) { // 테스트 케이스 
			N = Integer.parseInt(br.readLine());
			arr = new int[N+1][N+1];
			visited = new boolean[N+1];
			res = Integer.MAX_VALUE;
			
			for(int i=1;i<=N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=1;j<=N;j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			} // 입력 완료 
			
			combination(0,1); // 1번 재료 부터 (조합)
			
			sb.append("#").append(t+" ").append(res+"\n");
			
		}
		
		bw.write(String.valueOf(sb));
		
		bw.flush();
		br.close();
		bw.close();
	}
	
	static void combination(int cnt, int start) {
		
		if(cnt == N/2) { // 종료조건: N/2개씩 재료가 나누어 지면 
			
			int sumT = check(0, true); // true인 요소들의 시너지 합
			int sumF = check(0, false); // false인 요소들의 시너지 합
			int diff = Math.abs(sumT-sumF);
			
//			for(int i=1;i<=N;i++) { // true, false인 요소 확인
//				System.out.print(visited[i]? i+" ": "X ");
//			}
//			System.out.println();
			
			res = (diff< res)? diff:res;
			return;
		}
		
		for(int i=start;i<=N;i++) { // N번 재료까지 
			if(visited[i]) continue; // 이미 포함되었으면 아래 무시 
			
			visited[i] = true;
			combination(cnt+1, i+1);
			visited[i] = false;
		}
	}
	
	static int check(int cnt, boolean b) { // 시너지 더하기 
		int sum = 0;
		
		for(int i=1;i<=N;i++) {
			if(visited[i] == b) {
				for(int j=1;j<=N;j++) {
					if(visited[j] == b) sum += arr[i][j];
				}
			}
		}
		
		return sum;
			
	}
	
	
	
	
}