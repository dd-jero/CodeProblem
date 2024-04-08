import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Solution{
	
	static int T,res;
	static int[] cost,plan;
		
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		T = Integer.parseInt(br.readLine());
		
		for(int t=1;t<=T;t++) {
			res = Integer.MAX_VALUE;
			cost = new int[4];
			plan = new int[12];
			
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<4;i++) {
				cost[i] = Integer.parseInt(st.nextToken());
			} // 이용권 가격들
			
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<12;i++) {
				plan[i] = Integer.parseInt(st.nextToken());
			} // 12개월 이용 계획
			// 입력 완료
			
			dfs(0,0);
			
			// 1일, 1달, 3달 이용 방법 확인 후 1년 이용권 비용과 비교 
			res = res > cost[3] ? cost[3] : res;
			
			sb.append("#"+t+" "+res+"\n");
		}
		
		bw.write(String.valueOf(sb));
		bw.flush();
		br.close();
		bw.close();
	}

	private static void dfs(int cnt, int costSum) {
		
		if(cnt >= 12) { // 11월, 12월에도 3달 이용권 가능 이라 12 이상 일 수 있음. 
			res = costSum < res ? costSum : res;
			return;
		}
		
		// 1일 이용권
		dfs(cnt+1, costSum + plan[cnt] * cost[0]);
		// 1달 이용권
		dfs(cnt+1, costSum + cost[1]);
		// 3달 이용권
		dfs(cnt+3, costSum + cost[2]);

	}
}