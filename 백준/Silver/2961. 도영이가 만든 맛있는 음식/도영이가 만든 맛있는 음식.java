import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

// 도영이가 만든 맛있는 음식 
// 신맛: 곱, 쓴맛: 합
// 신맛과 쓴맛의 차이가 최소를 출력 

class Main {
		
	static int[] sList;
	static int[] bList;
	static boolean[] visited;
	static int N, res;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		
		sList = new int[N];
		bList = new int[N];
		visited = new boolean[N+1];
		res= Integer.MAX_VALUE;
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			sList[i] = Integer.parseInt(st.nextToken());
			bList[i] = Integer.parseInt(st.nextToken());
		} // 입력 완료
		subSet(0,1,0);
		
		bw.write(String.valueOf(res));
		bw.newLine();
		
		br.close();
		bw.flush();
		bw.close();
	}
	
	static void subSet(int cnt, int mulS, int sumB) {
		
		
		if(cnt == N) { // 모든 재료를 다 쓰면 (재료가 하나일 때 고려)
			int notVisitedCnt = 0; 
			
			for(int i=0;i<N;i++) {
				
				if(visited[i]) continue;
				notVisitedCnt++;
			}
			if(notVisitedCnt == N) return; // 사용한 재료가 없으면 돌아감.
			res = Math.min(Math.abs(mulS-sumB), res); // 사용한 재료가 있으면 최소 값 구하고 돌아감.
			return; 
		}
		
		visited[cnt] = true;
		subSet(cnt+1,mulS*(sList[cnt]),sumB+bList[cnt]);
		visited[cnt] = false;
		subSet(cnt+1,mulS,sumB);
		
	}
	
}
