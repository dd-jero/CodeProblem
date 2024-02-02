import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

class Main {
	
	static Deque<Integer> deq = new ArrayDeque<Integer>(); 
	static Deque<Integer> res = new ArrayDeque<Integer>();
	static boolean visited[]; // 해당 숫자 제거 여부 
	static int all; // 제거된 개수 
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		visited = new boolean[N+1];
		
		for(int i=1;i<N+1;i++) {
			deq.add(i);
		} // 입력 완료
		
		int cnt =0; // K번째 출력 위함.
		while(all<N) {
			
			int tmp = deq.pollFirst(); // First-In 뽑기
			
			deq.add(tmp); // First-In 뒤에 삽입
			
			if(!visited[tmp]) { // 방문 안했으면
				cnt++; 
				
				if(cnt == K) { // K 번째면
					cnt = 0;
					res.add(tmp); // 결과 덱에 삽입
					visited[tmp] = true; // 제거 
					all++; // 제거된 개수 1 증가 
				}
			}
		}
		
		sb.append("<");
		cnt = 0;
		while(!res.isEmpty()) {
			cnt++;
			
			if(cnt == N) {
				sb.append(res.pollFirst()).append(">");
				
			}
			else {
				sb.append(res.pollFirst()).append(", ");
			}
			
			
		}
		System.out.println(sb);
	}
	
}